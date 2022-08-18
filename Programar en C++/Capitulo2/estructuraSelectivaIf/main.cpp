/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 18 de agosto de 2022, 11:15
 */

#include <iostream>

//using namespace std;
//permite no utilizar el prefijo std:: para el código, using namespace también
using std::cout;
using std::cin;
using std::endl;

/*
 * Este programa muestra el funcionamiento de la estructura selectiva if
 */
int main(int argc, char** argv) {
    
    //declaramos e inicializamos las variables
    int numero1 = 0;
    int numero2 = 0;
    
    cout << "Ingrese el numero 1: ";
    cin  >> numero1;
    
    cout << "Ingrese el numero 2: ";
    cin  >> numero2;
    
    if( numero1 == numero2 ){
        cout << numero1 << " == " << numero2 << endl;
    }
    if( numero1 < numero2 ){
        cout << numero1 << " < " << numero2 << endl;
    }
    if( numero1 > numero2 ){
        cout << numero1 << " > " << numero2 << endl;
    }
    if( numero1 <= numero2 ){
        cout << numero1 << " <= " << numero2 << endl;
    }
    if( numero1 >= numero2 ){
        cout << numero1 << " >= " << numero2 << endl;
    }
    if( numero1 != numero2 ){
        cout << numero1 << " != " << numero2 << endl;
    }
    
    /*Conclusión del capítulo:
     Se aprendió muchas de las herramientas básicas importantes de C++.*/
    
    return 0;
}

