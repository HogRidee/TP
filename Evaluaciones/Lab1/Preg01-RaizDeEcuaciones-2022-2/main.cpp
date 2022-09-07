/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 5 de septiembre de 2022, 13:04
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "FuncionesAdicionales.hpp"

#define MAX_CICLOS 100
using namespace std;
/*
 * Programa para encontrar la raíz de una ecuación empleando el método de la
 * Posición falsa, ejercicio adaptado del libro de Schneider, G., Weingart, s...
 */
int main(int argc, char** argv) {
    int ciclos, raizEncontrada;
    double co5, co4, co3, co2, co1, co0; //coeficientes de la ecuación
    double x1, x2, x3, exactitud = 0.001;
    /*x1 y x2 intervalo que contiene la raiz, x3 nuevo punto*/
    double f1x, f2x, f3x;
    bool muchosCiclos, datosCorrectos;
    /*primero encontraremos un intervalo que contenga la raíz */
    datosCorrectos = false;
    muchosCiclos = false;
    cout.precision(6);
    cout << fixed;
    while(not datosCorrectos and not muchosCiclos){
        /*Para utilizar el programa, ingrese 2 puntos opuestos y los 5 
         * coeficientes de la función para hallar la raíz aproximada. Luego, 
         * introduzca la precisión que desea considerar para el cálculo.*/
        cout << "Ingresar dos puntos de inicio: " << endl;
        cin >> x1 >> x2;
        cout << "Ingresar los coeficientes: c5 al c0" << endl;
        cin >> co5 >> co4 >> co3 >> co2 >> co1 >> co0;
        f1x = calculaFuncion(x1,co5,co4,co3,co2,co1,co0);
        f2x = calculaFuncion(x2,co5,co4,co3,co2,co1,co0);
        if((fabs(x1)<exactitud) and (fabs(x2)<exactitud)){
            muchosCiclos = true;
        }
        else {
            if((f1x <= 0.0 and f2x >= 0.0) or
                    (f1x >= 0.0 and f2x <= 0.0)) {
                datosCorrectos = true;
            }
            else{
                cout << "Lo siento, los puntos dados no estan opuestos" << endl;
                cout << "Ingresar 0.0 para terminar (puntos de inicio)" << endl;
            }
        }
    }
    if (muchosCiclos) {
        cout << "Lo siento, el programa se concluye por una falla" << endl;
        cout << "para encontrar un intervalo inicial valido" << endl;
    }
    else { //solución del problema
        //La exactitud indicará cuando se haya llegado a un nivel deseado de
        //precisión
        cout << "Ingresar la exactitud deseada:" << endl;
        cin >> exactitud;
        raizEncontrada = 0;
        ciclos = 0;
        //Se utilizaran 100 ciclos, para cambiar este valor, modifique 
        //la constante: MAX_CICLOS
        while (not raizEncontrada and (ciclos<=MAX_CICLOS)){
            x3 = (x2 * f1x - x1 * f2x)/(f1x - f2x);
            f3x = calculaFuncion(x3,co5,co4,co3,co2,co1,co0);
            if (fabs(f3x)<exactitud) //hemos encontrado la raiz exacta
                raizEncontrada = 1;
            if (((f1x <= 0.0) and (f3x <= 0.0)) or
                    ((f1x >= 0.0) and (f3x >= 0.0))){
                x1 = x3;
                f1x = f3x;
            }
            else {
                x2 = x3;
                f2x = f3x;
            }
            ciclos += 1;
            if (fabs(f3x)<exactitud)
                raizEncontrada = 1;
        }
        cout << endl << "Numero de ciclos: " << ciclos << endl;
        if (raizEncontrada)
            cout << "La raiz es = " << x3 <<", con una exactitud de "
                    << exactitud << endl;
        else
            cout << "Lo sentimos, no pudimos encontrar la raiz en "
                    <<MAX_CICLOS << " iteraciones" << endl;
    }
    
    return 0;
}

