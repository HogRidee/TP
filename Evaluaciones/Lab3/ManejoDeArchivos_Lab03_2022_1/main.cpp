/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 27 de septiembre de 2022, 12:36
 */

using namespace std;
#include "Funciones.hpp"
#define MAXCLIENTES 50
#define MAXPEDIDOS 200

/*
 * ESTE PROGRAMA RESUELVE EL LAB3 DEL 2022-1
 */
int main(int argc, char** argv) {
    
    int arrDni[MAXCLIENTES], arrTelefono[MAXCLIENTES], nClientes=0, nPedidos=0;
    int arrCodigoProd[MAXPEDIDOS];
    double arrPrecioProd[MAXPEDIDOS], arrCantidadProd[MAXPEDIDOS], 
            arrTotalProd[MAXPEDIDOS], arrTotalGastadoCli[MAXCLIENTES]={0.0};
    
    ofstream archReporte("ReporteDeVentas.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: ReporteDeVentas.txt" << endl;
        exit(1);
    }
    
    //leemos y ordenamos los archivos
    leerClientes(arrDni, arrTelefono, nClientes);
    ordenarClientes(arrDni, arrTelefono, nClientes);
    leerPedidos(arrCodigoProd, arrPrecioProd, arrCantidadProd, arrTotalProd, 
            arrTotalGastadoCli, nPedidos, arrDni, nClientes);
    ordenarProductos(arrCodigoProd, arrPrecioProd, arrCantidadProd, arrTotalProd,
            nPedidos);
    ordenarClientesPorTotal(arrDni, arrTelefono, arrTotalGastadoCli, nClientes);
    //imprimimos el reporte
    imprimirCabecera(archReporte);
    imprimirProductos(arrCodigoProd, arrPrecioProd, arrCantidadProd, arrTotalProd, 
            nPedidos, archReporte);
    imprimirClientes(arrDni, arrTelefono, arrTotalGastadoCli, nClientes, 
            archReporte);
    
    return 0;
}

