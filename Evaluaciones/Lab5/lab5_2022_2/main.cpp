/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 8 de noviembre de 2022, 20:19
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE EL LAB 5 DEL 2022-2
 */
int main(int argc, char** argv) {

    int arrCodigo[MAXMIEMBROS], arrEscala[MAXMIEMBROS];
    double arrVCred[MAXMIEMBROS], arrCredMat[MAXMIEMBROS], arrPago[MAXMIEMBROS];
    char arrTipo[MAXMIEMBROS];
    char *arrNombreMiembro[MAXMIEMBROS], *arrNombreDistrito[MAXMIEMBROS],
            *arrEspecialidad[MAXMIEMBROS], *arrFacultad[MAXMIEMBROS];
    
    struct Docente arrDocentes[MAXMIEMBROS];
    
    int nMiembros = 0;
    int nMiembrosAlumnos = 0;
    int nMiembrosDocentes = 0;
    
    ifstream archMiembros("MiembrosDeTP.csv", ios::in);
    if(not archMiembros.is_open()){
        cout << "ERROR: MiembrosDeTP.csv" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    
    double ingresos, egresos, total;
    char tipo;
    
    while(true){
        archMiembros >> tipo;
        if(archMiembros.eof()) break;
        arrTipo[nMiembros] = tipo;
        archMiembros.get();
        //llamada funcion para leer el nombre del miembro en el formato pedido
        leerNombre(archMiembros, arrNombreMiembro, nMiembros);
        if(tipo == 'A'){
            //llamada a funcion para leer la linea del alumno y almacenarlo en
            //los arreglos respectivos
            leerAlumno(archMiembros, arrCodigo, arrNombreDistrito, 
                    arrEspecialidad, arrFacultad, arrEscala, arrVCred, arrCredMat,
                    nMiembrosAlumnos);
            arrPago[nMiembrosAlumnos] = arrVCred[nMiembrosAlumnos] * arrCredMat[nMiembrosAlumnos];
            nMiembrosAlumnos++;
        }
        else{
            //llamada a funcion para leer la linea del docente y almacenarlo
            //en el arreglo de estructuras
            leerDocente(archMiembros, arrDocentes, nMiembrosDocentes);
            nMiembrosDocentes++;
        }
        nMiembros++;
    }
    
    //llamadas a funciones para calcular ingresos y egresos
    ingresos = calcularIngresos(arrPago, arrTipo, nMiembrosAlumnos);
    egresos = calcularEgresos(arrDocentes, arrTipo, nMiembrosDocentes);
    total = ingresos - egresos;
    
    //llamada a funcion para ordenar los alumnos
    ordenarAlumnos(arrTipo, arrCodigo, arrNombreMiembro, 
            arrNombreDistrito, arrEspecialidad, arrFacultad, arrEscala, 
            arrVCred, arrCredMat, arrPago, nMiembrosAlumnos);
    
    //llamadas a funciones de impresion
    imprimirCabeceraAlumno(archReporte);
    imprimirAlumnos(archReporte, arrTipo, arrCodigo, arrNombreMiembro, 
            arrNombreDistrito, arrEspecialidad, arrFacultad, arrEscala, 
            arrVCred, arrCredMat, arrPago, nMiembrosAlumnos);
    imprimirResumenAlumno(archReporte, ingresos);
    imprimirCabeceraDocente(archReporte);
    imprimirDocentes(archReporte, arrDocentes, nMiembrosDocentes, arrTipo, 
            arrNombreMiembro);
    imprimirResumen(archReporte, egresos, total);
    
    return 0;
}

