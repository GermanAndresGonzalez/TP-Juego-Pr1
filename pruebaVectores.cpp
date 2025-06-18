#include <iostream>
#include <cstdlib>
// #include "codigoEnfrendados.h"
using namespace std;

int contarDadosVector(int vec[], int largo);
void sumarDadosVector(int vec[], int largo);
void restarVector(int vec[], int cantidad);
void inicializarVector(int vec[], int inicial);
void mostrarVector(int vec[], int largo);

int main()
{
    system("cls");
    cout << "Prueba de vectores" << endl;
    const int largo = 12;
    const int inicial = 6;
    int vec[largo] = {0}; // Inicializar el vector con ceros

    // Inicializar el vector
    inicializarVector(vec, inicial);
    mostrarVector(vec, largo);
    restarVector(vec, 3);
    mostrarVector(vec, largo);
    return 0;
}

void mostrarVector(int vec[], int largo)
{
    cout << endl;
    for (int i = 0; i < largo - 1; i++)
    {
        cout << "Elemento " << i << ": " << vec[i] << endl;
    }
}

void inicializarVector(int vec[], int inicial)
{
    for (int i = 0; i < inicial; i++)
    {
        vec[i] = 1;
    }
}

void restarVector(int vec[], int cantidad)
{
    for (int i = 11; i > 0; i--)
    {
        if ((vec[i] != 0) && (cantidad > 0))
        {
            vec[i] = 0;
            cantidad--;
        }
    }
}

void sumarDadosVector(int vec[], int largo)
{
}

// Cuenta los dados que tiene el jugador en el vector
int contarDadosVector(int vec[], int largo)
{
    int contador = 0;
    for (int i = 0; i < largo; i++)
    {
        if (vec[i] != 0)
        {
            contador++;
        }
    }
    return contador;
}
