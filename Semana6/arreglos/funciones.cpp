#include "funciones.hpp"

double buscar_valor(int *arr_int, double *arr_double, int cantidad_datos, int valor_buscar){
    double valor_encontrado = 0.0;
    for (int i = 0; i<cantidad_datos;i++){
        if(arr_int[i] == valor_buscar){
            valor_encontrado = arr_double[i];
        }
    }
    return valor_encontrado;
}

int buscar_posicion(int *arr_int, int cantidad_datos, int valor_buscar){
    int posicion_encontrado = -1;
    for (int i = 0; i<cantidad_datos;i++){
        if(arr_int[i] == valor_buscar){
            posicion_encontrado = i;
        }
    }
    return posicion_encontrado;
}

void almacenar_datos(ifstream &arch_input, int *arr_int, double *arr_double, int &cantidad){
    while(true){
        arch_input>>arr_int[cantidad]>>arr_double[cantidad];
        cantidad++;
        if(arch_input.eof()) break;
    }
}

void lecturacabecera(ifstream &arch_input, int *arr_int){
    for(int i = 0; i<4; i++){
        arch_input>>arr_int[i];
    }
}

void imprimircabecera(ofstream &arch_output, int *arr_cabecera){
    arch_output<<"Elemento 1 del arreglo: "<<arr_cabecera[0]<<endl;
    arch_output<<"Codigo: "<<arr_cabecera[1]<<endl;
    arch_output<<"Telefono: "<<arr_cabecera[2]<<endl;
    arch_output<<"Edad: "<<arr_cabecera[3]<<endl;
}

void lectura (ifstream &arch_input, int *arr_int, double *arr_doubles, char *arr_char, bool *arr_boolean, int &ndatos){
    int i=0;
    char extra;
    while(true){
        arch_input>>arr_int[i]>>arr_doubles[i];
        arch_input>>ws;
        arr_char[i] = arch_input.get();
        arch_input>>ws;
        extra = arch_input.get();
        if (extra == 'V') arr_boolean[i] = true;
        else
            arr_boolean[i] = false;
        if(arch_input.eof()) break;
        i++;
        ndatos++;
    }
}

void imprimir (ofstream &arch_output, int *arr_int, double *arr_doubles, char *arr_char, bool *arr_boolean,  int &ndatos){
    for(int i=0; i<ndatos; i++){
        arch_output<<"Valor Entero: "<<arr_int[i];
        arch_output<<" Valor Double: "<<arr_doubles[i];
        arch_output<<" Valor Char: "<<arr_char[i];
        arch_output<<" Valor Char: ";
        if(arr_boolean[i]){
            arch_output<<"Verdadero"<<endl;
        }
        else{
            arch_output<<"Falso"<<endl;
        }
        
    }
}