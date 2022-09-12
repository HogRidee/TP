/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 9 de septiembre de 2022, 9:10
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * ESTE PROGRAMA CONTIENE LOS APUNTES DE LA LECTURA: "Programación Modular"
 */
int main(int argc, char** argv) {

    /*Diseño descendente: consiste en empezar por lo más general e ir avanzando
                          nivel a nivel hacia lo más particular.
     Programación Modular: consiste en dividir el problema original en diversos
                           subproblemas que se pueden resolver por separado, 
                           para después recomponer los resultados y obtener la 
                           solución.
     Implementación de la programación modular:
     Las unidades básicas para este fin se denominan "funciones". Se pueden 
     definir como un conjunto de instrucciones que realiza un proceso y brinda
     un resultado. Se declara como:
     <tipo de retorno>Nombre de la función (<Parámetros (tipos)>);
     Se implementa como:
     <tipo de retorno>Nombre de la función (<Parámetros (tipos)>){
        <instrucción>
        <instrucción>
        ...
        return expresión;
     }
     
     Biblioteca de funciones:
     Se puede trabajar modularmente de muchas formas, pero nos centraremos en 
     el concepto de "Reutilización de código". La idea es que en las bibliotecas
     de funciones se coloque un grupo de funciones que estén relacionadas de 
     alguna forma.
     
     Tipos de variables:
     Variables globales: es aquella que ha sido declarada fuera del ámbito de 
                         cualquier función. Dependiendo de la ubicación de su 
                         declaración, pueden ser utilizadas dentro del código de
                         las funciones del programa.
     Variables locales: son aquellas que se definen dentro de una función y se 
                        destruyen cuando esta termina. No pueden ser utilizadas 
                        por otra función.
     Variables estáticas: son aquellas que solo se pueden emplear en la función
                          que la declaró, pero a diferencia de las locales no se
                          destruyen cuando la función es nuevamente invocada.
                          Se declaran anteponiendo static a la declaración.
     Referencias: es una variable que ocupa el mismo espacio de memoria que otra.
     * 
     Parámetros de una función: la información que se les da a las funciones para
                                que realicen su trabajo se denominan parámetros.
     Parámetros por valor: pase lo que pase dentro de la función, el valor de la
                           variable que se use como parámetro no será alterado.
     Parámetros por referencia: al ser modificados en la función, modifican 
                                también a la variable empleada como parámetro.
     
     EN EL PDF SE OBSERVA UN EJEMPLO DEL USO DE LA PROGRAMACIÓN MODULAR*/
    
    return 0;
}
    
