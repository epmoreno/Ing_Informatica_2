#include "../include/fechahistorica.h"

/**
* @brief Constructor de la clase FechaHistorica.
* 
* Este constructor crea una nueva instancia de FechaHistorica. 
* Inicializa el año con el valor proporcionado y copia los eventos del vector "eventos".
* 
* @param año El año de la fecha histórica, un entero que representa el año de los eventos.
* @param eventos Los eventos de la fecha histórica, una constante a un vector de cadenas de texto que contiene los eventos.
* 
* @note Este constructor realiza una copia de los eventos proporcionados, por lo que cualquier modificación posterior del vector de eventos proporcionado no afectará a la fecha histórica creada.
*/
FechaHistorica::FechaHistorica(int año, const std::vector<std::string> eventos) : año(año), eventos(eventos) {}
/**
 * @brief Metodo que devuelve el año de la fecha historica.
 * 
 * @return Devuelve el año.
*/
int FechaHistorica::getAño() const{
    return año;
}
/**
 * @brief Metodo que devuelve el vector de eventos.
 * 
 * @return Devuelve los eventos dentro del vector eventos.
*/
const std::vector<std::string>& FechaHistorica::getEventos() const{
    return eventos;
}
/**
* @brief Convierte la fecha histórica a una cadena de texto.
* 
* Esta función es responsable de convertir una fecha histórica a una representación de cadena de texto. 
* La cadena de texto resultante tiene el formato "año: evento1, evento2, ...".
* 
* Primero, la función convierte el año a una cadena de texto y añade ": " después del año. 
* Luego, la función recorre cada evento en el vector de eventos y esta añade el evento a la cadena de texto, seguido de una coma y un espacio.
* Después de recorrer todos los eventos, la función elimina la coma y el espacio finales de la cadena de texto. 
* 
* @return Devuelve una cadena de texto que representa la fecha histórica. 
* La cadena de texto tiene el formato "año: evento1, evento2, ...". 
* Si la fecha histórica no tiene eventos, la cadena de texto solo contendrá el año seguido de ": ".
* 
* @note Esta función no modifica el objeto FechaHistorica. 
* Solo accede a los datos del objeto y los utiliza para crear una nueva cadena de texto.
*/
std::string FechaHistorica::toString() const{
    std::string resultado = std::to_string(año) + ": ";
    for (const auto& evento : eventos) {
        resultado += evento + ", ";
    }
    resultado.pop_back();
    resultado.pop_back();
    return resultado;
}