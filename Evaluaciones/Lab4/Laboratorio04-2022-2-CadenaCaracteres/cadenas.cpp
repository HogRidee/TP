/* 
 * File  :  cadenas.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 24 de octubre de 2022, 16:20
 */

#include "funciones.hpp"
#include "cadenas.hpp"

char convertirMayus(char c){
    if(c >= 'a' and c <= 'z'){
        c = c - ('a' - 'A');
        return c;
    }
    return c;
}

void transformarUsuario(char *strUsuario){
    int j = 0;
    bool mayus;
    char strCopia[MAXCAR];
    for(int i = 0; strUsuario[i]; i++){
        if(strUsuario[i] != '@'){
            if(mayus){
                mayus = false;
                strCopia[j] = convertirMayus(strUsuario[i]);
                j++;
            }
            else{
                strCopia[j] = strUsuario[i];
                j++;
            }
        }
        else{
            mayus = true;
        }
    }
    strCopia[j] = 0;
    //llamada a funcion que copia cadenas de la biblioteca cstring
    strcpy(strUsuario, strCopia);
}

void quitarEspacios(char *strCopia){
    int j = 0;
    bool mayus = true;
    char strCopia2[MAXCAR];
    for(int i = 0; strCopia[i]; i++){
        if(strCopia[i] != '_'){
            if(mayus){
                mayus = false;
                strCopia2[j] = convertirMayus(strCopia[i]);
                j++;
            }
            else{
                strCopia2[j] = strCopia[i];
                j++;
            }
        }
        else{
            mayus = true;
        }
    }
    strCopia2[j] = 0;
    //llamada a funcion que copia cadenas de la biblioteca cstring
    strcpy(strCopia, strCopia2);
}

void quitarGuiones(char *strComentario){
    for (int i = 0; strComentario[i]; i++){
        if(strComentario[i] == '_')
            strComentario[i] = ' ';
    }
}