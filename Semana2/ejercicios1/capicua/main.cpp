/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 23 de agosto de 2022, 8:01
 */

#include <iostream>
#include <iomanip>
#include "funcionesCaracteres.h"
#include "funcionesMatematicas.h"

using namespace std;

/*
 * Este programa evalúa un numero para verificar si es capicúa y cambia un
 * caracter minúscula a uno mayúscula.
 * (Un numero capicua se lee igual de izquierda a derecha que de derecha a 
 * izquierda)
 * Finalmente veremos el funcionamiento de cout.width y setw.
 */
int main(int argc, char** argv) {
    
    //inicializamos el caracter a cambiar a mayuscula y donde se almacenará
    char caracterIngresado = 0;
    char caracterMayuscula = 0;
    
    cout << "Ingrese un caracter minuscula: ";
    cin  >> caracterIngresado;
    
    caracterMayuscula = cambiarMinuscMayusc(caracterIngresado);
    
    cout << "El caracter mayuscula es " << caracterMayuscula << endl;
     /*
    int *ptrNum1;
    
    ptrNum1  = new int;
    *ptrNum1 = 10;
    
    cout << ptrNum1  << endl; imprime direccion de memoria
    cout << *ptrNum1 << endl; imprime el valor 10*/
    
    //inicializamos el numero para comprobar si es capicua
    int numero = 0;
    bool esCapicua; //tendrá valor true(1) o false(0)
    int mayor, menor; //
    
    cout << "Ingrese un numero para evaluar si es capicua: ";
    cin  >> numero;
    
    if (evaluarCapicua(numero)){
        cout << "El numero " << numero << " es capicua" << endl;
    }
    else{
        cout << "El numero " << numero << " no es capicua" << endl;
    }
    
    evaluarCapicuaDigitoMayorMenor(numero, esCapicua, mayor, menor);
    
    if(esCapicua){
        cout << "El numero " << numero << " es capicua" << endl;
        cout << "El digito mayor es " << mayor << endl;
        cout << "El digito menor es " << menor << endl;
    }
    else{
        cout << "El numero " << numero << " no es capicua" << endl;
    }
    
    // verificaremos el yso de cout.width y setw
    numero = 7890;
    int numero1 = 3432235;
    
    //imprime los numeros de forma normal
    cout << numero  << endl;
    cout << numero1 << endl;
    
    //el siguiente numero se imprime en 10 espacios (numero)
    cout.width(10);
    cout << numero  << endl;
    cout << numero1 << endl;
    
    //ambos numeros se imprimen en 10 espacios (numero y numero1)
    cout.width(10);
    cout << numero << endl;
    cout.width(10);
    cout << numero1 << endl;
    
    //tambien imprime en 10 espacios
    cout << setw(10) << numero << endl;
    cout << setw(10) << numero1 << endl;
    
    //imprime en 10 espacios, pegado a la izquierda, numero1 tambien se pega
    cout << left << setw(10) << numero << endl;
    cout << setw(10) << numero1 << endl;
    
    //imprime en 10 espacios, pegado a la derecha, numero 1 tambien se pega
    cout << right << setw(10) << numero << endl;
    cout << setw(10) << numero1 << endl;
    
    //imprime en formato octal
    cout << oct << numero << endl;
    numero = 999;
    //imprime en formato hexadecimal
    cout << hex << numero << endl;
    //imprime en formato hexadecimal con mayuscula
    cout << uppercase << hex << numero <<endl;
    
    return 0;
}

