/* 
 * File:   Pokemon.hpp
 * Author: Ivan
 *
 * Created on 23 de noviembre de 2022, 10:18
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

struct Pokemon{
    int id;
    char *nombre;
    char *tipos[2];
    int estadisticas[7];
    int generacion;
    bool esLegendario;
    struct Movimiento *movimientos;
    int nMovimientos = 0;
};

#endif /* POKEMON_HPP */

