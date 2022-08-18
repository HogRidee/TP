## Resumen
# Sección 2.2 Su primer programa en C++: imprimir una línea de texto
•	 Los comentarios de una sola línea (pág. 40) comienzan con //. Insertamos comentarios para documentar los
   programas y mejorar su legibilidad.  <br />
•	 Los comentarios no provocan que la computadora realice ninguna acción (pág. 41) cuando se ejecuta el programa: el compilador los ignora y no provocan que se genere ningún código objeto en lenguaje máquina.
•	 Una directiva de preprocesamiento (pág. 40) comienza con # y es un mensaje para el preprocesador de C++. Las
   directivas de preprocesamiento se procesan antes de que se compile el programa. <br />
•	 La línea #include <iostream> (pág. 40) indica al preprocesador de C++ que debe incluir el contenido del encabezado del flujo de entrada/salida, que contiene la información necesaria para compilar programas que usen
   std::cin (pág. 46) y std::cout (pág. 41) junto con los operadores de inserción de flujo (<<, pág. 42) y de extracción de flujo (>>, pág. 46).
•	 El espacio en blanco (es decir líneas en blanco, caracteres de espacio y caracteres de tabulación, pág. 40) hace
   que los programas sean más fáciles de leer. El compilador ignora los caracteres de espacio en blanco que se encuentran fuera de las literales de cadena.
•	 Los programas en C++ empiezan a ejecutarse en main (pág. 41), incluso aunque main no aparezca primero en el
   programa.
•	 La palabra clave int a la izquierda de main indica que esta función “devuelve” un valor entero.
•	 El cuerpo (pág. 41) de toda función debe estar encerrado entre llaves ({ y }).
•	 Una cadena ( string) (pág. 41) entre comillas dobles se conoce algunas veces como cadena de caracteres, mensaje o literal de cadena. El compilador no ignora los caracteres de espacio en blanco en las cadenas.
•	 La mayoría de las instrucciones de C++ (pág. 41) terminan con un punto y coma, también conocido como
   terminador de instrucción (pronto veremos algunas excepciones a esto).
•	 En C++, las operaciones de entrada y salida se realizan mediante flujos (pág. 41) de caracteres.
•	 El objeto flujo de salida std::cout (que por lo general está conectado a la pantalla) se utiliza para mostrar
   datos. Es posible mostrar múltiples elementos de datos mediante la concatenación de operadores de inserción
   de flujo (<<).
•	 El objeto flujo de entrada std::cin (que por lo general está conectado al teclado) se utiliza para introducir datos.
   Es posible introducir múltiples elementos de datos mediante la concatenación de operadores de extracción de
   flujo (>>).
•	 La notación std::cout especifica que utilizamos cout del “espacio de nombres” std.
•	 Cuando hay una barra diagonal (es decir, un carácter de escape) en una cadena de caracteres, el siguiente carácter se combina con la barra diagonal para formar una secuencia de escape (pág. 42).
•	 La secuencia de escape de nueva línea \n (pág. 42) mueve el cursor al principio de la siguiente línea en la pantalla.
•	 Un mensaje que indica al usuario que realice una acción específica se conoce como indicador (prompt)
   (pág. 46).
•	 La palabra return de C++ (pág. 42) es uno de varios medios para salir de una función
# Sección 2.4 Otro programa en C++: suma de enteros
•	 Hay que declarar todas las variables (pág. 45) en un programa en C++ antes de poder usarlas.
•	 El nombre de una variable es cualquier identificador válido (pág. 45) que no sea una palabra clave. Un identificador es una serie de caracteres que consisten en letras, dígitos y guiones bajos (_). Los identificadores no pueden
   comenzar con un dígito. Su nombre puede ser de cualquier longitud, aunque tal vez algunos sistemas o implementaciones de C++ impongan restricciones en cuanto al largo.
•	 C++ es sensible al uso de mayúsculas y minúsculas (pág. 45).
•	 La mayoría de los cálculos se realizan en instrucciones de asignación (pág. 47).
•	 Una variable es una ubicación en memoria (pág. 48) en donde se puede almacenar un valor para que lo utilice
   un programa.
•	 Las variables de tipo int (pág. 45) contienen valores enteros; es decir, números integer como 7, –11, 0, 31914.
# Sección 2.5 Conceptos acerca de la memoria
•	 Toda variable almacenada en la memoria de la computadora tiene un nombre, valor, tipo y tamaño.
•	 Cada vez que se coloca un nuevo valor en una ubicación de memoria, el proceso es destructivo (pág. 48); es
   decir, el nuevo valor reemplaza al valor anterior en esa ubicación. El valor anterior se pierde.
•	 Cuando se lee un valor de la memoria, el proceso es no destructivo (pág. 49); es decir, se lee una copia del valor
   y el original queda sin ser perturbado en la ubicación de memoria.
•	 El manipulador de flujos std::endl (pág. 47) imprime una nueva línea y luego “vacía el búfer de salida”.
   Sección 2.6 Aritmética
•	 C++ evalúa las expresiones aritméticas (pág. 49) en una secuencia precisa determinada por las reglas de precedencia de operadores (pág. 50) y la asociatividad (pág. 50).
•	 Pueden usarse paréntesis para agrupar expresiones.
•	 La división de enteros (pág. 49) produce un cociente entero. Cualquier parte fraccional en la división de enteros se
trunca.
•	 El operador módulo % (pág. 50) produce el residuo después de la división de enteros.
# Sección 2.7 Toma de decisiones: operadores de igualdad y relacionales
•	 La instrucción if (pág. 53) permite a un programa tomar una acción alternativa con base en el cumplimiento
   de una condición. El formato para una instrucción if es:
   if ( condición )
       instrucción;
   Si la condición es verdadera, se ejecuta la instrucción en el cuerpo del if. Si la condición no se cumple (es falsa),
   se brinca el cuerpo de la instrucción.
•	 Por lo general, las condiciones en las instrucciones if se forman mediante el uso de operadores de igualdad y
   relacionales (pág. 53). El resultado de usar esos operadores siempre es un valor verdadero o falso.
•	 La siguiente declaración using (pág. 55):
    using std::cout;
   informa al compilador en dónde encontrar cout (namespace std) y elimina la necesidad de repetir std:: prefijo. La siguiente directiva using (pág. 55):
    using namespace std;
   permite al programa usar en el encabezado todos los nombres incluidos de cualquier biblioteca estándar de C++.
