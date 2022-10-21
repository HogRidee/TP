/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 18 de octubre de 2022, 17:37
 */

#include "Funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE LA PREGUNTA 2 DEL EX1 2022-2
 */
int main(int argc, char** argv) {
    
    int fechaI, fechaF;
    int arrFechas[MAXTIKTOKS], arrCantComentarios[MAXTIKTOKS]={},
            arrCantLikes[MAXTIKTOKS]={}, arrCantReproducciones[MAXTIKTOKS]={},
            arrCantSeguidoresPublicos[MAXTIKTOKS]={};
    int nTikToks = 0;
    int arrCod[MAXUSUARIOS], arrId[MAXUSUARIOS], nUsuarios = 0;
    double arrRatio[MAXTIKTOKS];
    bool arrViral[MAXTIKTOKS], arrPublico[MAXUSUARIOS];
    //llamada a funcion para leer el rango de fechas
    leerRangoFechas(fechaI, fechaF);
    //llamada a funcion para leer el archivo de TikToks
    leerTikToks(fechaI, fechaF, arrFechas, arrCantReproducciones, nTikToks);
    //llamada a funcion para leer el archivo de usuarios
    leerUsuarios(arrCod, arrId, arrPublico, nUsuarios);
    /*llamada a funcion que recorre el archivo de comentarios y rellena los
    arreglos*/
    procesarComentarios(arrFechas, arrCantComentarios, arrCantLikes, 
            arrCantSeguidoresPublicos, arrCod, arrId, arrPublico, nTikToks, 
            nUsuarios);
    //llamada a funcion que calcula la viralidad e inserta el ratio
    calcularViralidad(arrFechas, arrCantReproducciones, arrCantLikes, arrRatio,
            arrViral, nTikToks, arrCantComentarios);
    //llamada a funcion que ordena los arreglos en funcion de 2 criterios
    ordenarArreglos(arrFechas, arrCantComentarios, arrCantLikes,
            arrCantReproducciones, arrRatio, arrViral, arrCantSeguidoresPublicos,
            nTikToks);
    //llamada a funciones de impresion y declaracion del archivo de reporte
    ofstream archReporte("reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: reporte.txt" << endl;
        exit(1);
    }
    imprimirCabecera(archReporte, fechaI, fechaF);
    imprimirDetallado(archReporte, arrFechas, arrCantComentarios, arrCantLikes,
            arrCantReproducciones, arrRatio, arrViral, arrCantSeguidoresPublicos,
            nTikToks);
    imprimirResumen(archReporte, arrViral, nTikToks);
    
    return 0;
}

