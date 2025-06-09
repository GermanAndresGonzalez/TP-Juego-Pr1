#include <iostream>
#include <chrono>
#include <thread>
#include "codigoEnfrendados.h"
#include "rlutil.h"

const int DADOS_INICIALES = 6;
const int RONDAS = 3;



void cambiarFondo( int colorFondo)
{
    switch (colorFondo)
    {
    case 1:
        rlutil::setBackgroundColor(rlutil::GREY);
        break;
    case 2:
        rlutil::setBackgroundColor(rlutil::WHITE);
        break;
    case 3:
        rlutil::setBackgroundColor(rlutil::BLACK);
        break;
    }
}
void cambiarLetra( int colorLetra)
{

    switch (colorLetra)
    {
    case 1:
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        break;
    case 2:
        rlutil::setColor(rlutil::RED);
        break;
    case 3:
        rlutil::setColor(rlutil::BLACK);
        break;
    case 4:
        rlutil::setColor(rlutil::BLUE);
        break;
    }

}

bool salir()
{ // Pregunta si realmente desea salir
    char deseaSalir;
    rlutil::locate(51, 17);
    cout << "¿Realmente desea salir? S/N                ";
    rlutil::locate(79, 17);
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

        cambiarFondo(1);
        cambiarLetra(1);
        rlutil::cls();
        encabezado(40,6);

        rlutil::locate(59, 10);
        cout << "1 - JUGAR";

        rlutil::locate(59, 11);
        cout << "2 - ESTADÍSTICAS";

        rlutil::locate(59, 12);
        cout << "3 - CRÉDITOS";

        rlutil::locate(59, 13);
        cout << "0 - SALIR";

        rlutil::locate(40, 15);
        imprimirLineas(49,'-');

        rlutil::locate(59, 17);
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail())  // En caso de que se ingrese una caracter en vez de un número y no de error
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

    cambiarFondo(2);
    cambiarLetra(2);
    // rlutil::cls();
    cout << endl;
    cout << "Puntaje final: " << jugador1 << " = " << puntaje1 << ", " << jugador2 << " = " << puntaje2 << "\n";
    cout << endl
         << "Presiona una tecla para volver al menú." << endl;
    rlutil::anykey();
    cambiarFondo(1);
    cambiarLetra(1);


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

void imprimirLineas(int largo,char caracter){
    // Imprimir caracteres de manera repetida
    for (int i=0; i<largo;i++){
        cout << caracter;
    }

}

void encabezado(int x, int y){

    rlutil::locate(x, y);
    imprimirLineas(49, '-');

    rlutil::locate(x+19, y+1);
    cout << "Enfrendados" << endl;
    rlutil::locate(x, y+2);
    imprimirLineas(49, '-');



}

void mostrarCreditos()
{

    rlutil::cls();
    encabezado(40,5);
    rlutil::locate(59, 9);
    cambiarLetra(3);
    cout << "UTN|";

    cambiarLetra(4);
    cout << "FRGP";

    rlutil::locate(44, 10);
    cambiarLetra(3);
    cout << "Trabajo Práctico Integrador - Año 2025 1C";
    cambiarLetra(4);
    rlutil::locate(59, 11);
    cout << "Grupo 09";

    cambiarLetra(1);

    rlutil::locate(41, 13);
    cout << "Braian Gigena. Legajo numero ";

    rlutil::locate(41, 14);
    cout << "Francisco Emmanuel Montilla. Legajo numero ";

    rlutil::locate(41, 15);

    cout << "German Andres Gonzalez. Legajo numero ";

    rlutil::locate(41, 16);
    cout << "Mayra Elisabet Schuchman. Legajo numero ";
    rlutil::locate(40, 18);

    imprimirLineas(49, '-');

    rlutil::locate(40, 20);

    cout << "Presiona una tecla para volver al menú.";
    rlutil::anykey();
    rlutil::cls();

}
