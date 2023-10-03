/*#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
using namespace std;

void ordenar(int *v, int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (v[j]>v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}


int main()
{   
    //GENERADOR DE VECTOR ALEATORIO
    int tam = 15000;
    int *v=new int[tam];
    srand(time(0)); //inicialización generador numeros pseudoaleatorios
    for (int i = 0; i < tam; i++){
        v[i] = rand() & RAND_MAX;
    }
    

     
    //CALCULO DEL TIEMPO
    clock_t tini ;//tiempo de inicio
    tini=clock();

    ordenar(v, tam);//ORDENAMOS

    clock_t tfin ;//tiempo de finalizacion
    tfin=clock();
    
    cout<<(tfin-tini)/(double)CLOCKS_PER_SEC<<" "<<tam<<endl;

    // Liberar la memoria asignada al array
    delete[] v;
    return 0;
}*/

#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
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
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (v[j]>v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
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

    clock_t tini; // Anotamos el tiempo de inicio
    tini=clock();

    int x = vmax+1; // Buscamos un valor que no está en el vector
    buscar(v,tam,x); // de esta forma forzamos el peor caso
    ordenar(v, tam);//ORDENAMOS    

    clock_t tfin; // Anotamos el tiempo de finalización
    tfin=clock();
    // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

    delete [] v; // Liberamos memoria dinámica
}
