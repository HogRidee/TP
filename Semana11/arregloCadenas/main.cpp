/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on October 24, 2022, 2:41 AM
 */

#include "auxiliares.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //ifstream arch_musica("music_dataset.txt",ios::in);
    //lectura_emision_reporte(arch_musica);
    char * arr_artistas[MAX_DATOS];
    char * arr_temas[MAX_DATOS];
    int arr_duraciones[MAX_DATOS];
    double arr_danceabilities[MAX_DATOS];
    int cantidad_datos = 0;
    leer_canciones_csv(arr_artistas, arr_temas, arr_duraciones, arr_danceabilities, cantidad_datos, "music_dataset.csv");
    //"Profesor ordenamiento no hemos visto!". Tranquilos, es sumamente sencillo y usa los mismos criterios que el ordenamiento que hemos visto para arreglos.
    ordenar_arreglos(arr_artistas, arr_temas, arr_duraciones, arr_danceabilities, cantidad_datos);
    imprime_datos(arr_artistas, arr_temas, arr_duraciones, arr_danceabilities, cantidad_datos, "reporte_musica.txt");
    return 0;
}
