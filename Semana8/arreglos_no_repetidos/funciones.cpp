#include "funciones.hpp"

void cambiar_enteros(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void procesar_ordenar_arreglos(int *arr_codigo_profesores, int *arr_creditos_profesores, int cant_profesores){
    for(int i=0; i<cant_profesores; i++)
        for(int j=i+1; j<cant_profesores; j++)
            if(arr_creditos_profesores[i]<arr_creditos_profesores[j]){
                cambiar_enteros(arr_codigo_profesores, i, j);
                cambiar_enteros(arr_creditos_profesores, i, j);
            }
}

void imprimir_reporte_profesores(int *arr_codigo_profesores, int *arr_creditos_profesores, int cant_profesores){
    ofstream arch_reporte("reporte.txt", ios::out);
    if(not arch_reporte.is_open()){
        cout<<"No se pudo abrir reporte";
        exit(1);
    }
    for(int i=0;i<cant_profesores;i++){
        arch_reporte<<setw(10)<<arr_codigo_profesores[i]<<setw(4)<<arr_creditos_profesores[i]<<endl;
    }
}

int busca_posicion_profesor(int *arr_codigo_profesores, int codigo, int cant_profesores){
    for(int i=0; i<cant_profesores; i++){
        if(arr_codigo_profesores[i]==codigo) return i;
    }
    return NO_ENCONTRADO;
}

void leer_insertar_profesor(int *arr_codigo_profesores,
                            int *arr_creditos_profesores,
                            int codigo,
                            int credito,
                            int &cant_profesores){
    
    int pos_encontrado = -1;
    pos_encontrado = busca_posicion_profesor(arr_codigo_profesores, codigo, cant_profesores);
    
    if (pos_encontrado>=0){
        arr_creditos_profesores[pos_encontrado] = arr_creditos_profesores[pos_encontrado] + credito;
    }
    else{
        arr_codigo_profesores[cant_profesores] = codigo;
        arr_creditos_profesores[cant_profesores] = credito;
        cant_profesores++;
    }
    
}

void pasa_palabra(ifstream &arch, char caracter){
    char extra;
    arch>>ws;
    while(true){
        extra = arch.get();
        if(extra==caracter)break;
        if(arch.eof()) break;
    }
}

void leer_arch_profesores(int *arr_codigo_profesores, int *arr_creditos_profesores, int &cant_profesores){
    int codigo_profesor, credito_profesor;
    int extra_entero;
    ifstream arch_profesores("profesores.txt",ios::in);
    if(not arch_profesores.is_open()){
        cout<<"No se puede abrir el archivo";
        exit(1);
    }
    while(true){
        arch_profesores>>codigo_profesor>>extra_entero;
        pasa_palabra(arch_profesores,' ');
        arch_profesores>>credito_profesor;
        leer_insertar_profesor(arr_codigo_profesores,
                               arr_creditos_profesores,
                               codigo_profesor,
                               credito_profesor,
                               cant_profesores);
        if(arch_profesores.eof()) break;
    }
}