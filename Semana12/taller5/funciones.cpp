/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 4 de noviembre de 2022, 16:50
 */

#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0; i < n; i++)
        arch.put(c);
    arch.put('\n');
}

void imprimirReporte(struct Cancion *arrCanciones, int nCanciones, 
        int *arrFrecuencias, char **arrGeneros, int nGeneros){
    ofstream archReporte("reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: reporte.txt" << endl;
        exit(1);
    }
    archReporte << "Resumen de canciones" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << left << setw(40) << "Tema";
    archReporte << left << setw(30) << "Autor";
    archReporte << left << setw(20) << "Duracion";
    archReporte << left << setw(20) << "Danceability";
    archReporte << left << setw(20) << "Generos" << endl;
    for(int i = 0; i < nCanciones; i++){
        archReporte << setw(40) << arrCanciones[i].tema;
        archReporte << setw(30) << arrCanciones[i].autor;
        archReporte << fixed << setprecision(2);
        archReporte << setw(20) << arrCanciones[i].duracion;
        archReporte << setw(20) << arrCanciones[i].danceability;
        archReporte << setw(20) << arrCanciones[i].generos << endl;
    }
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "Resumen de generos" << endl;
    for(int i = 0; i < nGeneros; i++){
        archReporte << arrGeneros[i] << " : " << arrFrecuencias[i] << " ";
    }
    archReporte.put('\n');
}

int buscarGenero(char *buffer, char **arrGeneros, int nGeneros){
    for(int i = 0; i < nGeneros; i++){
        if(strcmp(buffer, arrGeneros[i]) == 0)
            return i;
    }
    return -1;
}

void contarGeneros(char *generos, int *arrFrecuencias, char **arrGeneros, 
        int &nGeneros){
    int i = 0, j = 0, posicion;
    char buffer[100];
    bool bandera = true;
    while(bandera){
        //una vez que el while(true) termine tendremos un genero en el buffer
        while(true){
            if(generos[i] == 0){
                buffer[j] = 0;
                bandera = false;
                i++;
                break;
            }
            if(generos[i] == '-'){
                buffer[j] = 0;
                j = 0;
                i++;
                break;
            }
            buffer[j] = generos[i];
            j++;
            i++;
        }
        //llamada a funcion que devuelve la posicion del genero (-1 no encontrado)
        posicion = buscarGenero(buffer, arrGeneros, nGeneros);
        if(posicion >= 0){
            arrFrecuencias[posicion]++;
        }
        else{
            arrGeneros[nGeneros] = new char[strlen(buffer) + 1];
            strcpy(arrGeneros[nGeneros], buffer);
            nGeneros++;
        }
    }
}

void leerLinea(ifstream &archMusica, struct Cancion &cancionLeida){
    double duracion, danceability;
    char buffer[100];
    
    //autor
    archMusica.getline(buffer, 100, ',');
    cancionLeida.autor = new char[strlen(buffer) + 1];
    strcpy(cancionLeida.autor, buffer);
    
    //tema
    archMusica.getline(buffer, 100, ',');
    cancionLeida.tema = new char[strlen(buffer) + 1];
    strcpy(cancionLeida.tema, buffer);
    
    //duracion
    archMusica >> duracion;
    archMusica.get();
    duracion = duracion / 60000;
    cancionLeida.duracion = duracion;
    
    //generos
    archMusica.getline(buffer, 100, ',');
    cancionLeida.generos = new char[strlen(buffer) + 1];
    strcpy(cancionLeida.generos, buffer);
    
    //danceability
    archMusica >> danceability;
    danceability = danceability * 100;
    cancionLeida.danceability = danceability;
    archMusica >> ws;
}

void leerCanciones(struct Cancion *arrCanciones, int &nCanciones, 
        int *arrFrecuencias, char **arrGeneros, int &nGeneros){
    ifstream archMusica("music_dataset_2.csv", ios::in);
    if(not archMusica.is_open()){
        cout << "ERROR: music_dataset_2.csv" << endl;
        exit(1);
    }
    struct Cancion cancionLeida;
    while(true){
        if(archMusica.eof()) break;
        //llamada a funcion para leer una linea del archivo
        leerLinea(archMusica, cancionLeida);
        //llamada a funcion que prepara el resumen de generos
        contarGeneros(cancionLeida.generos, arrFrecuencias, arrGeneros, nGeneros);
        arrCanciones[nCanciones] = cancionLeida;
        nCanciones++;
    }
}
