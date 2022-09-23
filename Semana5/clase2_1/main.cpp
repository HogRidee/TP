/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de septiembre de 2022, 12:04
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * ESTE PROGRAMA CONTIENE LOS APUNTES DE LA LECTURA: "Aplicaciones con arreglos
 *                                                    y punteros"
 */
int main(int argc, char** argv) {

    /*Dato estándar: define un solo elemento.
     Dato estructurado: permite definir variables en las que podemos almacenar
                        muchos valores.
     
     Arreglo: se define como una colección o conjunto de datos, que tiene como
              característica que todos los elementos son de un mismo tipo de 
              dato. La manera de diferenciar un elemento de otro se realiza 
              mediante índices, que a su vez indica la dimensión a la que
              pertenece(vector 1 dimensión, matriz 2 dimensiones, etc).
     
     Se declara como:
     
     Tipo identificador[Límite];
     
     Límite: indica la cantidad de datos que tendrá el arreglo.
     Tipo: indica el tipo de dato que tendrán los elementos del arreglo.
     
     Inicialización:
     Al momento de su declaración:
     int a[10]={3,5,1,7,0,2,6,9,8,4};
     Si se colocan menos elementos que la cantidad del arreglo, el resto se 
     inicializan en 0.
     El índice(a diferencia de los elementos)puede ser reemplazado por una 
     expresión cuyo valor está dentro del rango definido para los índices del
     arreglo.
     
     Punteros como arreglos:
     Un puntero tiene la misma naturaleza que un arreglo. Sin embargo, tienen
     diferencias:
        -Al puntero siempre se le almacena en 4bytes, mientras que el arreglo se
         define dependiendo del tipo de dato al que fue asignado.
        -Al puntero se le puede asignar cualquier dirección de memoria, mientras
         que la dirección de memoria del arreglo se mantiene constante.
     
     Arreglos como parámetros de funciones:
     Cuando se emplean así, la dirección de inicio del arreglo es enviado como
     parámetro y no todo el arreglo.
     
     En el pdf se observan ejemplos del uso de arreglos.
     */
    
    return 0;
}

