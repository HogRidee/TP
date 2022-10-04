/* 
 * File:   Funciones.cpp
 * Author: IVAN ALEXANDER ARAOZ ANDRADE 20201216
 *
 */

using namespace std;
#include "Funciones.hpp"
#define TAMLINEA 100

void imprimirLinea(char c, int tam, ofstream &archReporte){
    for(int i = 0; i <= tam; i++){
        archReporte.put(c);
    }
    archReporte.put('\n');
}

void cambiarD(double *arr, int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarI(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void ordenarArreglos(int *arrDni, int *arrCantCitas, int nPacientes, double *arrTiempo, 
        double *arrGasto){
    for(int i = 0; i < nPacientes -1; i++){
        for(int j = i + 1; j < nPacientes; j++){
            if(arrGasto[i] < arrGasto[j]){
                //llamadas a funciones que ordenan los arreglos
                cambiarI(arrDni, i, j);
                cambiarI(arrCantCitas, i, j);
                cambiarD(arrTiempo, i, j);
                cambiarD(arrGasto, i, j);
            }
        }
    }
}

void imprimirResumen(ofstream &archReporte, int *arrCantCitas, double *arrTiempo, 
        double *arrGasto, int nPacientes){
    int nTotalCitas = 0;
    double nTotalTiempo = 0.0, nTotalRecaudado = 0.0;
    for(int i = 0; i < nPacientes; i++){
        nTotalCitas += arrCantCitas[i];
        nTotalTiempo += arrTiempo[i];
        nTotalRecaudado += arrGasto[i];
    }
    archReporte << "CANTIDAD TOTAL DE CITAS: " << setw(20) << nTotalCitas << endl;
    archReporte << "CANTIDAD DE HORAS DE ATENCION: " << setprecision(5) << 
            setw(17) << nTotalTiempo << endl;
    archReporte << "TOTAL RECAUDADO POR LA CLINICA: " << setprecision(2) << 
            setw(16) << nTotalRecaudado << endl;
}

void imprimirArreglos(ofstream &archReporte, int *arrDni, int *arrCantCitas, 
        int nPacientes, double *arrTiempo, double *arrGasto){
    for(int i = 0; i < nPacientes; i++){
        archReporte << setw(2) << " " << arrDni[i] << setw(22) << arrCantCitas[i];
        archReporte << fixed;
        archReporte << setprecision(4) << setw(32) << arrTiempo[i] <<
                setprecision(2) << setw(35)<< arrGasto[i] << endl;
    }
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(38) << " " << "CLINICA PSICOLOGICA TP." << endl;
    archReporte << setw(34) << " " << "RELACION DE GASTOS POR PACIENTE" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << setw(10) << "PACIENTE" << setw(30) << "CANTIDAD DE CITAS" << 
            setw(40) << "TIEMPO TOTAL EN CONSULTAS (hrs.)" << setw(20) << 
            "GASTO TOTAL" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
}

void imprimirReporte(int *arrDni, int *arrCantCitas, int nPacientes, double *arrTiempo, 
        double *arrGasto){
    ofstream archReporte("ReporteDeGastosPorPaciente.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO ReporteDeGastosPorPaciente.txt" <<
                endl;
        exit(1);
    }
    imprimirCabecera(archReporte);
    imprimirArreglos(archReporte, arrDni, arrCantCitas, nPacientes, arrTiempo, 
            arrGasto);
    imprimirLinea('=', TAMLINEA, archReporte);
    //llamada a funcion que imprime el resumen(total de citas, horas, recaudado)
    imprimirResumen(archReporte, arrCantCitas, arrTiempo, arrGasto, nPacientes);
    imprimirLinea('=', TAMLINEA, archReporte);
}

double calcularGasto(int codMedico, double tarifaA, double tarifaB, double tarifaC, 
        double tiempo){
    int ultimasCifras;
    double tarifa;
    ultimasCifras = codMedico % 100;
    //selectiva que verifica la terminacion para asignar la tarifa
    if(((ultimasCifras >= 0) and (ultimasCifras <= 34)) or 
            ((ultimasCifras >= 35) and (ultimasCifras <= 70))){
        if((ultimasCifras >= 0) and (ultimasCifras <= 34)){
            tarifa = tarifaA;
        }
        else{
            tarifa = tarifaB;
        }
    }
    else{
        tarifa = tarifaC;
    }
    return tarifa;
}

int comprobarRepetido(int *arrDni, int dniPaciente, int nPacientes){
    for(int i = 0; i < nPacientes; i++){
        if(arrDni[i] == dniPaciente){
            return i;
        }
    }
    return -1;
}

void asignarArreglos(int *arrDni, int *arrCantCitas, double *arrTiempo, 
        double *arrGasto, int &nPacientes, double tarifaA, double tarifaB, 
        double tarifaC, int dniPaciente, int codMedico, double tiempoTotal){
    int posicion;
    double tiempoTotalHoras;
    tiempoTotalHoras = tiempoTotal/3600.0;
    //llamada a funcion que verifica si es repetido, y devuelve su posicion
    posicion = comprobarRepetido(arrDni, dniPaciente, nPacientes);
    if(posicion >= 0){
        arrCantCitas[posicion] += 1;
        arrTiempo[posicion] += tiempoTotalHoras;
        //llamada a funcion que calcular el gasto total de la cita
        arrGasto[posicion] += calcularGasto(codMedico, tarifaA, tarifaB, tarifaC, 
                arrTiempo[posicion]);
    }
    else{
        arrDni[nPacientes] = dniPaciente;
        arrCantCitas[nPacientes] = 1;
        arrTiempo[nPacientes] = tiempoTotalHoras;
        arrGasto[nPacientes] = calcularGasto(codMedico, tarifaA, tarifaB, tarifaC, 
                arrTiempo[nPacientes]);
        nPacientes++;
    }
}

double calcularTiempo(int hhI, int minI, int ssI, int hhF, int minF, int ssF){
    double tiempoI, tiempoF;
    tiempoI = hhI * 3600 + minI * 60 + ssI;
    tiempoF = hhF * 3600 + minF * 60 + ssF;
    return tiempoF - tiempoI;
}

void leerCitas(double &tarifaA, double &tarifaB, double &tarifaC, int &nPacientes, 
        int *arrDni, int *arrCantCitas, double *arrTiempo, double *arrGasto){
    int dniPaciente, codMedico, dd, mm, yyyy, hhI, hhF, minI, minF, ssI, ssF;
    double tiempoTotal;
    char extra;
    ifstream archCitas("Citas.txt", ios::in);
    if(not archCitas.is_open()){
        cout << "ERROR: EL ARCHIVO CITAS.TXT NO PUDO ABRRISE" << endl;
        exit(1);
    }
    archCitas >> tarifaA >> tarifaB >> tarifaC;
    while(1){
        archCitas >> dniPaciente;
        if(archCitas.eof()) break;
        archCitas >> codMedico >> dd >> extra >> mm >> extra >> yyyy >> hhI >>
                extra >> minI >> extra >> ssI >> hhF >> extra >> minF >> extra 
                >> ssF;
        //llamada a funcion que calcula el tiempo total en segundos
        tiempoTotal = calcularTiempo(hhI, minI, ssI, hhF, minF, ssF);
        //llamada a funcion que asigna valores en los arreglos
        asignarArreglos(arrDni, arrCantCitas, arrTiempo, arrGasto, nPacientes, 
                tarifaA, tarifaB, tarifaC, dniPaciente, codMedico, tiempoTotal);
    }
}