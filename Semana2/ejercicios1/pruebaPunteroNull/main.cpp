 /* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 24 de agosto de 2022, 9:20
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // int noPuntero = nullptr; ocasiona error en el compialdor
    int *puntero;
    
    puntero = nullptr;
    
    if(puntero) { cout << "true";}
    else { cout << "false"; }
    
    
    return 0;
}

