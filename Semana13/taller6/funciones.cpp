#include "funciones.hpp"

void imprimirLinea(char c, int n, ofstream &arch){
    for(int i = 0;i <= n; i++)
        arch.put(c);
    arch.put('\n');
}

void imprimirMovimientos(ofstream &archReporte, struct Pokemon pokemon){
    for(int i = 0; i < pokemon.nMovimientos; i++){
        archReporte << left << setw(15) << pokemon.movimientos[i].nombre;
        if(i % 6 == 0 and i != 0)
            archReporte.put('\n');
    }
    archReporte.put('\n');
    archReporte.put('\n');
}

int buscarPosicion(int estadistica, struct Pokemon *equipo, bool peorMejor){
    int pos = 0, stat;
    if(peorMejor)
        stat = 0;
    else
        stat = 999;
    if(peorMejor){
        for(int i = 0; i < 6; i++){
            if(equipo[i].estadisticas[estadistica] >= stat){
                pos = i;
                stat = equipo[i].estadisticas[estadistica];
            }
        }
    }
    else{
        for(int i = 0; i < 6; i++){
            if(equipo[i].estadisticas[estadistica] <= stat){
                pos = i;
                stat = equipo[i].estadisticas[estadistica];
            }
        }
    }
    return pos;
}

void imprimirResumen(ofstream &archReporte, struct Pokemon *equipoA, 
        struct Pokemon *equipoB, int hpA, int hpB){
    int pos;
    archReporte << "Resumen de Estadisticas Pokemon" << endl;
    archReporte << "Equipo A" << endl;
    //buscamos el pokemon dependiendo de la estadistica
    pos = buscarPosicion(6, equipoA, true);
    archReporte << "Pokemon mas rapido: " << equipoA[pos].nombre << endl;
    pos = buscarPosicion(3, equipoA, true);
    archReporte << "Pokemon mas defensivo: " << equipoA[pos].nombre << endl;
    pos = buscarPosicion(2, equipoA, true);
    archReporte << "Pokemon mas ofensivo: " << equipoA[pos].nombre << endl;
    pos = buscarPosicion(6, equipoA, false);
    archReporte << "Lista de ataques del pokemon mas lento: " << 
            equipoA[pos].nombre << endl;
    imprimirMovimientos(archReporte, equipoA[pos]);
    archReporte << "Equipo B" << endl;
    pos = buscarPosicion(6, equipoB, true);
    archReporte << "Pokemon mas rapido: " << equipoB[pos].nombre << endl;
    pos = buscarPosicion(5, equipoB, true);
    archReporte << "Pokemon mas especialmente defensivo: " << 
            equipoB[pos].nombre << endl;
    pos = buscarPosicion(4, equipoB, true);
    archReporte << "Pokemon mas especialmente ofensivo: " << 
            equipoB[pos].nombre << endl;
     pos = buscarPosicion(6, equipoB, false);
    archReporte << "Lista de ataques del pokemon mas lento: " << 
            equipoB[pos].nombre << endl;
    imprimirMovimientos(archReporte, equipoB[pos]);
    archReporte << "Ganador" << endl;
    if(hpA > hpB)
        archReporte << "Equipo A" << endl;
    else
        archReporte << "Equipo B" << endl;
}

void imprimirEquipos(ofstream &archReporte, struct Pokemon *equipoA, 
        struct Pokemon *equipoB){
    for(int i = 0; i < 6; i++){
        archReporte << left << setw(15) << equipoA[i].nombre;
        archReporte << setw(20) << " ";
        archReporte << setw(15) << equipoB[i].nombre << endl;
    }
}

void imprimirCabecera(ofstream &archReporte){
    archReporte << "Resumen de Batalla Pokemon" << endl;
    imprimirLinea('=', TAMLINEA, archReporte);
}

void imprimirBatallaPokemon(struct Pokemon *arrPokemones, int nPokemones){
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout << "ERROR: Reporte.txt" << endl;
        exit(1);
    }
    struct Pokemon equipoA[6];
    struct Pokemon equipoB[6];
    int a, b, hpA = 0, hpB = 0;
    imprimirCabecera(archReporte);
    srand(time(0));
    for(int i = 0; i < 6; i++){
        a = rand()%nPokemones;
        b = rand()%nPokemones;
        equipoA[i] = arrPokemones[a];
        equipoB[i] = arrPokemones[b];
        hpA += equipoA[i].estadisticas[1];
        hpB += equipoB[i].estadisticas[1];
    }
    archReporte << "Equipo A  " << hpA << "hp" << setw(20) << " ";
    archReporte << hpB << "hp  Equipo B" << endl;
    imprimirEquipos(archReporte, equipoA, equipoB);
    imprimirLinea('=', TAMLINEA, archReporte);
    imprimirResumen(archReporte, equipoA, equipoB, hpA, hpB);
}

void AsignarMovimiento(ifstream &arch, int idAtaque, 
        struct Pokemon &pokemon){
    arch.seekg(0, ios::beg);
    int id;
    int nMov;
    char buffer[100];
    while(true){
        arch >> id;
        if(arch.eof()) break;
        if(id == idAtaque){
            nMov = pokemon.nMovimientos;
            arch.get();
            arch.getline(buffer, 100, ',');
            pokemon.movimientos[nMov].nombre = new char[strlen(buffer) + 1];
            strcpy(pokemon.movimientos[nMov].nombre, buffer);
            arch >> pokemon.movimientos[nMov].tipo;
            arch.get();
            arch >> pokemon.movimientos[nMov].poder;
            if(arch.fail())
                arch.clear();
            arch.get();
            arch >> pokemon.movimientos[nMov].powerPoints;
            pokemon.nMovimientos++;
            break;
        }
        arch.ignore(100, '\n');
    }
}

void asignarMovimientos(struct Pokemon *arrPokemones, int nPokemones){
    ifstream archMovimientosPokemon("pokemon_moves.csv", ios::in);
    if(not archMovimientosPokemon.is_open()){
        cout << "ERROR: pokemon_moves.csv" << endl;
        exit(1);
    }
    ifstream archMovimientos("moves.csv", ios::in);
    if(not archMovimientos.is_open()){
        cout << "ERROR: moves.csv" << endl;
        exit(1);
    }
    
    int idPokemon, idAtaque, nivel;
    bool definirArreglo = true;
    
    for(int i = 0; i < nPokemones; i++){
        if(definirArreglo){
            arrPokemones[i].movimientos = new struct Movimiento[300];
            definirArreglo = false;
        }
        archMovimientosPokemon >> idPokemon;
        if(archMovimientosPokemon.eof()) break;
        archMovimientosPokemon.get();
        archMovimientosPokemon >> idAtaque;
        archMovimientosPokemon.get();
        archMovimientosPokemon >> nivel;
        archMovimientosPokemon >> ws;
        if(idPokemon == i+1){
            //llamada a funcion para asignar el movimiento al pokemon
            AsignarMovimiento(archMovimientos, idAtaque, arrPokemones[i]);
            i--;
        }
        else{
            arrPokemones[i+1].movimientos = new struct Movimiento[300];
            AsignarMovimiento(archMovimientos, idAtaque, arrPokemones[i+1]);
        }
    }
}

void leerLineaPokemon(ifstream &archPokemones, struct Pokemon &pokemonLeido){
    char buffer[100];
    archPokemones >> pokemonLeido.id;
    archPokemones.get();
    //utilizamos las funciones de la biblioteca cstring para copia y longitud   
    archPokemones.getline(buffer, 100, ',');
    pokemonLeido.nombre = new char[strlen(buffer) + 1];
    strcpy(pokemonLeido.nombre, buffer);
    
    archPokemones.getline(buffer, 100, ',');
    pokemonLeido.tipos[0] = new char[strlen(buffer) + 1];
    strcpy(pokemonLeido.tipos[0], buffer);
    
    archPokemones.getline(buffer, 100, ',');
    pokemonLeido.tipos[1] = new char[strlen(buffer) + 1];
    strcpy(pokemonLeido.tipos[1], buffer);
    
    for (int i = 0; i < 7; i++){
        archPokemones >> pokemonLeido.estadisticas[i];
        archPokemones.get();
    }
    archPokemones >> pokemonLeido.generacion;
    archPokemones.get();
    archPokemones >> buffer;
    if(strcmp(buffer, "False") == 0)
        pokemonLeido.esLegendario = false;
    else
        pokemonLeido.esLegendario = true;
    archPokemones >> ws;
}

void leerPokemones(struct Pokemon *arrPokemones, int &nPokemones){
    ifstream archPokemones("pokemon.csv", ios::in);
    if(not archPokemones.is_open()){
        cout << "El archivo pokemon.csv no pudo abrirste" << endl;
        exit(1);
    }
    struct Pokemon pokemonLeido;
    while(true){
        if(archPokemones.eof()) break;
        //llamada a funcion para leer una linea del archivo pokemon.csv
        leerLineaPokemon(archPokemones, pokemonLeido);
        arrPokemones[nPokemones] = pokemonLeido;
        nPokemones++;
    }
}
