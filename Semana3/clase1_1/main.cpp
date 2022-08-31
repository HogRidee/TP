/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 19:03
 */

#include <iostream>
#include <iomanip>
#include "functions.hpp"

using namespace std;

/*
 * Este programa contiene los apuntes de la clase 1 de la semana 3
 */
int main(int argc, char** argv) {
    int a, b, c;
    char g = 'g';
    char uppercase;
    cout<<"Hola Mundo"<<endl;
    a = 10;
    b = 6;
    c = 0;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    
    cout << g << endl;
    uppercase = g - ((g>='a' and g<='z')?'a'-'A':0);
    cout << uppercase<<endl;
    cout<< toUpperCase(g)<<endl;
    //cout<< functions::toUpperCase)(g)<<endl;
    
    int number1 = 88888888;
    int number2 = 11111111;
    cout << number1 << endl;
    cout << number2 << endl;
    
    cout << number1 <<"   "<< number2 << endl;
    cout.width(20);
    cout << number1 << endl;
    cout.width(10);
    cout << number2 << endl; 
    
    cout.width(10);
    cout << number1 << number2 << endl; 
    
    cout << left << setw(10) << number1 << setw(10) << number2 << endl;
    cout << right << setw(10) << number1 << setw(10) << number2 << endl;
    
    int sw = 10;
    cout << left << setw(sw) << number1 << setw(sw) << number2 << endl;
    cout << right << setw(sw) << number1 << setw(sw) << number2 << endl;
    
    //NOTA: LA PRECISION DE DOUBLE EN C++ ES DE 4 DECIMALES, LUEGO SE TRUNCA
    double r1, r2, r3;
    r1 = 2.35685584;
    r2 = 156.67;
    r3 = 26.99999999999;
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    
    cout << setw(10)<< r1 << endl;
    cout << setw(10)<< r2 << endl;
    cout << setw(10)<< r3 << endl;
    
    cout << fixed;
    cout << setprecision(3);
    
    cout << setw(10)<< r1 << endl;
    cout << setw(10)<< r2 << endl;
    cout << setw(10)<< r3 << endl;
    
    cout << fixed;
    cout << setprecision(2);
    cout << setw(10)<< r1 << endl;
    cout << setw(10)<< r2 << endl;
    cout << setw(10)<< r3 << endl;
    
    int n = 5;
    cout << isPerfectNumber(n) << endl;
    
    for (int x = 2; x < 1000; x++){
        if (isPerfectNumber(x)){
            cout << x << " Es un numero perfecto." << endl;
        }
    }
    
    for (int x = 2; x < 1000; x++){
        if (isPerfectNumber2(x)){
            cout << x << " Es un numero perfecto." << endl;
        }
    }
    
//    int n1 = 999;
//    
//    cout << uppercase << hex << n1 << endl;
//    cout << nouppercase << hex << n1 << endl;
//    
//    int n2 = 678;
//    
//    cout << dec;
//    cout << n2 << endl;
//    
//    int a1 = 64, a2 = 123, a3 = 45678;
//    
//    cout << setw(6) << a1 << endl;
//    cout << setw(6) << a2 << endl;
//    cout << setw(6) << a3 << endl;
//    
//    cout.fill('0');
//    cout << setw(6) << a1 << endl;
//    cout << setw(6) << a2 << endl;
//    cout << setw(6) << a3 << endl;
//    
//    cout.fill('-');
//    cout << setw(6) << a1 << endl;
//    cout << setw(6) << a2 << endl;
//    cout << setw(6) << a3 << endl;
    
    //cout.fill(c); rellena los espacios con un caracter
    
//    int dd, mm, yyyy;
//    dd = 29;
//    mm = 8;
//    yyyy = 2022;
//    
//    cout.fill('0');
//    cout << setw(2) << dd << "/" << setw(2) << mm << "/" << yyyy << endl;
    
//    int code;
//    cin >> code;
//    cout << code << endl;
    
    char c1, c2, c3;
    
    cout << "Ingrese 3 caracteres: ";
    c1 = cin.get();
    cin.unget();
    c2 = cin.get();
    cin.unget();
    c3 = cin.get();
    
    cout << "Los caracteres leidos son: " << c1 << "-" << c2 << "-" << c3 << endl;
    
    return 0;
}

