/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 11 de noviembre de 2022, 07:08 AM
 */

#include "functions.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    int entero = 11;
//    double real = 10.5;
//    char cadena[20] = "tengo sueno";
//    struct Pokemon pokemon;
//    pokemon.number = 1;
//    strcpy(pokemon.name, "Bulbasaur");
//    pokemon.types[0] = assignStr("Grass");
//    pokemon.types[1] = assignStr("Poison");
//    ofstream arch_bin("arch_pokemon.bin",ios::out|ios::binary);
//    if(!arch_bin.is_open()){
//        cout<<"GG"<<endl;
//        exit(1);
//    }
//    arch_bin.write(reinterpret_cast<const char*>(&entero), sizeof(int));
//    arch_bin.write(reinterpret_cast<const char*>(&real), sizeof(double));
//    arch_bin.write((char*)&cadena, sizeof(cadena));
//    arch_bin.write(reinterpret_cast<const char*>(&pokemon), sizeof(struct Pokemon));
//    arch_bin.close();
//    
//    int entero1 ;
//    double real1;
//    char cadena1[20];
//    struct Pokemon pokemon1;
//    
//    ifstream arch_bin_in("arch_pokemon.bin",ios::in|ios::binary);
//    arch_bin_in.read((char*)(&entero1), sizeof(int));
//    arch_bin_in.read((char*)(&real1), sizeof(double));
//    arch_bin_in.read((char*)(&cadena1), sizeof(cadena1));
//    arch_bin_in.read((char*)(&pokemon1), sizeof(struct Pokemon));
//    
//    cout<<entero1<<endl;
//    cout<<real1<<endl;
//    cout<<cadena1<<endl;
//    cout<<pokemon1.name<<endl;
//    cout<<pokemon1.types[0]<<endl;
//    cout<<pokemon1.types[1]<<endl;
    
    readPokemons("pokemon.csv","pokemon.bin");
    //printPokemons("pokemon.bin");
    //accessPokemon("pokemon.bin", 5);
    //sorting
    sortPokemons("pokemon.bin");
    updatePokemons("pokemon.bin");
    printPokemons("pokemon.bin");
    return 0;
}

