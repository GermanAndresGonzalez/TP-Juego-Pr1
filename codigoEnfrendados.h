#ifndef CODIGOENFRENDADOS_H_INCLUDED
#define CODIGOENFRENDADOS_H_INCLUDED

#include <string>
using namespace std;

bool salir ();
void cambiarColores(int codigo);
void mostrarMenu();
void jugar();
int lanzarDado(int caras);
void turnoJugador(string nombre, int& puntaje, int dadosStock[]);
bool verificarVictoria(int dadosStock[]);

#endif // CODIGOENFRENDADOS_H_INCLUDED
