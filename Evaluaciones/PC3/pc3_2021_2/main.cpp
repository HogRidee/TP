/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de octubre de 2022, 13:37
 */

#include "funciones.hpp"

/*
 *ESTE PROGRAMA RESUELVE LA PC3 DEL 2021_2 
 */
int main(int argc, char** argv) {

    int nEscalas = 0;
    double arrCreditos[MAXESCALAS];
    char *arrEscala[MAXESCALAS];
    
    int nCursos = 0;
    double arrCredCurso[MAXCURSOS];
    char *arrCodCurso[MAXCURSOS];
    
    //llamada a funcion para leer el archivo escalas y almacenarlo en arreglos
    leerEscalas(arrEscala, arrCreditos, nEscalas);
    //llamada a funcion para leer el archivo de cursos y almacenarlo en arreglos
    leerCursos(arrCodCurso, arrCredCurso, nCursos);
    //llamada a funcion para procesar el reporte junto con el archivo matricula
    procesarMatricula(arrEscala, arrCreditos, nEscalas, arrCodCurso, 
            arrCredCurso, nCursos);
    
    return 0;
}

