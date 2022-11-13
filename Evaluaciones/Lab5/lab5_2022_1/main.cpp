/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 4 de noviembre de 2022, 12:50
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE EL LAB5 DEL 2022-1
 */
int main(int argc, char** argv) {

    //declaracion de arreglos para el archivo Autores.csv
    char *arrCodigoAutor[MAXAUTORES], *arrNombreAutor[MAXAUTORES];
    int nAutores = 0;
    
    //declaracion de arreglos para el archivo Libro.csv
    //arreglos de libros
    int arrLibrosVendidos[MAXLIBROS];
    double arrPrecio[MAXLIBROS], arrTotalRecaudado[MAXLIBROS];
    char *arrCodigoLibro[MAXLIBROS], *arrNombreLibro[MAXLIBROS];
    int nLibros = 0;
    //arreglos auxiliares
    int arrCantidadLibrosVendidosAutor[MAXAUTORES];
    double arrRegalias[MAXAUTORES];
    char *arrCodigoAutorRegalias[MAXAUTORES], *arrNombreAutorRegalias[MAXAUTORES];
    int nAutoresRegalias = 0;
    
    //llaada a funcion para llenar arreglos del archivo autores
    leerArchivoAutores(arrCodigoAutor, arrNombreAutor, nAutores);
    //llamada a funcion para procesar el archivo libros
    procesarArchivoLibros(arrLibrosVendidos, arrCodigoLibro, arrNombreLibro, 
            arrTotalRecaudado, nLibros, arrCantidadLibrosVendidosAutor, 
            arrRegalias, arrCodigoAutorRegalias, arrNombreAutorRegalias, 
            nAutoresRegalias, arrCodigoAutor, arrNombreAutor, nAutores);
    
    return 0;
}

