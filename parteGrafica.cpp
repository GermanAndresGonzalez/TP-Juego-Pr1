#include <iostream>
#include <chrono>
#include <thread>
#include "codigoEnfrendados.h"
#include "rlutil.h"
using namespace std;


void borrarPantalla() {
    rlutil::cls(); // rlutil tiene su propia función para limpiar la pantalla
}

void cambiarFondo( int colorFondo)
{
    rlutil::setBackgroundColor(colorFondo);

}

void cambiarLetra( int colorLetra)
{
    rlutil::setColor(colorLetra);

}

void dibujarMarco(int x, int y, int largo,int ancho){
    //Cambiar color a rojo
    cambiarLetra(4);
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
    //Cambiar color a azul
    cambiarLetra(1);

}

bool mostrarMenu()
{ // Menú del juego con cambio de colores y posición
    int x=40;
    int y=5;

    int largo=13;
    int ancho=49;

    int opcion = 10;

    bool respuestaSalir2=false;


    int numInicial=6;
    string jugador1="", jugador2="";
    int dadosStock1[12] ={0};
    int dadosStock2[12] ={0};
    inicializarVector(dadosStock1,numInicial);
    inicializarVector(dadosStock2,numInicial);

    do
    {
        cambiarFondo(7);
        cambiarLetra(1);
        rlutil::saveDefaultColor();
        borrarPantalla();
        dibujarMarco(x,y,largo,ancho);
        encabezado(x,y, ancho);

        cambiarLetra(1);

        rlutil::locate(x+19, 10);
        cout << "1 - JUGAR";

        rlutil::locate(x+19, 11);
        cout << "2 - ESTADÍSTICAS";

        rlutil::locate(x+19, 12);
        cout << "3 - CRÉDITOS";

        rlutil::locate(x+19, 13);
        cout << "0 - SALIR";

        rlutil::locate(x, 16);

        // Cambiar letra a rojo

        cambiarLetra(4);
        imprimirLineas(x+9, '-');

        // Cambiar letra a azul
        cambiarLetra(1);


        rlutil::locate(x+14, 17);
        cout << "Seleccione una opción:";
        rlutil::locate(x, 18);

        rlutil::locate(x+37, 17);
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
            jugar(jugador1,jugador2,dadosStock1,dadosStock2);
            break;
        case 2:
            mostrarEstadisticas(jugador1, jugador2, dadosStock1, dadosStock2);
            break;
        case 3:
            mostrarCreditos();
            break;
        case 0:
            respuestaSalir2 = salir();

            break;

        }
    } while (respuestaSalir2 == false);
    return respuestaSalir2;
}


void imprimirLineas(int largo,char caracter){
    // Imprimir caracteres de manera repetida
    //Cambiar color a azul
    cambiarLetra(4);
    for (int i=0; i<largo;i++){
        cout << caracter;
    }
    cambiarLetra(1);
}

void encabezado(int x, int y, int largo){
    int medio=(largo-11)/2;

    rlutil::locate(x, y);
    imprimirLineas(largo, '-');

    rlutil::locate(x+medio, y+1);

    //Cambiar color a azul
    cambiarLetra(1);
    cout << "Enfrendados" << endl;

    //Cambiar color a color
    cambiarLetra(4);
    rlutil::locate(x, y+2);
    imprimirLineas(largo, '-');



}

void mostrarCreditos()
{
    int x=39,y=5,largo=15,ancho=49;

    borrarPantalla();
    dibujarMarco(x,y,largo,ancho);
    encabezado(x,y,ancho);
    rlutil::locate(x+20, y+4);
    cambiarLetra(3);
    cout << "UTN | ";

    cambiarLetra(4);
    cout << "FRGP";

    rlutil::locate(x+5, y+5);
    cambiarLetra(3);
    cout << "Trabajo Práctico Integrador - Año 2025 1C";
    cambiarLetra(4);
    rlutil::locate(x+20, y+6);
    cout << "Grupo 09";

    cambiarLetra(1);

    rlutil::locate(x+2, y+8);
    cout << "Braian Gigena. Legajo numero ";

    rlutil::locate(x+2, y+9);
    cout << "Francisco Emmanuel Montilla. Legajo numero ";

    rlutil::locate(x+2, y+10);

    cout << "German Andres Gonzalez. Legajo numero ";

    rlutil::locate(x+2, y+11);
    cout << "Mayra Elisabet Schuchman. Legajo numero ";
    rlutil::locate(x, y+13);

    imprimirLineas(x+10, '-');

    rlutil::locate(x+3, y+14);

    cout << "Presiona una tecla para volver al menú.";
    esperar(1000);
    rlutil::anykey();
    //borrarPantalla();

}


void dibujarDado(int cantCaras, int valorDado, int x, int y) {

    int colorFondo=15; // Color blanco //Color verde claro
    int colorLetra=12; // Color Light Red
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
        colorFondo=10;
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























