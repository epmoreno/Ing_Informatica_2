#ifndef FECHAHISTORICA_H
#define FECHAHISTORICA_H

#include <vector>
#include <string>

class FechaHistorica{
    private:
        int año; //Variable año
        std::vector<std::string> eventos; //Vector de eventos
    public:
        FechaHistorica(int año, const std::vector<std::string> eventos); //Constructor 
        int getAño() const; // Devuelve año y conts hace que no se modifique
        const std::vector<std::string>& getEventos() const; // Devuelve Eventos sin modificar
        void addEvento(const std::string& evento); //Añadimos evento
        std::string toString() const; //Convierte la informacion de FechaHistorica en una cadena
};
#endif