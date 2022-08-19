/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 19 de agosto de 2022, 12:09
 */

#include <iostream>

using namespace std;

/*
 * Este es un programa que resuelve los ejercicios 2.28
 */
int main(int argc, char** argv) {
    
    int numeroAEvaluar = 0; 
    int primerDigito = 0; 
    int segundoDigito = 0; 
    int tercerDigito = 0; 
    int cuartoDigito = 0; 
    int quintoDigito = 0; 
    
    cout << "Ingrese un numero de 5 digitos: ";
    cin  >> numeroAEvaluar;
    
    primerDigito  = numeroAEvaluar/10000; 
    segundoDigito = numeroAEvaluar/1000 % 10; 
    tercerDigito  = numeroAEvaluar/100 % 10; 
    cuartoDigito  = numeroAEvaluar/10 % 10 ; 
    quintoDigito  = numeroAEvaluar % 10; 
    
    cout << "Primer Digito : " << primerDigito << endl;
    cout << "Segundo Digito: " << segundoDigito << endl;
    cout << "Tercer Digito : " << tercerDigito << endl;
    cout << "Cuarto Digito : " << cuartoDigito << endl;
    cout << "Quinto Digito : " << quintoDigito << endl;
    
    return 0;
}

