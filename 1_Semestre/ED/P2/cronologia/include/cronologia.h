/**
* @file cronologia.h
* @brief Este archivo contiene la definición de la clase Cronologia.
* 
* La clase Cronologia representa una colección de fechas históricas.
* Cada fecha histórica es un objeto de la clase FechaHistorica, que contiene un año y una lista de eventos que ocurrieron en ese año.
* La cronología almacena las fechas históricas en un vector.
*/

#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

/**
* @class Cronologia
* @brief Representa una colección de fechas históricas.
* 
* La clase Cronologia permite almacenar, buscar y manipular un conjunto de fechas históricas.
* Cada fecha histórica es un objeto de la clase FechaHistorica, que contiene un año y una lista de eventos que ocurrieron en ese año.
* La cronología almacena las fechas históricas en un vector.
*/
#include "../include/fechahistorica.h"

 class  Cronologia
 {
    private:
        std::vector<FechaHistorica> fechasHistoricas;///< Vector de fechas históricas.
    public:
       
        void addFechaHistorica(const FechaHistorica& fechaHistorica);

       
        void BuscarEventoHistorico(int año_E);  
        
        
        void BuscarAñoHistorico(const std::string& nombreEvento);

        
        std::string toString() const;

        
        auto begin() { return fechasHistoricas.begin(); }

        
        auto end() { return fechasHistoricas.end(); }
 };
#endif