/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"
#include "cadenas.hpp"

void imprimirLinea(char c, int tam, ofstream &archReporte){
    for(int i = 0; i <= tam; i++)
        archReporte.put(c);
    archReporte.put('\n');
}

void imprimirResumen(ofstream &archReporte, int nCaracteres,int nPalabras){
    archReporte << "Resumen: " << endl;
    archReporte << "Cantidad de Caracteres: " << nCaracteres << endl;
    archReporte << "Cantidad de Palabras: " << nPalabras << endl;
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(10) << " " << "Lista de canciones para procesar" << endl;
    //llamada a funcion para imprimir una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
}

void procesarCadenas(ofstream &archReporte, char *strNombre, char *strCancion){
    char strCancionCopia[MAXCAR];
    //utilizacion de funcion de copia de cadenas de la biblioteca cstring
    strcpy(strCancionCopia, strCancion);
    archReporte << "Tema: " << strCancion << " Autor: " << strNombre << endl;
    //llamada a funcion para convertir a minuscula y quitar guiones
    convertirMinuscula(strCancionCopia);
    archReporte << "Minuscula: " << strCancionCopia << endl;
    //utilizacion de funcion de copia de cadenas de la biblioteca cstring
    strcpy(strCancionCopia, strCancion);
    //llamada a funcion para camelizar todas las letras de la cadena
    camelizadoInverso(strCancionCopia);
    archReporte << "Camelizado Inverso: " << strCancionCopia << endl;
    //utilizacion de funcion de copia de cadenas de la biblioteca cstring
    strcpy(strCancionCopia, strCancion);
    //llamada a funcion para transformar la segunda palabra de la cadena en *
    mascaraSegundaPalabra(strCancionCopia);
    archReporte << "Mascara Segunda Palabra: " << strCancionCopia << endl;
    //utilizacion de funcion de copia de cadenas de la biblioteca cstring
    strcpy(strCancionCopia, strCancion);
    //llamada a funcion que hace que la cadena solo contenga consonantes
    soloConsonantes(strCancionCopia);
    archReporte << "Solo consonantes: " << strCancionCopia << endl << endl;
}

void procesarReporte(){
    int nCaracteres = 0, nPalabras = 0;
    char strNombre[MAXCAR];
    char strCancion[MAXCAR];
    ifstream archMusica("music_dataset.txt", ios::in);
    if(not archMusica.is_open()){
        cout << "ERROR: music_dataset" << endl;
        exit(1);
    }
    ofstream archReporte("reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: reporte.txt" << endl;
        exit(1);
    }
    //llamada a funcion que imprime la cabecera 
    imprimirCabecera(archReporte);
    while(true){
        archMusica >> strNombre;
        if(archMusica.eof())break;
        archMusica >> strCancion;
        archMusica.ignore(1000, '\n');
        //llamada a funcion que realiza el conteo
        contarStr(strCancion, nCaracteres, nPalabras);
        //llamada a funcion que realiza las tareas encomendadas
        procesarCadenas(archReporte, strNombre, strCancion);
    }
    imprimirLinea('=', TAMLINEA, archReporte);
    imprimirResumen(archReporte, nCaracteres, nPalabras);
}