/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"
#include "Pokemon.hpp"

char * assignStr(const char *buffer){
    char *name;
    name = new char[strlen(buffer)+1];
    strcpy(name, buffer);
    return name;
}

void read_line_pokemon(ifstream &arch_pokemons,struct Pokemon &p){
    //number
    int number;
    arch_pokemons>>p.number;
    arch_pokemons.get();
    //name
    arch_pokemons.getline(p.name,50,',');
    //types
    char buffer[200];
    arch_pokemons.getline(buffer,200,',');
    p.types[0] = assignStr(buffer);
    arch_pokemons.getline(buffer,200,',');
    p.types[1] = assignStr(buffer);
    //to the \n
    arch_pokemons.getline(buffer, 200,'\n');
    arch_pokemons>>ws;
}

void readPokemons(const char *filename_in, const char *filename_out){
    ifstream arch_pokemons(filename_in,ios::in);
    ofstream arch_pokemons_bin(filename_out,ios::out|ios::binary);
    struct Pokemon pokemon_read;
    while(true){
        if(arch_pokemons.eof())break;
        read_line_pokemon(arch_pokemons,pokemon_read);
        arch_pokemons_bin.write((const char*)(&pokemon_read),sizeof(struct Pokemon));
    }
    arch_pokemons_bin.close();
}

void printPokemon(struct Pokemon pokemon){
    cout<<left<<setw(20)<<pokemon.name<<" has the type(s): "<<pokemon.types[0];
        if(!strcmp(pokemon.types[1],""))
            cout<<endl;
        else
            cout<<"-"<<pokemon.types[1]<<endl;
}

void printPokemons(const char *filename_in){
    ifstream arch_pokemons_bin(filename_in,ios::in|ios::binary);
    struct Pokemon pokemon;
    while(true){
        arch_pokemons_bin.read((char*)(&pokemon),sizeof(struct Pokemon));
        if(arch_pokemons_bin.eof())break;
        printPokemon(pokemon);
    }
}

void printPokemonByID(const char *filename_in, int id){
    cout<<filename_in<<endl;
    ifstream arch_pokemons_bin(filename_in,ios::in|ios::binary);
    struct Pokemon pokemon;
    arch_pokemons_bin.seekg((id-1)*sizeof(struct Pokemon), ios::beg);
    arch_pokemons_bin.read((char*)(&pokemon),sizeof(struct Pokemon));
    cout<<"Info of pokemon number : "<<id<<endl;
    printPokemon(pokemon);
}

void sortPokemon(const char *filename_in){
    //El archivo va a ser de lectura y escritura porque lo vamos a actualizar
    //Para eso usamos fstream
    fstream arch_pokemons_bin(filename_in,ios::in|ios::out|ios::binary);
    //Tamano del registro almacenado en el archivo binario
    int size = sizeof(struct Pokemon);
    //Nos ubicamos al final del archivo y contamos con tellg el tamano de bytes almacenados
    //dividimos entre el tamano de registro y obtenemos el numero de registros totales del archivo
    int cant = arch_pokemons_bin.seekg(0,ios::end).tellg()/size;
    //volvemos al inicio
    arch_pokemons_bin.seekg(0,ios::beg);
    struct Pokemon pokemon_i, pokemon_j;
    for(int i=0; i<cant-1;i++)
        for(int j=i+1; j<cant;j++){
            //leemos las 2 estructuras a comparar
            arch_pokemons_bin.seekg(i*size,ios::beg);
            arch_pokemons_bin.read((char*)(&pokemon_i),sizeof(struct Pokemon));
            arch_pokemons_bin.seekg(j*size,ios::beg);
            arch_pokemons_bin.read((char*)(&pokemon_j),sizeof(struct Pokemon));
            if((strcmp(pokemon_i.types[0],pokemon_j.types[0])>0) or
                    (strcmp(pokemon_i.types[0],pokemon_j.types[0])==0) and
                    (strcmp(pokemon_i.types[1],pokemon_j.types[1])>0)){
                //Hacemos el intercambio posicionandonos en los espacios i y j respectivamente
                arch_pokemons_bin.seekg(i*size,ios::beg);
                arch_pokemons_bin.write((const char*)(&pokemon_j),sizeof(struct Pokemon));
                arch_pokemons_bin.seekg(j*size,ios::beg);
                arch_pokemons_bin.write((const char*)(&pokemon_i),sizeof(struct Pokemon));
                //Flush para forzar la impresión de las direcciones rapidamente en el binary file
                arch_pokemons_bin.flush();
                
            }
        }
}