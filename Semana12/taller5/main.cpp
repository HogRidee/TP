/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 4 de noviembre de 2022, 16:48
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE EL TALLER 5 PARA EL LAB5
 */

int main(int argc, char** argv) {
    
    //probamos si podemos leer y escribir con la estructura
    //PRUEBA EXITOSA
//    struct Cancion pruebaCancion;
//    char buffer[100];
//    
//    cout << "Ingrese el nombre del artista, el tema, la duracion, los generos "
//            "y la danceability" << endl;
//    
//    cin >> buffer;
//    pruebaCancion.autor = new char[strlen(buffer) + 1];
//    strcpy(pruebaCancion.autor, buffer);
//    
//    cin >> buffer;
//    pruebaCancion.tema = new char[strlen(buffer) + 1];
//    strcpy(pruebaCancion.tema, buffer);
//    
//    cin >> pruebaCancion.duracion;
//    
//    cin >> buffer;
//    pruebaCancion.generos = new char[strlen(buffer) + 1];
//    strcpy(pruebaCancion.generos, buffer);
//    
//    cin >> pruebaCancion.danceability;
//    
//    cout << "Autor: " << pruebaCancion.autor << endl;
//    cout << "Tema: " << pruebaCancion.tema << endl;
//    cout << "Duracion: " << pruebaCancion.duracion << endl;
//    cout << "Generos: " << pruebaCancion.generos << endl;
//    cout << "Danceability: " << pruebaCancion.danceability << endl;
    
    struct Cancion arrCanciones[MAXCANCIONES];
    int nCanciones = 0;
    
    int frecuenciaGeneros[MAXGENEROS]={};
    char *arrGeneros[MAXGENEROS];
    int nGeneros = 0;
    
    //llamada a funcion para leer el archivo music dataset, almacenarlo en
    //una estructura y almacenarla frecuencia de generos
    leerCanciones(arrCanciones, nCanciones, frecuenciaGeneros, arrGeneros, 
            nGeneros);
    //llamada a funcion para emitir el reporte
    imprimirReporte(arrCanciones, nCanciones, frecuenciaGeneros, arrGeneros, 
            nGeneros);
    
    return 0;
}

