#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "../include/fechahistorica.h"

 class  Cronologia
 {
    private:
        std::vector<FechaHistorica> fechasHistoricas; //Vector de fechashistoricas
    public:
        void addFechaHistorica(const FechaHistorica& fechaHistorica);//toma como referencia la clase FH para mas tarde introducirlo en el vector de arriba
        void BuscarEventoHistorico(int año_E);//buscaremos los eventos por fecha   
        void BuscarAñoHistorico(const std::string& nombreEvento);//buscaremos la fecha segun los eventos sucediddos
        std::string toString() const; //Convertidor a cadena
        auto begin() { return fechasHistoricas.begin(); }
        auto end() { return fechasHistoricas.end(); }
 };
#endif