/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 16 de agosto de 2022, 17:34
 */

#include <cstdlib>

using namespace std;

/*
 * Apuntes Semana 1 - Clase 1
 */
int main(int argc, char** argv) {
    
    /*LECTURA: Diferencias entre C y C++
     C es un subconjunto de C++, es decir que todo lo que aprendimos en C se 
     puede aplicar en C++, pero no necesariamente al revés.
     C++ fue creado aprox. 20 años después de C para adquirir nuevos conceptos
     como:
     
     Tipo de dato bool y operadores lógicos:
     
     Tipo de dato bool: en C se manejan las expresiones booleanas con valores
                        enteros (0 false, 1 true), en C++ se manejan de la misma
                        forma, pero para mejorar la legibilidad se ha definido 
                        el tipo "bool" y las constantes "false" (0) y "true" (1).
     
     Operadores lógicos: en C se usan ! (not), || (or), && (and); en C++ se usan
     ADEMÁS los operadores not, or, and.
      
     Instrucción #include:
     
     Para las bibliotecas de C cambia de .h a una c adelante.
     
     #include <stdio.h> -> #include <cstdio>
     #include <math.h>  -> #include <cmath>
     
     Bibliotecas propias de C++
     #include <iostream>
     #include <fstream>
     #include <iomanip>
      
     Espacio de nombres ("namespace"):
     A C++ cada año se le incorporan más funciones, esto ocasiona el "choque 
     entre elementos", que se produce cuando dos identificadores con el mismo
     nombre son incluidos en un proyecto desde dos bibliotecas de funciones
     distintas.
     Como solución se creó el "espacio de nombre" o "name space".
     Esto es el nombre que se le ha dado a un conjunto de funciones.
     Ej:
     #ifndef FUNCIONESMATEMATICAS_H      
     #define FUNCIONESMATEMATICAS_H
     namespace MiEspacio{
        int factorial(int);
        double convierteACelcius(double);
     }
     #endif
      
     La forma de invocarlas cambia, debemos indicar el espacio de nombres al que
     pertenecen.
     #include "FuncionesMatematicas.h" (escribirlo es necesario) 
     
     int MiEspacio::factorial(int n){
        ...
     }
     
     El operador "::" se denomina operador de ámbito.
     En main u otro módulo:
     fact = MiEspacio::factorial(5);
      
     Modos de simplificar el uso de funciones definidas en un espacio de nombres:
     
     Cuando se requiere usar una función de un espacio de nombres varias veces
     en un módulo.
     ...
     using MiEspacio::factorial; (se emplea la cláusula using)
      
     int main(...){
        ...
        fact = factorial(5); (ya no requiere el espacio de nombres)
        tempC = MiEspacio::convierteACelcius(tempF);
     }
     * 
     Cuando se requiere usar muchas funciones de un mismo espacio de nombres en
     un módulo.
     ...
     using namespace MiEspacio; (se emplea la cláusula using namespace)
     
     int main(...){
        ...
        fact = factorial(5); (ninguna de las funciones requerirán del namespace
        tempC = convierteACelcius(tempF);
     }
      
     Bibliotecas Estándar de C++:
     En el caso de las estándar como "iostream", "fstream", "iomanip", etc; todos
     los elementos definidos allí han sido declarados en el espacio de nombres
     "std", por lo que para usarlos requerirá emplear alguna de las formas 
     explicadas atrás.
     Sobre las bibliotecas del lenguaje C, sus elementos siguen igual.
     
     Referencias:
     Es una variable que ha sido definida de una manera espacial.
     Variables simples -> a y b ocupan espacios de memoria diferentes.
     int a = 3;
     int b = a;
     * 
     Referencias -> a y b ocupan el mismo espacio de memoria. 
                    Se dice que b es el alias de a.
     int a = 3;
     int &b = a; -> b es una referencia.
      
     Parámetros por referencia:
     El lenguaje C++ (a diferencia de C) si define parámetros por referencia.
     La forma cómo se especifica es simple, pero diferente al lenguaje C. Sin 
     embargo, es importante dominarlo (porque usar la forma en C sería más
     complejo).
      
     Invocación a una función con parámetros por referencia:
     Lenguaje C                                   Lenguaje C++
     int a, b = 5;                                int a, b = 5;
     a = f(&b);                                   a = f(b);
     Se simula, enviando la dirección de          Solo se coloca la variable.
     memoria de la variable.
     
     Error común en C++: si el parámetro se define por referencia, no puede 
     mandar un valor constante o una expresión: 
     a = f(3);   incorrecto, constante
     a = f(3*b); incorrecto, expresión
     
     Implementación a una función con parámetroa por referencia:
     Lenguaje C                                   Lenguaje C++
     int f(int *b){                               int f(int &b){
        ...                                         ...                                                   
        *b += 5;                                    b += 5;
        ...                                         ...    
     }                                             }
     El dato es recibido por un puntero,           Se coloca un & delante del
     y como tal se debe emplear.                   parámetro, luego solo le usa
                                                   como una variable común.
                                                   EL COMPILADOR OCULTA EÑ
                                                   AL DESARROLLADOR.
     
     Punteros: 
     Lenguaje C                                   Lenguaje C++
     NULL: se define como un valor 0 o una        nullptr: se define una
     direccióm nula. Requiere incluir la          dirección nula. Pertenece
     biblioteca stdlib.h donde se define.         al núcleo de C++ por lo que
                                                  no requiere definición.
     Es válido:                                   Es válido:
     int a, *pt;                                  int a, *pt;
     a = NULL; (se produce un warning)            p = nullptr;
     p = NULL;                                    No es válido:
                                                  a = nullptr;
     
     Asignación dinámica:
     Lenguaje C                                   Lenguaje C++
     malloc: es una función. Requiere una         new: es un operador. Pertenece
     operación "cast" según el tipo de puntero.   al núcleo de C++ por lo que no
     Es necesario calcular el espacio que se      requiere definición.
     desea asignar. Requiere incluir la           NO REQUIERE operaciones "cast"
     biblioteca stdio.h donde se define.          ni cálculos.
     
     int *pt;                                     int a, *pt;
     pt = (int*)malloc(sizeof(int));              pt = new int;
     pt = (int*)malloc(sizeof(int)*10);           pt = new int[10];
     
     Diferencias significativas que se verán más adelante(LP1):
     
     Sobrecarga de funciones: se puede definir dos o más funciones con el mismo
                              nombre y que hagan cosas diferentes. 
     Sobrecarga de operadores: se puede dar a un operador una función diferente
                               a la que usualmente tiene (ej: + para otro uso).
     Entrada y salida de datos: C usa funciones como scanf y printf, en C++ se
                                usan objetos y sobrecarga de operadores como
                                cin y cout, << y >>.
     Plantillas: permite definir una sola función o clse y que de manera 
                 automática el compilador cree varias funciones o clase en donde
                 cada una de ellas se adapte a un tipo de dato diferente, 
                 según se necesite.
     Clases y objetos: las clases son una evolución de las estructuras y son los
                       elementos básicos de la programación orientada a objetos 
                       (PPO). Clase corresponde a un "tipo dato" mientras que un
                       objeto corresponde a una "variable".
     La clase string: en C, las cadenas de caracteres se definen como arreglos
                      de caracteres y se manipulan con la biblioteca de funciones
                      string.h. En C++ se manejan igual, con "cstring", sin embargo,
                      también ha definido una biblioteca "string" 
                      (string != string). Aquí se define la "clase string", con
                      la que se pueden definir objetos de esta clase. 
                      Esta clase se puede considerar como una caja negra que 
                      que permite encapsular la manipulación de cadenas de char.
                      EN EL CICLO NO ESTÁ PERMITIDO EL USO DE ESTA BIBLIOTECA.  
     
     */ 
    
    return 0;
}

