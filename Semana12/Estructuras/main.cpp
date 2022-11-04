/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 4 de noviembre de 2022, 07:02 AM
 */
#include "smartphone.hpp"
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Smartphone smartphone;
    smartphone.model = assignString("iPhone 12");
    smartphone.color = assignString("Gray");
    smartphone.price = 3499.99;
    smartphone.storage = 128;
    printSmartphone(smartphone);
    
    printLine('=',100);
    struct Smartphone smartphone2;
    smartphone2.model = assignString("Galaxy S20 ultra");
    smartphone2.color = assignString("Black");
    smartphone2.price = 5499.99;
    smartphone2.storage = 512;
    printSmartphone(smartphone2);
    printLine('=',100);
    
    struct Person person;
    person.name = assignString("Guanilo");
    person.age = 21;
    person.smartphone = smartphone;
    printPerson(person);
    printLine('=',100);
    
    struct Smartphone *ptr;
    ptr = new struct Smartphone;
    ptr->model = assignString("Modelo");
    ptr->color = assignString("Red");
    ptr->price = 2499.99;
    ptr->storage = 10;
    printSmartphone(*ptr); //ptr es el puntero y *ptr es donde apunta
    printLine('=',100);
    
    struct Smartphone arr_smartphones[20];
    int size_arr_smartphones = 0;
    //Leer varios smartphones
    readSmartphones(arr_smartphones, size_arr_smartphones);
    printSmartphones(arr_smartphones,size_arr_smartphones);
    
    
    return 0;
}

