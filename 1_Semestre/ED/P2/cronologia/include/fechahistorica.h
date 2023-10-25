/**
* @file fechahistorica.h
* @brief Este archivo contiene la definición de la clase FechaHistorica.
* 
* La clase FechaHistorica representa una fecha en la historia, que consiste en un año y una lista de eventos que ocurrieron en ese mismo año.
*/

#ifndef FECHAHISTORICA_H
#define FECHAHISTORICA_H

#include <vector>
#include <string>

/**
* @class FechaHistorica
* @brief Representa una fecha en la historia.
* 
* La clase FechaHistorica permite almacenar y manipular una fecha en la historia.
* Una fecha histórica consiste en un año y una lista de eventos que ocurrieron en ese año.
* Los eventos se almacenan en un vector de cadenas de texto.
*/
class FechaHistorica{
    private:
        int año; ///< Año de la fecha histórica.
        std::vector<std::string> eventos; ///< Eventos de la fecha histórica.
    public:
        
        FechaHistorica(int año, const std::vector<std::string> eventos); 

        
        int getAño() const;

        
        const std::vector<std::string>& getEventos() const; 

        
        void addEvento(const std::string& evento);

       
        std::string toString() const; 
};
#endif