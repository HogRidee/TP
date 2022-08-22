/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de agosto de 2022, 7:56
 */

#include <iostream>

using namespace std;

/*
 * Este programa contiene los apuntes de la lectura: "Identificadores"
 */
int main(int argc, char** argv) {
    
    /*IDENTIFICADORES:
     Un identificador es un nombre, que define el programador, que sirve para
     denotar ciertos elementos de un programa (variables, constantes, funciones).
     
     Expresiones:
     Es un conjunto de valores constantes, variables, constantes y funciones 
     unidas por un operador, se agrupan con la finalidad de obtener un resultado.
     
     Valores constantes:
     Están referidos a la forma cómo podemos escribir un valor según el tipo
     de dato al que queremos referirnos. Ej: entero -> 34912
     
     Variables y constantes:
     Variables: 
     Una variable es un identificador relacionado a una posición de memoria donde
     se pueden colocar datos. Podrá ser modificado a lo largo del programa.
     Buena práctica -> escribir la primera letra con minúsculas y luego así: 
                       areaDelCuadrado
     Constantes:
     Es básicamente lo mismo que una variable, con la única diferencia que la
     constante debe ser incializada en su definición y este valor no se podrá
     modificar a lo largo del programa.
     Constantes simbólicas:
     Son elementos dentro del lenguaje C++ que no pueden considerarse dentro
     de la misma categoría que las variables o constantes propiamente dichas.
     Son un texto que va a ser buscado y reemplazado por otro texto en el 
     programa, antes de iniciarse el proceso de compilación. 
     #define TEXTO_A_BUSCAR texto_de_reemplazo
     #define ENTERO  int
     
     Operadores:
     Son elementos de enlace en una expresión y nos sirven para realizar 
     operaciones y obtener un resultado.
     Se clasifican como unarios y binarios, se dice que un operador es unario
     cuando se aplica a un solo elemento, será binario cuando se aplique a dos 
     elementos.
     
     Operadores aritméticos:
     +, -, *, /, %
     
     Operadores de asignación:
     Una operación de asignación es una operación por medio de la cual se coloca
     información en una variable. 
     variable = expresión;
        Asignación múltiple:
        Puede concatenarse, por ejemplo:
        a = b = c = d = 5;
     Otros operadores de asignación: +=, -=, *=, /=, %=
     
     Conversión de tipos en la asignación:
     Se debe tener mucho cuidado cuando se manejan expresiones que devolverán
     valores de un tipo diferente al de la variable que recibe el resultado.
     El compilador no avisa si la conversión se realiza de una manera diferente 
     a la esperada.
     
     Conversión explícita de tipos: 
     "type cast" consiste en escribir un tipo de dato entre paréntesis al lado 
     de una variable dentro de una expresión. Al hacerlo el valor de la variable
     será convertido temporalmente al tipo de dato escrito.
     f = double(b)/a * c 
     
     Operadores unarios de incremento y decremento: 
     Se denominan operadores unarios porque se aplican a un solo operando.
     Son ++ y --. Se pueden usar como prefijo o sufijo, con resultados diferentes.
     int a = 3, b;
     b = ++a; aquí la variable a se incrementa a 4 y b recibe 4
     int a = 3;
     b = a++ aquí la variable a se incrementa a 4, pero b recibe 3
     
     Operadores de relación: 
     Se aplican para relacionar dos valores. El resultado será uno (true o 1) si
     la relación es correcta y cero (false u 0) si no lo es.
     ==, !=, <, >, <=, >=
     
     Operadores lógicos: 
     Se aplican sobre expresiones lógicas. Una expresión lógica es aquella que
     devuelva un valor falso (false o 0) o un valor verdadero (valor diferente
     de cero, true o 1).
     !, not; significa negación
     &&, and; significa conjunción
     ||, or; significa disyunción
     
     Operador condicional:
     variable = expr1 ? expr2 : expr3
     Ejemplo: cambiar a mayúscula un caracter si es minúscula
     carCambiado = car - (car >= 'a' and car <= 'z' ? 'a' - 'A' : 0);
     >
     Precedencia de los operadores:
     Ver clase 1.2
     
     Variables punteros:
     Son variables con características adicionales como: 
     Declaración:
     TIPO *nombre;
     int *esteEsUnPuntero;
     * identifica a la variable como puntero
     
     Una variable de tipo puntero almacena una dirección de memoria. Cuando
     mencionamos dirección de memoria nos referimos a un valor entero que 
     identifica el lugar en la memoria del computador donde se coloca una 
     variable.
     
     Asignación de valores a un puntero:
     Para utilizarla debemos inicializarla, esto porque C/C++ asigna valores
     indeterminados en la primera línea del programa.
     Tenemos dos formas de inicializar una variable tipo puntero:
     
     Asignación estática de memoria:
     Se da cuando a una variable puntero se le asigna la dirección de memoria 
     de una variable común.
     int a = 31;
     int *ptInt;
     
     ptInt = &a; & -> operador de dirección, cuando se aplica a una variable
                      devuelve su dirección de memoria
     En la última línea se inicializa el puntero, asignando la dirección de
     memoria de la variable a.
     
     Asignación dinámica de memoria:
     Se realiza mediante el operador "new", que entrega una dirección de memoria
     donde se puede colocar un valor, garantizándonos que ese espacio de memoria
     no está siendo utilizado por el programa que estamos desarrollando.
     puntero = new tipo;
     int *ptInt;
     double *ptDb1;
     char *n;
     
     ptInt = new int;
     ptDb1 = new double;
     n = new char;
     
     Asignación con valor nulo:
     Corresponde a una dirección cero.
     int *ptInt;
     ptInt = nullptr;
     
     Indirección o desreferencia de un puntero:
     Mediante el puntero podemos manipular el valor contenido en la dirección de
     memoria que se le asignó al puntero. Esta característica se emplea mediante
     el operador *, que aplicado a un puntero se le denomina operador de
     indirección u operador de desreferencia.
     
     int a = 31;
     int *ptInt;
     double *ptDb1;
     
     ptInt = &a;
     ptDb1 = new double;
     
     *ptInt = 22; Se modificó el valor de a, el sistema toma el valor que 
                  contiene ptInt y coloca en su dirección de memoria el valor 22.
     
     *ptDb1 = 357.81; El sistema toma el valor que contiene la variable ptDb1
                      (dirección de memoria asignada por malloc(new)) y se 
                      dirige a esa dirección de memoria y coloca en ella el 
                      valor de 357.81
     
     Un puntero inicializado con nullptr no puede desreferenciarse, de hacerlo
     se producirá un error que culminará el programa.
     */
    
    return 0;
}

