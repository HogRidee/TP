/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 3 de noviembre de 2022, 14:49
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE LA PC3 DEL 2022_2
 */
int main(int argc, char** argv) {

    //declaracion de arreglos para el reporte
    int arrFecha[MAXCOMENTARIOS], arrCantidadLikes[MAXCOMENTARIOS];
    char *arrNombreUsuario[MAXCOMENTARIOS], *arrNombrePais[MAXCOMENTARIOS], 
            *arrComentario[MAXCOMENTARIOS];
    int nComentarios = 0;
    
    //declaracion de arreglos auxiliares
    int arrCodigoPais[MAXPAISES], arrCodigoPaisUsuario[MAXUSUARIOS], 
            arrId[MAXUSUARIOS];
    char *arrPais[MAXPAISES], *arrUsuario[MAXUSUARIOS];
    int nPaises = 0;
    int nUsuarios = 0;
    
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    
    //llamada a funcion para leer el archivo paises y llenar los arreglos
    leerArchivoPaises(arrCodigoPais, arrPais, nPaises);
    //llamada a funcion para leer el archivo usuarios y llenar los arreglos
    leerArchivoUsuarios(arrCodigoPaisUsuario, arrId, arrUsuario, nUsuarios);
    //llamada a funcion para procesar el reporte
    procesarArchivoComentarios(arrCodigoPais, arrPais, nPaises, arrCodigoPaisUsuario, arrId,
            arrUsuario, nUsuarios, arrFecha, arrCantidadLikes, arrNombreUsuario,
            arrNombrePais, arrComentario, nComentarios);
    //llamada a funcion para ordenar los arreglos (pais, usuario, fecha)
    ordenarArreglos(arrFecha, arrCantidadLikes, arrNombreUsuario,
            arrNombrePais, arrComentario, nComentarios);
    //llamadas a funciones de impresion
    imprimirCabecera(archReporte);
    imprimirDetallado(archReporte, arrFecha, arrCantidadLikes, arrNombreUsuario,
            arrNombrePais, arrComentario, nComentarios);
    imprimirResumen(archReporte, nComentarios, arrCantidadLikes, nUsuarios);
    
    return 0;
}

