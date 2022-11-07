/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: erasmog
 *
 * Created on November 3, 2022, 2:05 PM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "smartphone.hpp"
#include "person.hpp"
using namespace std;
char * assignName(const char *);
void printSmartphoneInfo(Smartphone);
void printPersonInfo(Person);
void read_line(ifstream &, struct Smartphone &);
void readSmartphones(struct Smartphone *, int &);
void printSmartphonesInfo(struct Smartphone *, int);
void read_line_people(ifstream &, struct Person &);
void swapPeople(struct Person &,struct Person &);
void readPeople(struct Person *, int &);
void sortPeople(struct Person *, int);
void printPeople(struct Person *, int);

#endif /* FUNCTIONS_HPP */

