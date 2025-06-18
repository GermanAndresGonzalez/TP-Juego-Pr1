#ifndef CODIGOENFRENDADOS_H_INCLUDED
#define CODIGOENFRENDADOS_H_INCLUDED

#include <string>
using namespace std;
// Parte gráfica:
void borrarPantalla(); // Borra la pantalla de la consola. Parece más amigable.
void esperar(int tiempo);
void cambiarFondo( int colorFondo); // // Cambia el color del fondo de manera más amiigable;
void cambiarLetra( int colorLetra);// // Cambia el color de la letras fondo de manera más amiigable;
void encabezado(int x, int y, int largo); // Imprime el encabezado del juego
void dibujarMarco(int x, int y, int largo,int ancho);   //Dibuja el marco del menú
void mostrarMenu();  // Muestra el menu
void imprimirLineas(int largo,char caracter); // Imprimir caracteres de manera repetida
int calcularCentroTexto(int x, string cadena, int ancho);
void mostrarCreditos();

// Codigo enfrendados
void jugar(string &jugador1, string &jugador2,  int vec[], int vec2[]);
void ronda(string &jugador1, string &jugador2);
void jugarRonda(string &jugador1, string &jugador2,  int vec[], int vec2[]);

void sortearJugadores(string &jugador1,string &jugador2);
void dibujarDado(int cantCaras, int valorDado, int x, int y);
void mostrarDadoFalso (int cantCaras, int x, int y);

bool salir(); // Sale del juego/menu
int lanzarDado(int caras);
void turnoJugador(string nombre, int dadosStock[]);
bool verificarVictoria(int dadosStock[]);
void imprimirRonda(int x, int y, string nombre, int ronda);
void mostrarEstadisticas(string nombre1, string nombre2, int vec[], int vec2[]);
int imprimirLineaEstadistica (int x, int y, string nombre, int vec[]);

// Vectores:

void mostrarVector(int vec[],int cantidad);
void inicializarVector(int vec[], int inicial);
void restarVector(int vec[], int cantidad);
void sumarDadosVector(int vec[], int cantidad);
int contarDadosVector(int vec[], int cantidad); // Cuenta los dados que tiene el jugador en el vector



#endif // CODIGOENFRENDADOS_H_INCLUDED
