/* 
 * File  :   funcionesMatematicas.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 23 de agosto de 2022, 7:43
 */

#ifndef FUNCIONESMATEMATICAS_H
#define FUNCIONESMATEMATICAS_H

int factorial(int ); //calcula factorial
bool evaluarCapicua(int ); //evalua un numero, capicua o no
//calcula digito mayor, menor de un capicua
void evaluarCapicuaDigitoMayorMenor(int , bool &, int &, int &); 

//NUMEROS COMPLEJOS
//en c++ ya no se usa *, sino & 
void sumar(double, double, double, double, double &, double &);
void restar(double, double, double, double, double &, double &);
void multiplicar(double, double, double, double, double &, double &);
void dividir(double, double, double, double, double &, double &, double &);
void potenciar(double, double, int, double &, double &);

//Verifica si un número es perfecto
int esNumeroPerfecto(int );

#endif /* FUNCIONESMATEMÁTICAS_H */

