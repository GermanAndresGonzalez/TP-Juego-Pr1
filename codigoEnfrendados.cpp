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
    string mensaje="";


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




    //rlutil::locate(xDado+4,yDado-2);
    xDado=calcularCentroTexto(xDado+10, jugador1, 50);
    rlutil::locate(xDado,yDado-2);

    cout << jugador1;
    mostrarDadoFalso(12,xDado,yDado);
    dibujarDado(12, primerDado, xDado,yDado);

    xDado+=13;



    //rlutil::locate(xDado+2,yDado-2);
    xDado=(calcularCentroTexto(xDado, jugador2, 25)+25);
    rlutil::locate(xDado,yDado-2);
    cout << jugador2;

    mostrarDadoFalso(12,xDado, yDado);
    dibujarDado(12, segundoDado,xDado, yDado);
    if (primerDado < segundoDado){
        swap (jugador1,jugador2);

    }

    yDado+=6;
    rlutil::hidecursor();
    mensaje= jugador1 + " tira primero los dados.";
    rlutil::locate(40,yDado);

    cout << mensaje;
    rlutil::locate(40,yDado+2);
    cout << "¡Toca una tecla para comenzar a jugar!";
    rlutil::locate(55,yDado+3);
    cout << "¡Suerte!";


}


void jugar(bool inicial)
{
    string jugador1="", jugador2="";
    int x=35,y=6,largo=20,ancho=50;

    int puntaje1 = 0, puntaje2 = 0;
    int ronda=1;

    int dadosStock1[12] ={};
    int dadosStock2[12] ={};


    borrarPantalla();
    dibujarMarco(x,y,largo,ancho);
    sortearJugadores (jugador1, jugador2);
    //rlutil::locate(40, 11);

    //cout << jugador1 << " " << jugador2;
    rlutil::showcursor;

    rlutil::msleep(500);
    rlutil::anykey();
    jugarRonda(jugador1, jugador2,ronda);

}

int lanzarDado(int caras)
{
    return rand() % caras + 1;
}

void turnoJugador(string nombre, int &puntaje, int dadosStock[], int DADOS_INICIALES)
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



void jugarRonda(string &jugador1, string &jugador2, int &ronda){
    borrarPantalla();
    const int xOrig=5;
    int x=xOrig, y=5;
    //int vectorjugador[10]=
    int valorDado=0;
    int ancho =120;
    int vectorDados[11]={0,0,0,0,0,0,0,0,0,0,0};
    int vectorStock[11]={0,0,0,0,0,0,0,0,0,0,0}; // 1 presente 0 ausente
    int vectorUsados[11]={0,0,0,0,0,0,0,0,0,0,0}; // 1 presente 0 ausente
    int puntos=0;
    int dadoObj;
    int cantidadDados=11;
    int valorDado12A=0,valorDado12B=0;
    int sumaDados12;
    int sumaSeleccionada=0;
    int contadorDados=0;
    string mensaje="";

    dibujarMarco(x,y,30,ancho);
    encabezado(x,y,ancho);
    int contador=0;
    y+=4;
    if (ronda==1){
        x+=5;
        rlutil::locate(x+20,y);
        cout << "Estos son los dados Objetivo de " << jugador1 << ":";
        valorDado12A=lanzarDado(12);
        y+=2;
        mostrarDadoFalso(12,x+30,y);
        dibujarDado(12,valorDado12A,x+30,y);
        valorDado12B=lanzarDado(12);
        mostrarDadoFalso(12,x+40,y);
        dibujarDado(12,valorDado12B,x+40,y);
        y+=6;
        rlutil::locate(x,y);
        sumaDados12=valorDado12A+valorDado12B;
        cout << "La suma de los dados es: " << sumaDados12;
        y++;
        rlutil::locate(x,y);
        cout << "Estos son los dados de " << jugador1 << ":";
        y+=2;
        for (int i=0; i< cantidadDados;i++){
            rlutil::locate(x+1,y);
            cout << "Dado " << i+1;
            valorDado=lanzarDado(6);
            vectorDados[i]=valorDado;
            vectorStock[i]=1;
            vectorUsados[i]=1;
            mostrarDadoFalso(6,x,y+2);
            dibujarDado(6,valorDado,x,y+2);
            x+=10;

        }
        x = xOrig+5;
        y+=8;
        rlutil::locate(x,y);
        cout << "Elige el número de dado que deseas usar para lograr tu valor objetivo";
        rlutil::locate(x,y+1);
        cout << "(Elegí 0 para dejar de ingresar dados):     ";
        mensaje= "Dado(s) elegido(s)";
        rlutil::showcursor();
        do {
            rlutil::locate(x+41, y+1);
            cout << "    ";
            rlutil::locate(x+41, y+1);

            cin >> dadoObj;

            if (dadoObj != 0) {

                if (vectorUsados[dadoObj-1]==1){

                    rlutil::locate(x+41, y+5);
                    mensaje += " " + to_string(dadoObj);
                    cout << mensaje;
                    contador+=dadoObj;
                    sumaSeleccionada+=vectorDados[dadoObj-1];
                    rlutil::locate(x+41, y+6);
                    cout << "Suma de los dados: " << sumaSeleccionada << "          ";
                    vectorUsados[dadoObj-1]=0;
                    contadorDados++;

                }else{
                    rlutil::locate(x+41, y+6);
                    cout << "Dado ya usado o no presente";
                }



            }
        } while (dadoObj != 0);

        if (sumaSeleccionada==(valorDado12A+valorDado12B) ){
            puntos = sumaDados12* contadorDados;
            rlutil::locate(x+41, y+4);
            cout << "Tirada exitosa, se suman " << puntos << " puntos a " << jugador1 << endl;
            rlutil::locate(x+41, y+5);
            cout << "Le pasa " << contadorDados << " a " << jugador2 << endl;
        } else {
            rlutil::locate(x+41, y+4);
            cout << "Tirada fallida no se suman puntos"<< endl;
        }
        esperar(250);



        mostrarVector(vectorUsados,11);
        }
    rlutil::anykey();

}

int calcularCentroTexto(int x, string cadena, int ancho){
    int largo= cadena.length();
    int num=((x+ancho)-largo)/2;
    return num;
}
