#ifndef unJugador_h
#define unJugador_h

#include <string>
using namespace std;

void titulo();

void gotoxy(int x, int y);

void esquinas();

void modoUnJugador();

void modoDosJugadores();

void ActualizarEncabezado(string nombre, int numRonda, int numLanzamiento, int puntajeTotal, int puntajeRonda, int puntajeLanzamiento);

int ObtenerPuntaje(int dados[6]);

void Rectangulo1P();

void combinacionesGanadoras();

void comoSeJuega();

#endif
