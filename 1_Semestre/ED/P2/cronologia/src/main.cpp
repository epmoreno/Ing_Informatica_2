#include <iostream>
#include <algorithm>
#include "../include/cronologia.h"

int main() {
    Cronologia cronologia; // creamos una cronologia

    /*Creamos Eventos (Año,Evento)*/
    FechaHistorica evento1(1903, {"A Fast Fourier Transform algorithm presented by Carle David Tolmé Runge"});
    FechaHistorica evento2(1969, {"Alunizaje del Apolo 11"});
    FechaHistorica evento3(1991, {"Disolución de la Unión Soviética"});
    FechaHistorica evento4(1936,{"Turing machine, an abstract machine developed by Alan Turing","with others developed the modern notion of algorithm"});

    /*Introducimos Eventos en Cronologia*/
    cronologia.addFechaHistorica(evento1);
    cronologia.addFechaHistorica(evento2);
    cronologia.addFechaHistorica(evento3);
    cronologia.addFechaHistorica(evento4);

    /*Ordenamos por año los eventos e Imprimimos*/
    std::sort(cronologia.begin(), cronologia.end(), [](const FechaHistorica& a, const FechaHistorica& b) {
        return a.getAño() < b.getAño(); 
    }); 
    std::cout << cronologia.toString() << std::endl;

    return 0;
}

/**
 **DIARIO:
 * 
 * Asociar los archivos y que estos creen las fechas junto con los eventos
 * Vector en fechashistoricas que almacena los eventos que introducimos a mano
 * Vector en Cronologia que almacena dichos eventos junto con sus fechas
 * Utilizacion de la funcion sort() junto con sus metodos .begin y .end para ordenar gracias a #include<vector>
 * !Queda por reorganizare el codigo para que me de los eventos segun su fecha y su fecha segun el evento.
*/