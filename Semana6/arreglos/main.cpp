/* 
 * File:   main.cpp
 * Author: u_eeggcc
 *
 * Created on 23 de septiembre de 2022, 07:02 AM
 */

/*
 * 
 */

#define maxElements 20
#include "funciones.hpp"
int main(int argc, char** argv) {
    int arr_int[20];
    int arr_cabecera[4];
    double arr_doubles[maxElements] = {};
    int arr_prueba[4] = {0,0,0,0};
    char arr_char[maxElements];
    bool arr_boolean[maxElements];
    int entero;
    int indice = 0;
    int ndatos = 0;
    int cantidad_datos = 0;
    int valor_buscar;
    double valor_encontrado = 0.0;
    int posicion_encontrado = -1;
    
    int arr_int_2[maxElements];
    double arr_double_2[maxElements];
    
    ifstream arch_input("input.txt", ios::in);
    if(not arch_input.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    
    ifstream arch_inputsearch("inputsearch.txt", ios::in);
    if(not arch_inputsearch.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    
    ofstream arch_output("output.txt", ios::out);
    if(not arch_output.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    
    lecturacabecera(arch_input,arr_cabecera);
    imprimircabecera(arch_output, arr_cabecera);
    lectura(arch_input, arr_int, arr_doubles, arr_char, arr_boolean, ndatos);
    cout<<"El numero de elementos es : "<<ndatos<<endl;
    imprimir(arch_output, arr_int, arr_doubles, arr_char, arr_boolean, ndatos);
    
    //busquedas
    //leerdatos
    almacenar_datos(arch_inputsearch,arr_int_2, arr_double_2, cantidad_datos);
    //buscar valor
    valor_buscar = 345;
    valor_encontrado = buscar_valor(arr_int_2, arr_double_2, cantidad_datos, valor_buscar);
    cout<<valor_encontrado<<endl;
    //buscar posicion
    posicion_encontrado = buscar_posicion(arr_int_2, cantidad_datos, valor_buscar);
    cout<<arr_double_2[posicion_encontrado]<<endl;
    return 0;
}

