/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "functions.hpp"

char * assignStr(const char*buffer){
    char *str;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

void read_line_pokemon(ifstream & arch, struct Pokemon &p){
    //number
    arch>>p.number;
    arch.get();
    //nombre
    arch.getline(p.name,50,',');
    //types
    char buffer[200];
    arch.getline(buffer,200,',');
    p.types[0] = assignStr(buffer);
    arch.getline(buffer,200,','); // ""
    p.types[1] = assignStr(buffer);
    //pasar al final
    arch.getline(buffer,200,'\n');
    arch>>ws;
}

void readPokemons(const char *file_in,const char *file_out){
    ifstream arch_csv(file_in,ios::in);
    ofstream arch_bin(file_out, ios::out|ios::binary);
    struct Pokemon pokemon_read;
    
    while(true){
        if(arch_csv.eof()) break;
        read_line_pokemon(arch_csv,pokemon_read);
        //Insert to binary file
        arch_bin.write(reinterpret_cast<const char*>(&pokemon_read), sizeof(struct Pokemon));
        //Insert to an structure array
        //arr_pokemons[cant] = pokemon_read
    }
    arch_bin.close();
}

void printPokemon(struct Pokemon p){
    int number;
    char name[50];
    char *types[2];
    cout<<"Numero Pokemon : "<<p.number<<endl;
    cout<<"Nombre Pokemon : "<<p.name<<endl;
    cout<<"Tipos Pokemon : "<<p.types[0];
    if(!strcmp(p.types[1],"")){
        cout<<endl;
    }
    else{
        cout<<" y "<<p.types[1]<<endl;
    }
}

void printPokemons(const char *filename){
    ifstream arch_bin(filename,ios::in|ios::binary);
    struct Pokemon pokemon_read;
    while(true){
        if(arch_bin.eof()) break;
        arch_bin.read((char*)(&pokemon_read), sizeof(struct Pokemon));
        printPokemon(pokemon_read);
    }
    arch_bin.close();
}

void accessPokemon(const char *filename, int index){
    ifstream arch_bin(filename,ios::in|ios::binary);
    struct Pokemon pokemon_read;
    arch_bin.seekg((index-1)*(sizeof(struct Pokemon)), ios::beg);
    arch_bin.read((char*)(&pokemon_read), sizeof(struct Pokemon));
    printPokemon(pokemon_read);
}

void sortPokemons(const char* filename){
    fstream arch_bin(filename, ios::in|ios::out|ios::binary);
    int size_struct = sizeof(struct Pokemon);
    arch_bin.seekg(0, ios::end);
    int bytes = arch_bin.tellg();
    int cant_pokemon = bytes / size_struct;
    struct Pokemon pokemon_i, pokemon_j;
    for(int i = 0; i<cant_pokemon-1;i++){
        for(int j=i+1; j<cant_pokemon;j++){
            arch_bin.seekg(i*size_struct,ios::beg);
            arch_bin.read((char *)(&pokemon_i), size_struct);
            arch_bin.seekg(j*size_struct,ios::beg);
            arch_bin.read((char *)(&pokemon_j), size_struct);
            if(strcmp(pokemon_i.name,pokemon_j.name)>0){
                arch_bin.seekg(i*size_struct,ios::beg);
                arch_bin.write((const char*)(&pokemon_j), size_struct);
                arch_bin.seekg(j*size_struct,ios::beg);
                arch_bin.write((const char*)(&pokemon_i), size_struct);
                arch_bin.flush();
            }
        }
    }
    arch_bin.close();
}

void updatePokemons(const char* filename){
    //complete the second type with Normal type
    fstream arch_bin(filename, ios::in|ios::out|ios::binary);
    int size_struct = sizeof(struct Pokemon);
    arch_bin.seekg(0, ios::end);
    int bytes = arch_bin.tellg();
    int cant_pokemon = bytes / size_struct;
    struct Pokemon pokemon_read;
    for(int i = 0; i<cant_pokemon;i++){
        arch_bin.seekg(i*size_struct,ios::beg);//Importante
        arch_bin.read((char *)(&pokemon_read), size_struct);
        if(!strcmp(pokemon_read.types[1],"")==0){
            pokemon_read.types[1] = assignStr("Normal");
            arch_bin.seekg(i*size_struct,ios::beg);//Importante
            arch_bin.write((const char *)(&pokemon_read), size_struct);
        }
    }
}