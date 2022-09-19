/*20201216 IVAN ARAOZ*/
using namespace std;

#include "Funciones.hpp"
#define TAMLINEA 150

void imprimirLinea(char car, int tam, ofstream &archReporte){
    for(int i=0; i<tam; i++){
        archReporte.put(car);
    }
    archReporte.put('\n');
}

void imprimirMedico(ifstream &archMedicos, ofstream &archReporte, int codMedico, 
        double &tarifa){
    int codigo, contador=0;
    char letra;
    archMedicos.seekg(0, ios::beg);
    while(true){
        archMedicos >> codigo;
        if(codigo == codMedico){
            archMedicos >> ws;
            while(true){
                letra = archMedicos.get();
                if(letra != '_'){
                    archReporte.put(letra);
                    contador++;
                    if(letra == ' ') break;
                }
                else{
                    archReporte.put(' ');
                    contador++;
                }         
            }
            archMedicos >> tarifa;
            for(int i=0; i <= 53 - contador; i++){
                archReporte.put(' ');
            }
            break;
        }
        else{
            archMedicos.ignore(1000, '\n');
            archMedicos >> ws;
        }
    }
}
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
            archReporte << setw(6) << tarifa;           
            archReporte << setw(7) << " ";
            archReporte.fill('0');
            archReporte << setw(2) << hhI << dosPuntos << setw(2) << minI << 
                    dosPuntos << setw(2) << ssI;
            archReporte.fill(' ');
            archReporte << setw(7) << " ";
            archReporte.fill('0');
            archReporte << setw(2) << hhF << dosPuntos << setw(2) << minF << 
                    dosPuntos << setw(2) << ssF;
            archReporte.fill(' ');
            horaI = hhI*3600 + minI*60 + ssI;
            horaF = hhF*3600 + minF*60 + ssF;
            horaT = (double)(horaF - horaI)/3600;
            archReporte << fixed;
            archReporte << setw(15) << " " << setprecision(2) << horaT;
            archReporte << setw(15) << " " << setprecision(2) << tarifa*horaT 
                    << endl;
            total = total + tarifa*horaT;
            if(archCitas.eof()) break;
        }
        else{
            archCitas.ignore(1000, '\n');
            archCitas >> ws;
            if(archCitas.eof()) break;
        }
    }
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << "Total de gastos por citas: " << setw(10) << " " << 
            total << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirPaciente(ifstream &archPacientes, ofstream &archReporte, int dniPaciente){
    int telefono, contador=0;
    char letra;
    archReporte << setw(5) << dniPaciente << setw(3) << " ";
    while(true){
        letra = archPacientes.get();
        if(letra == ']') break;
        if(letra == '[') letra = ' ';
        archReporte.put(letra);
        contador++;
    }
    for(int i=0; i<=45-contador; i++){
        archReporte.put(' ');
    }
    archPacientes >> telefono;
    archReporte << telefono << endl << endl;
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
    archReporte << setw(5) << "DNI" << setw(20) << "Paciente" << setw(40) <<
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