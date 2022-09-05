/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 2 de septiembre de 2022, 7:25
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream> //para leer y escribir archivos
#include <cmath> //para usar sqrt, para usar abs
#include "funciones.hpp"

#define PRECISION 4

using namespace std;

/*
 * ESTE PROGRAMA CONTIENE LOS APUNTES DE CLASE DE LA CLASE 2 DE LA SEMANA 3
 */
int main(int argc, char** argv) {
    
    int codigo = 0;   //almacena el codigo del alumno
    int edad = 0;    //edad del alumno
    int dd = 0;     //dia de nacimiento
    int mm = 0;    //mes de nacimiento
    int yyyy = 0; //año de nacimiento
    double precio = 0.0; 
    double precioTotal = 0.0;
    double totalT = 0.0;
    double totalA = 0.0;
    char car; 
    char esProfesor;
    
    //data input es el nombre de la variable archivo
    ifstream dataInput("input.txt", ios::in); //(ios::out || ios::in) es válido
    /*validamos que el archivo pudo abrirse, para que se abra desde el terminal
     debes colocarlo en la carpeta MinGW Windows dentro de dist. Si se corre 
     desde el netbeans no hay problema con colcarlo en la ruta normal.*/
    if(not dataInput.is_open()){
        cout << "ERROR: El archivo no se pudo abrir" << endl;
        exit(1);
    }
    
    ofstream dataOutput("output.txt", ios::out);
    if(not dataOutput.is_open()){
        cout << "ERROR: El archivo no se pudo abrir" << endl;
        exit(1);
    }
    //damos formato al reporte
    /*
     * Llamada a función para imprimir 60 caracteres = en el archivo de salida
     */
    imprimirLinea('=', 90, dataOutput); 
    dataOutput << left << setw(15) << "CODIGO" << left << setw(15) << "DOB" 
            << left << setw(15) << "EDAD" << left << setw(15)<< "TIPO" << left 
            << setw(15) << "DEUDA" << setw(15) << "CARGO" << endl;
    //leemos e imprimimos los datos del input
    while(1){
        dataInput >> codigo;
        if(dataInput.eof()) break;
        dataInput >> edad >> dd >> car >> mm >> car >> yyyy >> esProfesor 
            >> precio;
        dataOutput << left << setw(15) << codigo;
        dataOutput.fill('0');
        dataOutput << left << setw(2) << dd << car << setw(2) << mm << car;
        dataOutput.fill(' ');
        dataOutput << left << setw(9) << yyyy;
        dataOutput << left << setw(15) << edad; 
    
        if(esProfesor == 'T'){
            dataOutput << left << setw(15) << "PROFESOR";
            dataOutput << left << fixed << setprecision(2) << setw(15) << precio; 
            dataOutput << left << setw(15) << '-' << endl;
            totalT += precio;
        }
        else{
            dataOutput << left << setw(15) << "ALUMNO";
            dataOutput << left << setw(15) << "-";
            dataOutput << left << fixed << setprecision(2) << setw(15) << precio 
                << endl; 
            totalA += precio;
        }
        precioTotal += precio;
        
        //ajustamos precision (decimales)
        //no se puede colocar ceros después. ej. 4.5 no puede ser 4.50
        //fixed le dice al programa que vamos a usar un valor de caracteres
        //luego del punto
        //dataOutput.fixed;
        //precision detalla la cantidad de decimales a mostrar
        //dataOutput.precision(PRECISION);
    }
    imprimirLinea('=', 90, dataOutput);
    dataOutput.fill(' ');
    dataOutput << "Totales:";
    dataOutput << right << fixed << setprecision(2) << setw(58) << totalT 
            << right << setw(14) << totalA << endl;
    dataOutput << left << setw(15) << "Saldo final:";
    dataOutput << right << fixed << setprecision(2) << setw(5) << precioTotal 
            << endl;
    imprimirLinea('=', 90, dataOutput);
    
    return 0;
}

/*
 * ¿Que comentar?
 * Llamadas a funciones
 * Uso de librerías externas
 * Condicionales complejas
 * 
 * Si queremos 6 columnas tendremos:
 * 6 x 15 = 90
 */