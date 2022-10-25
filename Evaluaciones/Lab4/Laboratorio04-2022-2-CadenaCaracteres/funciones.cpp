/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 24 de octubre de 2022, 16:20
 */

#include "funciones.hpp"
#include "cadenas.hpp"

void imprimirLinea(char c, int n, ofstream &archReporte){
    for(int i = 0; i <= n; i++)
        archReporte.put(c);
    archReporte.put('\n');
}

void buscarUsuario(ifstream &archUsuarios, int codB, int idB, 
        char *strUsuario){
    int cod, id;
    char extra;
    archUsuarios.clear();
    archUsuarios.seekg(0, ios::beg);
    while(true){
        archUsuarios >> cod;
        if(archUsuarios.eof()) break;
        archUsuarios >> extra >> id;
        //verificamos que hayamos leido el usuario que buscamos
        if(cod == codB and id == idB){
            archUsuarios >> strUsuario;
            break;
        }
        else{
            archUsuarios.ignore(1000, '\n');
            archUsuarios >> ws;
        }
    }
}

void imprimirAutor2(ofstream &archReporte, ifstream &archUsuarios, int codP,
        int id){
    int longitud;
    char strUsuario[MAXCAR], strCopia[MAXCAR];
    //llamada a funcion que busca el usuario y lo almacena en una cadena
    buscarUsuario(archUsuarios, codP, id, strUsuario);
    //llamada a funcion para quitar el @ de la cadena y colocar mayusculas
    transformarUsuario(strUsuario);
    //llamada a funcion para conteo de caracteres de la biblioteca cstring
    longitud = strlen(strUsuario);
    archReporte << setw(20) << strUsuario << setw(10) << longitud << endl;    
}

void imprimirComentario2(ofstream &archReporte, char *strComentario){
    int longitud;
    char strCopia[MAXCAR];
    //llamada a funcion de copia de la biblioteca cstring
    strcpy(strCopia, strComentario);
    //llamada a funcion que quita los espacios de la cadena y coloca mayusculas
    quitarEspacios(strCopia);
    //llamada a funcion que cuenta caracteres de la biblioteca cstring
    longitud = strlen(strCopia);
    archReporte << left << setw(130) << strCopia << setw(12) << longitud;
}

void imprimirAutor1(ofstream &archReporte, ifstream &archUsuarios, int codP,
        int id){
    int longitud;
    char strUsuario[MAXCAR];
    //llamada a funcion que busca el usuario y lo almacena en una cadena
    buscarUsuario(archUsuarios, codP, id, strUsuario);
    //llamada a funcion para conteo de caracteres de la biblioteca cstring
    longitud = strlen(strUsuario);
    archReporte << setw(10) << strUsuario << setw(10) << longitud;
}

void imprimirComentario1(ofstream &archReporte, char *strComentario){
    int longitud;
    char strCopia[MAXCAR];
    //llamada a funcion de copia de la biblioteca cstring
    strcpy(strCopia, strComentario);
    //llamada a funcion que quita los espacios de la cadena
    quitarGuiones(strCopia);
    //llamada a funcion de longitud de caracteres de la biblioteca cstring
    longitud = strlen(strCopia);
    archReporte << left << setw(130) << strCopia << setw(10) << longitud;
}

void leerComentarios(ofstream &archReporte, ifstream &archComentarios, 
        ifstream &archUsuarios){
    int codP, id, nLikes;
    char strComentario[MAXCAR];
    char extra;
    while(true){
        archComentarios >> codP >> extra >> id >> strComentario >> nLikes;
        //llamada a funcion que imprime el comentario sin guiones y su longitud
        imprimirComentario1(archReporte, strComentario);
        //llamada a funcion que busca el usuario y lo imprime
        imprimirAutor1(archReporte, archUsuarios, codP, id);
        /* llamada a funcion que imprime el comentario sin espacios y con 
         * mayusculas */
        imprimirComentario2(archReporte, strComentario);
        imprimirAutor2(archReporte, archUsuarios, codP, id);
        extra = archComentarios.get();
        if(extra == '\n') break;
    }
}

void imprimirCabeceraTikTok(ofstream &archReporte, int dd, int mm, int yyyy){
    char extra = '/';
    archReporte.fill('0');
    archReporte << "Fecha del TikTok: " << setw(2) << dd << extra << setw(2)
            << mm << extra << yyyy << endl << endl;
    archReporte.fill(' ');
    archReporte << left << setw(130) << "Comentario" << setw(10) << "Long" << 
            setw(10) << "Autor" << setw(10) << "Long" << setw(130) << 
            "Transformacion 1" << setw(10) << "Long" << setw(20) << 
            "Transformacion 2" << setw(10) << "Long" << endl;
    //llamada a funcion que imprime una linea de -
    imprimirLinea('-', TAMLINEA, archReporte);
}

void procesarComentarios(ofstream &archReporte, ifstream &archComentarios, 
        ifstream &archUsuarios){
    int dd, mm, yyyy;
    char extra;
    while(true){
        archComentarios >> dd;
        if(archComentarios.eof()) break;
        archComentarios >> extra >> mm >> extra >> yyyy;
        //llamada a funcion que imprime la cabecera de cada tik tok
        imprimirCabeceraTikTok(archReporte, dd, mm, yyyy);
        //llamada a funcion que lee cada comentario y lo imprime
        leerComentarios(archReporte, archComentarios, archUsuarios);
        imprimirLinea('=', TAMLINEA, archReporte);
    }
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(165) << " " << "@TikTok_tp" << endl;
    //llamada a funcion para imprimir una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
}

void procesarReporte(){
    //declaramos los archivos de texto
    ifstream archComentarios("Comentarios.txt", ios::in);
    if(not archComentarios.is_open()){
        cout << "ERROR: Comentarios.txt" << endl;
        exit(1);
    }
    ifstream archUsuarios("Usuarios.txt", ios::in);
    if(not archUsuarios.is_open()){
        cout << "ERROR: Usuarios.txt" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    //llamada a funcion para imprimir la cabecera del reporte
    imprimirCabecera(archReporte);
    //llamada a funcion que lee e imprime los comentarios y sus transformaciones
    procesarComentarios(archReporte, archComentarios, archUsuarios);
}