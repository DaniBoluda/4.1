#include <iostream>
#include "lib/rlutil.h"
#include "lib/unJugador.h"
#include "lib/dibujar.h"
#include "lib/dados.h"

using namespace std;

int main() {
	//int dados[6] = { 1, 1, 2, 1, 1, 1 };
	//bool combinacion = esSextetoX(dados);
	//int puntaje = puntajeTrio(dados);
	//cout << "PUNTAJE" << endl;
	//cout << puntaje << endl;

	//return 0;

	//parte del juego:
	bool salirDelJuego = false;
	int opcion = 1;

	do {
		titulo();
		esquinas();

		rlutil::setColor(opcion == 1 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 13);
		cout << "MODO UN JUGADOR" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 14);

		rlutil::setColor(opcion == 2 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 15);
		cout << "MODO DOS JUGADORES" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 16);

		rlutil::setColor(opcion == 3 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 17);
		cout << "PUNTUACION MAS ALTA" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 18);

		rlutil::setColor(opcion == 4 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 19);
		cout << "REGLAS DEL JUEGO" << endl;

		rlutil::setColor(opcion == 5 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 21);
		cout << "COMBINACIONES GANADORAS" << endl;

		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(46, 23);

		rlutil::setColor(opcion == 6 ? rlutil::COLOR::LIGHTMAGENTA : rlutil::COLOR::WHITE);
		rlutil::locate(48, 23);
		cout << "SALIR DEL JUEGO" << endl;

		rlutil::setColor(rlutil::COLOR::DARKGREY);
		rlutil::locate(110, 30);
		cout << "Dana Claros";

		int teclaPresionada = rlutil::getkey();

		switch (teclaPresionada) {
		case rlutil::KEY_DOWN: // Navegar hacia abajo
			if (opcion != 6) { // Si ya esta en la posicion 6 (Salir del juego) no debe hacer nada.
				opcion++;
			}
			break;
		case rlutil::KEY_UP: // Navegar hacia arriba
			if (opcion != 1) { // Si ya esta en la posicion 1 (Un jugador) no debe hacer nada.
				opcion--;
			}
			break;
			// Presionar Enter
		case rlutil::KEY_ENTER:
			switch (opcion) {
			case 1: 
				modoUnJugador();
				break;
			case 2:
				modoDosJugadores();
				break;
				// MOSTRAR CALIFICACION MAXIMA de los dos jugadores 
			case 3:
				rlutil::anykey();

				break;
			case 4:
				comoSeJuega();
				rlutil::anykey();
				break;
			case 5:
				combinacionesGanadoras();
				rlutil::anykey();
				break;
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
