#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdio>
#include "codigoEnfrendados.h"

#include "rlutil.h"

//const int DADOS_INICIALES = 6;
//const int RONDAS = 3;


void esperar(int tiempo){

    rlutil::msleep(tiempo);
    rlutil::anykey();

}

bool salir()
{ // Pregunta si realmente desea salir
    char deseaSalir;
    rlutil::locate(54, 17);
    cout << "¿Realmente deseas salir? S/N";
    rlutil::locate(83, 17);
    cin >> deseaSalir;
    deseaSalir = toupper(deseaSalir);
    if (deseaSalir == 'S')
    {
        return true;
    } else {
        return false;
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
    //xDado=calcularCentroTexto(xDado+10, jugador1, 25);
    xDado=xDado+5 ;
    rlutil::locate(xDado,yDado-2);

    cout << jugador1;
    mostrarDadoFalso(12,xDado,yDado);
    dibujarDado(12, primerDado, xDado,yDado);

    xDado+=13;



    //rlutil::locate(xDado+2,yDado-2);
    xDado+=jugador1.length()+1;
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


void jugar(string &jugador1, string &jugador2,  int vec[], int vec2[])
{
    int numInicial=6;

    int x=35,y=6,largo=20,ancho=50;

    int puntaje1 = 0, puntaje2 = 0;
    int ronda=1;
    bool ganador=false;


    inicializarVector(vec,numInicial);
    inicializarVector(vec2,numInicial);


    borrarPantalla();
    dibujarMarco(x,y,largo,ancho);
    sortearJugadores (jugador1, jugador2);


    rlutil::showcursor;

    rlutil::msleep(500);
    rlutil::anykey();


    do {
        borrarPantalla();
        imprimirRonda(25, 3, jugador1, ronda);
        jugarRonda(jugador1, jugador2, vec,vec2);

        if ((contarDadosVector(vec,12)==0)){
            mostrarGanador(jugador1,vec);
            ganador=true;
        }


        borrarPantalla();
        imprimirRonda(25, 3, jugador2, ronda);
        jugarRonda(jugador2, jugador1, vec2,vec);
        ronda++;

        if ((contarDadosVector(vec2,12)==0)){
            mostrarGanador(jugador2,vec2);
            ganador=true;
        }


    } while ((ronda<4) &&(ganador==false) );

    if (ganador==false) {
        if ((vec[11]) > (vec2[11])){

            mostrarGanador(jugador1,vec);

        }else {
            mostrarGanador(jugador2,vec2);

        }

    }
    esperar(500);
    rlutil::anykey();



}

int lanzarDado(int caras)
{
    return rand() % caras + 1;
}

void turnoJugador(string nombre, int vec[] )
{
    int dadosInciales = 0;
    dadosInciales= contarDadosVector(vec,11);
    cout << nombre << " está lanzando...\n";

    int dado1 = lanzarDado(5);
    int dado2 = lanzarDado(12);
    int objetivo = dado1 + dado2;

    cout << "Número objetivo: " << objetivo << endl;

    cout << "Dados en stock: ";
    for (int i = 0; i < dadosInciales; i++)
        cout << vec[i] << " ";
    cout << endl;

}

bool verificarVictoria(int vec[])
{

    int cantidadDados = 0;
    for (int i = 0; i < 11; i++)
        cantidadDados += vec[i] != 0 ? 1 : 0;
    return cantidadDados == 0;
}

//void ronda(string &jugador1, string &jugador2){}

void mostrarDadoFalso (int cantCaras, int x, int y){
	int rangoTiempo=140;
	for (int i=0;i<15;i++){
		rlutil::msleep(rand() % rangoTiempo+50);
		dibujarDado(cantCaras, lanzarDado(cantCaras), x, y);
	}
}



void jugarRonda(string &jugador1, string &jugador2,  int vec[], int vec2[]){


    // Variables coordenadas y dimensiones
    const int xOrig=5;
    int x=xOrig, y=5;
    int ancho =120;

    int valorDado=0;

    int vectorDados[12]={0};

    int puntos=0;
    int dadoObj;
    int cantidadDados=contarDadosVector(vec,11);
    int valorDado12A=0;
    int sumaDados12=0;
    int sumaSeleccionada=0;
    int contadorDados=0;
    string mensaje="";

    dibujarMarco(x,y,30,ancho);
    encabezado(x,y,ancho);

    int contador=0;
    y+=4;
    //if (ronda==1){
        x+=5;
        rlutil::locate(x+20,y);
        cout << "Estos son los dados Objetivo de " << jugador1 << ":";
        cout << cantidadDados;

        valorDado12A=lanzarDado(12);
        sumaDados12+=valorDado12A;
        y+=2;
        mostrarDadoFalso(12,x+30,y);
        dibujarDado(12,valorDado12A,x+30,y);
        valorDado12A=lanzarDado(12);
        sumaDados12+=valorDado12A;

        mostrarDadoFalso(12,x+50,y);
        dibujarDado(12,valorDado12A,x+50,y);
        y+=6;
        rlutil::locate(x,y);

        //cout << "La suma de los dados es: " << sumaDados12;
        y++;
        rlutil::locate(x,y);
        cout << "Estos son los dados de " << jugador1 << ":";
        y+=2;
        for (int i=0; i< cantidadDados;i++){
            rlutil::locate(x+1,y);
            cout << "Dado " << i+1;
            valorDado=lanzarDado(6);
            vectorDados[i]=valorDado;
            //vec[i]=valorDado;

            mostrarDadoFalso(6,x,y+2);
            dibujarDado(6,valorDado,x,y+2);
            x+=10;

        }
        x = xOrig+5;
        y+=8;
        rlutil::locate(x,y);
        cout << "Elige el número de dado que deseas usar para lograr tu valor objetivo";
        rlutil::locate(x,y+1);
        cout << "(Elige 0 para dejar de ingresar dados):     ";
        mensaje= "Dado(s) elegido(s)";
        rlutil::showcursor();
        do {
            rlutil::locate(x+41, y+1);
            cout << "    ";
            rlutil::locate(x+41, y+1);

            cin >> dadoObj;

            if (dadoObj != 0) {

                if (vectorDados[dadoObj-1]!=0){

                    rlutil::locate(x+41, y+5);
                    mensaje += " " + to_string(dadoObj);
                    cout << mensaje;
                    contador+=dadoObj;
                    sumaSeleccionada+=vectorDados[dadoObj-1];
                    //rlutil::locate(x+41, y+6);
                    //cout << "Suma de los dados: " << sumaSeleccionada << "          ";
                    vectorDados[dadoObj-1]=0;
                    contadorDados++;

                }else{
                    rlutil::locate(x+41, y+6);
                    cout << "Dado ya usado o no presente";
                }

            }

        } while (dadoObj != 0);

        if (sumaSeleccionada==(sumaDados12) ){
            puntos = sumaDados12* contadorDados;
            rlutil::locate(x+41, y+4);
            cout << "Tirada exitosa, se suman " << puntos << " puntos a " << jugador1 << endl;
            vec[11]+=puntos;
            restarVector(vec,contadorDados);
            sumarDadosVector(vec2,contadorDados);


            rlutil::locate(x+41, y+5);

            cout << "Le pasa " << contadorDados << " dados a " << jugador2 << "            " << endl;
            rlutil::locate(x+41, y+6);
            cout << "Presiona una tecla para seguir.";

        } else {
            rlutil::locate(x+41, y+4);
            cout << "Tirada fallida no se suman puntos"<< endl;
            if ((contarDadosVector(vec2,11)>1)) {
                sumarDadosVector(vec,1);
                restarVector(vec2,1);
                rlutil::locate(x+41, y+5);
                cout << jugador1 << " recibe 1 dado de " << jugador2;
                rlutil::locate(x+41, y+6);
                cout << "                                                 ";
            } else {
                rlutil::locate(x+41, y+5);
                cout << "                                                 ";
            }
            rlutil::locate(x+41, y+6);
            cout << "Presiona una tecla para seguir.";


        }

        esperar(250);

    rlutil::anykey();

}



void imprimirRonda(int x, int y, string nombre, int ronda){
    rlutil::locate(x,y);
    cout << "Turno de: " << nombre;

    rlutil::locate(x+55,y);
    cout << "Ronda: " << ronda << " de 3";

}

void mostrarEstadisticas(string nombre1, string nombre2, int vec[], int vec2[]){
    int x=35,y=6,largo=20,ancho=70;
    borrarPantalla();

    dibujarMarco(x,y,largo,ancho);
    x+=5;
    y+=5;
    if ((nombre1!="") && (nombre2!="")){

        rlutil::locate(x+25,y);
        cout << "Estadísticas";
        y+=2;
        y = imprimirLineaEstadistica(x,y,nombre1,vec);
        y+=2;
        y = imprimirLineaEstadistica(x,y,nombre2,vec2);
        rlutil::locate(x+5,y);
        rlutil::hidecursor();
        y+=5;
        rlutil::locate(x,y);
        cout << "Presiona una tecla para volver al menú principal.";
    } else {
        rlutil::locate(x,y);
        cout << "Todavía no hay estadísticas disponibles.";
        rlutil::locate(x,y+1);
        cout << "Presiona una tecla para volver al menú principal.";
    }



    esperar(500);
    rlutil::anykey();

}

int imprimirLineaEstadistica (int x, int y, string nombre, int vec[]){
    rlutil::locate(x,y);
    cout << nombre << " logró " << vec[11] << " puntos. " ;
    y++;
    //rlutil::locate(x,y);
    //cout << "Obtuvo: " << contarDadosVector(vec,11) << " dados" ;
    return y;

}

void mostrarGanador (string nombre, int vec[]){
    borrarPantalla();
    dibujarMarco(5,5,30,75);
    rlutil::locate(20,7);
    cout << "¡Felicitaciones " << nombre << " ganaste!";
    rlutil::locate(10,10);
    //cout << nombre << " ganó la partida por tener " << contarDadosVector(vec,12) << " y " << vec[11] << " puntos.";
    cout << "Lograste un total de " << vec[11] << " puntos.";
    rlutil::locate(10,11);
    cout << "Presiona una tecla para seguir.";
}
