#include <iostream>
#include "codigoEnfrendados.h"
using namespace std;

void mostrarVector(int vec[],int largo){
    cout << endl;
    for (int i=0; i<largo;i++){
        cout << vec[i] << " ";
    }
}

void inicializarVector(int vec[], int largo){
    for (int i=0;i<5;i++){
        vec[i]=1;
    }

}

void restarVector(int vec[], int largo){




}

void sumarDadosVector(int vec[], int largo){



}

// Cuenta los dados que tiene el jugador en el vector
int contarDadosVector(int vec[], int largo){
    int contador=0;
    for (int i=0;i<largo;i++){
        if (vec[i]!=0){
            contador++;
        }

    }
    return contador;
}


