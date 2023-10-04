#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 100
@ i = $inicio
set output_file = "resultados_WC.dat"
#echo > resultados.dat
while ( $i <= $fin )
 echo Ejecución tam = $i
 ./ordenacion_WC.exe $i 10000 >>& $output_file
 @ i += $incremento
end