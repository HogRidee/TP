/* 
 * File  :  Funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 27 de septiembre de 2022, 12:39
 */

using namespace std;
#include "Funciones.hpp"

void imprimirClientes(int *arrDni, int *arrTelefono, double *arrTotalGastadoCli, 
        int nClientes, ofstream &archReporte){
    int clienteMayor, clienteMenor;
    double cantMayor = 0.0, cantMenor = 1000.0;
    for(int i = 0; i < nClientes; i++){
        archReporte.fill('0');
        archReporte << setw(3) << i + 1 << ")";
        archReporte.fill(' ');
        archReporte << setw(15) << arrDni[i] << setw(15) << arrTelefono[i] <<
                setw(15) << arrTotalGastadoCli[i] << endl;
        if(arrTotalGastadoCli[i] > cantMayor){
            cantMayor = arrTotalGastadoCli[i];
            clienteMayor = arrDni[i];
        }
        if(arrTotalGastadoCli[i] < cantMenor){
            cantMenor = arrTotalGastadoCli[i];
            clienteMenor = arrDni[i];
        }
    }
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << "Cliente con mayor gasto: " << clienteMayor << " - S/." 
            << setw(6) << cantMayor << endl;  
    archReporte << "Cliente con menor gasto: " << clienteMenor << " - S/." 
            << setw(6) << cantMenor << endl; 
}

void imprimirProductos(int *arrCodigoProd, double *arrPrecioProd, 
        double *arrCantidadProd, double *arrTotalProd, int nPedidos, 
        ofstream &archReporte){
    double totalRecaudado = 0.0;
    for(int i = 0; i < nPedidos; i++){
        archReporte.fill('0');
        archReporte << setw(3) << i + 1 << ")";
        archReporte.fill(' ');
        archReporte << setw(15) << arrCodigoProd[i] << fixed << setprecision(2)
                << setw(15) << arrPrecioProd[i] << setw(15) 
                << arrCantidadProd[i] << setw(20) << arrTotalProd[i] << endl;
        totalRecaudado += arrTotalProd[i];
    }
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << setw(45) << " " << "TOTAL RECAUDADO: " << totalRecaudado << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "GASTOS POR CLIENTE" << endl;
    archReporte << "NO." << setw(15) << "DNI" << setw(15) << "TELEFONO" <<
            setw(20) << "TOTAL GASTADO" << endl;
}

void imprimirLinea(char c, int tam, ofstream &archReporte){
    for(int i = 0; i <= tam; i++){
        archReporte.put(c);
    }
    archReporte.put('\n');
}

void ordenarClientesPorTotal(int *arrDni, int *arrTelefono, 
        double *arrTotalGastadoCli, int nClientes){
    for(int i = 0; i < nClientes - 1; i++){
        for(int j = i + 1; j < nClientes; j++){
            if(arrTotalGastadoCli[i] > arrTotalGastadoCli[j]){
                cambiarI(arrDni, i, j);
                cambiarI(arrTelefono, i, j);
                cambiarD(arrTotalGastadoCli, i, j);
            }
        }
    }
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(18) << " " << "EMPRESA COMERCIALIZADORA ABC S.A." << endl;
    archReporte << setw(24) << " " << "REPORTE DE VENTAS" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "INGRESOS POR PRODUCTO" << endl<< "No." << 
            setw(16) << "CODIGO" << setw(15) << "PRECIO" << setw(20) 
            << "CANTIDAD VENDIDA" << setw(20) << "MONTO RECAUDADO" << endl;
}

void ordenarProductos(int *arrCodigoProd, double *arrPrecioProd, 
        double *arrCantidadProd, double *arrTotalProd, int nPedidos){
    for(int i = 0; i < nPedidos - 1; i++){
        for(int j = i + 1; j < nPedidos; j++){
            if(arrCodigoProd[i] > arrCodigoProd[j]){
                cambiarI(arrCodigoProd, i, j);
                cambiarD(arrPrecioProd, i, j);
                cambiarD(arrCantidadProd, i, j);
                cambiarD(arrTotalProd, i, j);
            }
        }
    }
}

void buscarCliente(double *arrTotalGastadoCli, int *arrDni, int nClientes, int dniCliente, 
        double total){
    for(int i = 0; i < nClientes; i++){
        if(arrDni[i] == dniCliente){
            arrTotalGastadoCli[i] += total;
        }
    }
}

int comprobarRepetido(int *arrCodigoProd, int nPedidos, int codigoProducto){
    for(int i = 0; i < nPedidos; i++){
        if(arrCodigoProd[i] == codigoProducto){
            return i;
        }
    }
    return -1;
}

void leerProducto(int *arrCodigoProd, double *arrPrecioProd, double *arrCantidadProd, double *arrTotalProd, 
                double *arrTotalGastadoCli, int *arrDni, int &nPedidos, int nClientes, int codigoProducto,
                double cantidadPedida, double precioProducto, int dniCliente){
    int posicion;
    posicion = comprobarRepetido(arrCodigoProd, nPedidos, codigoProducto);
    if(posicion >= 0){
        arrPrecioProd[posicion] += precioProducto;
        arrCantidadProd[posicion] += cantidadPedida;
        arrTotalProd[posicion] += precioProducto * cantidadPedida;
        buscarCliente(arrTotalGastadoCli, arrDni, nClientes, dniCliente, 
                arrTotalProd[posicion]);
    }
    else{
        arrCodigoProd[nPedidos] = codigoProducto;
        arrPrecioProd[nPedidos] = precioProducto;
        arrCantidadProd[nPedidos] = cantidadPedida;
        arrTotalProd[nPedidos] = precioProducto * cantidadPedida;
        buscarCliente(arrTotalGastadoCli, arrDni, nClientes, dniCliente, 
                arrTotalProd[nPedidos]);
        nPedidos++;
    }
}

void leerPedidos(int *arrCodigoProd, double *arrPrecioProd, double *arrCantidadProd,
        double *arrTotalProd, double *arrTotalGastadoCli, int &nPedidos, 
        int *arrDni, int nClientes){
    int codigoProducto, dniCliente, dd, mm, yyyy;
    double cantidadPedida, precioProducto;
    char extra;
    ifstream archPedidos("Pedidos.txt", ios::in);
    if(not archPedidos.is_open()){
        cout << "ERROR: Pedidos.txt" << endl;
        exit(1);
    }
    while(true){
        archPedidos >> codigoProducto;
        if(archPedidos.eof()) break;
        archPedidos >> extra;
        archPedidos.ignore(200, '*');
        archPedidos >> cantidadPedida >> precioProducto >> dniCliente >> dd >>
                extra >> mm >> extra >> yyyy;
        leerProducto(arrCodigoProd, arrPrecioProd, arrCantidadProd, arrTotalProd, 
                arrTotalGastadoCli, arrDni, nPedidos, nClientes, codigoProducto,
                cantidadPedida, precioProducto, dniCliente);
    }
}

void cambiarD(double *arr, int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarI(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void ordenarClientes(int *arrDni, int *arrTelefono, int nClientes){
    for(int i = 0; i < nClientes - 1; i++){
        for(int j = i + 1; j < nClientes; j++){
            if(arrDni[i] > arrDni[j]){
                cambiarI(arrDni, i, j);
                cambiarI(arrTelefono, i, j);
            }
        }
    }
}

void leerClientes(int *arrDni, int *arrTelefono, int &nClientes){
    ifstream archClientes("Clientes.txt", ios::in);
    if(not archClientes.is_open()){
        cout << "ERROR: Clientes.txt" << endl;
        exit(1);
    }
    while(true){
        archClientes >> arrDni[nClientes];
        if(archClientes.eof()) break;
        archClientes.ignore(200, ']');
        archClientes >> arrTelefono[nClientes];
        nClientes++;
    }
}
