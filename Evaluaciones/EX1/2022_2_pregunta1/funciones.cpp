/* 
 * File  :  funciones.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 17 de octubre de 2022, 17:02
 */
#include "funciones.hpp"

// Rango de prueba: 15/03/2022 03/10/2022

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0; i <= n; i++){
        arch.put(c);
    }
    arch.put('\n');
}

int convertirFecha(int dd, int mm, int yyyy){
    return yyyy * 10000 + mm * 100 + dd;
}

void desconvertirFecha(int fecha, int &dd, int &mm, int &yyyy){
    dd = fecha % 100;
    fecha = fecha / 100;
    mm = fecha % 100;
    yyyy = fecha / 100;
}

void imprimirCadena(ofstream &archReporte, ifstream &arch){
    int contador = 0;
    char c;
    arch >> ws;
    while(true){
        c = arch.get();
        if(c == ' ') break;
        archReporte.put(c);
        contador++;
    }
    for(int i = 0; i < 25-contador; i++){
        archReporte.put(' ');
    }
}

void imprimirMejorTikTok(ofstream &archReporte, ifstream &archUsuarios, 
        int mayorFecha, int cod, int id){
    int dd, mm, yyyy;
    bool extra;
    char slash = '/';
    //llamada a funcion que descompone la fecha
    desconvertirFecha(mayorFecha, dd, mm, yyyy);
    archReporte << endl << "RESUMEN MEJOR TIKTOK" << endl << "FECHA : " 
            << setw(5) << " ";
    archReporte.fill('0');
    archReporte << setw(2) << dd << slash << setw(2) << mm << slash << yyyy 
            << endl;
    archReporte.fill(' ');
    archReporte << "Seguidos que obtuvo mayor numero de likes: " << setw(5)
            << " ";
    //llamada a funcion que imprime el usuario con mas likes
    buscarUsuario(archReporte, archUsuarios, cod, id, extra);
    archReporte.put('\n');
    //llamada a funcion que imprime una linea de =
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirResumen(ofstream &archReporte, int nLikesT, int nReproducciones, 
        int nComentarios, int sPublicos, int sPrivados, double &ratioV){
    double ratio;
    bool viral;
    imprimirLinea('-', TAMLINEA, archReporte);
    archReporte << "RESUMEN TIKTOK" << setw(10) << " " << "Likes: " << nLikesT
            << setw(10) << " " << "Reproducciones: " << nReproducciones << endl;
    archReporte << "Cantidad comentarios: " << nComentarios << endl;
    archReporte << "Seguidores Publicos: " << sPublicos << endl;
    archReporte << "Seguidores Privados: " << sPrivados << setw(35) << " ";
    ratio = nReproducciones/(double)nLikesT * 100;
    viral = nComentarios > ratio;
    if(viral)
        archReporte << "TIKTOK VIRAL" << endl;
    else
        archReporte << "TIKTOK NO VIRAL" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
    ratioV = ratio;
}

void imprimirPais(ofstream &archReporte, ifstream &archPaises, int codPais){
    int cod;
    char c;
    archPaises.clear();
    archPaises.seekg(0, ios::beg);
    while(true){
        archPaises >> cod;
        if(archPaises.eof()) break;
        //verificamos el pais que buscamos
        if(cod == codPais){
            while(true){
                c = archPaises.get();
                if(c == '\n') break;
                if(archPaises.eof()) break;
                archReporte.put(c);
            }
        }
        else{
            archPaises.ignore(1000, '\n');
            archPaises >> ws;
        }
    }
    archReporte.put('\n');
}

void buscarUsuario(ofstream &archReporte, ifstream &archUsuarios, int codPaisB, 
        int idB, bool &esPublica){
    int codP, id, nSeguidores;   
    char extra, verificador;
    archUsuarios.clear();
    archUsuarios.seekg(0, ios::beg);
    while(true){
        archUsuarios >> codP;
        if(archUsuarios.eof()) break;
        archUsuarios >> extra >> id;
        if(codP == codPaisB and idB == id){
            //llamada a funcion que imprime el usuario
            imprimirCadena(archReporte, archUsuarios);
            archUsuarios >> nSeguidores >> verificador;
            if(verificador == 'V') 
                esPublica = true;
            else 
                esPublica = false;
            break;
        }
        else{
            archUsuarios.ignore(1000, '\n');
            archUsuarios >> ws;
        }
    }
}

void procesarComentarios(ofstream &archReporte, ifstream &archComentarios, 
        ifstream &archPaises, ifstream &archUsuarios, int &nComentarios, 
        int &nPublicos, int &nPrivados, int &mayorLike, int &codD,
        int &identificadorD){
    int codPais, id, nLikesComentario;
    bool esPublica;
    char extra;
    while(true){
        archComentarios >> codPais >> extra >> id;
        //llamada a funcion que imprime el comentario del usuario
        imprimirCadena(archReporte, archComentarios);
        nComentarios++;
        archComentarios >> nLikesComentario;
        //llamada a funcion que buscar e imprime al usuario y verifica si su cuenta es publica
        buscarUsuario(archReporte, archUsuarios, codPais, id, esPublica);
        archReporte << setw(5) << nLikesComentario << setw(10) << " ";
        //verificamos el mejor comentario respecto a likes de la fecha
        if(nLikesComentario >= mayorLike){
            mayorLike = nLikesComentario;
            codD = codPais;
            identificadorD = id;
        }
        if(esPublica){
            //llamada a funcion que busca e imprime el pais
            imprimirPais(archReporte, archPaises, codPais);
            nPublicos++;
        }
        else{
            archReporte << "Informacion NO Publica" << endl;
            nPrivados++;
        }
        if(archComentarios.eof()) break;
        if(extra = archComentarios.get() == '\n') break;
    }
}

void imprimirComentariosResumen(ofstream &archReporte, ifstream &archComentarios,
        ifstream &archPaises, ifstream &archUsuarios, int fecha, int nLikesT, 
        int nReproducciones, double &ratioV, int &cod, int &identificador){
    int dd, mm, yyyy, fechaLeida, codD, identificadorD;
    int nComentarios = 0, nPublicos = 0, nPrivados = 0, mayorLike = 0;
    char slash;
    archComentarios.clear();
    archComentarios.seekg(0, ios::beg);
    while(true){
        archComentarios >> dd;
        if(archComentarios.eof()) break;
        archComentarios >> slash >> mm >> slash >> yyyy;
        //llamada a funcion que convierte la fecha a entero
        fechaLeida = convertirFecha(dd, mm, yyyy);
        //verificamos que la fecha actual deba imprimirse
        if(fechaLeida == fecha){
            //llamada a funcion que lee los comentarios y continua el reporte
            procesarComentarios(archReporte, archComentarios, archPaises, 
                    archUsuarios, nComentarios, nPublicos, nPrivados, mayorLike, 
                    codD, identificadorD);
        }
        else{
            archComentarios.ignore(1000, '\n');
            archComentarios >> ws;    
        }
    }
    identificador = identificadorD;
    cod = codD;
    //llamada a funcion que imprime el resumen del tiktok
    imprimirResumen(archReporte, nLikesT, nReproducciones, nComentarios,
            nPublicos, nPrivados, ratioV);
}

void imprimirCabecera(ofstream &archReporte, int fecha, int contador){
    int dd, mm, yyyy;
    char slash = '/';
    archReporte << "TikTok " << contador << ") ";
    //llamada a funcion que descompone la fecha
    desconvertirFecha(fecha, dd, mm, yyyy);
    archReporte.fill('0');
    archReporte << setw(2) << dd << slash << setw(2) << mm << slash << yyyy << 
            endl << endl;
    archReporte.fill(' ');
    archReporte << "COMENTARIO" << setw(30) << "AUTOR DEL COMENTARIO" << setw(20)
            << "CANTIDAD DE LIKES" << setw(20) << "PAIS DEL AUTOR" << endl;
    //llamada a funcion para imprimir una linea de -
    imprimirLinea('-', TAMLINEA, archReporte);
}

void preguntarImprimirFechas(ofstream &archReporte, int &fechaI, int &fechaF){
    int ddI, mmI, yyyyI, ddF, mmF, yyyyF;
    char slash;
    cout << "Ingrese el rango de fecha en formato dd/mm/yyyy" << endl;
    cin >> ddI >> slash >> mmI >> slash >> yyyyI >> ddF >> slash >> mmF >> slash 
            >> yyyyF;
    //llamada a funcion para convertir la fecha en entero
    fechaI = convertirFecha(ddI, mmI, yyyyI);
    fechaF = convertirFecha(ddF, mmF, yyyyF);
    archReporte << setw(35) << " " << "@TikTok tp" << endl;
    archReporte << setw(20) << " " << "REPORTE PARA LA CAMPAÑA : Parcial 2022-2" 
            << endl;
    archReporte << setw(15) << " " << "Fecha Inicial: ";
    archReporte.fill('0');
    archReporte << setw(2) << ddI << slash << setw(2) << mmI << slash << yyyyI
            << " Fecha Final: " << setw(2) << ddF << slash << setw(2) << mmF << 
            slash << yyyyF << endl;
    archReporte.fill(' ');
    //llamada a funcion para imprimir una linea de caracteres
    imprimirLinea('=', TAMLINEA, archReporte);
}

void procesarReporte(ofstream &archReporte, ifstream &archTikToks, 
        ifstream &archComentarios, ifstream &archPaises, ifstream &archUsuarios){
    int fechaI, fechaF, dd, mm, yyyy, fechaTikTok, nTiktok = 1, nLikes,
            nReproducciones, mayorFecha, mayorCodP, mayorId, cod, identificador;
    double ratioV, mayorRatio = 0.0;
    char slash;
    //llamada a funcion que pregunta el rango e imprime la cabecera
    preguntarImprimirFechas(archReporte, fechaI, fechaF);
    while(true){
        archTikToks >> dd;
        if(archTikToks.eof()) break;
        archTikToks >> slash >> mm >> slash >> yyyy;
        //llamada a funcion que convierte la fecha a entero
        fechaTikTok = convertirFecha(dd, mm, yyyy);
        //si la fecha esta en el rango continuamos, de lo contrario ignoramos la linea
        if(fechaTikTok >= fechaI and fechaTikTok <= fechaF){
            //llamada a funcion que imprime la cabecera del tiktok
            imprimirCabecera(archReporte, fechaTikTok, nTiktok);
            archTikToks >> nLikes >> nReproducciones;
            //llamada a funcion que continua la impresion del tiktok
            imprimirComentariosResumen(archReporte, archComentarios, archPaises, 
                    archUsuarios, fechaTikTok, nLikes, nReproducciones, ratioV, 
                    cod, identificador);
            //verificamos el mejor ratio de viralidad(el tiktok mas viral)
            if(ratioV >= mayorRatio){
                mayorRatio = ratioV;
                mayorFecha = fechaTikTok;
                mayorCodP = cod;
                mayorId= identificador;
            }
            nTiktok++;
        }
        else{
            archTikToks.ignore(1000, '\n');
            archTikToks >> ws;
        }
    }
    imprimirMejorTikTok(archReporte, archUsuarios, mayorFecha, mayorCodP, mayorId);
}