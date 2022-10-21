/* 
 * File  :  Funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 18 de octubre de 2022, 19:26
 */

#include "Funciones.hpp"

//Rango de fechas para pruebas: 15/03/2022 03/10/2022

int convertirFecha(int dd, int mm, int yyyy){
    int fecha;
    fecha = yyyy * 10000 + mm * 100 + dd;
    return fecha;
}

int buscarPosicion(int *arr, int buscado, int nElementos){
    for(int i = 0; i < nElementos; i++){
        if(arr[i] == buscado)
            return i;
    }
    return NOENCONTRADO;
}

int buscarUsuario(int *arrCod, int *arrId, int codP, int id, int nUsuarios){
    for(int i = 0; i < nUsuarios; i++){
        if((arrCod[i] == codP) and (arrId[i] == id))
            return i;
    }
    return NOENCONTRADO;
}

void desconvertirFecha(int fecha, int &dd, int &mm, int &yyyy){
    dd = fecha % 100;
    fecha = fecha / 100;
    mm = fecha % 100;
    yyyy = fecha / 100;
}

void imprimirLinea(char c, int tam, ofstream &archReporte){
    for(int i = 0; i <= tam; i++){
        archReporte.put(c);
    }
    archReporte.put('\n');
}

void cambiarI(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarD(double *arr, int i, int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiarB(bool *arr, int i, int j){
    bool aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void imprimirResumen(ofstream &archReporte, bool *arrViral, int nTikToks){
    int nVirales = 0, nNoVirales = 0;
    archReporte << "RESUMEN" << endl;
    for(int i = 0; i < nTikToks; i++){
        if(arrViral[i])
            nVirales++;
        else
            nNoVirales++;
    }
    archReporte << left << setw(20) << "CANTIDAD VIRALES:" << right << setw(10) 
            << nVirales << endl;
    archReporte << left << setw(20) << "CANTIDAD NO VIRALES:" << right << setw(10)
            << nNoVirales << endl;
}

void ordenarArreglos(int *arrFechas, int *arrCantComentarios, 
        int *arrCantLikes, int *arrCantReproducciones, double *arrRatio, 
        bool *arrViral, int *arrCantSeguidoresPublicos, int nTikToks){
    //esta funcion deberia ser definida abajo de las funciones de impresion
    for(int i = 0; i < nTikToks - 1; i++){
        for(int j = i + 1; j < nTikToks; j++){
            if((arrCantReproducciones[j] > arrCantReproducciones[i]) or 
                    (arrCantReproducciones[j] == arrCantReproducciones[i]) and
                    (arrFechas[j] < arrFechas[i]){
                cambiarI(arrFechas, i, j);
                cambiarI(arrCantComentarios, i, j);
                cambiarI(arrCantLikes, i, j);
                cambiarI(arrCantReproducciones, i, j);
                cambiarI(arrCantSeguidoresPublicos, i, j);
                cambiarD(arrRatio, i, j);
                cambiarB(arrViral, i, j);
            }
        }
    }
}

void imprimirDetallado(ofstream &archReporte, int *arrFechas, int *arrCantComentarios, 
        int *arrCantLikes, int *arrCantReproducciones, double *arrRatio, 
        bool *arrViral, int *arrCantSeguidoresPublicos, int nTikToks){
    int dd, mm, yyyy;
    char slash = '/';
    for(int i = 0; i < nTikToks; i++){
        //llamada a funcion para obtener la fecha actual
        desconvertirFecha(arrFechas[i], dd, mm, yyyy);
        archReporte.fill('0');
        archReporte << setw(2) << dd << slash << right << setw(2) << mm << slash << yyyy;
        archReporte.fill(' ');
        archReporte << right << setw(11) << arrCantComentarios[i] << setw(20) << 
                arrCantLikes[i] << setw(17) << arrCantReproducciones[i];
        archReporte << fixed;
        archReporte << setw(15) << setprecision(2) << arrRatio[i];
        if(arrViral[i]){
            archReporte << setw(12) << " " << "Si" << setw(6) << " ";
        }
        else{
            archReporte << setw(12) << " " << "No" << setw(6) << " ";
        }
        archReporte << setw(7) << arrCantSeguidoresPublicos[i] << endl;
    }
    //llamada a funcion para imprimir una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirCabecera(ofstream &archReporte, int fechaI, int fechaF){
    int ddI, mmI, yyyyI, ddF, mmF, yyyyF;
    char slash = '/';
    archReporte << setw(47) << " " << "@TikTok_tp" << endl;
    archReporte << setw(32) << " " << "REPORTE PARA LA CAMPAÑA : PARCIAL 2022-2"
            << endl;
    desconvertirFecha(fechaI, ddI, mmI, yyyyI);
    desconvertirFecha(fechaF, ddF, mmF, yyyyF);
    archReporte << setw(28) << " " << "Fecha Inicial: ";
    archReporte.fill('0');
    archReporte << setw(2) << ddI << slash << setw(2) << mmI << slash << yyyyI
            << " Fecha Final: " << setw(2) << ddF << slash << setw(2) << mmF << 
            slash << yyyyF << endl;
    archReporte.fill(' ');
    //llamada a funcion que imprime una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
    archReporte << left << setw(15) << "Fecha del " << setw(15) << "Cantidad de"
            << setw(20) << "Cantidad de Likes" << setw(15) << "Cantidad de " << 
            setw(17) << "Ratio de" << setw(13) << "Es viral?" << setw(15) << 
            "Cantidad de " << endl;
    archReporte << left << setw(15) << "TikTok" << setw(15) << "Comentarios" << 
            setw(20) << "de comentarios" << setw(15) << "Reproducciones" << 
            setw(17) << "Comentarios" << setw(13) << " " << setw(15) << 
            "seguidores publicos" << endl;
    //llamada a funcion que imprime una linea de -
    imprimirLinea('-', TAMLINEA, archReporte);
}

void calcularViralidad(int *arrFechas, int *arrCantReproducciones, int *arrCantLikes, 
        double *arrRatio, bool *arrViral, int nTikToks, int *arrCantComentarios){
    double ratio;
    for(int i = 0; i < nTikToks; i++){
        ratio = arrCantReproducciones[i]/(arrCantLikes[i]*100.0);
        arrRatio[i] = ratio;
        if(arrCantComentarios[i] > ratio)
            arrViral[i] = true;
        else
            arrViral[i] = false;
    }
}

void procesarComentarios2(int *arrCantComentarios, int *arrCantLikes,
        int *arrCantSeguidoresPublicos, int *arrCod, int *arrId, bool *arrPublico,
        int nUsuarios, int posicion, ifstream &archComentarios){
    int codP, id, likes, nComentarios = 0, nLikesT = 0, posicionUsuario;
    char extra;
    while(true){
        archComentarios >> codP >> extra >> id;
        archComentarios >> ws;
        archComentarios.ignore(1000,' ');
        archComentarios >> likes;
        //llamada a funcion para buscar la posicion del usuario
        posicionUsuario = buscarUsuario(arrCod, arrId, codP, id, nUsuarios);
        //verificamos si existe el usuario
        if(posicionUsuario >= 0){
            if(arrPublico[posicionUsuario])
                arrCantSeguidoresPublicos[posicion]++;
        }
        nComentarios++;
        nLikesT += likes;
        //if(archComentarios.eof())break; 
        extra = archComentarios.get();
        if(extra == '\n') break;
    }
    arrCantComentarios[posicion] += nComentarios;
    arrCantLikes[posicion] += nLikesT;
}

void procesarComentarios(int *arrFechas, int *arrCantComentarios, int *arrCantLikes,
        int *arrCantSeguidoresPublicos, int *arrCod, int *arrId, 
        bool *arrPublico, int nTikToks, int nUsuarios){
    int dd, mm, yyyy, fecha, posicion;
    bool validacion1, validacion2, validacion3, validacion4, superValidacion;
    char extra;
    ifstream archComentarios("comentarios.txt", ios::in);
    if(not archComentarios.is_open()){
        cout << "ERROR: comentarios.txt" << endl;
        exit(1);
    }
    while(true){
        archComentarios >> dd;
        if(archComentarios.eof())break;
        archComentarios >> extra >> mm >> extra >> yyyy;
        fecha = convertirFecha(dd, mm, yyyy);
        //llamada a funcion para buscar la posicion de la fecha leida
        posicion = buscarPosicion(arrFechas, fecha, nTikToks);
        //verificamos si la fecha existe en nuestro arreglo
        if(posicion >= 0){
            //llamada a funcion que recorre los comentarios
            procesarComentarios2(arrCantComentarios, arrCantLikes, 
                    arrCantSeguidoresPublicos, arrCod, arrId, arrPublico, 
                    nUsuarios, posicion, archComentarios);
        }
        else{
            //verificamos que el archivo no termine mientras ignoramos una linea
            while(true){
                extra = archComentarios.get();
                validacion1 = extra >= '/' and extra <= '9';
                validacion2 = extra >= 'A' and extra <= 'Z';
                validacion3 = extra >= 'a' and extra <= 'z';
                validacion4 = extra == ' ';
                superValidacion = validacion1 or validacion2 or validacion3 or
                        validacion4;
                if(not superValidacion) break;
            }
            if(extra!='\n')break;
        }
    }
}

void leerUsuarios(int *arrCod, int *arrId, bool *arrPublico, int &nUsuarios){
    int codP, nSeguidores;
    char extra, esPublico;
    ifstream archUsuarios("usuarios.txt", ios::in);  
    if(not archUsuarios.is_open()){
        cout << "ERROR: usuarios.txt" << endl;
        exit(1);
    }
    while(true){
        archUsuarios >> codP;
        if(archUsuarios.eof()) break;
        arrCod[nUsuarios] = codP;
        archUsuarios >> extra >> arrId[nUsuarios];
        archUsuarios >> ws;
        archUsuarios.ignore(100, ' ');
        archUsuarios >> nSeguidores >> esPublico;
        if(esPublico == 'V')
            arrPublico[nUsuarios] = true;
        else
            arrPublico[nUsuarios] = false;
        nUsuarios++;
    }
}

void verificarRepetidos(int *arrFechas, int *arrCantReproducciones, int fecha,
                    int nReproducciones, int &nTikToks){
    int posicion;
    //llamada a funcion para buscar la posicion de la fecha
    posicion = buscarPosicion(arrFechas, fecha, nTikToks);
    //verificamos si existe un dato para evitar repetidos
    if(posicion >= 0){
        arrCantReproducciones[posicion] += nReproducciones;
    }
    else{
        arrFechas[nTikToks] = fecha;
        arrCantReproducciones[nTikToks] = nReproducciones;
        nTikToks++;
    }
}

void leerTikToks(int fechaI, int fechaF, int *arrFechas, int *arrCantReproducciones, 
        int &nTikToks){
    int dd, mm, yyyy, fecha, nLikes, nReproducciones;
    char slash;
    ifstream archTikToks("TikToks.txt", ios::in);
    if(not archTikToks.is_open()){
        cout << "ERROR: TikToks.txt" << endl;
        exit(1);
    }
    while(true){
        archTikToks >> dd;
        if(archTikToks.eof()) break;
        archTikToks >> slash >> mm >> slash >> yyyy;
        //llamada a funcion que convierte la fecha en entero
        fecha = convertirFecha(dd, mm, yyyy);
        if(fecha >= fechaI and fecha <= fechaF){
            archTikToks >> nLikes >> nReproducciones;
            //llamada a funcion que verifica si hay repetidos e inserta
            verificarRepetidos(arrFechas, arrCantReproducciones, fecha,
                    nReproducciones, nTikToks);
        }
        else{
            archTikToks.ignore(1000, '\n');
            archTikToks >> ws;
        }
    }
}

void leerRangoFechas(int &fechaI, int &fechaF){
    int ddI, ddF, mmI, mmF, yyyyI, yyyyF;
    char slash;
    cout << "Por favor ingrese el rango de fechas en el formato dd/mm/yyyy:" 
            << endl;
    cin >> ddI >> slash >> mmI >> slash >> yyyyI >> ddF >> slash >> mmF >> slash
            >> yyyyF;
    //llamada a funcion que convierte la fecha en entero
    fechaI = convertirFecha(ddI, mmI, yyyyI);
    fechaF = convertirFecha(ddF, mmF, yyyyF);
}