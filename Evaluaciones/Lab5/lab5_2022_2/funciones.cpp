/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 8 de noviembre de 2022, 20:20
 */

#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0; i <= n; i++)
        arch.put(c);
    arch.put('\n');
}

void cambiarStr(char *&cadenaI, char *&cadenaJ){
    char *aux = cadenaI;
    cadenaI = cadenaJ;
    cadenaJ = aux;
}

void cambiarD(double *arr, int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}


void cambiarI(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void imprimirResumen(ofstream &archReporte, double egresos, double total){
    archReporte << "Total de egresos por sueldos: " << egresos << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "Estado de las ganancias o perdidas" << total << endl;
    archReporte << "Recomendaciones: ";
    if(total >= 0){
        archReporte << "DEBE INVERTIR SUS GANANCIAS" << endl;
    }
    else
        archReporte << "DEBE CERRAR LA INSTITUCION" << endl;
}

void imprimirDocentes(ofstream &archReporte, struct Docente *arrDocentes, 
        int nMiembros, char *tipo, char **nombre){
    for (int i = 0; i < nMiembros; i++){
        archReporte << left << setw(10) << arrDocentes[i].codigo;
        archReporte << left << setw(40) << nombre[i];
        archReporte << left << setw(25) << arrDocentes[i].distrito;
        archReporte << left << setw(20) << arrDocentes[i].categoria;
        archReporte << left << setw(20) << arrDocentes[i].dedicacion;
        archReporte << left << setw(20) << arrDocentes[i].seccion;
        archReporte << left << setw(15) << arrDocentes[i].grado;
        archReporte << right << setw(10) << arrDocentes[i].pago << endl;
    }
    imprimirLinea('-', TAMLINEA, archReporte);
}

void imprimirCabeceraDocente(ofstream &archReporte){
    archReporte << "PAGO A LOS DOCENTES:" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << left << setw(20) << "CODIGO";
    archReporte << left << setw(30) << "NOMBRE";
    archReporte << left << setw(25) << "DISTRITO";
    archReporte << left << setw(20) << "CATEGORIA";
    archReporte << left << setw(20) << "DEDICACION";
    archReporte << left << setw(20) << "SECCION";
    archReporte << left << setw(20) << "GRADO";
    archReporte << left << setw(10) << "PAGOS" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
}

void imprimirResumenAlumno(ofstream &archReporte, double ingresos){
    archReporte << "Total de ingresos por matriculas: " << ingresos << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirAlumnos(ofstream &archReporte, char *arrTipo, int *arrCodigo, 
        char **arrNombreMiembro, char **arrNombreDistrito, char **arrEspecialidad, 
        char **arrFacultad, int *arrEscala, double *arrVCred, double *arrCredMat,
        double *arrPago, int nMiembros){
    for (int i = 0; i < nMiembros; i++){
        if(arrTipo[i] == 'A'){
            archReporte << left << setw(10) << arrCodigo[i];
            archReporte << left << setw(40) << arrNombreMiembro[i];
            archReporte << left << setw(30) << arrNombreDistrito[i];
            archReporte << left << setw(30) << arrEspecialidad[i];
            archReporte << left << setw(17) << arrFacultad[i];
            archReporte << left << setw(4) << arrEscala[i];
            archReporte << fixed << setprecision(2);
            archReporte << right << setw(10) << arrVCred[i];
            archReporte << right << setw(10) << arrCredMat[i];
            archReporte << right << setw(10) << arrPago[i] << endl;
        }
    }
    imprimirLinea('-', TAMLINEA, archReporte);
}

void imprimirCabeceraAlumno(ofstream &archReporte){
    archReporte << setw((TAMLINEA-14)/2) << "Universidad TP" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << "RECAUDACION POR MATRICULAS:" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << left;
    archReporte << setw(20) << "CODIGO";
    archReporte << setw(30) << "NOMBRE";
    archReporte << setw(30) << "DISTRITO";
    archReporte << setw(30) << "ESPECIALIDAD";
    archReporte << setw(15) << "FACULTAD";
    archReporte << setw(10) << "ESCALA";
    archReporte << setw(10) << "VCRED";
    archReporte << setw(10) << "CREDMAT";
    archReporte << setw(10) << "PAGO" << endl;
    imprimirLinea('-', TAMLINEA, archReporte);
}

void ordenarAlumnos(char *arrTipo, int *arrCodigo, char **arrNombreMiembro, 
        char **arrNombreDistrito, char **arrEspecialidad, char **arrFacultad, 
        int *arrEscala, double *arrVCred, double *arrCredMat, double *arrPago, 
        int nMiembros){
    bool validacion2, validacion2Prima, validacion3;
    for (int i = 0; i < nMiembros - 1; i++){
        for (int j = i + 1; j < nMiembros; j++){
            //validamos el orden descendente
            validacion2 = (strcmp(arrNombreDistrito[i], arrNombreDistrito[j]) < 0);
            validacion2Prima = (strcmp(arrNombreDistrito[i], arrNombreDistrito[j]) == 0);
            //validamos el orden ascendente
            validacion3 = (arrEscala[i] > arrEscala[j]);
            //validamos si debe ordenarse
            if((validacion2) or (validacion2Prima and validacion3)){
                cambiarI(arrCodigo, i, j);
                cambiarI(arrEscala, i, j);
                cambiarD(arrVCred, i, j);
                cambiarD(arrCredMat, i, j);
                cambiarD(arrPago, i, j);
                //se tiene que tener cuidado cambiando este arreglo (hay nombres
                //de alumnos y docentes)
                //cambiarStr(arrNombreMiembro)
                cambiarStr(arrNombreDistrito[i], arrNombreDistrito[j]);
                cambiarStr(arrEspecialidad[i], arrEspecialidad[j]);
                cambiarStr(arrFacultad[i], arrFacultad[j]);
            }
        }
    }
}

double calcularEgresos(struct Docente *arrDocentes, char *arrTipo, int nMiembros){
    double egresos = 0.0;
    for(int i = 0; i < nMiembros; i++){
        if(arrTipo[i] == 'D')
            egresos += arrDocentes[i].pago;
    }
    return egresos;
}

double calcularIngresos(double *arrPago, char *arrTipo, int nMiembros){
    double ingresos = 0.0;
    for(int i = 0; i < nMiembros; i++){
        if(arrTipo[i] == 'A')
            ingresos += arrPago[i];
    }
    return ingresos;
}

void leerDocente(ifstream &archMiembros, struct Docente *arrDocentes, 
        int nMiembros){
    char buffer[100];
    archMiembros >> arrDocentes[nMiembros].codigo;
    archMiembros.get();
    //utilizamos las funciones de copia y longitud de la biblioteca cstring
    archMiembros.getline(buffer, 100, ',');
    arrDocentes[nMiembros].distrito = new char[strlen(buffer) + 1];
    strcpy(arrDocentes[nMiembros].distrito, buffer);
    archMiembros.getline(buffer, 100, ',');
    arrDocentes[nMiembros].categoria = new char[strlen(buffer) + 1];
    strcpy(arrDocentes[nMiembros].categoria, buffer);
    archMiembros.getline(buffer, 100, ',');
    arrDocentes[nMiembros].dedicacion = new char[strlen(buffer) + 1];
    strcpy(arrDocentes[nMiembros].dedicacion, buffer);
    archMiembros.getline(buffer, 100, ',');
    arrDocentes[nMiembros].seccion = new char[strlen(buffer) + 1];
    strcpy(arrDocentes[nMiembros].seccion, buffer);
    archMiembros.getline(buffer, 100, ',');
    arrDocentes[nMiembros].grado = new char[strlen(buffer) + 1];
    strcpy(arrDocentes[nMiembros].grado, buffer);
    archMiembros >> arrDocentes[nMiembros].pago;
    arrDocentes[nMiembros].pago *= 8;
    archMiembros >> ws;
}

void leerAlumno(ifstream &archMiembros, int *arrCodigo, char **arrNombreDistrito, 
        char **arrEspecialidad, char **arrFacultad, int *arrEscala, 
        double *arrVCred, double *arrCredMat, int nMiembros){
    char buffer[100];
    archMiembros >> arrCodigo[nMiembros];
    archMiembros.get();
    //utilizamos las funciones de copia y longitud de la biblioteca cstring
    archMiembros.getline(buffer, 100, ',');
    arrNombreDistrito[nMiembros] = new char[strlen(buffer) + 1];
    strcpy(arrNombreDistrito[nMiembros], buffer);
    archMiembros.getline(buffer, 100, ',');
    arrEspecialidad[nMiembros] = new char[strlen(buffer) + 1];
    strcpy(arrEspecialidad[nMiembros], buffer);
    archMiembros.getline(buffer, 100, ',');
    arrFacultad[nMiembros] = new char[strlen(buffer) + 1];
    strcpy(arrFacultad[nMiembros], buffer);
    archMiembros >> arrEscala[nMiembros];
    archMiembros.get();
    archMiembros >> arrVCred[nMiembros];
    archMiembros.get();
    archMiembros >> arrCredMat[nMiembros];
    archMiembros >> ws;
}

void leerNombre(ifstream &archMiembros, char **arrNombreMiembro, int nMiembros){
    char apellidoPaterno[50], apellidoMaterno[50], nombres[100];
    archMiembros.getline(apellidoPaterno, 50, '/');
    archMiembros.getline(apellidoMaterno, 50, '/');
    archMiembros.getline(nombres, 50, ',');
    arrNombreMiembro[nMiembros] = new char[strlen(nombres) + strlen(apellidoPaterno)
            + strlen(apellidoMaterno) + 1 + 1 + 1];
    //utilizamos las funciones de la bibilioteca cstring para copiar y 
    //concatenar cadenas
    strcpy(arrNombreMiembro[nMiembros], nombres);
    strcat(arrNombreMiembro[nMiembros], " ");
    strcat(arrNombreMiembro[nMiembros], apellidoPaterno);
    strcat(arrNombreMiembro[nMiembros], " ");
    strcat(arrNombreMiembro[nMiembros], apellidoMaterno);
}


