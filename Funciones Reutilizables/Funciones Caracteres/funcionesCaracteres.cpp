/* 
 * File  :  funcionesCaracteres.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 8:12
 */

#include <iostream>
#include <iomanip>

using namespace std;

char cambiarMinuscMayusc(char minuscula){
    
    char mayusc = 0;
    
    //verificamos si minuscula es una minuscula y luego cambiamos
    mayusc = minuscula - ((minuscula >= 'a' and minuscula <= 'z') ? 'a' - 'A' : 0);
    
    return mayusc;
    
}