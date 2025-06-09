#include <iostream>
#include "codigoEnfrendados.h"
#include <time.h>

using namespace std;

int main() {
    bool respuestaSalir=true;
    srand(time(0)); // Inicializar la aleatoriedad
    while (respuestaSalir == true){
        mostrarMenu();
        respuestaSalir=salir();
    }




    return 0;
}




