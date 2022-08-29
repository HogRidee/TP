/* 
 * File  :  FuncionesAuxiliares.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 16:50
 */

#include <iostream>
#include <iomanip>
//#include "FuncionesAuxiliares.hpp"

using namespace std;

void imprimirResultado(double real, double imaginario){
    //adaptado para c++
    if(imaginario < 0){
        cout << endl << "Resultado: ";
        cout << fixed;
        cout << setprecision(2) << real << " - ";
        cout << setprecision(2) << imaginario * (-1) << endl;
    }
    else{
        cout << endl << "Resultado: ";
        cout << fixed;
        cout << setprecision(2) << real << " + ";
        cout << setprecision(2) << imaginario << endl;
    }
}

