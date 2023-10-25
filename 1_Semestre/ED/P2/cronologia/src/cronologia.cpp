#include <iostream>
#include "../include/cronologia.h" //incluimos el archivo necesario

/**
* @brief Añade una fecha histórica a la cronología.
* 
* Esta función toma una fecha histórica y la añade al final del vector de fechas históricas.
* 
* @param fechaHistorica La fecha histórica a añadir. Es una constante que hace referencia a un objeto de la clase FechaHistorica.
* 
* @return No devuelve nada.
* 
* @note Esta función modifica el objeto cronología añadiendo una nueva fecha histórica.
*/
void Cronologia::addFechaHistorica(const FechaHistorica& fechaHistorica){
    
    fechasHistoricas.push_back(fechaHistorica); //Metemos en fechashistoricas fechahistorica
}
/**
* @brief Busca un evento histórico en la cronología por año.
* 
* Recorre cada fecha histórica dentro del vector de fechas históricas. Si el año de la fecha histórica es igual al año proporcionado,
* almacena los eventos de la fecha histórica y los imprime en pantalla.
* 
* @param año_E Año del evento a buscar. Es un entero que representa el año del evento histórico que se quiere buscar.
* 
* @return No devuelve nada, pero imprime en pantalla el año y los eventos correspondientes si se encuentra una fecha histórica con el año proporcionado.
* 
* @note Esta función no modifica el objeto cronología.
* 
* @warning Si no se encuentra ninguna fecha histórica con el año proporcionado, se imprime "No se ha encontrado el año.".
*/
void Cronologia::BuscarEventoHistorico(int año_E){

    for (const auto& fechaHistorica : fechasHistoricas){// Recorremos cada fechaHistorica dento del vector de fechasHistoricas
        if (fechaHistorica.getAño() == año_E){ // Si el año es igual al año de la fechaHistorica
            const auto& eventos = fechaHistorica.getEventos(); //Almacenamos los eventos de la fechaHistorica
            std::cout<< "--" << año_E << "-- \n";
            for (const auto& evento : eventos){ // Recorremos cada evento de la fechaHistorica y lo reproducimos en pantalla
                std::cout << evento << "\n";
            }
            return;
        } 
    }
    std::cout<<"No se ha encontrado el año.\n";
}
/**
* @brief Busca una fecha histórica en la cronología por evento sucedido en dicha fecha.
* 
* Recorre cada fecha histórica dentro del vector de fechas históricas. Si el evento de la fecha histórica es igual al evento proporcionado,
* almacena el año de la fecha histórica y los imprime en pantalla.
* 
* @param nombreEvento Evento del evento a buscar. Es un string que representa el evento del año histórico que se quiere buscar.
* 
* @return No devuelve nada, pero imprime en pantalla el año y el evento correspondiente si se encuentra una fecha histórica con el evento proporcionado.
* 
* @note Esta función no modifica el objeto cronología.
* 
* @warning Si no se encuentra ninguna fecha histórica con el evento proporcionado, se imprime "No se ha encontrado el evento.".
*/
void Cronologia::BuscarAñoHistorico(const std::string& nombreEvento){
    for (const auto& fechaHistorica : fechasHistoricas){// Recorremos cada fechaHistorica dento del vector fechasHistoricas
        const auto& eventos = fechaHistorica.getEventos(); //almacenamos los eventos de la fechaHistorica
        for(const auto& evento : eventos){ // Recorremos cada evento de la fechaHistorica
            if(evento == nombreEvento){ // si el evento es igual al nombre del evento
                const auto& año = fechaHistorica.getAño(); //Almacenamos
                std::cout<<"--" << año << "-- \n"; //Mostramos el año junto con el nombre del evento
                std::cout<< nombreEvento << "\n";
                return; 
            }
        }
    }
    std::cout<<"No se ha encontrado el evento.\n";
}
/**
* @brief Convierte la cronología a una cadena de texto.
* 
* Esta función es responsable de convertir una cronología completa a una representación de cadena de texto. 
* La cadena de texto resultante tiene el formato "FechaHistorica1\nFechaHistorica2\n...".(Siendo '\n' un salto de línea).
* 
* Primero, la función inicializa una cadena de texto vacía llamada `resultado`.
* Luego, la función recorre cada fecha histórica en el vector de fechas históricas. 
* Para cada fecha histórica, la función convierte la fecha histórica a una cadena de texto llamando a la función `toString` de la fecha histórica. 
* Luego, añade la cadena de texto de la fecha histórica a `resultado`, seguida de un carácter de nueva línea.
* Después de recorrer todas las fechas históricas, la función devuelve `resultado`.
* 
* @return Devuelve una cadena de texto que representa la cronología.  
* 
* @note Esta función no modifica el objeto Cronologia. 
* Solo accede a los datos del objeto y los utiliza para crear una nueva cadena de texto.
*/
std::string Cronologia::toString() const {
    std::string resultado; //variable resultado
    for (const auto& fechaHistorica : fechasHistoricas){ //recorre cada fechahistorica en el vector fechashistoricas
        resultado += fechaHistorica.toString() + "\n"; // llamamos al metodo toString de cada fechaHistorica, convertimos en cadenas las fechasHistoricas
    }
    return resultado; //devuelve fechashistoricas
}