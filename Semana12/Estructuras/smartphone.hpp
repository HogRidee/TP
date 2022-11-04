/* 
 * File:   smartphone.hpp
 * Author: u_eeggcc
 *
 * Created on 4 de noviembre de 2022, 07:37 AM
 */

#ifndef SMARTPHONE_HPP
#define SMARTPHONE_HPP

struct Smartphone{
    //Lista de propiedades
    char* model;
    int storage;
    char* color;
    double price;
};

struct Person{
    char* name;
    int age;
    Smartphone smartphone;
};

#endif /* SMARTPHONE_HPP */

