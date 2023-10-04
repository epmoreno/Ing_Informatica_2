#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
#include <chrono>
#include <iomanip>

using namespace std;
int buscar(const int *v, int n, int x) {
    int i=0;
    while (i<n && v[i]!=x)
        i=i+1;
        if(i<n)
            return i;
        else
            return -1;
}
void ordenar(int *v, int n) {
    bool cambio=true;
    for (int i=0; i<n-1 && cambio; i++) {
        cambio=false;
        for (int j=0; j<n-i-1; j++)
            if (v[j]>v[j+1]) {
                cambio=true;
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
    }
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
 exit(EXIT_FAILURE);
}
int main(int argc, char * argv[]) {
    if (argc!=3) // Lectura de parámetros
        sintaxis();
    int tam=atoi(argv[1]); // Tamaño del vector
    int vmax=atoi(argv[2]); // Valor máximo
    if (tam<=0 || vmax<=0)
        sintaxis();

    // Generación del vector aleatorio
    int *v=new int[tam]; // Reserva de memoria
    srand(time(0)); // Inicialización generador números pseudoaleatorios
    for (int i=0; i<tam; i++) // Recorrer vector
        v[i] = rand() % vmax; // Generar aleatorio [0,vmax[

    

    auto start = std::chrono::high_resolution_clock::now();

    ordenar(v, tam);//ORDENAMOS PREVIAMENTE
    ordenar(v, tam);//ORDENAMOS PREVIAMENTE
    buscar(v,tam,vmax);
    

    auto stop = std::chrono::high_resolution_clock::now();

    //Microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    //Mayor nº demimales
    cout << fixed << setprecision(100);

    // Mostramos resultados y convertimos e milisegundos a segindos /1000000.0
    cout <<  tam << "\t" << duration.count()/ 1000000.0 << endl;
    
    delete [] v; // Liberamos memoria dinámica
}
