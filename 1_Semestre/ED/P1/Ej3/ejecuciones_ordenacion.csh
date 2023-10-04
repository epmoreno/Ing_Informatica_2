#!/bin/csh
@ inicio = 101
@ fin = 70000
@ incremento = 100
@ i = $inicio
set output_file = "resultados_test.dat"
while ( $i <= $fin )
 ./main.exe $i >>& $output_file
 @ i += $incremento
end
echo Ejecución Terminada.