#include "../include/fechahistorica.h"

FechaHistorica::FechaHistorica(int año, const std::vector<std::string> eventos) : año(año), eventos(eventos) {} //inicializacion de constructor

int FechaHistorica::getAño() const{ //devuelve año
    return año;
}

const std::vector<std::string>& FechaHistorica::getEventos() const{ //devuelve eventos
    return eventos;
}

std::string FechaHistorica::toString() const{ //metodo que devuelve cadena de texto
    std::string resultado = std::to_string(año) + ": "; //creamos resultados y convertimos año a cadena
    for (const auto& evento : eventos) { //bucle que recorre cada evento en el vector eventos
        resultado += evento + ", "; //añaede el evento y añadimos coma
    }
    resultado.pop_back(); // Elimina el espacio final
    resultado.pop_back(); // Por ulyimo elimina la coma
    return resultado;
}