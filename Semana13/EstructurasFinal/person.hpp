/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   person.hpp
 * Author: erasmog
 *
 * Created on November 4, 2022, 5:09 AM
 */

#ifndef PERSON_HPP
#define PERSON_HPP

struct Person{
    char* name;
    int id;
    struct Smartphone smartphones[5];
    int cantSmartphones = 0;
};

#endif /* PERSON_HPP */

