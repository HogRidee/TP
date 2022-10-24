/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on October 19, 2022, 2:18 PM
 */

#include "auxiliares.hpp"
#include "cadenas.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch_musica;
    ofstream arch_reporte;
    apertura_archivo(arch_musica);
    apertura_archivo(arch_reporte);
    lectura_cadena_estatica(arch_musica, arch_reporte);
    lectura_cadena_estatica(arch_musica, arch_reporte);
    lectura_cadena_estatica(arch_musica, arch_reporte);
    lectura_cadena_estatica(arch_musica, arch_reporte);
    return 0;
}

