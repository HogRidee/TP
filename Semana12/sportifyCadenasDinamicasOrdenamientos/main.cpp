
/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 21 de octubre de 2022, 07:01 AM
 */
#include "auxiliares.hpp"
#include "cadenas.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Solo para este ejercicio no validamos por que es una prueba
    //ifstream arch_musica("music_dataset_2.txt",ios::in);
    //ofstream arch_reporte("reporte.txt",ios::out);
    //lectura_canciones(arch_musica, arch_reporte);
    //lectura_canciones(arch_musica, arch_reporte);
    //lectura_canciones(arch_musica, arch_reporte);
    //lectura_impresion_reporte(arch_musica,arch_reporte);
    char *arr_nombre_artistas[MAX_DATOS];
    char *arr_nombre_temas[MAX_DATOS];
    int arr_duraciones[MAX_DATOS];
    double arr_danceabilities[MAX_DATOS];
    int cant_datos = 0;
    lectura_arch_canciones_csv(arr_nombre_artistas,
                              arr_nombre_temas,
                              arr_duraciones,
                              arr_danceabilities,
                              cant_datos,
                              "music_dataset_3.csv");
    
    procesar_arreglos_csv(arr_nombre_artistas,
                              arr_nombre_temas,
                              arr_duraciones,
                              arr_danceabilities,
                              cant_datos);
    
    emtir_reporte(arr_nombre_artistas,
                  arr_nombre_temas,
                  arr_duraciones,
                  arr_danceabilities,
                  cant_datos);
    return 0;
}

