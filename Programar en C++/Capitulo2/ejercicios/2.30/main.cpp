/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 24 de agosto de 2022, 9:51
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Este programa resuelve los ejercicios 2.30
 */
int main(int argc, char** argv) {
    
    double pesoKg = 0.0;
    double alturaMetros = 0.0;
    
    cout << "Ingrese el peso en kilogramos: ";
    cin  >> pesoKg;
    cout << "Ingrese la altura en metros: ";
    cin  >> alturaMetros;
    
    cout << "Su indice de masa corporal (BMI) es: " << pesoKg / (alturaMetros *
            alturaMetros) << endl;
    cout << "VALORES DE BMI" << endl;
    cout << "Bajo peso:    menos de 18.5" << endl;
    cout << "Normal:       entre 18.5 y 24.9" << endl;
    cout << "Sobrepeso:    entre 25 y 29.9" << endl;
    cout << "Obeso:        entre 30 y mas" << endl;
    
    return 0;
}

