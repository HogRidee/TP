#include "auxiliares.hpp"


void  imprime_linea(ofstream &arch_reporte, char car, int cant){
    for(int i=0;i<cant;i++) arch_reporte.put(car);
    arch_reporte<<endl;
}

void str_cpy(char * str_to, char *str_source){
    int n_cant=0;
    while(true){
        str_to[n_cant] = str_source[n_cant];
        if(not str_source[n_cant]) break;
        //if(str_source[n_cant] == 0) break;
        n_cant++;
    }
}

char pasar_caracter_minusculas(char car){
    return car + ((car>='A' and car<='Z') ? 'a' - 'A':0);
}

char pasar_caracter_mayusculas(char car){
    return car - ((car>='a' and car<='z') ? 'a' - 'A':0);
}

void str_to_upper(char *str){
    for(int n_cant = 0; str[n_cant]; n_cant++){
        str[n_cant] -= ((str[n_cant]>='a' and str[n_cant]<='z') ? 'a' - 'A':0);
    }
}

void str_to_lower(char *str){
    for(int n_cant = 0; str[n_cant]; n_cant++){
        str[n_cant] += ((str[n_cant]>='A' and str[n_cant]<='Z') ? 'a' - 'A':0);
    }
}

int str_len(char *str){
    int n_cant;
    for(n_cant = 0;str[n_cant];n_cant++);
    return n_cant;
}

void lectura_canciones(ifstream &arch_musica, ofstream &arch_reporte){
    char str_nombre_artista[MAX_TAM_CADENA];
    char str_nombre_cancion[MAX_TAM_CADENA];
    int duracion;
    char str_explicito[MAX_TAM_CADENA];
    int fecha;
    double danceability, energy;
    char str_genero[MAX_TAM_CADENA];
    char str_genero_copiado[MAX_TAM_CADENA];
    char str_genero_copiado_cstring[MAX_TAM_CADENA];
    
    arch_musica>>str_nombre_artista;
    //for(int i=0;i<MAX_TAM_CADENA;i++) cout<<str_nombre_artista[i]<<endl;
    arch_musica>>str_nombre_cancion;
    arch_musica>>duracion;
    arch_musica>>str_explicito;
    arch_musica>>fecha>>danceability>>energy;
    arch_musica>>str_genero;
    
    imprime_linea(arch_reporte, '*', 80);
    arch_reporte<<"Reporte de Lectura"<<endl;
    arch_reporte<<"Nombre del Artista :"<<str_nombre_artista<<endl;
    arch_reporte<<"Tamaño Nombre Artista :"<<str_len(str_nombre_artista)<<endl;
    arch_reporte<<"Tamaño Nombre Artista CSTRING:"<<strlen(str_nombre_artista)<<endl;
    arch_reporte<<"Nombre de la Cancion :"<<str_nombre_cancion<<endl;
    str_to_upper(str_nombre_cancion);
    arch_reporte<<"Nombre de la Cancion Mayusculas:"<<str_nombre_cancion<<endl;
    arch_reporte<<"Duracion de la cancion :"<<duracion/60000.0<<endl;
    arch_reporte<<"Es explicito? :"<<str_explicito<<endl;
    arch_reporte<<"Fecha de lanzamiento :"<<fecha<<endl;
    arch_reporte<<"Danceability :"<<danceability*100<<'%'<<endl;
    arch_reporte<<"Energy :"<<energy*100<<'%'<<endl;
    arch_reporte<<"Genero:"<<str_genero<<endl;
    str_cpy(str_genero_copiado,str_genero);
    arch_reporte<<"Genero Copiado:"<<str_genero_copiado<<endl;
    strcpy(str_genero_copiado_cstring,str_genero);
    arch_reporte<<"Genero Copiado CSTRING:"<<str_genero_copiado_cstring<<endl;
    imprime_linea(arch_reporte, '*', 80);
}

void juntar_palabras(char * cadena){
    int cant_car =0;
    char str_copia[MAX_TAM_CANCION];
    for(int i = 0;cadena[i];i++){
        if(not (cadena[i] ==' ')){
            str_copia[cant_car] = cadena[i];
            cant_car++;
        }
    }
    str_copia[cant_car] = 0;
    strcpy(cadena,str_copia);
}

void remover_guiones(char *str_cancion){
    int cant_car;
    char str_copia[MAX_TAM_CANCION];
    for(cant_car = 0;str_cancion[cant_car];cant_car++){
        str_copia[cant_car] = str_cancion[cant_car];
        if(str_cancion[cant_car]=='_') str_copia[cant_car]=' ';
    }
    str_copia[cant_car] = 0;
    strcpy(str_cancion,str_copia);
}

void camelizar(char *cadena, bool esInverso){
    int cant_car;
    bool inicio_palabra = true;
    char str_copia[MAX_TAM_CANCION];
    for(cant_car = 0;cadena[cant_car];cant_car++){
        str_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car])*!esInverso+pasar_caracter_mayusculas(cadena[cant_car])*esInverso;
        if(inicio_palabra){
            if(esInverso) str_copia[cant_car] = pasar_caracter_minusculas(cadena[cant_car]);
            else str_copia[cant_car] = pasar_caracter_mayusculas(cadena[cant_car]);
            inicio_palabra  = false;
        }
        if(cadena[cant_car] == ' ') inicio_palabra = true;
    }
    str_copia[cant_car] = 0;
    strcpy(cadena,str_copia);
}

void lectura_impresion_reporte(ifstream &arch_musica, ofstream &arch_reporte){
    char str_artista[MAX_TAM_ARTISTA];
    char str_cancion[MAX_TAM_CANCION];
    char str_copia[MAX_TAM_CANCION];
    while(true){
        arch_musica>>str_artista;
        if(arch_musica.eof())break;
        arch_musica>>str_cancion;
        arch_musica.ignore(256,'\n');
        remover_guiones(str_cancion);
        arch_reporte<<"Tema: "<<setw(40)<<left<<str_cancion<<"autor: "<<setw(40)<<left<<str_artista<<endl;
        strcpy(str_copia,str_cancion);
        str_to_lower(str_copia);
        arch_reporte<<"Minuscula: "<<setw(40)<<left<<str_copia<<endl;
        arch_reporte<<"Minuscula Lonngitud: "<<setw(40)<<left<<strlen(str_copia)<<endl;
        //arch_reporte<<"Normal: "<<setw(40)<<left<<str_cancion<<endl;
        strcpy(str_copia,str_cancion);
        camelizar(str_copia, true);
        juntar_palabras(str_copia);
        arch_reporte<<"Camelizado Inverso: "<<setw(40)<<left<<str_copia<<endl;
        arch_reporte<<"Camelizado Inverso Lonngitud: "<<setw(40)<<left<<strlen(str_copia)<<endl;
    }
}

void leer_linea(ifstream &arch_canciones, char *&artista, char *&tema, int &duracion, double &danceability){
    char buffer[40];
    //artista cadena
    arch_canciones.getline(buffer, 40, ',');
    if(arch_canciones.eof()) return;
    artista = new char[strlen(buffer)+1];
    strcpy(artista, buffer);
    //Cancion cadena
    arch_canciones.getline(buffer, 40, ',');
    tema = new char[strlen(buffer)+1];
    strcpy(tema, buffer);
    //duracion int
    arch_canciones>>duracion;
    arch_canciones.get(); //La coma de guanilo
    //danceability double
    arch_canciones>>danceability;
    arch_canciones>>ws;
    
}

void lectura_arch_canciones_csv(char ** arr_artistas, 
                                char ** arr_temas, 
                                int * duraciones, 
                                double * danceabilities, 
                                int & cantidad, 
                                const char *nombre_archivo){
    ifstream arch_canciones(nombre_archivo, ios::in);
    if(not arch_canciones.is_open()){
        cout<<"GG"<<endl;
        exit(1);
    }
    int duracion;
    double danceability;
    char *artista;
    char *tema;
    
    while(true){
        leer_linea(arch_canciones, artista, tema, duracion, danceability);
        if(arch_canciones.eof()) break;
        arr_artistas[cantidad] = artista;
        arr_temas[cantidad] = tema;
        duraciones[cantidad] = duracion;
        danceabilities[cantidad] = danceability;
        cantidad++;
    }
}

void intercambiar_arr_char(char *&cadenaI, char *&cadenaJ){
    char *aux = cadenaI;
    cadenaI = cadenaJ;
    cadenaJ = aux;
}

void intercambiar_doubles(double *arr, int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void intercambiar_enteros(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void procesar_arreglos_csv(char ** arr_artistas, 
                           char ** arr_temas, 
                           int * duraciones, 
                           double * danceabilities, 
                           int cantidad){
    
    //ordenamiento
    for(int i=0; i<cantidad; i++)
        for(int j=i+1; j<cantidad; j++){
            //criterio ordenar por artista y luego danceability
            if((strcmp(arr_artistas[i], arr_artistas[j])>0) or
                    (strcmp(arr_artistas[i], arr_artistas[j])==0) and
                    danceabilities[i]>danceabilities[j]){
                //cambiar
                intercambiar_enteros(duraciones, i, j);
                intercambiar_doubles(danceabilities, i, j);
                intercambiar_arr_char(arr_artistas[i], arr_artistas[j]);
                intercambiar_arr_char(arr_temas[i], arr_temas[j]);
            }
            
        }
    
}

void emtir_reporte(char ** arr_artistas, 
                           char ** arr_temas, 
                           int * duraciones, 
                           double * danceabilities, 
                           int cantidad){
    ofstream arch_reporte("reporte_2.txt",ios::out);
    int duracion_total=0;
    int contador_danceabilities_80 = 0;
    arch_reporte<<setprecision(2)<<fixed;
    for(int i =0 ; i<cantidad;i++){
        arch_reporte<<"Tema " << setw(10) << left << arr_temas[i]<<endl;
        arch_reporte<<"Author " << setw(10) << left << arr_artistas[i]<<endl;
        arch_reporte<<"Duracion " << setw(10) << left << duraciones[i]<<endl;
        arch_reporte<<"Danceability " << setw(10) << left << danceabilities[i]<<endl;
        imprime_linea(arch_reporte, '=', 100);
    }
    //calcular los valores del resumen
    //duracion total
    for(int i=0;i<cantidad;i++)
        duracion_total = duracion_total + duraciones[i];
    arch_reporte<<"Duracion Total: "<<duracion_total<<endl;
    //cuantos danceability 80%
    for(int i = 0; i<cantidad;i++){
        if(danceabilities[i]>=0.8) contador_danceabilities_80++;
    }
    arch_reporte<<"Danceabilities >=80%: "<<contador_danceabilities_80<<endl;    
}










