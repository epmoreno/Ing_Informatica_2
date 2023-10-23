#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "../include/fechahistorica.h"

 class  Cronologia
 {
    private:
        std::vector<FechaHistorica> fechasHistoricas; //Vector de fechashistoricas
    public:
        void addFechaHistorica(const FechaHistorica& fechaHistorica);   //toma como referencia la clase FH para mas tarde introducirlo en el vector de arriba
        std::string toString() const; //Convertidor a cadena
        auto begin() { return fechasHistoricas.begin(); }
        auto end() { return fechasHistoricas.end(); }
 };
#endif