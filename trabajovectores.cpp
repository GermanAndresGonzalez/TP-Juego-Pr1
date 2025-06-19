#include <iostream>
#include "codigoEnfrendados.h"
using namespace std;

void mostrarVector(int vec[],int cantidad){
    cout << endl;
    for (int i=0; i<cantidad;i++){
        cout << vec[i] << " ";
    }
}

void inicializarVector(int vec[], int inicial){

    for (int i=0; i<12;i++){
        vec[i]=0;
    }

    for (int i = 0; i < inicial; i++)
    {
    vec[i] = 1;
    }
}

void restarVector(int vec[], int cantidad)
{
    for (int i = 0; i <10; i++)
    {
        if ((vec[i] != 0) && (cantidad > 0))
        {
            vec[i] = 0;
            cantidad--;
        }
    }
}

void sumarDadosVector(int vec[], int cantidad){
    for (int i = 0; i <11; i++)
    {
        if ((vec[i] == 0) && (cantidad > 0))
        {
            vec[i] = 1;
            cantidad--;
        }
    }


}


// Cuenta los dados que tiene el jugador en el vector
int contarDadosVector(int vec[], int cantidad){
    int contador=0;
    for (int i=0;i<cantidad;i++){
        if (vec[i]!=0){
            contador++;
        }

    }
    return contador;
}


