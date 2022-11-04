/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: u_eeggcc
 *
 * Created on 4 de noviembre de 2022, 07:02 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
void printLine(char ,int);
void printSmartphone(struct Smartphone);
void printPerson(struct Person);
char * assignString(const char *);
void read_line(ifstream &, struct Smartphone &);
void readSmartphones(struct Smartphone *, int &);
void printSmartphones(struct Smartphone *,int);

#endif /* FUNCIONES_HPP */

