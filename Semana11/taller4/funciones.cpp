/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 30 de octubre de 2022, 17:23
 */

#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0; i <= n; i++)
        arch.put(c);
    arch.put('\n');
}

void imprimirResumenGeneros(ofstream &archReporte, char **arrGeneros, int nDatos){
    //NO SE PUEDE REALIZAR CON LO QUE SABEMOS HASTA LA PC3
}

void imprimirCanciones(ofstream &archReporte, char **arrArtista, char **arrCancion, 
        int *arrDuracion, char **arrGeneros, double *arrDanceability, int nDatos){
    double duracion;
    char *genero;
    archReporte << "RESUMEN DE CANCIONES" << endl;
    //llamada a funcion para imprimir una linea de = 
    imprimirLinea('=', TAMLINEA, archReporte);
    for(int i = 0; i < nDatos; i++){
        archReporte << "Tema: " << arrCancion[i] << " Autor: " << arrArtista[i] 
                << endl;
        duracion = arrDuracion[i] / 60000.0;
        archReporte << fixed;
        archReporte << "Duracion: " << setw(4) << setprecision(2) << duracion 
                << " Danceability: " << setprecision(2) << arrDanceability[i] 
                << endl;
        //usamos strtok de la biblioteca cstring para imprimir la cadena separada
        genero = strtok(arrGeneros[i], "-");
        while(genero != NULL){
            archReporte << genero << endl;
            genero = strtok(NULL, "-");
        }
        //llamada a funcion para imprimir una linea de = 
        imprimirLinea('=', TAMLINEA, archReporte);
    }
}

void cambiarStr(char *&strI, char *&strJ){
    char *aux = strI;
    strI = strJ;
    strJ = aux;
}

void cambiarD(double *arr, int i, int j){
    double aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarI(int *arr, int i, int j){
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void ordenarArreglos(char **arrArtista, char **arrCancion, int *arrDuracion, 
        char **arrGeneros, double *arrDanceability, int nDatos){
    for(int i = 0; i < nDatos - 1; i++){
        for(int j = i + 1; j < nDatos; j++){
            //condicion para el ordenamiento
            //if(criterio1 or (criterio1* and criterio2)
            //criterio1* es el criterio 1 pero en igual
            if((strcmp(arrArtista[i], arrArtista[j]) > 0) or 
                    ((strcmp(arrArtista[i], arrArtista[j]) == 0) and 
                    (arrDanceability[i] > arrDanceability[j]))){
                cambiarI(arrDuracion, i, j);
                cambiarD(arrDanceability, i, j);
                cambiarStr(arrArtista[i], arrArtista[j]);
                cambiarStr(arrCancion[i], arrCancion[j]);
                cambiarStr(arrGeneros[i], arrGeneros[j]);
            }
        }
    }
}

void leerLinea(ifstream &archMusica, char *&artista, char *&cancion, int &duracion,
        char *&generos, double &danceability){
    char buffer[200]; //cadena auxiliar que nos ayudara a ver la longitud del str
    archMusica.getline(buffer, 200, ',');
    if(archMusica.eof())return;
    artista = new char[strlen(buffer) + 1]; //asignamos memoria al str
    //llamada a funcion de la biblioteca cstring que copia cadenas
    strcpy(artista, buffer);
    archMusica.getline(buffer, 200, ',');
    cancion = new char[strlen(buffer) + 1];
    //llamada a funcion de la biblioteca cstring que copia cadenas
    strcpy(cancion, buffer);
    archMusica >> duracion;
    archMusica.get(); //leemos la coma que quedo en el archivo
    archMusica.getline(buffer, 200, ',');
    generos = new char[strlen(buffer) + 1];
    //llamada a funcion de la biblioteca cstring que copia cadenas
    strcpy(generos, buffer);
    archMusica >> danceability;
    archMusica >> ws;
}

void leerArchivoMusica(char **arrArtista, char **arrCancion, int *arrDuracion, 
        char **arrGeneros, double *arrDanceability, int &nDatos, 
        const char *nombreArchivo){
    ifstream archMusica(nombreArchivo, ios::in);
    if(not archMusica.is_open()){
        cout << "ERROR: " << nombreArchivo << endl;
        exit(1);
    }
    //creamos variables y cadenas auxiliares que nos ayudarán con la lectura
    int duracion;
    double danceability;
    char *artista, *cancion, *generos; //necesitan asignarse con new
    while(true){
        if(archMusica.eof())break;
        //llamada a funcion que lee los datos por linea
        leerLinea(archMusica, artista, cancion, duracion, generos, danceability);
        arrArtista[nDatos] = artista;
        arrCancion[nDatos] = cancion;
        arrDuracion[nDatos] = duracion;
        arrGeneros[nDatos] = generos;
        arrDanceability[nDatos] = danceability;
        nDatos++;
    }
}