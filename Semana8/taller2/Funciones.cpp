 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

using namespace std;
#include "Funciones.hpp"
#define TAMLINEA 75

void imprimirLinea(char c, int tam, ofstream &archReporte){
    for(int i = 0; i <= tam; i++){
        archReporte.put(c);
    }
    archReporte.put('\n');
}

void buscarMayorSueldo(ofstream &archReporte, ifstream &archProfesores, int cod){
    int codB;
    char c;
    archProfesores.clear();
    archProfesores.seekg(0, ios::beg);
    while(true){
        archProfesores >> codB;
        if(archProfesores.eof()) break;
        if(codB == cod){
            archProfesores >> ws;
            while(true){
                c = archProfesores.get();
                if(c == ' ') break;
                archReporte.put(c);
            }
            break;
        }
        else{
            archProfesores.ignore(1500, '\n');
        }
    }
}

void imprimirResumenFecha(ofstream &archReporte, double sueldoProfesor, 
        int incrementado){
    archReporte << "Resumen: Sueldo en la fecha - " << sueldoProfesor << endl;
    archReporte << setw(9) << " " << "Sueldos incrementados - " << incrementado
            << endl;
}

double buscarCurso(ifstream &archCursos, int codBuscar){
    int cod;
    double creditos = 0.0;
    char extra;
    archCursos.clear();
    archCursos.seekg(0, ios::beg);
    while(true){
        if(archCursos.eof()) break;
        for(int i = 0; i < 3; i++){
            extra = archCursos.get();            
        }
        archCursos >> cod;
        if(cod == codBuscar){
            archCursos >> ws;
            archCursos.ignore(1000, ' ');
            archCursos >> creditos;
            return creditos;
        }
        else
            archCursos.ignore(1000, '\n');
    }
    return creditos;
}

void buscarCursos(ofstream &archReporte, ifstream &archCursos, ifstream &archSueldos){
    int cod, nCursos = 0;
    double creditos, nCreditos = 0.0;
    char extra;
    while(true){
        extra = archSueldos.get();
        if(extra == '\n') break;
        archSueldos >> ws;
        for(int i = 0; i < 3; i++){
            extra = archSueldos.get();
        }
        archSueldos >> cod;
        creditos = buscarCurso(archCursos, cod);
        nCursos++;
        nCreditos += creditos;
    }
    archReporte << setw(10) << nCursos << setw(15) << nCreditos << endl;
}

void buscarImprimirProfesor(ofstream &archReporte, ifstream &archProfesores, 
        int codProfesor, bool &incrementa){
    int cod, contador = 0;
    char trueFalse, c;
    archProfesores.clear();
    archProfesores.seekg(0, ios::beg);
    while(true){
        archProfesores >> cod;
        if(archProfesores.eof()) break;
        if(cod == codProfesor){
            archProfesores >> ws;
            while(true){
                c = archProfesores.get();
                if(c == ' ') break;
                archReporte.put(c);
                contador++;
            }
            archProfesores >> trueFalse;
            if(trueFalse == 'V') 
                incrementa = true;
            else
                incrementa = false;
            break;
        }
        else{
            archProfesores.ignore(1500, '\n');
        }
    }
    for(int i = 0; i <= 30 - contador; i++){
        archReporte.put(' ');
    }
}

void buscarSueldo(ofstream &archReporte, ifstream &archSueldos, ifstream &archProfesores, 
        ifstream &archCursos, int ddB, int mmB, int yyyyB, int &nProfesores, 
        double &mayorSueldo, int &codMayorSueldo){
    int dd, mm, yyyy, codProfesor, incrementado = 0;
    double sueldoProfesor, sueldoFecha = 0.0;
    bool incrementa;
    char extra;
    archSueldos.clear();
    archSueldos.seekg(0, ios::beg);
    while(true){
        archSueldos >> dd;
        if(archSueldos.eof()) break;
        archSueldos >> extra >> mm >> extra >> yyyy;
        if((ddB == dd) and (mmB == mm) and (yyyyB)){
            archSueldos >> codProfesor >> sueldoProfesor;
            buscarImprimirProfesor(archReporte, archProfesores, codProfesor, 
                    incrementa);
            nProfesores++;
            if(incrementa){
                sueldoProfesor +=  sueldoProfesor/10;
                incrementado++;
            }
            archReporte << setw(15) << sueldoProfesor;
            mayorSueldo = sueldoProfesor;
            codMayorSueldo = codProfesor;
            buscarCursos(archReporte, archCursos, archSueldos);
            sueldoFecha += sueldoProfesor;
        }
        else{
            archSueldos.ignore(1000, '\n');
        }
    }
    imprimirResumenFecha(archReporte, sueldoFecha, incrementado);
}

void imprimirFecha(ofstream &archReporte, int dd, int mm, int yyyy, int contador,
        char extra){
    archReporte << contador << ')' << "Fecha de Pago: ";
    archReporte.fill('0');
    archReporte << setw(2) << dd << extra << setw(2) << mm << extra << yyyy 
            << endl;
    archReporte.fill(' ');
    archReporte  << "Nombre Profesor" << setw(30) << "Sueldo" << 
            setw(15) << "#Cursos" << setw(15) << "#Creditos" << endl;
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(29) << " " << "Resumen de Pagos" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void procesarReporte(ifstream &archFechas, ifstream &archSueldos, 
        ifstream &archProfesores, ifstream &archCursos, ofstream &archReporte){
    int contador = 1, dd, mm, yyyy, nProfesores = 0;
    int ddM, mmM, yyyyM, codMayorSueldo, cod;
    int maxProf = 0;
    double mayorSueldo = 0.0, sueldo = 0.0;
    char extra;
    imprimirCabecera(archReporte);
    while(true){
        archFechas >> dd;
        if(archFechas.eof()) break;
        archFechas >> extra >> mm >> extra >> yyyy;
        imprimirFecha(archReporte, dd, mm, yyyy, contador, extra);
        nProfesores = 0;
        buscarSueldo(archReporte, archSueldos, archProfesores, archCursos, 
                dd, mm, yyyy, nProfesores, mayorSueldo, codMayorSueldo);
        if(nProfesores > maxProf){
            maxProf = nProfesores;
            ddM = dd;
            mmM = mm;
            yyyyM = yyyy;
        }
        if(mayorSueldo > sueldo){
                sueldo = mayorSueldo;
                cod = codMayorSueldo;
        }
        contador++;
    }
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "Resumen" << endl << "Fecha con mayor numero de Profesores: ";
    archReporte.fill('0');
    archReporte << setw(2) << ddM << extra << setw(2) << mmM << extra << yyyyM 
            << endl;
    archReporte.fill(' ');
    archReporte << "Profesor con mayor sueldo: ";
    buscarMayorSueldo(archReporte, archProfesores, cod);
}