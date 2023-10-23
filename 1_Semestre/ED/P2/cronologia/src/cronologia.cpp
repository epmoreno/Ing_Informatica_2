#include "../include/cronologia.h" //incluimos el archivo necesario

void Cronologia::addFechaHistorica(const FechaHistorica& fechaHistorica){
    fechasHistoricas.push_back(fechaHistorica); //Metemos en fechashistoricas fechahistorica
}

std::string Cronologia::toString() const {
    std::string resultado; //variable resultado
    for (const auto& fechaHistorica : fechasHistoricas){ //recorre cada fechahistorica en el vector fechashistoricas
        resultado += fechaHistorica.toString() + "\n"; // convierte a cadena la fechahistorica a mostrar
    }
    return resultado; //devuelve fechashistoricas
}