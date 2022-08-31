/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 25 de agosto de 2022, 16:02
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Este programa contiene los apuntes de la lectura: "Ingreso y salida de datos
 * en el lenguaje c++"
 */
int main(int argc, char** argv) {

    /*Bibliotecas de funciones y espacios de nombres:
     Se usará primordialmente la biblioteca "iostream". Sin embargo, para
     manipular los datos, sobre todo para la salida de datos, se podrá usar
     la biblioteca "iomanip". Asimismo, el lenguaje ha implementado un mecanismo
     por medio del cual los elementos definidos en una biblioteca se pueden 
     colocar dentro de un ámbito, identificado con un nombre, ese ámbito se 
     conoce como "espacio de nombres". Para el caso de las bibliotecas iostream
     e iomanip el espacio de nombres se ha definido como std.
     
     Objeto "cout":
     El objeto cout permite enviar al medio estándar de salida el resultado de 
     expresiones que se le proporcionan, similar a printf. Cout es un objeto
     definido de la clase ostream que se encuentran en la biblioteca iostream.
     Las 3 formas para implementarlo son: usando std::cout, usando using 
     y usando using namespace. Esta última es la que se usará en el curso 
     (using namespace std;). Para poder realizar la operación de salida por
     medio del objeto cout se necesita el operador de inserción de flujo (<<)
     > Modo de uso (suponiendo haber usado using namespace std:
        cout << expresion;
     > Esta operación permite enviar a la salida estándar un flujo de caracteres
     provenientes de la conversión del resultado de la expresión en una cadena 
     de caracteres. Esta operación puede concatenarse: 
     cout << expresion1 << expresion2 << endl; >
     La herramienta endl funciona igual que \n.
     El operador << se aplica una sola vez al objeto cout >, por tanto el
     compilador entiende la concatenación como varias instrucciones cout separadas.
     El lenguaje c++ nos brinda herramientas que permiten solucionar los 
     problemas en el formato, mediante: "funciones miembro" del objeto cout y
     mediante funciones que proporciona la biblioteca iomanip.
     En el primer caso se usa: cout.width(n) que representa el llamado a 
     ejecución de la función miembro width que pertenece a cout. n indica la 
     cantidad mínima de caracteres a emplear en la salida del valor(equivalente
     a %nd en c). Por ejemplo:*/
    
    int a = 2351;
    int b = 765;
    
    cout << a << endl;
    cout.width(10);
    cout << a << endl;
    cout << b << endl;
    
    /*En este ejemplo se observa que el formato se aplica solo a la operación de
     salida inmediata, al resto no se aplica por lo que deberá anteponerlo en
     cada instrucción de salida.
     
     A continuación utilizaremos una función definida en "iomanip". En
     específico "setw(n)" (setw viene del inglés "set width". Esta función, al 
     igual que cout.width(n), define la mínima cantidad de caracteres en que 
     se representará el valor, sin embargo, su implementación es mucho más
     sencilla y práctica (implementación en la misma línea).*/
    
    a = 2351;
    b = 765;
    int c = 1234;
    
    cout << setw(10) << a << setw(10) << b << endl;
    cout << setw(10) << c << endl << endl;
    
    /*Podemos observar que se puede concatenar en una sola instrucción, sin
     embargo, como en el primer caso el formato solo se aplica a la expresión
     contigua. Asmimismo, setw forma parte del namespace std.
     
     Banderas de formato:
     Son constantes que permiten definir ciertos atributos que influenciarán la
     forma en la que aparecerán los datos en el medio de salida.*/
    
    cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    cout << left << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    cout << right << setw(10) << a << setw(10) << b << setw(10) << c << endl << endl;
    
    /*Left y right son banderas de formato, que hace que los resultados se 
     alineen a la izquierda o a la derecha. Una vez que se ejecuta al elemento,
     la alineación se mantiene hasta que otro elemento lo cambie. 
     Otras son: hex, uppercase, oct, dec, nouppercase. Que imprimen en formato
     hexadecimal, la forma de las letras, el formato octal, el formato decimal y
     quitar las mayúsculas en el medio de salida, respectivamente.
     A continuación, mostraremos como poder rellenear los espacios colocados en
     los formatos con otro caracter diferente.*/
    
    cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    
    cout.fill('0');
    cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    
    cout.fill(' ');
    cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    
    cout << setfill('X');
    cout << setw(10) << a << setw(10) << b << setw(10) << c << endl;
    
    cout << setfill(' ') << endl;
    
    /*Formato en valores de punto flotante:
     Por defecto, aparecerán en un formato. Para darle uno diferente c++ requiere
     el uso de dos herramientas, una que define la precisión en la que aparecerá
     el número (cout.precision(n) o setprecision(n)) y la otra que interpretará
     el significado de la precisión (fixed).
     Por defecto cout.precision(n) y setprecision(n), define la cantidad de 
     cifras o dígitos que se mostrarán (número de dígitos, no número de cifras
     decimales). */
    
    double f = 314.158938081212345;
    
    cout << setw(14) << f << endl; //añade espacios a la derecha
    
    cout.precision(10);
    cout << setw(14) << f << endl; //imprime 10 digitos del numero y 4 espacios
    
    cout.precision(3);
    cout << setw(14) << f << endl << endl; // imprime 3 digitos y el resto espacios
    
    /*Ya que no definen el número de decimales, sino el número de dígitos, se 
     requiere otra herramienta (fixed). Al activar esta bandera, el valor de 
     precisión se interpretará como el número de decimales.*/
    
    cout << fixed;
    cout.precision(5); 
    
    cout << setw(14);
    cout.precision(10);//equivalente a: cout << setprecision(10) << setw(14) << f << endl
    cout << setw(14) << f << endl; //14 espacios y 10 decimales
    cout.precision(3);
    cout << setw(14) << f << endl; //14 espacios y 3 decimales
    cout.unsetf(ios::fixed);
    
    /*Objeto Cin: 
     Al igual que la funcion scanf, permite leer, uno por uno, los caracteres
     de un flujo de caracteres que ingresa del medio estándar de entrada. Los
     caracteres son convertidos de acuerdo al tipo de variable que acompaña al
     objeto.
     Modo de uso: cin >> expresión;
     Aquí tambipen se ha sobrecargado un operador: el operador de extracción (>>)
     de flujo.
     Igual que el cout, cin puede concatenarse, por ejemplo:
     cin >> expresion1 >> expresion2 >> ...;
     
     Entrada y salida de caracteres: 
     Se puede realizar con los objetos cin y cout, empleando una variable de 
     tipo char, sin embargo existen algunos métodos que pueden ser muy útiles
     dado el caso.
     
     Método cin.get():
     El método toma un caracter del buffer de entrada y lo entrega al programa.*/
    
//    char caracter = 'A';
//    
//    cout << "Ingrese un texto:";
//    caracter = cin.get();
//    cout << "Caracter = " << caracter << endl;
    
    /*La principal diferencia entre métodos es que con cin los separadores
     (espacios) se ignoran si se encuentran antes del dato a leer, en cambio, 
     con cin.get se lee el caracter inmediato sea cual fuera.
     
     Método cout.put(c):
     El método toma el caracter contenido en c y lo envía al medio de salida.*/
    
//    char caracter2 = 'A';
//    
//    cout << "Ingrese un texto: ";
//    caracter2 = cin.get();
//    
//    cout << "Caracter2 = ";
//    cout.put(caracter2);
//    cout << endl; //imprime el caracter que ingrese
    
    /*Método cin.unget():
     Envía al buffer de entrada el último caracter extraído por el método
     cin.get().*/
    
//    char caracterA, caracterB, caracterC;
//    
//    cout << "Ingrese un texto: ";
//    caracterA = cin.get();
//    cin.unget();           //va a regresar el caracter, si escribimos hola extrae  
//    caracterB = cin.get(); //la h y la devuelve para leerla de nuevo
//    caracterC = cin.get();
//    
//    cout << "A = " << caracterA << endl;
//    cout << "B = " << caracterB << endl;
//    cout << "C = " << caracterC << endl; //imprimiria hoo
    
    /*Método cin.peek():
     Obtiene una copia del caracter del buffer de entrada, sin extraerlo y lo 
     entrega al programa.*/
    
//    char carA, carB, carC, carD;
//    
//    cout << "Ingrese un texto: ";
//    
//    carD = cin.peek();
//    
//    carA = cin.get();
//    carB = cin.get();
//    carC = cin.get();
//    
//    //Al ejecutarse escribiendo un hola, devuelve h o l h, esto significa
//    //que carD leyó la primera h pero no la retiró para no ser leída de nuevo
//    cout << "A = " << carA << endl;
//    cout << "B = " << carB << endl;
//    cout << "C = " << carC << endl;
//    cout << "D = " << carD << endl;
    
    /*Método cin.putback(c):
     Es similar a cin.unget() con la diferencia que el usuario puede enviar al
     buffer de entrada al caracter que desee.*/
    
//    char carA, carB, carC, carD;
//    
//    cout << "Ingrese un texto: ";
//    
//    carA = cin.get();
//    
//    //ingresando hola, leemos h y agregamos M: Mola
//    cin.putback('M');
//    
//    carB = cin.get();
//    carC = cin.get();
//    carD = cin.get();
//    
//    //imprime H M o l
//    cout << "A = " << carA << endl;
//    cout << "B = " << carB << endl;
//    cout << "C = " << carC << endl;
//    cout << "D = " << carD << endl;
    
    /*Función ws:
     Permite extraer del buffer de entrada todos los separadores 
     (espacios en blanco, tabuladores y cambios de línea) que vaya encontrando
     hasta encontrar un caracter diferente.*/
    
    char carA, carB, carC, carD;
    
    cout << "Ingrese un texto: ";
    
    carA = cin.get();
    cin >> ws;
    carB = cin.get();
    carC = cin.get();
    carD = cin.get();
    
    /*Si ingresamos h  ola (con dos espacios) el programa descartará los 
     espacios e imprimirá h o l a*/
    cout << "A = " << carA << endl;
    cout << "B = " << carB << endl;
    cout << "C = " << carC << endl;
    cout << "D = " << carD << endl;
    
    /*Re direccionamiento de la entrada y salida de datos:
     Es una propiedad del sistema operativo que se aplica sobre cualquier 
     programa ejecutable (.exe). Por lo general, el ingreso de datos se da
     mediante el teclado, y la salida mediante la pantalla. Esta propiedad hará
     que se pueda direccionarla entrada a otro medio (archivo de textos, impresora)
     o el medio de salida (archivo de textos, impresora). Para el redireccionamiento
     de la entrada a un archivo sería (en el cmd):
     C: \...\programa\dist\debug\ming...>programa.exe<datos.txt
     El símbolo < indica al sistema operativo que los datos ingresarán a través
     del archivo de textos en lugar del teclado. >
     
     En el caso de la salida sería:
     C: \...\programa\dist\debug\ming...>programa.exe>reporte.txt
     En este caso se usa el >, que le indica al sistema operativo que los
     resultados se enviarán al archivo que colocamos.
     
     Manejo de archivos de texto en el Lenguaje C++:
     La idea de emplear archivos de textos es poder almacenar información que 
     podrá ser empleada cada vez que se ejecute el programa o por diferentes
     programas. La ventaja de utilizarlos es que la consola del comñputador ha
     sido diseñada de manera similara la de un archivo de textos.
     
     Variable de archivo:
     Para utilizar un archivo de textos se requiere relacionar de manera LÓGICA
     el archivo con el programa. Para esto, C++ nos proporciona dos CLASES (dos
     tipos de datos) que nos permitan definir los objetos que creamos
     convenientes para desarrollar un programa.
     En C++ se ha implementado una biblioteca de funciones denominada fstream, 
     donde se han definido dos clases ifstream y ofstream y con ellos podemos 
     definir los objetos para conectarnos con los archivos.
     La clase ifstream permite definir variables de archivo para realizar 
     operaciones de LECTURA en archivos de texto, mientras que ofstream permite
     definir variables de archivo para realizar operaciones de ESCRITURA en 
     archivos de texto.
     
     Constructores y destructores:
     Son métodos o funciones miembro definidos para una clase. Tanto los 
     constructores como los destructores se ejecutan de manera AUTOMÁTICA.
     Los constructores para las clases ofstream e ifstream permiten abrir los 
     archivos, mientras que los destructores permiten cerrarlos.
     
     Definición, enlace y apertura de archivos:
     Antes de poder leer o escribir en un archivo se deben hacer 3 tareas:
     a) Definir una variable de archivo
     b) Enlazarla a un archivo físico
     c) Abrir el archivo para que podamos manipularlo
     Estas 3 tareas se pueden hacer en una sola instrucción (usando el
     constructor de la clase) o en dos instrucciones (usando un método de la 
     clase).
     Con una instrucción:
     #include <fstream>
     using namespace std;
     ...
     ifstream arch("archivo.txt", ios::in);
     Donde:
     -ifstream: es el nombre de la clase
     -arch: es la variable de archivo
     -"archivo.txt": es el nombre del archivo al que se enlazará la variable arch
     -ios::in : indica el modo de apertura(input) que permite leer datos del arch.
     Sin emplear el constructor:
     #include <fstream>
     using namespace std;
     ...
     ifstream arch;
     ...
     arch.open("archivo.txt", ios::in);
     La diferencia está en open, que realiza las mismas operaciones de apertura.
     
     Para que la instrucción se ejcute correctamente el archivo debe existir en
     el disco.
     
     Para escribir en el archivo, la instrucción será:
     #include <fstream>
     using namespace std;
     ...
     ofstream arch("archivo.txt", ios::out);
     Similar al anterior caso.
     Sin emplear el destructor:
     #include <fstream>
     using namespace std;
     ...
     ofstream arch;
     ...
     arch.open("archivo.txt", ios::out);
     Cambiando el ifstream por el ofstream y el ios::in por el ios::out.
     Al ejecutar estas instrucciones. si el archivo existe lo sobreescribirá y
     si no existe lo creará.
     
     Verificación correcta de la apertura de un archivo:
     Cuando abrimos un archivo debemos verificar que se abrió correctamente. De
     no hacerlo, el programa no funcionará correctamente terminando por
     interrumpirse abruptamente, sin mostrar el lugar del error.
     A continuación se muestra la verificación:
     
     #include <fstream>
     using namespace std;
     ...
     ifstream arch("archivo.txt", ios::in);
     if(not arch.is_open()){
        cout << "ERROR: no se pudo abrir el archivo archivo.txt" << endl;
        exit(1);
     }*/
    
    /*Debe hacerse inmediatamente después de la apertura. El uso de la función
     exit hará que el programa se interrumpa.
     
     Cierre de un archivo:
     Inmediatamente después de terminar de usar un archivo, este debe cerrarse.
     De no hacerse podría perderse información importante del archivo. Para esto, 
     existe el método close(arch.close()).
     
     Entrada y salida de datos desde archivos de texto:
     Es muy similar a la entrada y salida estándar ( cout <<, cin >>). 
     Solo debemos cambiar el cin y cout por arch y mantener los operadores de 
     control de flujo -> arch << y arch >> .
     
     Detección de errores en la entrada de datos:
     El lenguaje C++ tiene herramientas para detectar errores de lectura (los 
     métodos fail() y eof()). El método fail(), devuelve true si se ha producido
     un error en la lectura de datos y false en caso contrario. El método eof()
     devuelve true si se ha producido un error en el ingreso de datos si se
     intentó leer luego del final de un archivo y false en caso contrario.
     
     Cómo bajar la bandera de error:
     Cuando se levanta, ya no se puede leer datos. Si se desea seguir leyendo el
     método que permite hacerlo es clear().
     
     EN EL PDF SE OBSERVA UN EJERCICIO QUE UTILIZA TODO LO EXPLICADO*/
    
    return 0;
}