/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de agosto de 2022, 7:22
 */

#include <iostream>

using namespace std;

/*
 * Este programa contiene los apuntes de la presentación: "Conceptos básicos
 * en la elaboración de un programa" (parte1)
 */
int main(int argc, char** argv) {
    
    /*3.2 ¿Qué es un identificador?
     Reglas de formación inválidas: ñ, Ñ, empezar con un dígito, símbolos (a
                                    excepción de _.
     Hay diferencias en el uso de minúsculas y mayúsculas.
     
     3.3 Tipos de datos:
     Tipo               Tamaño (bits)
     char                   8
     unsigned char          8
     short / short int     16
     unsigned short        16
     int                   32
     unsigned int          32
     long long             64
     float                 32
     double                64
     bool                   8
     
     3.4 Expresiones:
     Conjunto de valores constantes, variables, constantes y funciones unidas
     por un operador.
      
     3.5 Operadores: 
     +, -, *, /, %
      
     3.6 Operador condicional: 
     variable = expresión1 ? expresión verdadera: expresión falsa
     a = b>5 ? c*3 : c*2;
     
     3.6 Precedencia de los operadores:
     ()
     !, not, ++, etc
     *, /, %
     +, -
     <, >, etc
     ==, !=
     &&, and
     ||, or
     ?, :
     =, +=, etc
     
     3.7 Variables puntero: 
     Variables cuyos valores son direcciones de memoria.
     (& -> operador de dirección)
     
     3.7.1 Asignación de valores a punteros: 
     Estática           Dinámica        Nula
     int contador = 7;  int *ptr;       int *ptr = nullptr;
     int *ptr;          ptr = new int;
     ptr = &contador
     
     3.7.2 Indirección o desreferencia:
     int contador = 7;
     int *ptr;
     ptr = contador;
     *ptr = 25;
     Esto cambia el valor de contador a 25, ptr sigue apuntando a contador.
     
     */
    
    return 0;
}

