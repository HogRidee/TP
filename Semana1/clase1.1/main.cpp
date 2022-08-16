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
 * Creado el 16 de agosto de 2022, 17:12
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    /* Memoria del Computador:
     Principal : es donde se coloca el programa que se utiliza, es volatil
     Secundaria: permite almacenar permanentemente la informacion, para 
                 procesarla se debe colocar en la memoria principal */
    
    /* Como se almacena la informacion en el computador:
     1 bit  -> unidad mas pequena de almacenamiento, puede tener valor 1 o 0
     1 byte -> unidad de informacion de 8 bits, el mas significativo esta en el 
               lado izquierdo. Cada bit toma el valor de una potencia de 0, en 
               orden del 0 al 7, la suma es 255 por lo tanto el byte puede 
               manejar 256 estados (del 0 al 255) */
    
    /* Representacion de diversos tipos de informacion:
     
     Numeros enteros: 1 byte puede almacenar numeros del 0 al 255, para numeros 
                      mayores se forman grupos de bytes (2 bytes -> 0 a 65 535).
                      Suma de bits : 1 + 1 = 0, se acarrea 1
                      Suma de bytes: 
                      1111 1111 +
                      0000 0001
                      ----------
                      0000 0000, se acarrea 1 para el siguiente byte, si no existe
                                 se pierde
     Numeros negativos: se utiliza el metodo de Complemento a 2 (complemento + 1).
     
     Numeros reales: R = m x b^e . En C se usan 4 bytes (32 bits); 1 para el signo,
                     8 para el exponente (normalizar sumando 127) y 23 para la 
                     mantisa (en complemento a 2, sin la parte entera).
     
     Almacenamiento Invertido - "back words": el computador almacena los numeros
                                              invertidos (a nivel de bytes).
        00000000 00000000 00000010 11101101, (749) se almacena como
        11101101 00000010 00000000 00000000  (947)
      
     Caracteres: la tabla ASCII almacena 256 caracteres o 1 byte. 
      
     Cadena de caracteres: se puede manejar con arreglos o con punteros (direcciones
                           de memoria que se gestionan dinamicamente).
      
     Imagenes: usan el pixel - 1 bit (0 blanco, 1 negro), 3 bits para 8 colores.
               El formato BMP indica los datos necesarios para procesar una imagen
               (la cantidad de bits para cada pixel, la cantidad de pixeles por 
               fila que tiene la imagen, etc). 
     */
    
    // LECTURA : Capitulo 1 : Almacenamiento de datos en el computador
    
    /* Se menciona informacion muy parecida a lo ya visto.*/
    
    return 0;
}

