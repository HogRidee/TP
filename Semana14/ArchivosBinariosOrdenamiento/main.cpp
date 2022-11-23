/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on November 7, 2022, 6:36 AM
 */
#include "Pokemon.hpp"
#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    int entero = 5;
//    double real = 3.5;
//    char cadena[20] = "erasmo tiene sueno";
//    Pokemon pokemon;
//    pokemon.level = 1;
//    strcpy(pokemon.name,"Bulbasaur");
//    pokemon.types[0] = assignStr("Grass");
//    pokemon.types[1] = assignStr("Poison");
//    ofstream arch_bin("arch.bin", ios::binary|ios::out);
//    arch_bin.write(reinterpret_cast<const char*>(&entero),sizeof(int));
//    arch_bin.write(reinterpret_cast<const char*>(&real), sizeof(double));
//    arch_bin.write((char*)&cadena, sizeof(cadena));
//    arch_bin.write(reinterpret_cast<const char*>(&pokemon),sizeof(struct Pokemon));
//    arch_bin.close();
//    ifstream arch_bin_in("arch.bin", ios::binary|ios::in);
//    int a;
//    double b;
//    char c[20];
//    char *d = assignStr("1234567890222222");
//    Pokemon pokemon2;
//    arch_bin_in.read((char*)(&a),sizeof(int));
//    arch_bin_in.read((char*)(&b),sizeof(double));
//    arch_bin_in.read((char*)(&c),sizeof(c));
//    arch_bin_in.read(reinterpret_cast<char*>(&pokemon2),sizeof(struct Pokemon));
//    cout<<a+2<<endl;
//    cout<<b<<endl;
//    cout<<c<<endl;
//    cout<<strlen(d)<<endl;
//    cout<<sizeof(d)<<endl;
//    cout<<pokemon2.level<<endl;
//    cout<<pokemon2.name<<endl;
//    cout<<pokemon2.types[0]<<'-'<<pokemon2.types[1]<<endl;
//    struct Pokemon arr_pokemons[500];
    readPokemons("pokemon.csv", "pokemons.bin");
    //printPokemons("pokemons.bin");
    //printPokemonByID("pokemons.bin",46);
    sortPokemon("pokemons.bin");
    printPokemons("pokemons.bin");
//    ifstream arch_pokemons_bin("pokemons.bin",ios::in|ios::binary);
    //cout<<arch_pokemons_bin.tellg()<<endl;
    //cout<<sizeof(arch_pokemons_bin)<<endl;
    //cout<<sizeof(struct Pokemon)<<endl;
//    char *name;
//    int *codigos;
//    struct Pokemon pokemon;
//    struct Pokemon arr_pokemon[150];
//    cout<<sizeof(name)<<endl;
//    cout<<sizeof(int)<<endl;
//    cout<<sizeof(codigos)<<endl;
//    cout<<sizeof(pokemon)<<endl;
//    cout<<sizeof(pokemon.types[0])<<endl;
//    cout<<sizeof(arr_pokemon[0].types[0])<<endl;
//    cout<<sizeof(arr_pokemon)<<endl;
//    srand(time(0));
//    int v1;
//    for(int i=0;i<12;i++){
//        v1= rand()%150 + 1; 
//        cout<<v1<<endl;
//    }
    return 0;
}

