/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 4 de noviembre de 2022, 12:52
 */

#include "funciones.hpp"

void leerLibro(ifstream &archLibros, char **arrCodigoLibro, char **arrNombreLibro,
        double &precioLibro, int nLibros){
    char buffer[200];
    archLibros.getline(buffer, 200, ',');
    //utilizamos las funciones de copia y longitud de la biblioteca cstring
    arrCodigoLibro[nLibros] = new char[strlen(buffer) + 1];
    strcpy(arrCodigoLibro[nLibros], buffer);
    archLibros.getline(buffer, 200, ',');
    arrCodigoLibro[nLibros] = new char[strlen(buffer) + 1];
    strcpy(arrCodigoLibro[nLibros], buffer);
    archLibros >> precioLibro;
    archLibros.get();
}

void procesarArchivoLibros(int *arrLibrosVendidos, char **arrCodigoLibro, 
        char **arrNombreLibro, double *arrTotalRecaudado, int &nLibros, 
        int *arrCantidadLibrosVendidosAutor, double *arrRegalias, 
        char **arrCodigoAutorRegalias, char **arrNombreAutorRegalias, 
        int &nAutoresRegalias, char **arrCodigoAutor, char **arrNombreAutor, 
        int nAutores){
    double precioLibro;
    ifstream archLibros("Libros.csv", ios::in);
    if(not archLibros.is_open()){
        cout << "ERROR: Libros.csv" << endl;
        exit(1);
    }
    while(true){
        if(archLibros.eof()) break;
        leerLibro(archLibros, arrCodigoLibro, arrNombreLibro, precioLibro, nLibros);
        break; //PENDIENTE
    }                                
}

void leerArchivoAutores(char **arrCodigoAutor, char **arrNombreAutor, 
        int &nAutores){
    char buffer[100];
    ifstream archAutores("Autores.csv", ios::in);
    if(not archAutores.is_open()){
        cout << "ERROR: Autores.csv" << endl;
        exit(1);
    }
    while(true){
        if(archAutores.eof()) break;
        //utilizamos las funciones de copia y longitud de la biblioteca cstring
        archAutores.getline(buffer, 100, ',');
        arrCodigoAutor[nAutores] = new char[strlen(buffer) + 1];
        strcpy(arrCodigoAutor[nAutores], buffer);
        archAutores.getline(buffer, 100);
        arrNombreAutor[nAutores] = new char[strlen(buffer) + 1];
        strcpy(arrNombreAutor[nAutores], buffer);
        nAutores++;
    }
}
