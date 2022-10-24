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
    ifstream arch_musica("music_dataset.txt",ios::in);
    lectura_emision_reporte(arch_musica);
    return 0;
}
