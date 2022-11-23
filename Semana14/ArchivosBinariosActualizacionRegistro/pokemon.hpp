/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   pokemon.hpp
 * Author: u_eeggcc
 *
 * Created on 11 de noviembre de 2022, 08:02 AM
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Move.hpp"


struct Pokemon{
    int number;
    char name[50];
    char *types[2];
    //struct Move movements[200]; //Estatico
    struct Move *movements;//Dinamica
    int stats[7];
    int cantMovements = 0;
};
#endif /* POKEMON_HPP */

