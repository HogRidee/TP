/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 30 de octubre de 2022, 17:18
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE EL TALLER 4 RESUELTO EL VIERNES 28
 */
int main(int argc, char** argv) {

    int arrDuracion[MAXDATOS], nDatos = 0;
    double arrDanceability[MAXDATOS];
    char *arrArtista[MAXDATOS], *arrCancion[MAXDATOS], *arrGeneros[MAXDATOS];
    
    ofstream archReporte("reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: reporte.txt" << endl;
        exit(1);
    }
   
    //llamada a funcion para leer el archivo csv
    //podemos mandar el nombre del archivo como cadena(es probable que venga en 
    //la pc3)
    leerArchivoMusica(arrArtista, arrCancion, arrDuracion, arrGeneros, 
            arrDanceability, nDatos, "music_dataset_2.csv");
    //llamada a funcion para ordenar los arreglos
    ordenarArreglos(arrArtista, arrCancion, arrDuracion, arrGeneros, 
            arrDanceability, nDatos);
    //llamada a funcion de impresion
    imprimirCanciones(archReporte, arrArtista, arrCancion, arrDuracion, 
            arrGeneros, arrDanceability, nDatos);
    //llamada a funcion que imprime el resumen de generos
    imprimirResumenGeneros(archReporte, arrGeneros, nDatos);
    
    return 0;
}

