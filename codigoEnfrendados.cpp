#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>
#include "codigoEnfrendados.h"

#include "rlutil.h"

const int DADOS_INICIALES = 6;
const int RONDAS = 3;


void esperar(int tiempo){
    rlutil::msleep(tiempo);
    rlutil::anykey();




}

bool salir()
{ // Pregunta si realmente desea salir
    char deseaSalir;
    rlutil::locate(54, 17);
    cout << "¿Realmente desea salir? S/N";
    rlutil::locate(82, 17);
    cin >> deseaSalir;
    deseaSalir = toupper(deseaSalir);
    if (deseaSalir == 'S')
    {
        return true;
    }
}




void sortearJugadores(string &jugador1,string &jugador2){
    int primerDado=0;
    int segundoDado=0;
    int xDado=46;
    int yDado=15;


    rlutil::locate(40, 8);
    cout << "Ingresa el nombre del Jugador 1: ";

    rlutil::locate(40, 10);
    cout << "Ingresa el nombre del Jugador 2: ";

    rlutil::locate(73, 8);
    cin >> jugador1;
    rlutil::locate(73, 10);
    cin >> jugador2;

    do {
        primerDado=lanzarDado(12);
        segundoDado=lanzarDado(12);

    } while(primerDado == segundoDado);


    rlutil::locate(xDado-5,yDado-3);
    cout << "Ahora se sorteará quien juega primero:";
    yDado++;

    rlutil::locate(xDado+4,yDado-2);
    cout << jugador1;

    dibujarDado(12, primerDado, xDado+3,yDado);

    xDado+=13;

    rlutil::locate(xDado+2,yDado-2);
    cout << jugador2;

    dibujarDado(12, segundoDado,xDado+2, yDado);
    if (primerDado < segundoDado){
        swap (jugador1,jugador2);

    }

    yDado+=6;
    rlutil::hidecursor();
    rlutil::locate(40,yDado);
    cout << jugador1 << " le toca tirar primero los dados.";
    rlutil::locate(40,yDado+2);
    cout << "¡Toca una tecla para comenzar a jugar!";
    rlutil::locate(55,yDado+3);
    cout << "¡Suerte!";




}


void jugar()
{

    string jugador1="", jugador2="";
    int x=35,y=6,largo=20,ancho=50;


    int puntaje1 = 0, puntaje2 = 0;

    int dadosStock1[DADOS_INICIALES] = {0, 0, 0, 0, 0, 0}; // Valores iniciales
    int dadosStock2[DADOS_INICIALES] = {0, 0, 0, 0, 0, 0};

    borrarPantalla();
    dibujarMarco(x,y,largo,ancho);
    sortearJugadores (jugador1, jugador2);
    //rlutil::locate(40, 11);

    //cout << jugador1 << " " << jugador2;
    rlutil::showcursor;
    esperar(1000);
    ronda(jugador1, jugador2);



}

int lanzarDado(int caras)
{
    return rand() % caras + 1;
}

void turnoJugador(string nombre, int &puntaje, int dadosStock[])
{
    cout << nombre << " está lanzando...\n";

    int dado1 = lanzarDado(5);
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

void ronda(string &jugador1, string &jugador2){

}

void mostrarDadoFalso (int cantCaras, int x, int y){
	int rangoTiempo=140;
	for (int i=0;i<15;i++){
		rlutil::msleep(rand() % rangoTiempo+50);
		dibujarDado(cantCaras, lanzarDado(cantCaras), x, y);
	}
}
