/* 
 * File  :  funcionesMatematicas.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 7:34
 */

#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int numero){
    //inicializamos el numero que almacenará el factorial
    int f = 1;
    
    //estructura iterativa para calcular el factorial
    for (int i = numero; i > 0; i--){
        f *= i; //f = f * i
    }
    return f;
}

bool evaluarCapicua(int numero){
    
    //inicializacion
    int digito         = 0; // guardaremos el ultimo digito del numero
    int invertido      = 0; // numero original invertido
    int numeroOriginal = 0; // numero original guardado
    
    numeroOriginal = numero;
    
    while (numero > 0){
        digito = numero % 10; //sacando el módulo obtenemos el último dígito
        numero /= 10; // numero = numero/10, descarta el ultimo digito
        //empieza a formar el numero invertido
        invertido = invertido * 10 + digito; 
    }
    
    return invertido == numeroOriginal;
}

void evaluarCapicuaDigitoMayorMenor(int numero, bool &esCapicua, int &mayor, 
        int&menor){
    
    //recordar que para manejar punteros en c++ no necesitamos del *
    
    int digito         = 0; // almacena ultimo digito del numero
    int invertido      = 0; // numero original invertido
    int numeroOriginal = 0; // numero original guardado
    
    numeroOriginal = numero;
    
    mayor = 0; // cualquier digito es mayor o igual que 0 
    menor = 9; // cualquier digito es menor o igual que 9
    
    while(numero > 0){
        digito = numero % 10; //sacando el módulo obtenemos el último dígito
        numero /= 10; // numero = numero/10, descarta el ultimo digito
        //empieza a formar el numero invertido
        invertido = invertido * 10 + digito;
        if(digito > mayor){
            mayor = digito; // verifica que el digito actual sea o no el mayor
        }
        if(digito < menor){
            menor = digito; // verifica que el digito actual sea o no el menor
        }
    }
    esCapicua = invertido == numeroOriginal;
}