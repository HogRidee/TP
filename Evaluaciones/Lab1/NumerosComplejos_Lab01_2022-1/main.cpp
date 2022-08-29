/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 16:35
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.hpp"
#include "NumerosComplejos.hpp"

using namespace std;

/*
 * Programa que permite realizar operaciones aritméticas empleando números
 * complejos de la forma "a+bi".
 * Está ligeramente adaptado para el lenguaje C++ y no C
 */
int main(int argc, char** argv) {
    
    /*declaración de variables*/
    char opcion, operador;
    double a, b, c, d, real, imaginario;
    double numReal, numImag, denominador;
    int n = 0, guardarImaginario, guardarReal;
    char i;
    
    cout << endl << "Ingrese un numero complejo: ";
    cin  >> a >> b >> i;
    
    while(1){
        cout << endl << "Ingrese la operacion y el siguiente numero complejo: ";
        cin  >> opcion;
        if((opcion == 'F') || (opcion == 'f')) break;
        if((opcion == 'P') || (opcion == 'p')){
            cin >> n;
            //no necesitamos colocar & en parámetros por referencia (c++)
            potenciar(a, b, n, real, imaginario);
        }
        else{
            cin >> c >> d >> i;
            if((opcion == 'S') || (opcion == 's'))
                sumar(a, b, c, d, real, imaginario);
            else if((opcion == 'R') || (opcion == 'r'))
                restar(a, b, c, d, real, imaginario);
            else if((opcion == 'M') || (opcion == 'm'))
                multiplicar(a, b, c, d, real, imaginario);
            else if((opcion == 'D') || (opcion == 'd')){
                dividir(a, b, c, d, real, imaginario, denominador);
                
            }
        }
        a = real; b = imaginario;
        imprimirResultado(real, imaginario);
    }
        
    return 0;
}
