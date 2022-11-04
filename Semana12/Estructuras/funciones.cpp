/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <valarray>

#include "funciones.hpp"
#include "smartphone.hpp"

void printLine(char car,int n){
    for(int i=0;i<n;i++)cout<<car;
    cout<<endl;
}

void printPerson(struct Person p){
    cout<<"Name: "<<p.name<<endl;
    cout<<"Age: "<<p.age<<endl;
    printSmartphone(p.smartphone);
}
void printSmartphone(struct Smartphone sp){
    cout<<"Modelo: "<<sp.model<<endl;
    cout<<"Color: "<<sp.color<<endl;
    cout<<"Storage: "<<sp.storage<<" GB"<<endl;
    cout<<"Price: "<<"S/"<<sp.price<<endl;
}

char * assignString(const char *buffer){
    char *str;
    str = new char[strlen(buffer) +1];
    strcpy(str, buffer);
    return str;
}

void read_line(ifstream &arch, struct Smartphone &sp){
    char buffer[100];
    //Model
    arch.getline(buffer,100,',');
    sp.model = new char[strlen(buffer)+1];
    strcpy(sp.model,buffer);
    
    //Storage
    arch>>sp.storage;
    arch.get(); //coma de guanilo
    
    //Color
    arch.getline(buffer,100,',');
    sp.color = new char[strlen(buffer)+1];
    strcpy(sp.color,buffer);
    
    //Price
    arch>>sp.price;
    arch>>ws;
}

void readSmartphones(struct Smartphone *smartphones, int & size){
    ifstream arch_smartphones("smartphones.csv", ios::in);
    if(!arch_smartphones.is_open()){
        cout<<"gg"<<endl;
        exit(1);
    }
    struct Smartphone sp_read;
    while(true){
        if(arch_smartphones.eof()) break;
        read_line(arch_smartphones, sp_read);
        smartphones[size] = sp_read;
        size++;
    }
}

void printSmartphones(struct Smartphone *arr_smartphones,int size_arr_smartphones){
    for(int i=0;i<size_arr_smartphones;i++){
        printSmartphone(arr_smartphones[i]);
        printLine('#',100);
    }
        
}