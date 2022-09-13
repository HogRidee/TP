/* 
 * File  :  Funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 6 de septiembre de 2022, 19:16
 */

#include "Funciones.hpp"
#define TAM_LINEA 160
#define PERU 51
#define BRASIL 63
#define URUGUAY 98
#define COLOMBIA 77

using namespace std;

void imprimirLinea(char car, int cant, ofstream &archReporte){
    for (int i = 1; i < cant; i++){
        archReporte.put(car);
    }
    archReporte << endl;
}

void imprimirCabecera(ifstream &archVentas, ofstream &archReporte){
    int dd, mm, yyyy;
    char slash;
    //33 letras, 160-33 = 127/2 = 63.5
    archReporte << setw(63) << " " << "EMPRESA COMERCIALIZADORA ABC S.A." << endl;
    archVentas >> dd >> slash >> mm >> slash >> yyyy;
    archReporte << setw(66) << " ";
    archReporte.fill('0');
    //ocupa 28 espacios: 160-28 = 132/2 = 66
    archReporte << "Fecha de emision: ";
    archReporte << setw(2) << dd << slash << setw(2) << mm << slash << yyyy 
            << endl;
    archReporte.fill(' ');
}

void leerEImprimirDescuentos(ifstream &archVentas, ofstream &archReporte, 
        double &descuentoA, double &descuentoB, double &descuentoC, 
        int &productoConDescuento, double &descuentoProducto, 
        int &codigoPaisConImpuestos, double &impuestoPais){
    char descartarCar;
    
    archVentas >> descuentoA >> descartarCar >> descuentoB >> descartarCar 
            >> descuentoC >> descartarCar;
    archVentas >> productoConDescuento >> descuentoProducto >> descartarCar;
    archVentas >> codigoPaisConImpuestos >> impuestoPais >> descartarCar;
    
    //7 espacios de margen
    archReporte << setw(7) << " " << "Productos con descuento: " 
            << productoConDescuento << endl;
    archReporte << setw(7) << " " << "Pais con impuestos a las ventas: ";
    if(codigoPaisConImpuestos == PERU){
        archReporte << "Peru (" << codigoPaisConImpuestos << ")" << endl;
    }
    if(codigoPaisConImpuestos == BRASIL){
        archReporte << "Brasil (" << codigoPaisConImpuestos << ")" << endl;
    }
    if(codigoPaisConImpuestos == URUGUAY){
        archReporte << "Uruguay (" << codigoPaisConImpuestos << ")" << endl;
    }
    if(codigoPaisConImpuestos == COLOMBIA){
        archReporte << "Colombia (" << codigoPaisConImpuestos << ")" << endl;
    }
    //imprimimos una linea de =
    imprimirLinea('=', TAM_LINEA, archReporte);
}

int leerEntero(ifstream &archVentas, int ncifras){
    int valor = 0, dig, potencia;
    for(int i = ncifras - 1; i >= 0; i--){
        //primera cifra * 10 elevado a la cifra - 1
        dig = archVentas.get() - '0';
        potencia = pow(10,i);
        valor = valor + dig * potencia;
    }
    return valor;
}

void leerPedido(ifstream &archVentas, ofstream &archReportes){
    int dni, cpais, cciudad, telefono;
    archVentas >> dni;
    /* La función para leer un entero carcter por caracter:
     * entero = leerEntero(archVentas, numCifras);*/
    archVentas >> ws;
    cciudad  = leerEntero(archVentas, 3);
    cpais    = leerEntero(archVentas, 2);
    telefono = leerEntero(archVentas, 9);
}

void imprimirReporte(ifstream &archVentas, ofstream &archReporte, double descuentoA,
        double descuentoB, double descuentoC, int productoConDescuento, 
        double descuentoProducto, int codigoPaisConImpuestos, double impuestoPais){
    while(true){
        //lee la información de un pedido
        leerPedido(archVentas, archReporte);
    }
}
