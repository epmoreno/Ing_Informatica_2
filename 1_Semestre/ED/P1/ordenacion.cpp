#include <iostream>
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
    int tam = 30000;
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
    
    cout<<endl;
    cout<<"Tamaño = "<<tam<<", tiempo de ejecución en seg = "<<(tfin-tini)/(double)CLOCKS_PER_SEC<<endl;
    cout<<endl;
    
    // Liberar la memoria asignada al array
    delete[] v;
    return 0;
}
