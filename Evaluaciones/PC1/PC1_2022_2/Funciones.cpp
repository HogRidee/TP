/* 
 * File  :  Funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 14 de septiembre de 2022, 14:53
 */

using namespace std;

#include "Funciones.hpp"

char convertirMayuscula(char caracter){
    if(caracter >= 'a' and caracter <= 'z'){
        caracter = caracter - ('a' - 'A');
    }
    return caracter;
}

void imprimirResumen(ofstream &archReporte, int ddI, int ddF, int mmI, int mmF,
        int yyyyI, int yyyyF, int contador, int tiempoLlovidoTotal, 
        double totalLlovido, double maxLluvia, int ddL, int mmL, int yyyyL){
    char slash = '/', dosPuntos = ':';
    archReporte << endl << "RESUMEN:" << endl;
    archReporte << setw(4) << " " << "Fecha incial: ";
    archReporte.fill('0');
    archReporte << setw(2) << ddI << slash << setw(2) << mmI << slash <<
            yyyyI;
    archReporte.fill(' ');
    archReporte << setw(4) << " " << "Fecha final: ";
    archReporte.fill('0');
    archReporte << setw(2) << ddF << slash << setw(2) << mmF << slash <<
            yyyyF << endl;
    archReporte.fill(' ');
    archReporte << setw(4) << " " << "Cantidad de dias registrados: " << setw(10)
            << " " << contador << endl;
    archReporte << setw(4) << " " << "Tiempo total de lluvia: " << setw(10) << " ";
    archReporte.fill('0');
    archReporte << setw(2) << tiempoLlovidoTotal/3600 << dosPuntos << setw(2) <<
            tiempoLlovidoTotal%3600/60 << dosPuntos << setw(2) << 
            tiempoLlovidoTotal%3600%60 << " horas" << endl;
    archReporte.fill(' ');
    archReporte << setw(4) << " " << "Total llovido en el periodo: " << setw(5)
            << " ";
    archReporte.fill('0');
    archReporte << fixed << setprecision(2) << totalLlovido << " mm" << endl;
    archReporte.fill(' ');
    archReporte << setw(4) << " " << "En la fecha ";
    archReporte.fill('0');
    archReporte << setw(2) << ddL << slash << setw(2) << mmL << slash << yyyyL
            << " se obtuvo la mayor precipitacion, con " << fixed << setprecision(2)
            << maxLluvia << " mm" << endl << endl;
    archReporte.fill(' ');
}

int calcularTiempoLlovido(int hhI, int minI, int ssI, int hhF, int minF, int ssF){
    int tiempoSegundosInicio, tiempoSegundosFinal, tiempoLlovidoSegundos;
    tiempoSegundosInicio = hhI * 3600 + minI * 60 + ssI;
    tiempoSegundosFinal = hhF * 3600 + minF * 60 + ssF;
    tiempoLlovidoSegundos = tiempoSegundosFinal - tiempoSegundosInicio;
}
//esta función debe revisarse (tiene demasiadas líneas)
void imprimirReporte(ifstream &archLectura, ofstream &archReporte){
    int dd, mm, yyyy, hhI, minI, ssI, hhF, minF, ssF, tiempoLlovido, contador = 0;
    int ddI, mmI, yyyyI, ddF, mmF, yyyyF, tiempoLlovidoTotal = 0;
    int ddL, mmL, yyyyL;
    double cantidadLlovida, totalLlovido = 0.0, maxLluvia = 0.0;
    char slash, dosPuntos, comprobar;
    while(true){
        archLectura >> dd >> slash >> mm >> slash >> yyyy;
        archReporte << archReporte.fill('0') << setw(2) << dd << slash << setw(2) 
                << mm << slash << yyyy << "    ";
        archLectura >> hhI >> dosPuntos >> minI >> dosPuntos >> ssI;
        archLectura >> hhF >> dosPuntos >> minF >> dosPuntos >> ssF;
        tiempoLlovido = calcularTiempoLlovido(hhI, minI, ssI, hhF, minF, ssF);
        tiempoLlovidoTotal += tiempoLlovido;
        archReporte << setw(2) << tiempoLlovido/3600 << dosPuntos << setw(2) << 
                tiempoLlovido%3600/60 << dosPuntos << setw(2) << 
                tiempoLlovido%3600%60;
        archReporte.fill(' ');
        archLectura >> cantidadLlovida;
        if(cantidadLlovida > maxLluvia){
            maxLluvia = cantidadLlovida;
            ddL = dd;
            mmL = mm;
            yyyyL = yyyy;
        }
        archReporte << setw(11) << " " << right << setw(7)  << fixed << setprecision(2) 
                << cantidadLlovida<< endl;
        totalLlovido += cantidadLlovida;
        if(contador == 1){
            ddI = dd;
            mmI = mm;
            yyyyI = yyyy;
        }
        else{
            ddF = dd;
            mmF = mm;
            yyyyF = yyyy;
        }
        contador++;
        comprobar = archLectura.get();
        if(comprobar == '\n') break;
        archLectura >> ws;
    }
    imprimirResumen(archReporte, ddI, ddF, mmI, mmF, yyyyI, yyyyF, contador, 
            tiempoLlovidoTotal, totalLlovido, maxLluvia, ddL, mmL, yyyyL);
}

void imprimirFrase(ifstream &archLectura, ofstream &archReporte, char parada){
    char caracter;
    while(true){
        caracter = archLectura.get();
        if(caracter == parada){
            archReporte << endl;
            break;
        }
        caracter = convertirMayuscula(caracter);
        archReporte.put(caracter);
    }
}

void imprimirCabecera(ifstream &archLectura, ofstream &archReporte, 
        int contadorEstaciones){
    archReporte << "ESTACION No. " << contadorEstaciones << endl << endl;
    archReporte << "Nombre:";
    imprimirFrase(archLectura, archReporte, ',');
    archReporte << "Ciudad:";
    imprimirFrase(archLectura, archReporte, ',');
    archReporte << "Region:";
    imprimirFrase(archLectura, archReporte, ':');
    archReporte << endl << setw(4) << " " << "Fecha" << setw(4) << " " 
            << "Tiempo llovido" << setw(4) << " " << "Cantidad llovida" << endl;
    
}

void leerImprimirArchivos(ifstream &archLectura, ofstream &archReporte){
    int contadorEstaciones;
    archReporte << setw(20) << " " << "INFORME DE PRECIPITACIONES" << endl;
    while(true){
        archLectura >> contadorEstaciones;
        if(archLectura.eof()) break;
        imprimirCabecera(archLectura, archReporte, contadorEstaciones);
        imprimirReporte(archLectura, archReporte);
    }
}

