/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "auxiliares.hpp"

char pasar_caracter_minusculas(char car){
    return car + ((car>='A' and  car<='Z') ? 'a'-'A' : 0);
}

char pasar_caracter_mayusculas(char car){
    return car - ((car>='a' and car<='z') ? 'a'-'A' : 0);
}

void pasar_minusculas(char* str){
    for(int i=0; str[i]; i++)
    str[i] += ((str[i]>='A' and str[i]<='Z') ? 'a'-'A' : 0);
}

void imprime_linea(ofstream &arch ,char car , int num){
    for(int i=0; i<num ; i++) arch.put(car);
    arch<<endl;
}

void eliminar_guiones(char *cadena){
    char cadena_copia[60];
    int cant_car;
    for(cant_car=0;cadena[cant_car];cant_car++){
        cadena_copia[cant_car] = cadena[cant_car];
        if(cadena[cant_car]=='_') cadena_copia[cant_car]=' ';        
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void juntar_palabras(char *cadena){
    char cadena_copia[60];
    int cant_car = 0;
    for(int i=0;cadena[i];i++){
        if(not (cadena[i]==' ')) {
            cadena_copia[cant_car] = cadena[i]; 
            cant_car++;
        }
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void camelizar(char *cadena, bool inverso){
    char cadena_copia[60];
    int cant_car = 0;
    bool inicio_palabra = true;
    for(cant_car=0;cadena[cant_car];cant_car++){
        cadena_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car])*!inverso+pasar_caracter_mayusculas(cadena[cant_car])*inverso;
        if(inicio_palabra){
            if(inverso) cadena_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car]);
            else cadena_copia[cant_car] = pasar_caracter_mayusculas(cadena[cant_car]);
            inicio_palabra = false;
        }
        if(cadena[cant_car]==' ') inicio_palabra = true;
            
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void lectura_emision_reporte(ifstream &arch){
    char str_nombre_artista[60];
    char str_nombre_cancion[60];
    char str_nombre_cancion_aux[60];
    int duracion;
    ofstream arch_reporte("reporte.txt", ios::out);
    arch_reporte<<setw(60)<<"Lista de canciones para procesar"<<endl;
    imprime_linea(arch_reporte,'=',100);
    while(true){
        arch>>str_nombre_artista;
        if (arch.eof()) break;
        arch>>str_nombre_cancion>>duracion;
        arch.ignore(200,'\n');
        arch_reporte.precision(2);
        arch_reporte<<fixed;
//        cout<<setw(30)<<left<<str_nombre_artista
//                <<setw(40)<<left<<str_nombre_cancion
//                <<setw(10)<<left<<duracion/60000.0<<endl;
        eliminar_guiones(str_nombre_artista);
        eliminar_guiones(str_nombre_cancion);
        arch_reporte<<"Tema: "<<setw(40)<<left<<str_nombre_cancion
                <<"Author: "<<setw(40)<<left<<str_nombre_artista<<endl;
        pasar_minusculas(str_nombre_cancion);
        arch_reporte<<"Minuscula: "<<setw(40)<<left<<str_nombre_cancion<<endl;
        strcpy(str_nombre_cancion_aux,str_nombre_cancion);
        camelizar(str_nombre_cancion_aux, true);
        juntar_palabras(str_nombre_cancion_aux);
        arch_reporte<<"Camelizado Inverso: "<<setw(40)<<left<<str_nombre_cancion_aux<<endl;
        
    }
}