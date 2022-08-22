/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de agosto de 2022, 12:11
 */

#include <iostream>

using namespace std;

/*
 * Este programa contiene los apuntes de la lectura: "Control del flujo de 
 * programas"
 */
int main(int argc, char** argv) {
    
    /*CONTROL DEL FLUJO DE PROGRAMAS
     Bloques:
     Son un conjunto de instrucciones sintácticamente equivalentes a una 
     instrucción sencilla. Se definen mediante un juego de llaves ({ y }).
     Toda instrucción que tenga influencia sobre otra lo hará en la misma forma
     si la instrucción influenciada fuese un bloque.
     
     if...else (estructuras de decisión):
     if(expresión) sentencia;
     if(expresión) sentencia1; else sentencia2;
     Expresión es cualquier expresión aritmética o lógica. Si la expresión da 
     un valor diferente de 0 se ejecuta la sentencia inmeadiata a esta, si es
     0 se ejecuta, si existe, la sentencia que sigue a la cláusula else.
     Ejemplo:
     if (a>b) cout <<"a es mayor" << endl;
     >
     Intrucción while, do, for:
     Ver clases anteriores (misma lógica).
     
     Instrucción break:
     Se utiliza sólo en bloques de instrucciones como while, for, do y switch.
     Da por terminada las iteraciones o el bloque.
     
     Instrucción continue:
     Se usa sólo en bloques iterativos. Da por terminado un ciclo de la
     iteración.
     while(numDat<MaxDat){ >
        cin >> dato;
        if(dato == -1) break;
        if(dato < 0) continue; >
        numDato++;
        suma += dato;
     }
     Aquí se descartan los valores negativos porque la orden continue salta
     las instrucciones que están debajo y empieza un nuevo ciclo.
     
     Instrucción switch:
     Si el valor de la constante coincide con una de las constantes, entonces
     se transfiere la ejecución del programa al lugar de la constante. Luego
     de ejecutar las instrucciones para un caso, se continuará ejecutando el
     siguiente caso a menos que al final del grupo de instrucciones coloquemos
     la cláusula break.*/
    
    return 0;
}

