#include <iostream>
#include <clocale>
#include "codigoEnfrendados.h"

#include <time.h>


using namespace std;

int main()
{
    bool respuestaSalir = true;
    srand(time(0)); // Inicializar la aleatoriedad

    //dibujarMarco(10, 6, 20,60);


    while (respuestaSalir == true)
    {
        mostrarMenu();
        respuestaSalir = salir();
    }

    return 0;
}
