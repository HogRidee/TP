/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 29 de agosto de 2022, 20:21
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Este programa contiene un ejercicio desarrollado en clase
 */
int main(int argc, char** argv) {
    
    int code, age, year;
    char isProfessor;
    
    cin  >> code;
    cout << code << endl;
    
    //cin.eof
    //objeto.método
    //para verificar condicion de parada: 
    while(1){
        cin >> code >> age >> year >> isProfessor;
        if (cin.eof()) break;
        cout << code << endl
        cout << age << endl
        cout << year << endl
        cout << isProfessor << endl
    }
    
    return 0;
}

