#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <clocale>
#include "codigoEnfrendados.h"

#include <time.h>


using namespace std;

int main()
{
    HWND hWnd = GetConsoleWindow(); // Usado para maximizar la pantalla
    ShowWindow(hWnd, SW_SHOWMAXIMIZED); // Usado para maximizar la pantalla

    bool respuestaSalir = false;
    srand(time(0)); // Inicializar la aleatoriedad

    //dibujarMarco(10, 6, 20,60);


    while (respuestaSalir != true)
    {
        mostrarMenu();
        respuestaSalir = salir();
    }

    return 0;
}
