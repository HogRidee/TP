/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 31 de octubre de 2022, 13:38
 */

#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &archReporte){
    for(int i = 0; i <= n; i++){
        archReporte.put(c);
    }
    archReporte.put('\n');
}

double buscarEscala(char **arrEscala, double *arrCreditos, char *escala, 
        int nEscalas){
    int posicion = 0;
    for(posicion; posicion < nEscalas; posicion++){
        if(strcmp(arrEscala[posicion], escala) == 0)
            return arrCreditos[posicion];
    }
}

double buscarCreditos(char *codigo, char **arrCodCurso, double *arrCredCurso, 
        int nCursos){
    for(int i = 0; i < nCursos; i++){
        if(strcmp(arrCodCurso[i], codigo) == 0){
            return arrCredCurso[i];
        }
    }
}

double contarCreditos(ifstream &archMatricula, char **arrCodCurso, 
        double *arrCredCurso, int nCursos){
    double creditos;
    double nCreditos = 0.0;
    char codigo[10], extra;
    //A PARTIR DE AQUI EN C++ NO SE PUEDE CONTINUAR SIN GETS
    while(true){
        archMatricula >> codigo;
        creditos = buscarCreditos(codigo, arrCodCurso, arrCredCurso, nCursos);
        nCreditos += creditos;
        extra = archMatricula.get();
        if(extra == '\n') break;
        if(archMatricula.eof()) break;
    }
    return nCreditos;
}

void imprimirCabeceraBoletas(ofstream &archReporte, int nCuotas){
    archReporte << setw(14) << "Boletas:" << setw(13) << "1" << setw(13) << "2"
            << setw(13) << "3" << setw(13) << "4" << setw(13) << "5";
    if(nCuotas == 6){
        archReporte << setw(13) << "6";
    }
    else{
        archReporte << setw(13) << " ";
    }
    archReporte << setw(5) << " " << "TOTAL" << endl;
}

int calcularNumeroCuotas(char *escala){
    if(escala[1] == '1'){
        return 5;
    }
    else
        return 6;
}

void imprimirCabeceraAlumno(ofstream &archReporte, int nAlumnos, int codAlumno, 
        char *nombreAlumno, char *escala){
    archReporte << right << setw(2) << nAlumnos << ") Nombre" << setw(40) << " " << 
            "Codigo" << setw(10) << " " << "Escala" << endl;
    archReporte << left << setw(4) << " " << setw(45) << nombreAlumno << codAlumno <<
            setw(10) << " " << escala << endl;
    //llamada a funcion para imprimir una linea de -
    imprimirLinea('-', TAMLINEA, archReporte);
}

void leerLineaMatricula(ifstream &archMatricula, int &codAlumno, 
        char *&nombreAlumno, char *&escala){
    char buffer[200];
    archMatricula >> codAlumno;
    if(archMatricula.eof()) return;
    archMatricula.get();
    archMatricula.getline(buffer, 200, ',');
    //utilizacion de funciones de la biblioteca cstring (copia y longitud)
    nombreAlumno = new char[strlen(buffer) + 1];
    strcpy(nombreAlumno, buffer);
    archMatricula.getline(buffer, 200, ',');
    //utilizacion de funciones de la biblioteca cstring (copia y longitud)
    escala = new char[strlen(buffer) + 1];
    strcpy(escala, buffer);
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << setw(53) << " " << "INSTITUTO ABC" << endl;
    archReporte << setw(48) << " " << "Rol de pago de pensiones" << endl;
    //llamada a funcion para imprimir una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
}

void procesarMatricula(char **arrEscala, double *arrCreditos, int nEscalas, 
        char **arrCodCurso, double *arrCredCurso, int nCursos){
    int nAlumnos = 1, codAlumno, nCuotas;
    double precioCredito, nCreditos;
    char *nombreAlumno, *escala;
    ifstream archMatricula("Matricula.csv", ios::in);
    if(not archMatricula.is_open()){
        cout << "ERROR: Matricula.csv" << endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    //llamada a funcion para imprimir la cabecera del reporte
    imprimirCabecera(archReporte);
    while(true){
        if(archMatricula.eof()) break;
        //llamada a funcion que lee la linea hasta escala
        leerLineaMatricula(archMatricula, codAlumno, nombreAlumno, escala);
        //llamadaa funcion para imprimir la informacion del alumno
        imprimirCabeceraAlumno(archReporte, nAlumnos, codAlumno, nombreAlumno, 
                escala);
        //llamada a funcion para calcular en cuantas cuotas dividiremos el monto
        nCuotas = calcularNumeroCuotas(escala);
        //llamada a funcion para imprimir el n de boletas
        imprimirCabeceraBoletas(archReporte, nCuotas);
        //llamada a funcion de busqueda del precio del credito para el alumno
        precioCredito = buscarEscala(arrEscala, arrCreditos, escala, nEscalas);
        nCreditos = contarCreditos(archMatricula, arrCodCurso, arrCredCurso, 
                nCursos);
        cout << nCreditos << endl;
        nAlumnos++;
    }
}

void leerLineaCurso(ifstream &archCursos, char *&codigo, double &creditos){
    char buffer[80];
    archCursos.getline(buffer, 10, ',');
    if(archCursos.eof()) return;
    //utilizacion de funciones de la biblioteca cstring (copia y longitud)
    codigo = new char[strlen(buffer) + 1];
    strcpy(codigo, buffer);
    archCursos.getline(buffer, 80, ',');
    archCursos >> creditos;
    archCursos >> ws;
}

void leerCursos(char **arrCodCurso, double *arrCredCurso, int &nCursos){
    double creditos;
    char *codigo;
    ifstream archCursos("Cursos.csv", ios::in);
    if(not archCursos.is_open()){
        cout << "ERROR: Cursos.csv" << endl;
        exit(1);
    }
    while(true){
        if(archCursos.eof()) break;
        //llamada a funcion para leer 1 linea del archivo csv
        leerLineaCurso(archCursos, codigo, creditos);
        arrCodCurso[nCursos] = codigo;
        arrCredCurso[nCursos] = creditos;
        nCursos++;
    }
}

void leerLineaEscala(ifstream &archEscalas, char *&escala, double &creditos){
    char buffer[5];
    archEscalas.getline(buffer, 5, ' ');
    if(archEscalas.eof()) return;
    //utilizamos la biblioteca cstring para obtener longitud y copiar cadenas
    escala = new char[strlen(buffer) + 1];
    strcpy(escala, buffer);
    archEscalas >> creditos;
    archEscalas >> ws;
}

void leerEscalas(char **arrEscala, double *arrCreditos, int &nEscalas){
    double creditos;
    char *escala;
    ifstream archEscalas("Escalas.txt", ios::in);
    if(not archEscalas.is_open()){
        cout << "ERROR: Escalas.txt" << endl;
        exit(1);
    }
    while(true){
        if(archEscalas.eof()) break;
        //llamada a funcion para leer una linea del archivo
        leerLineaEscala(archEscalas, escala, creditos);
        arrEscala[nEscalas] = escala;
        arrCreditos[nEscalas] = creditos;
        nEscalas++;
    }
}