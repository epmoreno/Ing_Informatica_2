#include <iostream>
#include <algorithm>
#include "../include/cronologia.h"

int main() {
    Cronologia cronologia; // creamos una cronologia

    /*Creamos Eventos (Año,Evento)*/
    FechaHistorica evento1(1903, {"A Fast Fourier Transform algorithm presented by Carle David Tolmé Runge"});
    FechaHistorica evento2(1969, {"Alunizaje del Apolo 11"});
    FechaHistorica evento3(1991, {"Disolución de la Unión Soviética"});
    FechaHistorica evento4(1936, {"Turing machine","an abstract machine developed by Alan Turing","with others developed the modern notion of algorithm"});

    /*Introducimos Eventos en Cronologia*/
    cronologia.addFechaHistorica(evento1);
    cronologia.addFechaHistorica(evento2);
    cronologia.addFechaHistorica(evento3);
    cronologia.addFechaHistorica(evento4);

    /*Ordenamos por año los eventos e Imprimimos*/
    std::sort(cronologia.begin(), cronologia.end(), [](const FechaHistorica& a, const FechaHistorica& b) { // funcion sort() la utilizamos para recorrer el vector fechashistoricas, iniciando previamente begin() y end() en cronologia.h,
        return a.getAño() < b.getAño(); //organizandolo segun su fecha
    });

    /*Mostramos los eventos ya ordenados de mayor a menos en base al año*/
    std::cout << "--Eventos--" << std::endl;
        /*Aplicamos la funcion toString() de la clase cronologia en la cual hemos almacenado los datos de fechasHistoricas 
        y nos mostrara estas convertiudas ya en cadena*/
    std::cout << cronologia.toString() << std::endl;// 

    /*Buscamos un evento por fecha*/
    cronologia.BuscarEventoHistorico(1991);
    
    std::cout << "\n" ;

    /*Buscamos una fecha por el evento sucedido en ella*/
    cronologia.BuscarAñoHistorico("Turing machine");

    return 0;
}