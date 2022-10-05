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

void intercambiar(int *arr_int,double *arr_double, int i, int j){
    int aux_int;
    double aux_double;
    //intercambio entero
    aux_int = arr_int[i];
    arr_int[i] = arr_int[j]; //chancar
    arr_int[j] = aux_int;
    //intercambiar doubles
    aux_double = arr_double[i];
    arr_double[i] = arr_double[j]; //chancar
    arr_double[j] = aux_double;
    
}

void ordenar_arreglos(int *arr_int,double *arr_double,int cantidad_datos){
    for (int i=0; i<cantidad_datos; i++)
        for(int j = i+1;j<=cantidad_datos; j++)
            if(arr_int[i]>arr_int[j])
                intercambiar(arr_int,arr_double,i,j);
}

void actualizarInformacion(int *arr_int, double *arr_double, int cantidad_datos){
    for(int i=0; i<cantidad_datos;i++ ){
        if(arr_int[i]%2 == 0){
            arr_double[i] = arr_double[i]*2;
        }
    }
}

void actualizarInformacionEspecifica(int *arr_int, int cantidad_datos, int codigo){
    int posicion_encontrado;
    posicion_encontrado = buscar_posicion(arr_int, cantidad_datos, codigo);
    arr_int[posicion_encontrado] = arr_int[posicion_encontrado]/10;
}

void procesarDatos(int *arr_int, double *arr_double, int cantidad_datos){
    int valor_buscar;
    double valor_encontrado;
    int posicion_encontrado;
    valor_buscar = 345;
    //buscar valor
    valor_encontrado = buscar_valor(arr_int, arr_double, cantidad_datos, valor_buscar);
    cout<<valor_encontrado<<endl;
    //buscar posicion
    posicion_encontrado = buscar_posicion(arr_int, cantidad_datos, valor_buscar);
    cout<<arr_double[posicion_encontrado]<<endl;
    
    //ordenar los arreglos
    ordenar_arreglos(arr_int,arr_double,cantidad_datos);
}

void lecturaArchivoSearch(int *arr_int, double *arr_double, int &cantidad){
    
    ifstream arch_inputsearch("inputsearch.txt", ios::in);
    if(not arch_inputsearch.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    
    while(true){
        arch_inputsearch>>arr_int[cantidad]>>arr_double[cantidad];
        cantidad++;
        if(arch_inputsearch.eof()) break;
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

void lecturaArchivoInput (int *arr_int, double *arr_doubles, char *arr_char, bool *arr_boolean, int &ndatos){
    int i=0;
    int arr_int_cabecera[4];
    char extra;
    ifstream arch_input("input.txt", ios::in);
    if(not arch_input.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    //Lectura Cabecera
    lecturacabecera(arch_input,arr_int_cabecera);
    //Lectura hasta fin de archivo
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

void imprimirordenado(int *arr_int_2, double *arr_double_2, int cantidad_datos){
    for(int i=1; i<cantidad_datos; i++){
        cout<<"Valor Entero: "<<arr_int_2[i];
        cout<<" Valor Double: "<<arr_double_2[i]<<endl;
    }
    cout<<endl<<endl;
}

void imprimirreporte (int *arr_int, double *arr_doubles, char *arr_char, bool *arr_boolean,  int &ndatos){
    ofstream arch_output("output.txt", ios::out);
    if(not arch_output.is_open()){
        cout<<"El archivos no existe o no lo puedo encontrar"<<endl;
        exit(1);
    }
    
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