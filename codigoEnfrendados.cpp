#include <iostream>
#include <chrono>
#include <thread>
#include "codigoEnfrendados.h"
#include "rlutil.h"

const int DADOS_INICIALES = 6;
const int RONDAS = 3;

void cambiarColores(int codigo)
{
    switch (codigo)
    {
    case 1:
        rlutil::setBackgroundColor(rlutil::GREY);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        break;
    case 2:
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::RED);
        break;
    }
}

bool salir()
{ // Pregunta si realmente desea salir
    char deseaSalir;
    rlutil::locate(40, 17);
    cout << "¿Realmente desea salir? S/N ";
    cin >> deseaSalir;
    deseaSalir = toupper(deseaSalir);
    if (deseaSalir == 'S')
    {
        return false;
    }
}

void mostrarMenu()
{ // Menú del juego con cambio de colores y posción

    int opcion = 10;

    do
    {
        cambiarColores(1);
        rlutil::cls();
        rlutil::locate(40, 10);
        cout << "1 - JUGAR" << endl;
        rlutil::locate(40, 11);
        cout << "2 - ESTADÍSTICAS" << endl;
        rlutil::locate(40, 12);
        cout << "3 - CRÉDITOS" << endl;
        rlutil::locate(40, 13);
        cout << "0 - SALIR" << endl;
        rlutil::locate(40, 14);
        cout << "------------------------------" << endl;
        rlutil::locate(40, 15);
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 10;
            continue;
        }

        switch (opcion)
        {
        case 1:
            jugar();
            break;
        case 2:
            cout << "Mostrar estadísticas\n";
            break;
        case 3:
            mostrarCreditos();
            continue;
        }
    } while (opcion != 0);
}

void jugar()
{
    string jugador1, jugador2;
    int puntaje1 = 0, puntaje2 = 0;
    int dadosStock1[DADOS_INICIALES] = {6, 3, 5, 2, 4, 1}; // Valores iniciales
    int dadosStock2[DADOS_INICIALES] = {1, 2, 3, 4, 5, 6};
    rlutil::cls();
    rlutil::locate(40, 10);
    cout << "Ingrese nombre del Jugador 1: ";
    cin >> jugador1;
    rlutil::locate(40, 11);
    cout << "Ingrese nombre del Jugador 2: ";
    cin >> jugador2;

    // Simulación de rondas
    for (int ronda = 1; ronda <= RONDAS; ronda++)
    {
        cout << "\n--- RONDA " << ronda << " ---\n";
        turnoJugador(jugador1, puntaje1, dadosStock1);
        turnoJugador(jugador2, puntaje2, dadosStock2);

        // Verificar si alguien ganó automáticamente
        if (verificarVictoria(dadosStock1) || verificarVictoria(dadosStock2))
        {
            cout << "¡Victoria automática!\n";
            break;
        }
    }

    // Resultado final

    cambiarColores(2);
    // rlutil::cls();
    cout << endl;
    cout << "Puntaje final: " << jugador1 << " = " << puntaje1 << ", " << jugador2 << " = " << puntaje2 << "\n";
    cout << endl
         << "Presiona una tecla para volver al menú." << endl;
    rlutil::anykey();
    cambiarColores(1);
}

int lanzarDado(int caras)
{

    return rand() % caras + 1;
}

void turnoJugador(string nombre, int &puntaje, int dadosStock[])
{
    cout << nombre << " está lanzando...\n";

    int dado1 = lanzarDado(12);
    int dado2 = lanzarDado(12);
    int objetivo = dado1 + dado2;

    cout << "Número objetivo: " << objetivo << endl;

    cout << "Dados en stock: ";
    for (int i = 0; i < DADOS_INICIALES; i++)
        cout << dadosStock[i] << " ";
    cout << endl;

    // Aquí se puede agregar la lógica de selección de dados y cálculo de puntaje
}

bool verificarVictoria(int dadosStock[])
{
    int cantidadDados = 0;
    for (int i = 0; i < DADOS_INICIALES; i++)
        cantidadDados += dadosStock[i] != 0 ? 1 : 0;
    return cantidadDados == 0;
}

void mostrarCreditos()
{
    rlutil::cls();
    rlutil::locate(40, 10);
    cout << "------------------------------" << endl;
    rlutil::locate(40, 11);
    cout << "Braian Gigena" << endl;
    rlutil::locate(40, 12);
    cout << "Francisco Emmanuel Montilla" << endl;
    rlutil::locate(40, 13);
    cout << "German Andres Gonzalez" << endl;
    rlutil::locate(40, 14);
    cout << "Mayra Elisabet Schuchman" << endl;
    rlutil::locate(40, 15);
    cout << "------------------------------" << endl;
    rlutil::locate(40, 16);
    cout << "Presiona una tecla para volver al menú.";

    rlutil::anykey();
    rlutil::cls();

    // return 0;
}
