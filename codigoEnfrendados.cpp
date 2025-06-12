#include <iostream>
#include <chrono>
#include <thread>
#include "codigoEnfrendados.h"

#include "rlutil.h"

const int DADOS_INICIALES = 6;
const int RONDAS = 3;

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
        return false;
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


void mostrarMenu()
{ // Menú del juego con cambio de colores y posición
    int x=40;
    int y=5;
    int largo=13;
    int ancho=49;

    int opcion = 10;

    do
    {
        cambiarFondo(1);
        cambiarLetra(1);
        rlutil::saveDefaultColor();
        borrarPantalla();
        dibujarMarco(x,y,largo,ancho);
        encabezado(x,y, ancho);

        rlutil::locate(59, 10);
        cout << "1 - JUGAR";

        rlutil::locate(59, 11);
        cout << "2 - ESTADÍSTICAS";

        rlutil::locate(59, 12);
        cout << "3 - CRÉDITOS";

        rlutil::locate(59, 13);
        cout << "0 - SALIR";

        rlutil::locate(40, 16);

        imprimirLineas(49, '-');

        rlutil::locate(54, 17);
        cout << "Seleccione una opción:";
        rlutil::locate(40, 18);

        rlutil::locate(77, 17);
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

    rlutil::locate(40,yDado);
    cout << jugador1 << " le toca tirar primero los dados.";
    rlutil::locate(55,yDado+2);
    cout << "¡Suerte!";


}


void jugar()
{
    string jugador1="", jugador2="";
    int x=35,y=6,largo=20,ancho=50;


    int puntaje1 = 0, puntaje2 = 0;

    int dadosStock1[DADOS_INICIALES] = {6, 3, 5, 2, 4, 1}; // Valores iniciales
    int dadosStock2[DADOS_INICIALES] = {1, 2, 3, 4, 5, 6};

    borrarPantalla();
    dibujarMarco(x,y,largo,ancho);
    sortearJugadores (jugador1, jugador2);
    //rlutil::locate(40, 11);

    //cout << jugador1 << " " << jugador2;
    rlutil::msleep(10000);
    rlutil::anykey();

    /*

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
    // borrarPantalla();
    cout << endl;
    cout << "Puntaje final: " << jugador1 << " = " << puntaje1 << ", " << jugador2 << " = " << puntaje2 << "\n";
    cout << endl
         << "Presiona una tecla para volver al menú." << endl;
    rlutil::anykey();
    cambiarFondo(1);
    cambiarLetra(1);
    */

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

void imprimirLineas(int largo,char caracter){
    // Imprimir caracteres de manera repetida
    for (int i=0; i<largo;i++){
        cout << caracter;
    }

}

void encabezado(int x, int y, int largo){

    rlutil::locate(x, y);
    imprimirLineas(largo, '-');

    rlutil::locate(x+19, y+1);
    cout << "Enfrendados" << endl;
    rlutil::locate(x, y+2);
    imprimirLineas(largo, '-');



}

void mostrarCreditos()
{

    borrarPantalla();
    encabezado(40,5,49);
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
    borrarPantalla();

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

    //rlutil::setColor(15); //devuelve el color
    //rlutil::setBackgroundColor(0); // devuelve el color

}

