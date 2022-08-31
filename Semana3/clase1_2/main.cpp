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
 * Se necesita crear un archivo
 */
int main(int argc, char** argv) {
    
    //cin.eof
    //objeto.método
    //para verificar condicion de parada: cin.eof()
    int code, age, year;
    char isProfessor;
    int selectedCode;
    while(1){
        cin >> code >> age >> year >> isProfessor;
        if (cin.eof()) break;
        cout << code << endl;
        cout << age << endl;
        cout << year << endl;
        cout << isProfessor << endl;
        if (isProfessor == 'T') selectedCode = code;
    }
    cout << "The professor is : " << selectedCode << endl;
    
    return 0;
}
