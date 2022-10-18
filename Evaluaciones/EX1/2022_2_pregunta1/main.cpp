/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 17 de octubre de 2022, 17:02
 */
#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE LA PREGUNTA 1 DEL EX1 2022-2
 */
int main(int argc, char** argv) {

    //declaracion de archivos
    ifstream archTikToks("TikToks.txt", ios::in);
    if(not archTikToks.is_open()){
        cout << "ERROR: TikToks.txt" << endl;
        exit(1);
    }
    ifstream archUsuarios("usuarios.txt", ios::in);
    if(not archUsuarios.is_open()){
        cout << "ERROR: usuarios.txt" << endl;
        exit(1);
    }
    ifstream archComentarios("comentarios.txt", ios::in);
    if(not archComentarios.is_open()){
        cout << "ERROR: comentarios.txt" << endl;
        exit(1);
    }
    ifstream archPaises("paises.txt", ios::in);
    if(not archPaises.is_open()){
        cout << "ERROR: paises.txt" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    
    //llamada a funcion para procesar el reporte
    procesarReporte(archReporte, archTikToks, archComentarios, archPaises,
            archUsuarios);
    
    return 0;
}

