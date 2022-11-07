/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on November 3, 2022, 1:32 PM
 */
#include "smartphone.hpp"
#include "person.hpp"
#include "functions.hpp"
#include "person.hpp"


/*
 * 
 */

int main(int argc, char** argv) {
    //User defined DATATYPES
    struct Smartphone arr_smartphones[10];
//    int size_arr_smartphones;
//    Smartphone smartphone;
//    smartphone.name = assignName("Samsung Galaxy S21 Ultra");
//    smartphone.storage = 128;
//    smartphone.color = assignName("purple");
//    smartphone.price = 4499.99;
//    
//    //printSmartphoneInfo(smartphone);
//    
//    Person person;
//    person.name = assignName("Erasmo");
//    person.age = 32;
//    person.smartphone = smartphone;
//    person.smartphone.storage = 256;
//    
//    printPersonInfo(person);
//    
//    
//    //arr_smartphones[0] = smartphone;
//    
//    //readSmartphones(arr_smartphones, size_arr_smartphones);
//    //printSmartphoneInfo(arr_smartphones[0]);
//    //cout<<arr_smartphones[0].color<<endl;
//    //printSmartphonesInfo(arr_smartphones, size_arr_smartphones);
//    
//    struct Smartphone *ptr;
//    ptr = new struct Smartphone;
//    ptr->price = 3.5;
//    ptr = &smartphone;
//    cout<<ptr->price<<endl;
//    printSmartphoneInfo(*ptr);
    struct Person arr_people[10];
    int size_arr_people = 0;
    readPeople(arr_people, size_arr_people);
    sortPeople(arr_people, size_arr_people);
    printPeople(arr_people, size_arr_people);
    return 0;
}

