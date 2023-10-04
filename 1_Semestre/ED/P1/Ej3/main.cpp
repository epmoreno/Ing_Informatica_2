#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>
#include <iomanip>

using namespace std;

int operacion(int *v, int n, int x, int inf, int sup) {
//Verificacion
  if (x<v[0] || x>v[n-1])
  {
    cout << " ";
    return -1;
  }
  

  int med; //media
  bool enc=false;
  while ((inf<sup) && (!enc)) { //mientras inf sea < sup && enc no sea false
    med = (inf+sup)/2; //hacemos la media de ambos
    if (v[med]==x) //si la posicion de 
      enc = true;
    else if (v[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();
  
  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % tam;
  
  //Inicio
  auto start = std::chrono::high_resolution_clock::now();

    // Algoritmo a evaluar
  operacion(v,tam,tam+1,0,tam-1);
  
  //Fin
  auto stop = std::chrono::high_resolution_clock::now();

  //Microsegundos
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  //Mayor nº demimales
  cout << fixed << setprecision(100);

  // Mostramos resultados y convertimos e milisegundos a segindos /1000000.0
  cout <<  tam << "\t" << duration.count()/ 1000000.0 << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}