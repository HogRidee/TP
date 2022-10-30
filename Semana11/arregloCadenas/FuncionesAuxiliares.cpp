/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "auxiliares.hpp"

char pasar_caracter_minusculas(char car){
    return car + ((car>='A' and  car<='Z') ? 'a'-'A' : 0);
}

char pasar_caracter_mayusculas(char car){
    return car - ((car>='a' and car<='z') ? 'a'-'A' : 0);
}

void pasar_minusculas(char* str){
    for(int i=0; str[i]; i++)
    str[i] += ((str[i]>='A' and str[i]<='Z') ? 'a'-'A' : 0);
}

void imprime_linea(ofstream &arch ,char car , int num){
    for(int i=0; i<num ; i++) arch.put(car);
    arch<<endl;
}

void eliminar_guiones(char *cadena){
    char cadena_copia[60];
    int cant_car;
    for(cant_car=0;cadena[cant_car];cant_car++){
        cadena_copia[cant_car] = cadena[cant_car];
        if(cadena[cant_car]=='_') cadena_copia[cant_car]=' ';        
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void juntar_palabras(char *cadena){
    char cadena_copia[60];
    int cant_car = 0;
    for(int i=0;cadena[i];i++){
        if(not (cadena[i]==' ')) {
            cadena_copia[cant_car] = cadena[i]; 
            cant_car++;
        }
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void camelizar(char *cadena, bool inverso){
    char cadena_copia[60];
    int cant_car = 0;
    bool inicio_palabra = true;
    for(cant_car=0;cadena[cant_car];cant_car++){
        cadena_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car])*!inverso+pasar_caracter_mayusculas(cadena[cant_car])*inverso;
        if(inicio_palabra){
            if(inverso) cadena_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car]);
            else cadena_copia[cant_car] = pasar_caracter_mayusculas(cadena[cant_car]);
            inicio_palabra = false;
        }
        if(cadena[cant_car]==' ') inicio_palabra = true;
            
    }
    cadena_copia[cant_car] = 0;
    strcpy(cadena,cadena_copia);
}

void lectura_emision_reporte(ifstream &arch){
    char str_nombre_artista[60];
    char str_nombre_cancion[60];
    char str_nombre_cancion_aux[60];
    int duracion;
    ofstream arch_reporte("reporte.txt", ios::out);
    arch_reporte<<setw(60)<<"Lista de canciones para procesar"<<endl;
    imprime_linea(arch_reporte,'=',100);
    while(true){
        arch>>str_nombre_artista;
        if (arch.eof()) break;
        arch>>str_nombre_cancion>>duracion;
        arch.ignore(200,'\n');
        arch_reporte.precision(2);
        arch_reporte<<fixed;
//        cout<<setw(30)<<left<<str_nombre_artista
//                <<setw(40)<<left<<str_nombre_cancion
//                <<setw(10)<<left<<duracion/60000.0<<endl;
        eliminar_guiones(str_nombre_artista);
        eliminar_guiones(str_nombre_cancion);
        arch_reporte<<"Tema: "<<setw(40)<<left<<str_nombre_cancion
                <<"Author: "<<setw(40)<<left<<str_nombre_artista<<endl;
        pasar_minusculas(str_nombre_cancion);
        arch_reporte<<"Minuscula: "<<setw(40)<<left<<str_nombre_cancion<<endl;
        strcpy(str_nombre_cancion_aux,str_nombre_cancion);
        camelizar(str_nombre_cancion_aux, true);
        juntar_palabras(str_nombre_cancion_aux);
        arch_reporte<<"Camelizado Inverso: "<<setw(40)<<left<<str_nombre_cancion_aux<<endl;
        
    }
}

void leer_linea(ifstream &arch, char *&artista, char *&cancion, int &duracion, double &danceability){
    char cadena[200];
    //Artista
    arch.getline(cadena, 200, ','); //Ya el getline lee y consume la ,
    if (arch.eof()) return;
    artista = new char[strlen(cadena)+1];
    strcpy(artista,cadena);
    //Cancion
    arch.getline(cadena, 200, ',');
    cancion = new char[strlen(cadena)+1];
    strcpy(cancion,cadena);
    //Duracion
    arch>>duracion;
    arch.get(); //Para leer la coma que dijo Guanilo cuando son enteros o doubles o no se use getline.
    //Danceability
    arch>>danceability;
    arch>>ws;
}

void leer_canciones_csv(char **arr_artistas, 
                        char**arr_canciones, 
                        int *arr_duraciones, 
                        double *arr_danceabilities,
                        int &cantidad_datos,
                        const char *nombre_archivo_csv){
    ifstream arch_canciones(nombre_archivo_csv, ios::in);
    if(!arch_canciones.is_open()){
        cout<<"gg";
        exit(1);
    }
    char *artista;
    char *cancion;
    int duracion;
    double danceability;
    
    while(true){
        if (arch_canciones.eof()) break;
        leer_linea(arch_canciones,artista, cancion, duracion, danceability);
        arr_artistas[cantidad_datos]=artista;
        arr_canciones[cantidad_datos] = cancion;
        arr_duraciones[cantidad_datos] = duracion;
        arr_danceabilities[cantidad_datos] = danceability;
        cantidad_datos++;
    }
    
}

void imprime_datos(char **arr_artistas, 
                   char**arr_canciones, 
                   int *arr_duraciones, 
                   double *arr_danceabilities,
                   int cantidad_datos,
                   const char *nombre_archivo_reporte){
    ofstream arch_reporte(nombre_archivo_reporte, ios::out);
    if(!arch_reporte.is_open()){
        cout<<"GG"<<endl;
        exit(1);
    }
    arch_reporte<<setprecision(2)<<fixed;
    for(int i = 0; i<cantidad_datos;i++){
        arch_reporte<<"Tema: "<<setw(10)<<left<<arr_canciones[i]<<endl;
        arch_reporte<<"Author: "<<setw(10)<<left<<arr_artistas[i]<<endl;
        arch_reporte<<"Duracion: "<<setw(10)<<left<<arr_duraciones[i]/60000.0<<endl;
        arch_reporte<<"Danceability: "<<setw(10)<<left<<arr_danceabilities[i]*100<<endl;
        imprime_linea(arch_reporte, '=', 100);
    }
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

void intercambiar_arr_char(char *& cadenaI, char*& cadenaJ){
    //Cambio los punteros a las direcciones de memoria.
    //Aquí basta con declarar un puntero a char para igualar la direccion de cadenaI como auxiliar
    //Y luego realizar el intercambio de los punteros.
    //Aquí NO hay q actualizar en el arreglo char** por que todo lo hacemos en direcciones.
    char *aux = cadenaI;
    cadenaI = cadenaJ;
    cadenaJ = aux;
}

void ordenar_arreglos(char **arr_artistas, 
                     char**arr_canciones, 
                     int *arr_duraciones, 
                     double *arr_danceabilities,
                     int cantidad_datos){
    //Vamos a ordenar por nombre del artista y como segundo criterio el danceability
    for(int i=0;i<cantidad_datos;i++)
        for(int j=i+1;j<cantidad_datos;j++)
            //Usamos strcmp para COMPARAR 2 cadenas, la cadena en el indice i y la cadena en el indice j
            //strcmp devuelve un valor negativo si cadena i es "menor" q cadena j
            //strcmp devuelve un valor positivo si cadena i es "mayor" q cadena j
            //strcmp devuelve 0 si cadena i y cadena j son IGUALES
            if((strcmp(arr_artistas[i],arr_artistas[j])>0) or 
                    ((strcmp(arr_artistas[i],arr_artistas[j])==0) and 
                    (arr_danceabilities[i]>arr_danceabilities[j]))){
                intercambiar_arr_char(arr_artistas[i],arr_artistas[j]);
                intercambiar_arr_char(arr_canciones[i],arr_canciones[j]);
                intercambiar_entero(arr_duraciones,i,j);
                intercambiar_double(arr_danceabilities,i,j);    
            }
}
