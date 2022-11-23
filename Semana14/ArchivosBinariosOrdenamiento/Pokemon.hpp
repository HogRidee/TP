/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.hpp
 * Author: erasmog
 *
 * Created on November 11, 2022, 1:57 AM
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

struct Pokemon{
    char name[50];
    int number;
    char *types[2];
    int stats[7];
};

#endif /* POKEMON_HPP */

