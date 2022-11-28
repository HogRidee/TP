/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 23 de noviembre de 2022, 10:07
 */

#include "funciones.hpp"

/*
 * ESTE PROGRAMA RESUELVE EL TALLER 6 PARA LA PC4 Y PARA EL FINAL
 */
int main(int argc, char** argv) {

    struct Pokemon arrPokemones[200];
    int nPokemones = 0;
    
    //llamada a funcion para leer los pokemones del archivo csv
    leerPokemones(arrPokemones, nPokemones);
    //llamada a funcion para asignar movimientos a cada pokemon
    asignarMovimientos(arrPokemones, nPokemones);
    //llamada a funciones de impresion
    imprimirBatallaPokemon(arrPokemones, nPokemones);
    
    return 0;
}

