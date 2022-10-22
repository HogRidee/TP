/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"
#include "cadenas.hpp"

void contarStr(char *str, int &nCaracteres, int &nPalabras){
    nPalabras++;
    for(int i = 0; str[i]; i++){
        if(str[i] == '_'){
            nPalabras++;
        }          
        else
            nCaracteres++;
    }
}

bool verificarConsonante(char str){
    bool validacionA, validacionE, validacionI, validacionO, validacionU;
    //verificamos si es minuscula
    if(str >= 'a' and str <= 'z'){
        validacionA = str != 'a';
        validacionE = str != 'e';
        validacionI = str != 'i';
        validacionO = str != 'o';
        validacionU = str != 'u';
        if(validacionA and validacionE and validacionI and validacionO and validacionU)
            return true;
    }
    if(str >= 'A' and str <= 'Z'){
        validacionA = str != 'A';
        validacionE = str != 'E';
        validacionI = str != 'I';
        validacionO = str != 'O';
        validacionU = str != 'U';
        if(validacionA and validacionE and validacionI and validacionO and validacionU)
            return true;
    }
    return false;
}

void soloConsonantes(char *strCancionCopia){
    int i = 0, j = 0;
    bool esConsonante;
    char strAuxiliar[MAXCAR];
    while(true){
        if(strCancionCopia[i] == 0)break;
        if(strCancionCopia[i] == '_'){
            strAuxiliar[j] = ' ';
            i++;
            j++;
        }
        esConsonante = verificarConsonante(strCancionCopia[i]);
        if(esConsonante){
            strAuxiliar[j] = strCancionCopia[i];
            i++;
            j++;
        }
        else{
            i++;
        }
        
    }
    //utilizamos la funcion de copia de la libreria cstring
    strcpy(strCancionCopia, strAuxiliar);
}

void mascaraSegundaPalabra(char *strCancionCopia){
    int i = 0, j = 0;
    char cadena[MAXCAR];
    bool bandera = true;  //indica si debemos copiar a la segunda cadena
    bool bandera2 = true; //indica si no hemos colocado la mascara en la 2da palabra
    while(true){
        //verificamos si es minuscula
        if(strCancionCopia[i] >= 'a' and strCancionCopia[i] <= 'z'){
            //si es minuscula cambiamos a mayuscula
            strCancionCopia[i] = strCancionCopia[i] - ('a'- 'A');
        }
        //verificamos que sea la segunda palabra
        if(strCancionCopia[i] == '_' and bandera2){
            //colocamos las banderas en false y llenamos el espacio con un *
            bandera = false;
            bandera2 = false;
            cadena[j] = '*';
            i++;
            j++;
        }
        //verificamos que la palabra que sigue se debe imprimir
        if(strCancionCopia[i] == '_' and not bandera2){
            bandera = true;
            i++;
        }
        //en caso de que mi bandera sea verdadera copiamos el caracter y aumentamos j
        if(bandera){
            cadena[j] = strCancionCopia[i];
            j++;
        }
        //verificamos si se termino la cadena principal e aumen
        if(strCancionCopia[i] == 0)break;
        //aumentamos i, si lo aumentamos antes podemos perder el caracter \0
        i++;
        
    }
    //utilizamos la funcion de copia de la libreria cstring
    strcpy(strCancionCopia, cadena);
}

void camelizadoInverso(char *strCancionCopia){
    int k = 0, j = 0;
    char strCadena[MAXCAR];
    bool validacion;
    for(int i = 0; strCancionCopia[i]; i++){
        //verificamos si es mayuscula
        validacion = strCancionCopia[i] >= 'A' and strCancionCopia[i] <= 'Z';
        if(validacion){
            strCancionCopia[i] = strCancionCopia[i] + ('a'- 'A');
        }
        else{
            //verificamos si es minuscula
            if(strCancionCopia[i] >= 'a' and strCancionCopia[i] <= 'z'){
                strCancionCopia[i] = strCancionCopia[i] - ('a'- 'A');
            }
        }
    }
    while(true){    
        if(strCancionCopia[j] == '_'){
            j++;
        }
        strCadena[k] = strCancionCopia[j];
        if(not strCancionCopia[j])break;
        j++;
        k++;
    }
    strcpy(strCancionCopia, strCadena);
}

void convertirMinuscula(char *strCancion){
    for(int i = 0; strCancion[i]; i++){
        if(strCancion[i] == '_'){
            strCancion[i] = ' ';
        }
        if(strCancion[i] >= 'A' and strCancion[i] <= 'Z'){
            strCancion[i] = strCancion[i] + ('a'- 'A');
        }
    }
}