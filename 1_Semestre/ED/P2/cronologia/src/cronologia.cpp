#include <iostream>
#include "../include/cronologia.h" //incluimos el archivo necesario

void Cronologia::addFechaHistorica(const FechaHistorica& fechaHistorica){
    
    fechasHistoricas.push_back(fechaHistorica); //Metemos en fechashistoricas fechahistorica
}
void Cronologia::BuscarEventoHistorico(int año_E){

    for (const auto& fechaHistorica : fechasHistoricas){// Recorremos cada fechaHistorica dento del vector de fechasHistoricas
        if (fechaHistorica.getAño() == año_E){ // Si el año es igual al año de la fechaHistorica
            const auto& eventos = fechaHistorica.getEventos(); //Almacenamos los eventos de la fechaHistorica
            std::cout<< "--" << año_E << "-- \n";
            for (const auto& evento : eventos){ // Recorremos cada evento de la fechaHistorica y lo reproducimos en pantalla
                std::cout << evento << ",\n";
            }
        } 
    }
}
std::string Cronologia::toString() const {

    std::string resultado; //variable resultado
    for (const auto& fechaHistorica : fechasHistoricas){ //recorre cada fechahistorica en el vector fechashistoricas
        resultado += fechaHistorica.toString() + "\n"; // convierte a cadena la fechahistorica a mostrar
    }
    return resultado; //devuelve fechashistoricas
}