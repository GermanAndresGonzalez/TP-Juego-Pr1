#ifndef CODIGOENFRENDADOS_H_INCLUDED
#define CODIGOENFRENDADOS_H_INCLUDED

#include <string>
using namespace std;

void borrarPantalla(); // Borra la pantalla de la consola. Parece más amigable.
void esperar(int tiempo);

void cambiarFondo( int colorFondo); // // Cambia el color del fondo de manera más amiigable;
void cambiarLetra( int colorLetra);// // Cambia el color de la letras fondo de manera más amiigable;

void encabezado(int x, int y, int largo); // Imprime el encabezado del juego
void dibujarMarco(int x, int y, int largo,int ancho);   //Dibuja el marco del menú
void mostrarMenu();  // Muestra el menu
void imprimirLineas(int largo,char caracter); // Imprimir caracteres de manera repetida

void jugar();
void ronda(string &jugador1, string &jugador2);

void sortearJugadores(string &jugador1,string &jugador2);
void dibujarDado(int cantCaras, int valorDado, int x, int y);


bool salir(); // Sale del juego/menu
int lanzarDado(int caras);
void turnoJugador(string nombre, int &puntaje, int dadosStock[]);
bool verificarVictoria(int dadosStock[]);

void mostrarCreditos();

#endif // CODIGOENFRENDADOS_H_INCLUDED
