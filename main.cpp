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



    while (respuestaSalir != true)
    {
        respuestaSalir= mostrarMenu();
        //respuestaSalir = salir();
    }

    return 0;
}
