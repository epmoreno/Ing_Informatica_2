# T.D.A. y Documentación del software
## Objetivos
    - Asimilar los conceptos fundamentales de abstracción, aplicado al desarrollo de programas.
    - Documentar un tipo de dato abstracto (T.D.A).
    - Practicar con el uso de doxygen.
    - Profundizar en los conceptos relacionados especifcación del T.D.A,
    representación del T.D.A., función de Abstracción e Invariante de la representación.

## Ejercicio
Con la fnalidad de mejorar nuestros conocimientos sobre Historia,
queremos desarrollar una aplicación que nos permita obtener acontecimientos históricos sucedidos en una fecha y
viceversa, averiguar el año en el que sucedió algún acontecimiento.

- Dato Abstratcos a desarrollar (T.D.A):
    + FechaHistórica: Se compone de una fecha y uno o más eventos sucedidos en dicha
    fecha.
    + Cronología: Es un conjunto de fechas históricas ordenadas por año.

- Módulos a desarrollar :
    + 'fechahistorica.cpp' y 'fechahistorica.h'.
        * Constructor de la clase.
        * Metodos get Año y Evento.
        * Función toString() que une y convierte a cadena los datos.
    + 'cronologia.cpp' y 'cronologia.h'.
        * Vector contenedor de las fechas creadas.
        * Función para añadir evento addFechaHistorica().
        * Función para buscar evento segun el año introducido BuscarEventoHistorico().
        * Función para buscar el año en el que sucedio el evento introducido BuscarAñoHistorico().
        * Función toString() que une todas las fechas creadas en una misma cadena a mostrar.
        * Función sort() junto a sus metodos begin() y end().
    + 'main.cpp'.
        * Creación de las fechas historicas.
        * Creación de la cronologia de estas.
        * Ordenación de esta cronologia.
        * Muestra de la funcionalidad de las funciones BuscarEventoHistorico() y BuscarAñoHistorico().
