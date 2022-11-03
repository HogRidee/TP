/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 3 de noviembre de 2022, 14:50
 */

#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0; i <= n; i++){
        arch.put(c);
    }
    arch.put('\n');
}

int buscarUsuario(int codigoPais, int id, int *arrCodigoPaisUsuario, int *arrId, 
        int nUsuarios){
    for(int i = 0; i < nUsuarios; i++){
        if(arrCodigoPaisUsuario[i] == codigoPais and arrId[i] == id)
            return i;
    }
    return 0;
}

int buscarPais(int codigoPais, int *arrCodigoPais, int nPaises){
    for(int i = 0; i < nPaises; i++){
        if(arrCodigoPais[i] == codigoPais)
            return i;
    }
    return 0;
}

void cambiarI(int *arr, int i, int j){
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarStr(char *&cadenaI, char *&cadenaJ){
    char *aux = cadenaI;
    cadenaI = cadenaJ;
    cadenaJ = aux;
}

void imprimirResumen(ofstream &archReporte, int nComentarios, int *arrCantidadLikes,
        int nUsuarios){
    int likesTotales = 0;
    for(int i = 0; i < nComentarios; i++){
        likesTotales += arrCantidadLikes[i];
    }
    archReporte << "CANTIDAD DE COMENTARIOS:  " << nComentarios << endl;
    archReporte << "CANTIDAD TOTAL DE LIKES:  " << likesTotales << endl;
    archReporte << "CANTIDAD DE USUARIOS:  " << nUsuarios << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirDetallado(ofstream &archReporte, int *arrFecha, int *arrCantidadLikes, 
        char **arrNombreUsuario, char **arrNombrePais, char **arrComentario, 
        int nComentarios){
    int dd, mm, yyyy, fecha;
    char extra = '/';
    for(int i = 0; i < nComentarios; i++){
        fecha = arrFecha[i];
        dd = fecha % 100;
        fecha = fecha / 100;
        mm = fecha % 100;
        yyyy = fecha / 100;
        archReporte.fill('0');
        archReporte << right << setw(2) << dd << extra << setw(2) << mm << extra << yyyy;
        archReporte.fill(' ');
        archReporte << left << setw(5) << " " << setw(20) << arrNombreUsuario[i] << 
                setw(20) << arrNombrePais[i] << setw(25) << arrComentario[i] << 
                right << setw(10) << arrCantidadLikes[i] << endl;
    }
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(39) << " " << "LISTADO DE COMENTARIOS" << endl;
    //llamada a funcion para imprimir una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << left << setw(15) << "Fecha";
    archReporte << setw(20) << "Usuario";
    archReporte << setw(23) << "Pais";
    archReporte << setw(20) << "Comentario";
    archReporte << setw(20) << "Cantidad de likes" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
}

void ordenarArreglos(int *arrFecha, int *arrCantidadLikes, 
        char **arrNombreUsuario, char **arrNombrePais, char **arrComentario, 
        int nComentarios){
    bool criterio1, criterio1Prima, criterio2, criterio2Prima, criterio3;
    for(int i = 0; i < nComentarios - 1; i++){
        for(int j = i + 1; j < nComentarios; j++){
            criterio1 = strcmp(arrNombrePais[i], arrNombrePais[j]) > 0;
            criterio1Prima = strcmp(arrNombrePais[i], arrNombrePais[j]) == 0;
            criterio2 = strcmp(arrNombreUsuario[i], arrNombreUsuario[j]) > 0;
            criterio2Prima = strcmp(arrNombreUsuario[i], arrNombreUsuario[j]) == 0;
            criterio3 = arrFecha[i] < arrFecha[j];
            if(criterio1 or (criterio1Prima and criterio2) or (criterio1Prima 
                    and criterio2Prima and criterio3)){
                cambiarI(arrFecha, i, j);
                cambiarI(arrCantidadLikes, i, j);
                cambiarStr(arrNombreUsuario[i], arrNombreUsuario[j]);
                cambiarStr(arrNombrePais[i], arrNombrePais[j]);
                cambiarStr(arrComentario[i], arrComentario[j]);
            }
        }
    }
}

void leerComentario(ifstream &archComentarios, char **arrComentario, int nComentarios){
    char buffer[300];
    archComentarios >> buffer;
    //quitamos los guiones
    for(int i = 0; buffer[i]; i++){
        if(buffer[i] == '_')
            buffer[i] = ' ';
    }
    arrComentario[nComentarios] = new char [strlen(buffer) + 1];
    strcpy(arrComentario[nComentarios], buffer);
}

void procesarComentarios(int *arrCodigoPais, char **arrPais, int nPaises, 
        int *arrCodigoPaisUsuario, int *arrId, char **arrUsuario, int nUsuarios, 
        int *arrCantidadLikes, char **arrNombreUsuario, char **arrNombrePais, 
        char **arrComentario, int &nComentarios, ifstream &archComentarios, 
        int fecha, int *arrFecha){
    int codigoPais, id, posicionPais, posicionUsuario;
    char extra;
    while(true){
        arrFecha[nComentarios] = fecha;
        archComentarios >> codigoPais >> extra >> id;
        posicionPais = buscarPais(codigoPais, arrCodigoPais, nPaises);
        posicionUsuario = buscarUsuario(codigoPais, id, arrCodigoPaisUsuario, 
                arrId, nUsuarios);
        //utilizamos las funciones de la bilbioteca cstring (longitud y copia)
        arrNombreUsuario[nComentarios] = new char [strlen(arrUsuario[posicionUsuario]) + 1];
        arrNombrePais[nComentarios] = new char [strlen(arrPais[posicionPais]) + 1];
        strcpy(arrNombreUsuario[nComentarios], arrUsuario[posicionUsuario]);
        strcpy(arrNombrePais[nComentarios], arrPais[posicionPais]);
        leerComentario(archComentarios, arrComentario, nComentarios);
        archComentarios >> arrCantidadLikes[nComentarios];
        nComentarios++;
        if(archComentarios.eof()) break;
        extra = archComentarios.get();
        if(extra == '\n') break;
    }
}

void procesarArchivoComentarios(int *arrCodigoPais, char **arrPais, int nPaises, 
        int *arrCodigoPaisUsuario, int *arrId, char **arrUsuario, int nUsuarios, 
        int *arrFecha, int *arrCantidadLikes, char **arrNombreUsuario,
        char **arrNombrePais, char **arrComentario, int &nComentarios){
    int dd, mm, yyyy, fecha;
    char extra;
    ifstream archComentarios("comentarios.txt", ios::in);
    if(not archComentarios.is_open()){
        cout << "ERROR: comentarios.txt" << endl;
        exit(1);
    }
    while(true){
        archComentarios >> dd;
        if(archComentarios.eof()) break;
        archComentarios >> extra >> mm >> extra >> yyyy;
        fecha = yyyy * 10000 + mm * 100 + dd;
        //llamada a funcion para leer la informacion del bucle de comentarios
        procesarComentarios(arrCodigoPais, arrPais, nPaises, arrCodigoPaisUsuario,
                arrId, arrUsuario, nUsuarios, arrCantidadLikes, arrNombreUsuario,
                arrNombrePais, arrComentario, nComentarios, archComentarios, 
                fecha, arrFecha);
    }
}

void leerArchivoUsuarios(int *arrCodigoPaisUsuario, int *arrId, char **arrUsuario, 
        int &nUsuarios){
    int codigoPais;
    char extra, buffer[50];
    ifstream archUsuarios("usuarios.txt", ios::in);
    if(not archUsuarios.is_open()){
        cout << "ERROR: usuarios.txt" << endl;
        exit(1);
    }
    while(true){
        archUsuarios >> codigoPais;
        if(archUsuarios.eof()) break;
        arrCodigoPaisUsuario[nUsuarios] = codigoPais;
        archUsuarios >> extra >> arrId[nUsuarios] >> buffer;
        //utilizamos las funciones de la bilbioteca cstring (longitud y copia)
        arrUsuario[nUsuarios] = new char [strlen(buffer) + 1];
        strcpy(arrUsuario[nUsuarios], buffer);
        archUsuarios.ignore(1000, '\n');
        nUsuarios++;
    }
}

void leerArchivoPaises(int *arrCodigoPais, char **arrPais, int &nPaises){
    int codigoPais;
    char buffer[50];
    ifstream archPaises("paises.txt", ios::in);
    if(not archPaises.is_open()){
        cout << "ERROR: paises.txt" << endl;
        exit(1);
    }
    while(true){
        archPaises >> codigoPais;
        if(archPaises.eof()) break;
        arrCodigoPais[nPaises] = codigoPais;
        archPaises >> buffer;
        //utilizamos las funciones de la bilbioteca cstring (longitud y copia)
        arrPais[nPaises] = new char [strlen(buffer) + 1];
        strcpy(arrPais[nPaises], buffer);
        nPaises++;
    }
}

