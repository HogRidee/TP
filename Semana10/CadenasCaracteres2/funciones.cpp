/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "auxiliares.hpp"
#include "cadenas.hpp"

void str_cpy(char* str_to, const char *str_source){
    int i=0;
    while(1){
        str_to[i] = str_source[i];
        if(str_source[i]==0) break;
        i++;
    }
}

void str_to_upper(char* str){
    for(int i=0; str[i]; i++)
    str[i] -= ((str[i]>='a' and str[i]<='z') ? 'a'-'A' : 0);
}

int str_length(char *str){
    int n_caracteres;
    for (n_caracteres=0; str[n_caracteres]; n_caracteres++);
    return n_caracteres;
}

void imprime_linea(ofstream &arch ,char car , int num){
    for(int i=0; i<num ; i++) arch.put(car);
    arch<<endl;
}

void apertura_archivo(ifstream &arch){
    arch.open("music_dataset.txt",ios::in);
}

void apertura_archivo(ofstream &arch){
    arch.open("reporte.txt",ios::out);
}

void lectura_cadena_estatica(ifstream &arch, ofstream &reporte){
    char str_artista[MAX_TAM_CADENA];
    char str_cancion[MAX_TAM_CADENA];
    int duracion;
    char str_explicito[MAX_TAM_CADENA];
    int fecha;
    double danceability, energy;
    char str_genero[MAX_TAM_CADENA];
    char str_genero_copia[MAX_TAM_CADENA];

    arch>>str_artista>>str_cancion;
    arch>>duracion;
    arch>>str_explicito;
    arch>>fecha>>danceability>>energy;
    arch>>str_genero;
    imprime_linea(reporte,'=',80);
    reporte <<left<<setw(TAB)<< "Artista = "<<setw(10)<<str_artista<<endl;
    str_to_upper(str_artista);
    reporte <<left<<setw(TAB)<< "Artista Mayusculas = "<<setw(10)<<str_artista<<endl;
    reporte <<left<<setw(TAB)<< "Cancion = "<<setw(10)<<str_cancion<<endl;
    reporte <<left<<setw(TAB)<< "Cantidad Caracteres = "<<setw(10)<<str_length(str_cancion)<<endl;
    reporte <<left<<setw(TAB)<< "Cantidad Caracteres CSTRING= "<<setw(10)<<strlen(str_cancion)<<endl;
    reporte <<left<<setw(TAB)<< "Duracion = "<<fixed<<setprecision(2)<<duracion/60000.0<<" min"<<endl;
    reporte <<left<<setw(TAB)<< "Explicito? = "<<setw(10)<<str_explicito<<endl;
    reporte <<left<<setw(TAB)<< "Fecha de Lanzamiento = "<<setw(10)<<fecha<<endl;
    reporte <<left<<setw(TAB)<< "Danceability = "<<danceability*100<<'%'<<endl;
    reporte <<left<<setw(TAB)<< "Energy = "<<energy*100<<'%'<<endl;
    reporte <<left<<setw(TAB)<< "Genero = "<<setw(10)<<str_genero<<endl;
    str_cpy(str_genero_copia, str_genero);
    reporte <<left<<setw(TAB)<< "Genero Copiado = "<<setw(10)<<str_genero_copia<<endl;
    strcpy(str_genero_copia,str_genero);
    reporte <<left<<setw(TAB)<< "Genero Copiado CSTRING = "<<setw(10)<<str_genero_copia<<endl;
    imprime_linea(reporte,'=',80);
}
