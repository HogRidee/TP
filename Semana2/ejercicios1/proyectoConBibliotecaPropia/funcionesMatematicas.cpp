/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 7:34
 */

#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int numero){
    //inicializamos el numero que almacenará el factorial
    int f = 1;
    
    //estructura iterativa para calcular el factorial
    for (int i = numero; i > 0; i--){
        f *= i; //f = f * i
    }
    return f;
}