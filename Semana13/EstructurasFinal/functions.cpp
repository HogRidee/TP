/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "person.hpp"

void printLine(char car, int n){
    for(int i=0; i<n; i++) cout<<car;
    cout<<endl;
}
char * assignName(const char *buffer){
    char *name;
    name = new char[strlen(buffer)+1];
    strcpy(name, buffer);
    return name;
}

void printSmartphoneInfo(Smartphone sp){
    cout<<"Modelo: "<<sp.name<<endl;
    cout<<"Storage: "<<sp.storage<<" GB"<<endl;
    cout<<"Color: "<<sp.color<<endl;
    cout<<"Price: "<<"$"<<sp.price<<endl;
}

void printPersonInfo(Person p){
    cout<<"Name: "<<p.name<<endl;
    cout<<"ID: "<<p.id<<" years"<<endl;
    for(int i = 0; i<p.cantSmartphones;i++)
        printSmartphoneInfo(p.smartphones[i]);
}

void read_line(ifstream &arch_sp, struct Smartphone &smartphone_read){
    char buffer[100];
    //Model
    arch_sp.getline(buffer,100,',');
    //cout<<buffer<<endl;
    smartphone_read.name = new char[strlen(buffer)+1];
    strcpy(smartphone_read.name,buffer);
    //cout<<model<<endl;
    //Storage
    arch_sp>>smartphone_read.storage;
    arch_sp.get();
    //cout<<storage<<endl;
    //Color
    arch_sp.getline(buffer,100,',');
    smartphone_read.color = new char[strlen(buffer)+1];
    strcpy(smartphone_read.color,buffer);
    //cout<<color<<endl;
    //price
    arch_sp>>smartphone_read.price;
    //cout<<price<<endl;
    arch_sp>>ws;
}

void readSmartphones(struct Smartphone *arr_smartphones, int & size_arr_smartphones){
    ifstream arch_sp("smartphones.csv",ios::in);
    size_arr_smartphones = 0;
    struct Smartphone smartphone_read;
    while(true){
        if(arch_sp.eof()) break;
        read_line(arch_sp, smartphone_read);
        arr_smartphones[size_arr_smartphones] = smartphone_read;
        //cout<<arr_smartphones[size_arr_smartphones].name<<endl;
        //break;
        //printSmartphoneInfo(arr_smartphones[size_arr_smartphones]);
        size_arr_smartphones++;
        
    }
}

void printSmartphonesInfo(struct Smartphone *arr_smartphones, int size_arr_smartphones){
    for(int i=0; i<size_arr_smartphones;i++){
        printSmartphoneInfo(arr_smartphones[i]);
        printLine('=',100);
    }
}

void read_line_people(ifstream & arch, struct Person &p){
    if(arch.fail()){
        arch.clear();
    }
    //code
    arch>>p.id;
    arch.get();
    //name
    char apellido[100];
    char nombre[100];
    arch.getline(apellido, 100, ',');
    arch.getline(nombre,100,',');
    p.name = new char[strlen(nombre) + strlen(apellido) + 4];
    strcpy(p.name, nombre);
    strcat(p.name, " - ");
    strcat(p.name, apellido); //strcat ya asigna el valor al char*
    //smarphones
    int cant_smartphones = 0;
    char buffer[100];
    arch>>cant_smartphones;
    for(int i=0;i<cant_smartphones;i++){
        if(i==cant_smartphones-1)
            arch.getline(buffer,100,'\n');
        else
            arch.getline(buffer,100,',');
        struct Smartphone sp;
        sp.price = 4499.99;
        sp.storage = 128;
        sp.color = assignName("Black");
        sp.name = assignName(buffer);
        p.smartphones[i] = sp;
    }
}

void readPeople(struct Person *arr_people, int &size_arr_people){
    ifstream arch_people("people.csv",ios::in);
    struct Person person_read;
    while(true){
        if(arch_people.eof()) break;
        read_line_people(arch_people, person_read);
        arr_people[size_arr_people] = person_read;
        size_arr_people++;
    }
}

void swapPeople(struct Person &p1,struct Person &p2){
    struct Person aux = p1;
    p1 = p2;
    p2 = aux;
}

void sortPeople(struct Person *arr_people, int size_arr_people){
    for(int i=0;i<size_arr_people;i++)
        for(int j=0;j<size_arr_people;j++){
            if(arr_people[i].id<arr_people[j].id){
                swapPeople(arr_people[i],arr_people[j]);
            }
        }
}

void printPeople(struct Person *arr_people, int size_arr_people){
    for(int i=0; i<size_arr_people; i++){
        cout<<"ID: "<<arr_people[i].id<<endl;
        cout<<"Name: "<<arr_people[i].name<<endl;
        for(int j=0; j<arr_people[i].cantSmartphones;j++)
            cout<<"Phone "<<j<<") "<<arr_people[i].smartphones[j].name;
    }
}