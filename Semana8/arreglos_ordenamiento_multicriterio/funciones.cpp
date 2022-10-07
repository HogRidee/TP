/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "funciones.hpp"
void intercambiar_entero(int *arr,int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiar_double(double *arr,int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
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

int busca_posicion(int *arr, int criterio, int cantidad){
    for(int i=0; i<cantidad;i++)
        if(arr[i] == criterio) return i;
    
    return NO_ENCONTRADO;
}

void insertar_datos(int *arr_fechas_profesores, 
                    int *arr_cantidad_profesores,
                    int *arr_horas_profesores,
                    double *arr_sueldos_profesores,
                    int fecha, int horas_profesor, double sueldo_profesor,
                    int &cantidad_fechas){
    int posicion;
    posicion = busca_posicion(arr_fechas_profesores, fecha, cantidad_fechas);
    if(posicion>=0){
        //actualizar
        arr_cantidad_profesores[posicion]++;
        arr_horas_profesores[posicion]+=horas_profesor;
        arr_sueldos_profesores[posicion]+=sueldo_profesor;                
    }
    else{
        //insertar
        arr_fechas_profesores[cantidad_fechas] = fecha;
        arr_cantidad_profesores[cantidad_fechas]=1;
        arr_horas_profesores[cantidad_fechas]=horas_profesor;
        arr_sueldos_profesores[cantidad_fechas]=sueldo_profesor; 
        cantidad_fechas++;
    }
}
void leer_archivo_profesores(int *arr_fechas_profesores, 
                             int *arr_cantidad_profesores,
                             int *arr_horas_profesores, 
                             double *arr_sueldos_profesores, 
                             int &cantidad_fechas){
    int codigo_profesor,dd,mm,yyyy,horas_profesor, fecha;
    double sueldo_profesor;
    char extra;
    ifstream arch_profesores("profesores.txt", ios::in);
    if(not arch_profesores.is_open()){
        cout<<"GG"<<endl;
        exit(1);
    }
    
    while(true){
        arch_profesores>>codigo_profesor;
        if(arch_profesores.eof()) break;
        pasa_palabra(arch_profesores, ' ');
        arch_profesores>>dd>>extra>>mm>>extra>>yyyy;
        arch_profesores>>sueldo_profesor;
        arch_profesores>>horas_profesor;
        fecha = yyyy*10000 + mm*100 + dd;
        //insercion
        insertar_datos(arr_fechas_profesores, 
                       arr_cantidad_profesores,
                       arr_horas_profesores,
                       arr_sueldos_profesores,
                       fecha,horas_profesor,sueldo_profesor,
                       cantidad_fechas);
    }
}

void ordenar_arreglos(int *arr_fechas_profesores, 
                      int *arr_cantidad_profesores,
                      int *arr_horas_profesores, 
                      double *arr_sueldos_profesores, 
                      int cantidad_fechas){
    
    for(int i=0;i<cantidad_fechas;i++)
        for(int j = i+1;j<cantidad_fechas;j++)
            if((arr_fechas_profesores[i]>arr_fechas_profesores[j]) or
                (arr_fechas_profesores[i]==arr_fechas_profesores[j]) and 
                (arr_sueldos_profesores[i]>arr_sueldos_profesores[j])){
                intercambiar_entero(arr_fechas_profesores,i,j);
                intercambiar_entero(arr_cantidad_profesores,i,j);
                intercambiar_entero(arr_horas_profesores,i,j);
                intercambiar_double(arr_sueldos_profesores,i,j);
            }
                
    
}

void mostrar_fecha(ofstream &arch, int fecha){
    int dd, mm, yyyy;
    dd = fecha%100;
    fecha = fecha/100;
    mm = fecha%100;
    yyyy = fecha/100;
    arch.fill('0');
    arch<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<yyyy;
    arch.fill(' ');
}

void imprimir_reporte(int *arr_fechas_profesores, 
                             int *arr_cantidad_profesores,
                             int *arr_horas_profesores, 
                             double *arr_sueldos_profesores, 
                             int cantidad_fechas){
    ofstream arch_reporte("reporte.txt", ios::out);
    if(not arch_reporte.is_open()){
        cout<<"GG"<<endl;
        exit(1);
    }
    for(int i =0; i<cantidad_fechas;i++){
        mostrar_fecha(arch_reporte, arr_fechas_profesores[i]);
        arch_reporte<<setw(10)<<arr_cantidad_profesores[i];       
        arch_reporte<<setw(10)<<arr_horas_profesores[i];        
        arch_reporte<<setw(10)<<arr_sueldos_profesores[i]<<endl;        
    }
       
}