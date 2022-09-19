/*20201216 IVAN ARAOZ*/
using namespace std;

#include "Funciones.hpp"
#define TAMLINEA 140

void imprimirLinea(char car, int tam, ofstream &archReporte){
    for(int i=0; i<tam; i++){
        archReporte.put(car);
    }
    archReporte.put('\n');
}

void imprimirMedico(ifstream &archMedicos, ofstream &archReporte, int codMedico, 
        double &tarifa){
    int codigo, contador=0;
    char letra, extra;
    archMedicos.seekg(0, ios::beg);
    while(true){
        archMedicos >> codigo;
        if(codigo == codMedico){
            archMedicos >> ws;
            while(true){
                letra = archMedicos.get();
                contador++;
                if(letra != '_'){
                    archReporte.put(letra);
                    if(letra == ' ') break;
                }
                else
                    archReporte.put(' ');           
            }
            archMedicos >> tarifa;
            for(int i=0; i<= contador; i++){
                archReporte.put(' ');
            }
            break;
        }
        else{
            while(true){
                extra = archMedicos.get();
                if(extra == '\n') break;
            }
        }
    }
}
//FALTA REVISAR ESTA FUNCION PARA IMPRIMIR CORRECTAMENTE
//FALTA AJUSTAR EL CONTADOR PARA ORDENAR CORRECTAMENTE
void imprimirCitas(ifstream &archCitas, ifstream &archMedicos, 
        ofstream &archReporte, int dniPaciente){
    int dni, codMedico, dd, mm, yyyy;
    int hhI, minI, ssI, horaI;
    int hhF, minF, ssF, horaF;
    double tarifa, horaT, total = 0.0;
    char slash, dosPuntos;
    archCitas.seekg(0, ios::beg);
    while(true){
        archCitas >> dni;
        if(archCitas.eof()) break;
        if(dni == dniPaciente){
            archCitas >> codMedico >> dd >> slash >> mm >> slash >> yyyy;
            archCitas >> hhI >> dosPuntos >> minI >> dosPuntos >> ssI;
            archCitas >> hhF >> dosPuntos >> minF >> dosPuntos >> ssF;
            archReporte.fill('0');
            archReporte << setw(2) << dd << slash << setw(2) << mm << slash << yyyy;
            archReporte.fill(' '); archReporte << setw(5) << " ";
            imprimirMedico(archMedicos, archReporte, codMedico, tarifa);
            archReporte << setw(20) << tarifa;
            archReporte << setw(3) << " " << hhI << dosPuntos << minI << dosPuntos
                    << ssI;
            archReporte << setw(3) << " " << hhF << dosPuntos << minF << dosPuntos
                    << ssF;
            horaI = hhI*3600 + minI*60 + ssI;
            horaF = hhF*3600 + minF*60 + ssF;
            horaT = (horaF - horaI)/(double)3600;
            archReporte << setw(3) << " " << horaT;
            archReporte << setw(3) << " " << tarifa*horaT << endl;
            total = total + tarifa*horaT;
        }
        else{
            archCitas.ignore(500, '\n');
            archCitas >> ws;
        }
    }
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << "Total de gastos por citas: " << setw(10) << " " << 
            total << endl;
    
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirPaciente(ifstream &archPacientes, ofstream &archReporte, int dniPaciente){
    int telefono;
    char letra;
    archReporte << setw(5) << dniPaciente << setw(3) << " ";
    while(true){
        letra = archPacientes.get();
        if(letra == ']') break;
        if(letra == '[') letra = ' ';
        archReporte.put(letra);
    }
    archPacientes >> telefono;
    archReporte << setw(20) << telefono << endl << endl;
    archReporte << "CITAS REALIZADAS:" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << setw(10) << "FECHA";
    archReporte << setw(30) << "MEDICO";
    archReporte << setw(35) << "TARIFA";
    archReporte << setw(15) << "LLEGADA";
    archReporte << setw(15) << "SALIDA";
    archReporte << setw(25) << "TIEMPO(hrs.)";
    archReporte << setw(15) << "PAGO" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
}

void imprimirCabeceraPaciente(ofstream &archReporte){
    archReporte << setw(5) << "DNI" << setw(20) << "Paciente" << setw(25) <<
            "Telefono" << endl;
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(70) << "CLINICA PSIOLOGICA TP." << endl;
    archReporte << setw(75) << "RELACION DE CITAS POR PACIENTES" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirReporte(ifstream & archMedicos, ifstream & archPacientes, 
        ifstream & archCitas, ofstream & archReporte){
    int dniPaciente;
    imprimirCabecera(archReporte);
    while(true){
        archPacientes >> dniPaciente;
        if(archPacientes.eof()) break;
        imprimirCabeceraPaciente(archReporte);
        imprimirPaciente(archPacientes, archReporte, dniPaciente);
        imprimirCitas(archCitas, archMedicos, archReporte, dniPaciente);
    }
}