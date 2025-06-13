/*
        Este código solo maneja la parte gráfica y de selección de los datos
        PERO NO MANEJA LA PARTE DE LA LÓGICA de los vectores y del juego.
        Solo representación gráfica

*/

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>


#include "rlutil.h"
using namespace std;

void borrarPantalla();
void cambiarFondo( int colorFondo);
void cambiarLetra( int colorLetra);
void dibujarMarco(int x, int y, int largo,int ancho);
void sortearJugadores(string &jugador1,string &jugador2);
void jugar(CONST int DADOS_INICIALES);
int lanzarDado(int caras);
void turnoJugador(string nombre, int &puntaje, int dadosStock[], int DADOS_INICIALES);
void imprimirLineas(int largo,char caracter);
void encabezado(int x, int y, int ancho);
void dibujarDado(int cantCaras, int valorDado, int x, int y);

void jugarRonda(string &jugador1, string &jugador2, int &ronda);






int main(){
    const int DADOS_INICIALES = 6;
    const int RONDAS = 3;


    HWND hWnd = GetConsoleWindow(); // Usado para maximizar la pantalla
    ShowWindow(hWnd, SW_SHOWMAXIMIZED); // Usado para maximizar la pantalla
    srand(time(0));
    cambiarFondo(1);
    cambiarLetra(1);
    rlutil::saveDefaultColor();
    jugar(DADOS_INICIALES);



   return 0;
}




void borrarPantalla() {
    rlutil::cls(); // rlutil tiene su propia función para limpiar la pantalla
}

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


void dibujarMarco(int x, int y, int largo,int ancho){
    rlutil::locate(x, y);
    imprimirLineas(ancho, '-');
    for (int i=1;i<largo;i++){
        rlutil::locate(x, y+i);
        imprimirLineas(1, '|');
        rlutil::locate(x+ancho-1, y+i);
        imprimirLineas(1, '|');
        rlutil::locate(x+10, y+i);

    }
    rlutil::locate(x, y+largo);
    imprimirLineas(ancho, '-');

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


void jugar(CONST int DADOS_INICIALES)
{
    string jugador1="", jugador2="";
    int x=35,y=6,largo=20,ancho=50;

    int puntaje1 = 0, puntaje2 = 0;
    int ronda=1;

    int dadosStock1[DADOS_INICIALES] = {0, 0, 0, 0, 0, 0}; // Valores iniciales
    int dadosStock2[DADOS_INICIALES] = {0, 0, 0, 0, 0, 0};

    //int dadosStock1[DADOS_INICIALES] = {6, 3, 5, 2, 4, 1}; // Valores iniciales
    //int dadosStock2[DADOS_INICIALES] = {1, 2, 3, 4, 5, 6};

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



void imprimirLineas(int largo,char caracter){
    // Imprimir caracteres de manera repetida
    for (int i=0; i<largo;i++){
        cout << caracter;
    }

}

void encabezado(int x, int y, int ancho){
    int ubicacion=0;
    ubicacion=ancho-x-11;
    ubicacion = ubicacion/2;
    rlutil::locate(x, y);
    imprimirLineas(ancho, '-');

    rlutil::locate(ubicacion, y+1);
    cout << "Enfrendados" << endl;
    rlutil::locate(x, y+2);
    imprimirLineas(ancho, '-');



}




void dibujarDado(int cantCaras, int valorDado, int x, int y) {

    int colorFondo=10; // Color verde claro
    int colorLetra=3; // Color Cyan
    string dado[5]; // 5 filas de caracteres

    // Inicializamos con el borde y espacios
    dado[0] = "+-------+";
    dado[1] = "|       |";
    dado[2] = "|       |";
    dado[3] = "|       |";
    dado[4] = "+-------+";


    // Lógica para colocar los puntos O EL NÚMERO según el valor del dado y cantCaras
    if (cantCaras == 12) {
        dado[0] = "/=======\\";
        dado[4] = "\\=======/";
        colorLetra=4; //  Cambiamos el color de la letra a rojo para diferenciar el dado de 6 caras

        // Si es un dado de 12 caras, mostramos el número en el centro
        string sValor = to_string(valorDado); // Convertimos el número a string
        int len = sValor.length(); // Longitud del número

        // Calculamos la posición inicial para centrar el número
        // La columna 4 es el centro, pero si el número es de 2 dígitos, necesitamos ajustar
        int startCol = 4 - (len / 2);

        // Limpiamos la fila central para asegurar que no haya asteriscos residuales
        dado[2] = "|       |";

        // Colocamos el número en la posición calculada
        for (int i = 0; i < len; ++i) {
            dado[2][startCol + i] = sValor[i];
        }
    } else {
        // Si no es un dado de 12 caras (asumimos que es de 6, pero puedes extenderlo),
        // mantenemos la lógica de los puntos
        switch (valorDado) {
            case 1:
                dado[2][4] = '*'; // Punto central
                break;
            case 2:
                dado[1][2] = '*'; // Superior izquierda
                dado[3][6] = '*'; // Inferior derecha
                break;
            case 3:
                dado[1][2] = '*';
                dado[2][4] = '*';
                dado[3][6] = '*';
                break;
            case 4:
                dado[1][2] = '*';
                dado[1][6] = '*';
                dado[3][2] = '*';
                dado[3][6] = '*';
                break;
            case 5:
                dado[1][2] = '*';
                dado[1][6] = '*';
                dado[2][4] = '*';
                dado[3][2] = '*';
                dado[3][6] = '*';
                break;
            case 6:
                dado[1][2] = '*';
                dado[1][6] = '*';
                dado[2][2] = '*';
                dado[2][6] = '*';
                dado[3][2] = '*';
                dado[3][6] = '*';
                break;
            default:
                // Manejar un valor inválido o para dados de más de 6 caras que no sean 12
                break;
        }
    }

    // Imprimir el dado
    rlutil::setBackgroundColor(colorFondo);
    rlutil::setColor(colorLetra);
    for (int i = 0; i < 5; ++i) {
        rlutil::locate(x, y + i); // Ahora 'y' es la posición inicial, sumamos 'i' para cada fila
        cout << dado[i] << endl;
    }

    rlutil::resetColor();

}

void jugarRonda(string &jugador1, string &jugador2, int &ronda){
    borrarPantalla();
    const int xOrig=5;
    int x=xOrig, y=5;
    //int vectorjugador[10]=
    int valorDado=0;
    int ancho =120;
    int vectorDados[11]={0,0,0,0,0,0,0,0,0,0,0};
    int dadoObj;
    int cantidadDados=11;
    int valorDado12A=0,valorDado12B=0;
    int sumaSeleccionada=0;
    string mensaje="";

    dibujarMarco(x,y,30,ancho);
    encabezado(x,y,ancho);
    int contador=0;
    y+=4;
    if (ronda==1){
        x+=5;
        rlutil::locate(x,y);
        cout << "Estos son los dados Objetivo del jugador/a " << jugador1 << ":";
        valorDado12A=lanzarDado(12);
        y+=2;
        dibujarDado(12,valorDado12A,x+10,y);
        valorDado12B=lanzarDado(12);
        dibujarDado(12,valorDado12B,x+20,y);
        y+=6;
        rlutil::locate(x,y);
        cout << "La suma de los dados es: " << valorDado12A+valorDado12B;
        y++;
        rlutil::locate(x,y);
        cout << "Estos son los dados del jugador/a " << jugador1 << ":";
        y+=2;
        for (int i=0; i< cantidadDados;i++){
            rlutil::locate(x+1,y);
            cout << "Dado " << i+1;
            valorDado=lanzarDado(6);
            vectorDados[i]=valorDado;
            dibujarDado(6,valorDado,x,y+2);
            x+=10;

        }
        x = xOrig+5;
        y+=8;
        rlutil::locate(x,y);
        cout << "Elige el número de dado que deseas usar para lograr tu valor objetivo";
        rlutil::locate(x,y+1);
        cout << "(Dejas de ingresar dados si escribes 0):   ";
        mensaje= "Dado(s) elegido(s)";
        rlutil::showcursor();
        do {
            rlutil::locate(x+41, y+1);
            cin >> dadoObj;

            if (dadoObj != 0) {
                rlutil::locate(x+41, y+5);
                mensaje += " " + to_string(dadoObj);
                cout << mensaje;
                contador+=dadoObj;
                sumaSeleccionada+=vectorDados[dadoObj-1];
                rlutil::locate(x+41, y+6);
                cout << "Suma de los dados: " << sumaSeleccionada;
            }
        } while (dadoObj != 0);




        }
    rlutil::anykey();

}

