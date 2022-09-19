/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 2 de septiembre de 2022, 8:09
 */

#include "funciones.hpp"

using namespace std;

void imprimirLinea(char car, int cant, ofstream &dataOutput){
    
    for (int i = 1; i < cant; i++){
        //dataOutput << car;
        dataOutput.put(car); //es una función más rápida
    }
    dataOutput << endl;
}
