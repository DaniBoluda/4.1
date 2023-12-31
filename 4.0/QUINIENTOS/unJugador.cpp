﻿#include "lib/unJugador.h"
#include "lib/dibujar.h"
#include "lib/dados.h"
#include "rlutil.h"
#include <string>

using namespace std;



void Rectangulo1P() {
	// Dibujar pared izquierda
	DibujarLineas(1, 1, 1, 9, (char)186);

	// Dibujar pared derecha
	DibujarLineas(120, 1, 120, 9, (char)186);

	//Dibujar Linea superior
	DibujarLineas(1, 1, 120, 1, (char)205);

	//Dibujas Linea inferior 
	DibujarLineas(1, 9, 120, 9, (char)205);
}

void modoUnJugador() {
	string Nombre1P;
	int puntajeTotalP1 = 0;
	int puntajeRondaP1 = 0;
	int lanzamientosP1 = 0;
	int NumRondaP1 = 0;

	bool volverAlMenu = false;

	while (!volverAlMenu) {
		rlutil::cls();
		rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
		rlutil::locate(50, 10);
		cout << "MODO UN JUGADOR";
		rlutil::locate(45, 4);
		DibujarLineas(50, 9, 65, 9, (char)196);
		DibujarLineas(50, 11, 65, 11, (char)196);
		DibujarLineas(49, 9, 49, 9, (char)174);
		DibujarLineas(65, 11, 65, 11, (char)175);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(50, 12);
		cout << "Ingresar Nombre: ";
		DibujarLineas(48, 9, 68, 9, (char)205);
		DibujarLineas(47, 10, 47, 15, (char)186);
		DibujarLineas(69, 10, 69, 15, (char)186);
		DibujarLineas(48, 16, 68, 16, (char)205);

		rlutil::locate(50, 14);
		cin >> Nombre1P;
		rlutil::locate(57, 18);
		cout << (char)175;
		rlutil::locate(42, 20);
		cout << "Presione cualquier letra para jugar";
		rlutil::anykey();

		while (puntajeTotalP1 <= 500) {
			NumRondaP1++;
			lanzamientosP1 = 0;
			puntajeRondaP1 = 0;

			while (lanzamientosP1 < 3) {
				lanzamientosP1++;

				rlutil::cls();
				Rectangulo1P();
				esquinas();
				rlutil::locate(50, 3);

				// se crea un vector que representa el numero aleatorio asignado a cada dado (6 dados)
				int dados[6];
				for (int i = 0; i < 6; ++i) {
					int numeroAleatorio = numAleatorio1_6();
					dados[i] = numeroAleatorio;
					dibujarDado(1 + (i * 20), 11, numeroAleatorio, 19);
				}

				// Aca verificar los dados y las jugadas
				int puntaje = ObtenerPuntaje(dados);

				// Actualizar el puntaje por ronda
				puntajeRondaP1 += puntaje;
				// Actualizar el puntaje total del jugador
				puntajeTotalP1 += puntaje;

				// Actualiza los datos del encabezado
				ActualizarEncabezado(Nombre1P, NumRondaP1, lanzamientosP1, puntajeTotalP1, puntajeRondaP1, puntaje);
				
				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(42, 28);
				cout << "Presione enter para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);

				// Verificar si se obtuvo escalera para terminar la ronda
				if (puntajeTotalP1 >= 500) {
					rlutil::anykey();
					break; 
				}
			}

			rlutil::cls();
			rlutil::locate(48, 10);
			rlutil::setColor(rlutil::COLOR::GREY);
			rlutil::setBackgroundColor(rlutil::RED);
			if (puntajeTotalP1 >= 500) {
				cout << "GANASTE LA PARTIDA " << Nombre1P << endl;
			}
			else {
				cout << "TURNO DE: " << Nombre1P;
			}
			rlutil::locate(48, 12);
			rlutil::setColor(rlutil::COLOR::LIGHTRED);
			rlutil::setBackgroundColor(rlutil::BLACK);
			cout << "SE TERMINO LA RONDA N" << NumRondaP1 << endl;
			rlutil::locate(48, 14);
			cout << "PUNTAJE DE LA RONDA: " << puntajeRondaP1 << " PUNTOS" << endl;

			if (puntajeTotalP1 < 500) {
				rlutil::locate(48, 17);
				cout << "SIGUIENTE RONDA N" << NumRondaP1 + 1; 
			}
			else {
				rlutil::setColor(rlutil::COLOR::LIGHTRED);
				rlutil::locate(48, 16);
				cout << "PUNTUAJE FINAL: " << puntajeTotalP1;
				rlutil::setColor(rlutil::COLOR::WHITE);
				rlutil::locate(37, 20);
				cout << "Presione cualquier tecla para volver al menu principal";
				volverAlMenu = true;
			}

			rlutil::setColor(rlutil::COLOR::WHITE);
			rlutil::anykey();
		}


	}
	return;


}

void modoDosJugadores() {
	string Nombre1P;
	string Nombre2P;
	string ganador;
	int puntajeTotalP1 = 0, puntajeTotalP2 = 0;
	int puntajeRondaP1 = 0, puntajeRondaP2 = 0;
	int lanzamientosP1 = 0, lanzamientosP2 = 0;
	int NumRondaP1 = 0, NumRondaP2 = 0;
	int cantRondas;
	int contadorLanzamientosP1 = 0, contadorLanzamientosP2 = 0;

	bool volverAlMenu = false;
	bool hayEscalera = false;
	
	while (!volverAlMenu) {
		rlutil::cls();
		rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
		rlutil::locate(50, 10);
		cout << "MODO DOS JUGADORES";
		rlutil::locate(45, 4);
		DibujarLineas(50, 9, 65, 9, (char)196);
		DibujarLineas(50, 11, 65, 11, (char)196);
		DibujarLineas(49, 9, 49, 9, (char)174);
		DibujarLineas(65, 11, 65, 11, (char)175);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(43, 12);
		cout << "Ingresar nombre del primer jugador: ";
		DibujarLineas(40, 9, 80, 9, (char)205);
		DibujarLineas(40, 10, 40, 15, (char)186);
		DibujarLineas(80, 10, 80, 15, (char)186);
		DibujarLineas(40, 16, 80, 16, (char)205);
		rlutil::locate(50, 14);
		cin >> Nombre1P;

		rlutil::cls();
		rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
		rlutil::locate(50, 10);
		cout << "MODO DOS JUGADORES";
		rlutil::locate(45, 4);
		DibujarLineas(50, 9, 65, 9, (char)196);
		DibujarLineas(50, 11, 65, 11, (char)196);
		DibujarLineas(49, 9, 49, 9, (char)174);
		DibujarLineas(65, 11, 65, 11, (char)175);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(43, 12);
		cout << "Ingresar nombre del segundo jugador: ";
		DibujarLineas(40, 9, 80, 9, (char)205);
		DibujarLineas(40, 10, 40, 15, (char)186);
		DibujarLineas(80, 10, 80, 15, (char)186);
		DibujarLineas(40, 16, 80, 16, (char)205);
		rlutil::locate(50, 14);
		cin >> Nombre2P;

		rlutil::cls();
		rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
		rlutil::locate(50, 10);
		cout << "MODO DOS JUGADORES";
		rlutil::locate(45, 4);
		DibujarLineas(50, 9, 65, 9, (char)196);
		DibujarLineas(50, 11, 65, 11, (char)196);
		DibujarLineas(49, 9, 49, 9, (char)174);
		DibujarLineas(65, 11, 65, 11, (char)175);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(43, 12);
		cout << "Ingresar cantidad de rondas: ";
		DibujarLineas(40, 9, 80, 9, (char)205);
		DibujarLineas(40, 10, 40, 15, (char)186);
		DibujarLineas(80, 10, 80, 15, (char)186);
		DibujarLineas(40, 16, 80, 16, (char)205);
		rlutil::locate(50, 14);
		cin >> cantRondas;

		rlutil::locate(59, 18);
		cout << (char)175;
		rlutil::locate(43, 20);
		cout << "Presione cualquier letra para jugar";
		rlutil::anykey();

		while (NumRondaP1 < cantRondas && puntajeTotalP1 < 500 && puntajeTotalP2 < 500) { //numronda se inicializa en 1 despues del while

			if (hayEscalera == true) {
				volverAlMenu = true;
			}

			lanzamientosP1 = 0, lanzamientosP2 = 0;
			// Se reinicia puntaje ronda al comenzar una nueva
			puntajeRondaP1 = 0, puntajeRondaP2 = 0;

			NumRondaP1++;

			rlutil::cls();

			rlutil::locate(55, 10);
			rlutil::setColor(rlutil::COLOR::GREY);
			rlutil::setBackgroundColor(rlutil::RED);
			cout << "RONDA N" << NumRondaP1 << endl;
			rlutil::locate(48, 12);
			rlutil::setBackgroundColor(rlutil::BLACK);
			rlutil::setColor(rlutil::COLOR::LIGHTRED);
			cout << "PROXIMO TURNO DE: " << Nombre1P << endl;
			rlutil::locate(48, 17);
			rlutil::setColor(rlutil::COLOR::LIGHTRED);
			cout << "PUNTAJE DE " << Nombre1P << ": " << puntajeTotalP1 << " PUNTOS" << endl;
			rlutil::locate(48, 19);
			rlutil::setColor(rlutil::COLOR::LIGHTRED);
			cout << "PUNTAJE DE " << Nombre2P << ": " << puntajeTotalP2 << " PUNTOS" << endl;
			rlutil::anykey();

			rlutil::setColor(rlutil::COLOR::WHITE);

			while (lanzamientosP1 < 3) {

				if (hayEscalera == true) {
					break;
				}

				lanzamientosP1++;
				contadorLanzamientosP1++;

				rlutil::cls();
				Rectangulo1P();
				esquinas();
				rlutil::locate(50, 3);

				// se crea un vector que representa el numero aleatorio asignado a cada dado (6 dados)
				int dados[6];
				for (int i = 0; i < 6; ++i) {
					int numeroAleatorio = numAleatorio1_6();
					dados[i] = numeroAleatorio;
					dibujarDado(1 + (i * 20), 11, numeroAleatorio, 19);
				}

				// Aca verificar los dados y las jugadas
				int puntaje = ObtenerPuntaje(dados);

				puntajeRondaP1 += puntaje;
				// Actualiza el puntaje total del jugador
				puntajeTotalP1 += puntaje;

				// Actualiza los datos del encabezado
				ActualizarEncabezado(Nombre1P, NumRondaP1, lanzamientosP1, puntajeTotalP1, puntajeRondaP1, puntaje);

				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(40, 28);
				cout << "Presione cualquier tecla para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);

				//verifica escalera player1	
				if (puntaje == 500) {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre1P << endl; //pantalla ganador player1
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP1 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP1;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();

					hayEscalera = true;

				}
			}

			/*if (puntajeTotalP1 >= 500)
				break; */ //diria que no por si despues hay empate

			NumRondaP2++;

			//Mostrar los resultados de la ronda en DOS JUGADORES, deberia mostrar al player2 , resumen de pantalla
			rlutil::cls();
			rlutil::locate(55, 10);
			rlutil::setColor(rlutil::COLOR::GREY);
			rlutil::setBackgroundColor(rlutil::RED);
			cout << "RONDA N" << NumRondaP2;
			rlutil::locate(48, 12);
			rlutil::setColor(rlutil::COLOR::LIGHTRED);
			rlutil::setBackgroundColor(rlutil::BLACK);
			cout << "PROXIMO TURNO DE: " << Nombre2P << endl;
			rlutil::locate(48, 17);
			cout << "PUNTAJE DE " << Nombre1P << ": " << puntajeTotalP1 << " PUNTOS" << endl;
			rlutil::locate(48, 19);
			cout << "PUNTAJE DE " << Nombre2P << ": " << puntajeTotalP2 << " PUNTOS" << endl;
			rlutil::anykey();

			rlutil::setColor(rlutil::COLOR::WHITE);

			//aca va el while del player 2
			while (lanzamientosP2 < 3) {

				if (hayEscalera == true) {
					break;
				}

				lanzamientosP2++;
				contadorLanzamientosP2++;

				rlutil::cls();
				Rectangulo1P();
				esquinas();
				rlutil::locate(50, 3);

				// Se crea un vector que representa el numero aleatorio asignado a cada dado (6 dados)
				int dados[6];
				for (int i = 0; i < 6; ++i) {
					int numeroAleatorio = numAleatorio1_6();
					dados[i] = numeroAleatorio;
					dibujarDado(1 + (i * 20), 11, numeroAleatorio, 19);
				}

				// Aca verificar los dados y las jugadas
				int puntaje = ObtenerPuntaje(dados);

				puntajeRondaP2 += puntaje;

				puntajeTotalP2 += puntaje;

				// Actualiza los datos del encabezado
				ActualizarEncabezado(Nombre2P, NumRondaP2, lanzamientosP2, puntajeTotalP2, puntajeRondaP2, puntaje); 

				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(40, 28);
				cout << "Presione enter para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);

				//verifica escalera player2
				if (puntaje == 500) {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre2P << endl; //pantalla ganador player2
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP2 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP2;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();

					hayEscalera = true;
				}
			}


			if (puntajeTotalP1 >= 500 && puntajeTotalP2 >= 500) {  //en caso de empate
				//se desempata con el que tuvo el mayor puntaje en la menor cantidad de lanzamientos 
				if (contadorLanzamientosP1 > contadorLanzamientosP2) {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre2P << endl; //pantalla ganador player2
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP2 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP2;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();
				}
				else {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre1P << endl; //pantalla ganador player1
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP1 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP1;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();
				}
			}

			if (cantRondas <= NumRondaP1 && puntajeTotalP1 < 500 && puntajeTotalP2 < 500) {  //la partida termina sin ninguno mayor a 500 puntos
				if (puntajeTotalP1 > puntajeTotalP2) {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre1P << endl; //pantalla ganador player1
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP1 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP1;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();
				}
				else {
					rlutil::cls();
					rlutil::locate(48, 10);
					rlutil::setColor(rlutil::COLOR::GREY);
					rlutil::setBackgroundColor(rlutil::RED);
					cout << "GANASTE LA PARTIDA " << Nombre2P << endl; //pantalla ganador player2
					rlutil::locate(48, 12);
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::setBackgroundColor(rlutil::BLACK);
					cout << "SE TERMINO LA RONDA N" << NumRondaP2 << endl;
					rlutil::setColor(rlutil::COLOR::LIGHTRED);
					rlutil::locate(48, 14);
					cout << "PUNTUAJE FINAL: " << puntajeTotalP2;
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::locate(37, 20);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::setColor(rlutil::COLOR::WHITE);
					rlutil::anykey();
				}

			}

			//bborrar si no funciona
			if (NumRondaP1 < NumRondaP2 && puntajeTotalP1 > puntajeTotalP2) {
				Nombre1P;
			}
			else if (NumRondaP2 < NumRondaP1 && puntajeTotalP2 > puntajeRondaP1) {
				Nombre2P;
			}
			
			if (NumRondaP1 == NumRondaP2) {
				if (contadorLanzamientosP1 < contadorLanzamientosP2 && puntajeTotalP1 > puntajeTotalP2) {
					Nombre1P;
				}
				else if (contadorLanzamientosP2 < contadorLanzamientosP1 && puntajeTotalP2 > puntajeTotalP1) {
					Nombre2P;
				}
			}
			//bborrar si no funciona




			rlutil::anykey(); // no borrar 
		}
		return;

	}
}

void nombreMasAlta() {
	//Esta opción debe mostrar el nombre del jugador que haya finalizado el juego en la menor cantidad de rondas.
	// En caso de empatar la cantidad de rondas, se debe analizar la menor cantidad de lanzamientos.
}

void esquinas() {
	//Esquina superior izquierda
	rlutil::locate(1, 1);
	cout << (char)201;

	//Esquina superior derecha
	rlutil::locate(120, 1);
	cout << (char)187;

	//Esquina inferior izquierda
	rlutil::locate(1, 9);
	cout << (char)200;

	//Esquina inferior derecha
	rlutil::locate(120, 9);
	cout << (char)188;
}

void titulo() {

	rlutil::setColor(rlutil::COLOR::WHITE); // COLOR TEXTO MENU

	rlutil::hidecursor(); // Sin Cursor

	rlutil::cls(); //Limpiar Consola

	rlutil::setColor(rlutil::COLOR::MAGENTA); // Titulo
	rlutil::locate(2, 2);
	cout << "          xxxxxxx    x     x    x    xx      x   x    xxxxxxx    xx      x    xxxxxxx    xxxxxxx    xxxxxxx             ";
	rlutil::locate(2, 3);
	cout << "          x     x    x     x         x x     x        x          x x     x       x       x     x    x                   ";
	rlutil::locate(2, 4);
	cout << "          x     x    x     x    x    x  x    x   x    x          x  x    x       x       x     x    x                   ";
	rlutil::locate(2, 5);
	cout << "          x     x    x     x    x    x   x   x   x    xxxxxxx    x   x   x       x       x     x    xxxxxxx             ";
	rlutil::locate(2, 6);
	cout << "          x     x    x     x    x    x    x  x   x    x          x    x  x       x       x     x          x             ";
	rlutil::locate(2, 7);
	cout << "          x    xx    x     x    x    x     x x   x    x          x     x x       x       x     x          x             ";
	rlutil::locate(2, 8);
	cout << "          xxxxxxxxx  xxxxxxx    x    x      xx   x    xxxxxxx    x      xx       x       xxxxxxx    xxxxxxx             ";



	// Dibujar pared izquierda
	DibujarLineas(1, 1, 1, 9, (char)186);

	// Dibujar pared derecha
	DibujarLineas(120, 1, 120, 9, (char)186);

	//Dibujar Linea superior
	DibujarLineas(1, 1, 120, 1, (char)205);

	//Dibujas Linea inferior 
	DibujarLineas(1, 9, 120, 9, (char)205);

	//////////////////////////////////////////

	//Dibujar Linea superior (Opciones)
	DibujarLineas(47, 11, 73, 11, (char)205);

	//Dibujar Linea Inferior  (Opciones)
	DibujarLineas(47, 25, 73, 25, (char)205);

	//Dibujar Linea superior (Opciones)
	DibujarLineas(47, 40, 30, 60, (char)186);
}

void combinacionesGanadoras() {
	rlutil::cls();
	rlutil::setColor(rlutil::COLOR::CYAN);
	rlutil::locate(10, 7);
	cout << "LAS COMBINACIONES PUEDEN SER: " << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 9);
	cout << "SUMA DE DADOS: " << "menos de 3 dados con valores iguales (cualquier combinacion). Ejemplo: 6,5,5,2,2,1." << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 10);
	cout << "PUNTAJE OTORGADO: " << "suma de los valores de todos los dados. Ejemplo: 6 + 5 + 5 + 2 + 2 + 1 = 21. ";
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 12);
	cout << "TRIO X++ (X es el numero del dado): " << "3 dados o mas con el mismo valor (hasta 5 iguales). Ejemplo: 5,5,5,1,2,3. " << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 13);
	cout << "PUNTAJE OTORGADO: " << "X*10puntos. Ejemplo: 5 * 10 = 50. En el caso que haya 2 ternas de dados se debe elegir la que " << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 14);
	cout << "otorgue el puntaje mayor. " << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 16);
	cout << "SEXTETO X (X es el numero del dado): " << "vendrian a ser 6 dados iguales (menos para el numero 6)." << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 17);
	cout << "PUNTAJE OTORGADO: " << "X*50 puntos." << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 19);
	cout << "ESCALERA: " << "escalera tipo (1, 2, 3, 4, 5, 6), pero en cualquier orden. " << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 20);
	cout << "PUNTAJE OTORGADO: " << "Gana la partida en esa ronda. " << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 22);
	cout << "SEXTETO 6: " << "son seis dados que den 6. " << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 23);
	cout << "PUNTAJE OTORGADO: " << "resetea el puntaje total a 0. " << endl;

}

void comoSeJuega() {
	rlutil::cls();
	rlutil::setColor(rlutil::COLOR::CYAN);
	rlutil::locate(10, 5);
	cout << "REGLAMENTO DEL JUEGO: " << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 7);
	cout << "El objetivo del juego es obtener al menos 500 puntos en la menor cantidad posible de  rondas, ";
	rlutil::locate(10, 8);
	cout << "o sacar una escalera en un lanzamiento. " << endl;
	rlutil::locate(10, 10);
	cout << "Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y ";
	rlutil::locate(10, 11);
	cout << "evaluar sus valores para determinar el puntaje. " << endl;
	rlutil::locate(10, 13);
	cout << "El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en ";
	rlutil::locate(10, 14);
	cout << "la seccion ";
	rlutil::locate(22, 14);
	rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
	cout << "COMBINACIONES GANADORAS. " << endl;
	rlutil::setColor(rlutil::COLOR::WHITE);
	rlutil::locate(10, 16);
	cout << "El puntaje final de la ronda sera el valor máximo de los puntos obtenidos entre los 3 lanzamientos, ";
	rlutil::locate(10, 17);
	cout << "con las siguientes excepciones : " << endl;
	rlutil::locate(10, 19);
	cout << "- Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento. " << endl;
	rlutil::locate(10, 20);
	cout << "- Si en un lanzamiento se obtiene una combinación de 6 dados con valor 6, el puntaje total ";
	rlutil::locate(10, 21);
	cout << "de la persona se resetea a 0. " << endl;
	rlutil::setColor(rlutil::COLOR::LIGHTCYAN);
	rlutil::locate(10, 24);
	cout << "Para el caso de la opción para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) ";
	rlutil::locate(10, 25);
	cout << "alternativamente. " << endl;

}

int ObtenerPuntaje(int dados[6]) {
	int puntaje = 0;

	if (esSexteto(dados)) {
		puntaje = 0;
		rlutil::locate(50, 25);
		cout << "¡Combinacion Sexteto! ¡Perdiste todo! " << endl;
	}
	else if (esEscalera(dados)) {
		puntaje = 500;
		rlutil::locate(47, 25);
		cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
	}
	else if (esSextetoX(dados))
	{
		puntaje = dados[0] * 50;
		rlutil::locate(50, 25);
		cout << "Combinacion Sexteto X";
	}
	else if (esTrio(dados)) {
		puntaje = puntajeTrio(dados);
		rlutil::locate(50, 25);
		cout << "¡Combinacion TRIO! ";
	}
	else if (esSumaDeDados(dados)) {
		puntaje = puntajeSumaDeDados(dados);
		rlutil::locate(50, 25);
		cout << "¡Suma de dados! ";
	}

	return puntaje;
}

void ActualizarEncabezado(string nombre, int numRonda, int numLanzamiento, int puntajeTotal, int puntajeRonda, int puntajeLanzamiento) {
	rlutil::locate(15, 3);
	cout << "TURNO DE: " << nombre;
	rlutil::locate(15, 5);
	cout << "RONDA NUMERO: " << numRonda;
	rlutil::locate(15, 7);
	cout << "LANZAMIENTO: " << numLanzamiento;
	rlutil::locate(60, 3);
	cout << "PUNTUAJE TOTAL: " << puntajeTotal;
	rlutil::locate(60, 5);
	cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << " PUNTOS" << endl << endl;
	rlutil::locate(60, 7);
	cout << "PUNTAJE DEL LANZAMIENTO: " << puntajeLanzamiento << " PUNTOS" << endl << endl;
}