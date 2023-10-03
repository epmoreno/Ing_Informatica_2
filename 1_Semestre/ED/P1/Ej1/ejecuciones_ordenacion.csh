# Definir el nombre del archivo de salida
set output_file = "resultados.dat"

# Borrar el archivo de salida si ya existe
#if (-e $output_file) then
#    rm $output_file
#endif

# Definir cuántas veces se ejecutará el programa
@ iterations = 1

# Ejecutar el programa varias veces
while ($iterations > 0)
    # Ejecutar el programa y redirigir la salida al archivo
    ./ordenacion.exe >>& $output_file
    @ iterations--
end