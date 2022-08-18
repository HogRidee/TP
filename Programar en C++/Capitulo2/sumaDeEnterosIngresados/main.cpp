/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 18 de agosto de 2022, 9:41
 */

#include <iostream>

using namespace std;

/*
 * Este programa suma 2 enteros ingresados por el usuario.
 */
int main(int argc, char** argv) {

    int numero1;
    int numero2;
    int suma;
    //es recomendado inicializar (en 0, etc) para prevenir errores
    /*Buenas prácticas de programación: 
     "Declare sólo una variable en cada declaración y proporcione un comentario 
      que explique el propósito de cada una"
     "Seleccionar nombres descriptivos facilita la legibilidad del código"
     "Evitar usar abreviaciones también facilita la legibilidad"*/
    
    cout << "Escriba el primer entero: ";
    cin  >> numero1; 
    //lee el numero y lo coloca en la variable (similar a scanf)
    //gracias a using namespace no tenemos que usar: std::cin o std::cout
    /*utiliza el objeto flujo de entrada estándar cin (del espacio de nombres 
     std) y el operador de extracción de flujo (>>) para obtener un valor del 
     teclado*/
    
    cout << "Escriba el segundo entero: ";
    cin  >> numero2;
    
    suma = numero1 + numero2;
    
    /*Buena práctica de programación: 
     "Coloca espacios en ambos lados de un operador binario, esto hace que
      resalte y mejora la legibilidad del programa" */
    
    cout << "El resultado es: " << suma << endl;
    
    /*std::endl o endl -> se le conoce como manipulador de flujos (end of line).
     Imprime una nueva línea y después vacía el búfer de salida*/
    
    return 0;
}

