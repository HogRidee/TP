/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de agosto de 2022, 12:08
 */

#include <iostream>
#include <iomanip>
#include "NumerosComplejos.hpp"

using namespace std;

/*
 * Este programa resuelve el primer laboratorio del ciclo 2021-2
 * Desarrollado ya no en C, sino en C++
 */
int main(int argc, char** argv) {
    
    //inicialización de variables
    int exponente = 0; //almacena el exponente en la potencia
    double numReal = 0.0; //almacena la parte real del numero imaginario
    double numImg = 0.0;  //almacena la parte imaginaria del numero imaginario
    double numRealTemporal = 0.0; //almacena la parte real del  segundo numero imaginario
    double numImgTemporal = 0.0; //almacena la parte imaginaria del segundo numero imaginario
    char i; //almacena el i ingresado para evitar errores de lectura
    char operacion; //almacena la operación que ejecutará el programa
    
    
    //leemos el primer número complejo
    cout << "Ingrese un numero complejo: ";
    cin  >> numReal >> numImg >> i;
    
    //asignamos la precisión para las impresiones de los reales
    cout << fixed;
    cout.precision(2);
    
    while(true){
        //leemos la operación y el siguiente número complejo
        cout << "Ingrese la operacion y el siguiente numero complejo: ";
        cin  >> operacion;
        //detenemos el ciclo si se ingresa una F
        if (operacion == 'F' or operacion == 'f') break;
        //verificamos la suma
        if (operacion == 'S' or operacion == 's'){
            cin >> numRealTemporal >> numImgTemporal >> i;
            sumarComplejos(numReal, numImg, numRealTemporal, numImgTemporal);
            cout << "Resultado: " << numReal << " + " << numImg << "i" << endl;
        }
        //verificamos la resta
        if (operacion == 'R' or operacion == 'r'){
            cin >> numRealTemporal >> numImgTemporal >> i;
            restarComplejos(numReal, numImg, numRealTemporal, numImgTemporal);
            cout << "Resultado: " << numReal << " + " << numImg << "i" << endl;
        }
        //verificamos la multiplicación
        if (operacion == 'M' or operacion == 'm'){
            cin >> numRealTemporal >> numImgTemporal >> i;
            multiplicarComplejos(numReal, numImg, numRealTemporal, 
                    numImgTemporal);
            cout << "Resultado: " << numReal << " + " << numImg << "i" << endl;
        }
        //verificamos la división
        if (operacion == 'D' or operacion == 'd'){
            cin >> numRealTemporal >> numImgTemporal >> i;
            dividirComplejos(numReal, numImg, numRealTemporal, numImgTemporal);
            cout << "Resultado: " << numReal << " + " << numImg << "i" << endl;
        }
        //verificamos la potencia
        if (operacion == 'P' or operacion == 'p'){
            cin >> exponente;
            potenciarComplejo(numReal, numImg, exponente);
            cout << "Resultado: " << numReal << " + " << numImg << "i" << endl;
        }
    }
    //imprimimos el resultado final
    cout << "El resultado final es " << numReal << " + " << numImg << "i" << endl;
    
    return 0;
}

/*ES RECOMENDABLE CREAR UNA FUNCIÓN AUXILIAR QUE IMPRIMA LOS RESULTADOS PARA 
 EVITAR IMPRESIONES DE LA FORMA: real + -imgi*/