#include <iostream>
#include "lib/rlutil.h"
#include "lib/unJugador.h"
#include "lib/dibujar.h"
#include "lib/dados.h"

using namespace std;

int main() {
	//int dados[6] = { 2, 3, 1, 1, 5, 6 };
	//bool combinacion = esEscalera(dados);
	//int puntaje = puntajeTrio(dados);
	//cout << "PUNTAJE" << endl;
	//cout << puntaje << endl;

	//return 0;

	//parte del juego:
	bool salirDelJuego = false;
	int opcion = 1;

	do {
		Titulo();
		Esquinas();

		rlutil::setColor(opcion == 1 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 13);
		cout << "MODO UN JUGADOR" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 14);

		rlutil::setColor(opcion == 2 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 15);
		cout << "MODO DOS JUGADORES" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 16);

		rlutil::setColor(opcion == 3 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 17);
		cout << "PUNTUACION MAS ALTA" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 18);

		rlutil::setColor(opcion == 4 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 19);
		cout << "COMO SE JUEGA?" << endl;

		rlutil::setColor(opcion == 5 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 21);
		cout << "COMBINACIONES GANADORAS" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 23);

		rlutil::setColor(opcion == 6 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
		rlutil::locate(48, 23);
		cout << "SALIR DEL JUEGO" << endl;

		rlutil::setColor(rlutil::COLOR::LIGHTRED);
		rlutil::locate(1, 30);
		cout << "Agustin Bernal";

		rlutil::setColor(rlutil::COLOR::LIGHTRED);
		rlutil::locate(110, 30);
		cout << "Dana Claros";

		int teclaPresionada = rlutil::getkey();

		switch (teclaPresionada) {
			// Navegar hacia abajo
		case rlutil::KEY_DOWN:
			// Si ya esta en la posicion 6 (Salir del juego) no debe hacer nada.
			if (opcion != 6) {
				opcion++;
			}
			break;
			// Navegar hacia arriba
		case rlutil::KEY_UP:
			// Si ya esta en la posicion 1 (Un jugador) no debe hacer nada.
			if (opcion != 1) {
				opcion--;
			}
			break;
			// Presionar Enter
		case rlutil::KEY_ENTER:
			switch (opcion) {
				// Modo un jugador
			case 1: //actualizar en orden como escalera
				ModoUnJugador();
				break;
				// MODO DOS JUGADORES
			case 2:
				ModoDosJugadores();
				break;
				// MOSTRAR CALIFICACION MAXIMA
			case 3:
				rlutil::anykey();
				break;
				// AYUDA
			case 4:
				rlutil::anykey();
				break;
				// COMBINACIONES GANADORAS
			case 5:
				rlutil::anykey();
				break;
				// SALIR DEL JUEGO
			case 6:
				salirDelJuego = true;
				break;
			}
			break;
		default:
			break;
		}

	} while (!salirDelJuego);

	return 0;
}
