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
        arch_bin.write(reinterpret_cast<const char*>(&pokemon_read), sizeof(struct Pokemon));
    }
    arch_bin.close();
}
