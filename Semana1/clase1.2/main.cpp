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
 * Creado el 16 de agosto de 2022, 17:28
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    /* Compilacion -> proceso de traduccion de un programa a un lenguaje que el 
                  computador entienda (lenguaje maquina).
 
   Etapas de la compilacion:
  
    1. Precompilacion.
       Regla del lenguaje C: "Todo identificador (ej. variable) debe ser 
       declarado antes de poder utilizarlo" En C existen instrucciones del 
       preprocesador que empiezan con el simbolo # que declaran tambien identificadores.
       La precompilacion consiste en ejecutar las instrucciones del preprocesador
       antes de la traduccion del codigo. 
       La reutilizacion de codigo (emplear elementos que no hemos implentado ni
       hemos declarado en el programa que estamos desarrollando) debe ser dominada
       y aplicada siempre por un desarrollador de software. 
 
    2. Compilacion propiamente dicha.
       Es la traduccion del programa (programa fuente .c -> programa objeto .o).
       La compilacion no esta completa, un programa objeto NO puede ejecutarse.
       Al computador le faltan instrucciones que le digan como ejecutarlo.
 
    3. Enlace.
       Aqui el compilador creara un nuevo archivo agregandole al codigo del 
       programa objeto, todo lo que requiera para ejecutarse.
 */

/* Proceso de compilacion de un proyecto
 
   Netbeans permite desarrollar proyectos, esto quiere decir que los programas
   que realizaremos no los desarrollaremos en un solo archivo para la posibilidad
   de reutilizar el codigo. 
   El proceso es similar, creando un archivo .o para cada archivo .c y uniendolo
   con el resto de arhivos necesarios para crear el .exe*/
    
    return 0;
}

