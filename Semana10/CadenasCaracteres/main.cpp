
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
    ifstream arch_musica("music_dataset.txt",ios::in);
    ofstream arch_reporte("reporte.txt",ios::out);
    lectura_canciones(arch_musica, arch_reporte);
    lectura_canciones(arch_musica, arch_reporte);
    lectura_canciones(arch_musica, arch_reporte);
    return 0;
}

