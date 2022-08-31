/* 
 * File  :  functions.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 19:13
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "functions.hpp"

char toUpperCase(char c){
    return c - ((c>='a' and c<='z')?'a'-'A':0);
}

int isPerfectNumber(int n){
    //forma rústica
    int value;
    int i = 1, sum =0;
    
    while (i<n){
        if(n%i == 0){
            sum = sum + i;
        }
        i++;
    }
    
    if (sum == n)
        value = 1;
    else
        value = 0;
    
    return value;
}

int isPerfectNumber2(int n){
    int sum = 1;
    for (int i = 2; i <= n/2; i++){
        if(n % i == 0){
            sum = sum + i;
        }
    }
    if (sum == n) return 1;
    return 0;
}
