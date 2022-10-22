#include "auxiliares.hpp"
#include "cadenas.hpp"


void  imprime_linea(ofstream &arch_reporte, char car, int cant){
    for(int i=0;i<cant;i++) arch_reporte.put(car);
    arch_reporte<<endl;
}

void str_cpy(char * str_to, char *str_source){
    int n_cant=0;
    while(true){
        str_to[n_cant] = str_source[n_cant];
        if(not str_source[n_cant]) break;
        //if(str_source[n_cant] == 0) break;
        n_cant++;
    }
}

void str_to_upper(char *str){
    for(int n_cant = 0; str[n_cant]; n_cant++){
        str[n_cant] -= ((str[n_cant]>='a' and str[n_cant]<='z') ? 'a' - 'A':0);
    }
}

int str_len(char *str){
    int n_cant;
    for(n_cant = 0;str[n_cant];n_cant++);
    return n_cant;
}

void lectura_canciones(ifstream &arch_musica, ofstream &arch_reporte){
    char str_nombre_artista[MAX_TAM_CADENA];
    char str_nombre_cancion[MAX_TAM_CADENA];
    int duracion;
    char str_explicito[MAX_TAM_CADENA];
    int fecha;
    double danceability, energy;
    char str_genero[MAX_TAM_CADENA];
    char str_genero_copiado[MAX_TAM_CADENA];
    char str_genero_copiado_cstring[MAX_TAM_CADENA];
    
    arch_musica>>str_nombre_artista;
    //for(int i=0;i<MAX_TAM_CADENA;i++) cout<<str_nombre_artista[i]<<endl;
    arch_musica>>str_nombre_cancion;
    arch_musica>>duracion;
    arch_musica>>str_explicito;
    arch_musica>>fecha>>danceability>>energy;
    arch_musica>>str_genero;
    
    imprime_linea(arch_reporte, '*', 80);
    arch_reporte<<"Reporte de Lectura"<<endl;
    arch_reporte<<"Nombre del Artista :"<<str_nombre_artista<<endl;
    arch_reporte<<"Tamaño Nombre Artista :"<<str_len(str_nombre_artista)<<endl;
    arch_reporte<<"Tamaño Nombre Artista CSTRING:"<<strlen(str_nombre_artista)<<endl;
    arch_reporte<<"Nombre de la Cancion :"<<str_nombre_cancion<<endl;
    str_to_upper(str_nombre_cancion);
    arch_reporte<<"Nombre de la Cancion Mayusculas:"<<str_nombre_cancion<<endl;
    arch_reporte<<"Duracion de la cancion :"<<duracion/60000.0<<endl;
    arch_reporte<<"Es explicito? :"<<str_explicito<<endl;
    arch_reporte<<"Fecha de lanzamiento :"<<fecha<<endl;
    arch_reporte<<"Danceability :"<<danceability*100<<'%'<<endl;
    arch_reporte<<"Energy :"<<energy*100<<'%'<<endl;
    arch_reporte<<"Genero:"<<str_genero<<endl;
    str_cpy(str_genero_copiado,str_genero);
    arch_reporte<<"Genero Copiado:"<<str_genero_copiado<<endl;
    strcpy(str_genero_copiado_cstring,str_genero);
    arch_reporte<<"Genero Copiado CSTRING:"<<str_genero_copiado_cstring<<endl;
    imprime_linea(arch_reporte, '*', 80);
}