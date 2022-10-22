/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

int busqueda_binaria(int *arr, int criterio, int cantidad){
    //Definimos 3 indices
    //por ejemplo, para un arreglo de 7 elementos
    //      []         [][]      []      [][]       []
    //[indice_inferior][][][indice_medio][][][indice_superior]
    int indice_inferior, indice_superior, indice_medio;
    indice_inferior = 0;//Posicion 0
    indice_superior = cantidad -1; //Recuerden que la cantidad - 1 es el indice_superior
    while(true){
        //Cuando los indices se intercambian, es decir q el indice_superior se hace 
        //mas pequeño que el indice_inferior, es por que no hemos encontrado el valor buscado
        if(indice_superior<indice_inferior) return NO_ENCONTRADO; 
        //Calculamos el indice_medio, dentro del bucle por que se tiene que actualizar.
        indice_medio = (indice_inferior+indice_superior)/2;
        //Verificamos si el elemento en el indice_medio es el que estamos buscando y retornamos el indice.
        if(criterio == arr[indice_medio]) return indice_medio;
        //Aqui es donde hacemos la división de los subgrupos.
        if(criterio<arr[indice_medio])//Preguntamos si el valor en el medio es mayor que el elemento a buscar.
            indice_superior = indice_medio -1;//Reducimos los extremos del arreglo hacia la izq
        else
            indice_inferior = indice_medio +1;//Reducimos los extremos del arreglo hacia la derecha
    }
}

int buscar_posicion(int *arr, int criterio, int cantidad){
    for(int i=0; i<cantidad;i++)
        if(arr[i]==criterio) return i;
    return NO_ENCONTRADO;
}

void intercambiar_entero(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiar_double(double *arr, int i, int j){
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
        if(extra==caracter) break;
        if(arch.eof()) break;
    }
}

void insertar_en_arreglos(int *arr_fecha_profesores,
                       int *arr_cantidad_profesores, 
                       int *arr_horas_profesores, 
                       double *arr_sueldo_profesores,
                       int fecha,
                       int horas,
                       double sueldo,
                       int &cantidad_fechas){
    int posicion;
    posicion = buscar_posicion(arr_fecha_profesores, fecha, cantidad_fechas);
    if(posicion>=0){
        arr_horas_profesores[posicion]+=horas;
        arr_sueldo_profesores[posicion]+=sueldo;
        arr_cantidad_profesores[cantidad_fechas]++;
    }
    else{
        arr_fecha_profesores[cantidad_fechas] = fecha;
        arr_horas_profesores[cantidad_fechas] = horas;
        arr_sueldo_profesores[cantidad_fechas] = sueldo;
        arr_cantidad_profesores[cantidad_fechas]++;
        cantidad_fechas++;
    }
    
}

void leer_arch_profesores(int *arr_fecha_profesores, 
                          int *arr_cantidad_profesores, 
                          int *arr_horas_profesores, 
                          double *arr_sueldo_profesores,
                          int &cantidad_fechas){
    int codigo_profesor, dd, mm, yyyy,fecha, horas;
    double sueldo;
    char extra;
    ifstream arch_profesores("profesores.txt",ios::in);
    if(not arch_profesores.is_open()){
        cout<<"No se pudo abrir el archivo profesores.txt"<<endl;
        exit(1);
    }
    
    while(true){
        arch_profesores>>codigo_profesor;
        pasa_palabra(arch_profesores,' ');
        arch_profesores>>dd>>extra>>mm>>extra>>yyyy;
        arch_profesores>>sueldo>>horas;
        fecha = yyyy*10000+mm*100+dd;
        insertar_en_arreglos(arr_fecha_profesores,
                          arr_cantidad_profesores,
                          arr_horas_profesores, 
                          arr_sueldo_profesores,
                          fecha,
                          horas,
                          sueldo,
                          cantidad_fechas);
        if(arch_profesores.eof()) break;
    }                     
}
    
void ordenar_arreglos(int *arr_fecha_profesores, 
                      int *arr_cantidad_profesores, 
                      int *arr_horas_profesores, 
                      double *arr_sueldo_profesores,
                      int &cantidad_fechas){
    for(int i=0;i<cantidad_fechas;i++)
        for(int j=i+1;j<cantidad_fechas;j++)
            if((arr_fecha_profesores[i]>arr_fecha_profesores[j] or 
                    ((arr_fecha_profesores[i]==arr_fecha_profesores[j])and
                    arr_sueldo_profesores[i]>arr_sueldo_profesores[j]))){
                intercambiar_entero(arr_fecha_profesores,i,j);
                intercambiar_entero(arr_cantidad_profesores,i,j);
                intercambiar_entero(arr_horas_profesores,i,j);
                intercambiar_double(arr_sueldo_profesores,i,j);
            }
}
  
void mostrar_fecha(ofstream &arch, int fecha){
    int dd, mm, yyyy;
    dd = fecha%100;
    fecha = fecha/100;
    mm = fecha%100;
    yyyy = fecha/100;
   
    //arch<<setw(6)<<" "; 
    arch.fill('0');
    arch<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<yyyy;
    arch.fill(' ');
}

void imprimir_reporte(int *arr_fecha_profesores, 
                      int *arr_cantidad_profesores, 
                      int *arr_horas_profesores, 
                      double *arr_sueldo_profesores,
                      int cantidad_fechas){
    ofstream arch_reporte("reporte.txt",ios::out);
    if(not arch_reporte.is_open()){
        cout<<"No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    for(int i=0; i<cantidad_fechas;i++){
        mostrar_fecha(arch_reporte,arr_fecha_profesores[i]);
        arch_reporte<<setw(10)<<arr_cantidad_profesores[i];
        arch_reporte<<setw(10)<<arr_horas_profesores[i];
        arch_reporte<<fixed;
        arch_reporte<<setw(10)<<setprecision(2)<<arr_sueldo_profesores[i]<<endl;
    }
}

void imprimir_busqueda(int *arr_fecha_profesores, 
                      int *arr_cantidad_profesores, 
                      int *arr_horas_profesores, 
                      double *arr_sueldo_profesores,
                      int elemento_buscar,
                      int cantidad_fechas){
    int posicion;
    //Declaramos un segundo archivo de reporte para su visualización.
    ofstream arch_reporte_busqueda("reporte_busqueda.txt",ios::out);
    if(not arch_reporte_busqueda.is_open()){
        cout<<"No se pudo abrir el archivo reporte_busqueda.txt"<<endl;
        exit(1);
    }
    //Realizamos el mismo proceso, buscamos la posicion del elemento a buscar
    posicion = busqueda_binaria(arr_fecha_profesores, elemento_buscar, cantidad_fechas);
    //Con la posicion podremos acceder a los elementos de los arreglos en la pos encontrada.
    if (posicion != NO_ENCONTRADO){
        arch_reporte_busqueda<<"Los datos almacenados para la fecha buscada son los siguientes:"<<endl;
        arch_reporte_busqueda<<"Fecha de pago: ";
        mostrar_fecha(arch_reporte_busqueda,arr_fecha_profesores[posicion]);
        arch_reporte_busqueda<<endl;
        arch_reporte_busqueda<<"Cantidad de Profesores pagados :"<<setw(10)<<arr_cantidad_profesores[posicion]<<endl;
        arch_reporte_busqueda<<"Horas pagadas :"<<setw(10)<<arr_horas_profesores[posicion]<<endl;
        arch_reporte_busqueda<<fixed;
        arch_reporte_busqueda<<"Sueldos pagados :"<<setw(10)<<setprecision(2)<<arr_sueldo_profesores[posicion]<<endl;
    }
    else cout<<"No se encontro la Fecha"<<endl<<endl;
}