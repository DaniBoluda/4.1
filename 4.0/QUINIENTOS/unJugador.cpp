#include "lib/unJugador.h"
#include "lib/dibujar.h"
#include "lib/dados.h"
#include <random>
#include "rlutil.h"
#include <windows.h>
#include <vector>
#include <map>
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

void ModoUnJugador() {
	string Nombre1P;
	int PuntajeTotalP1 = 0;
	int MaxPuntajeP1 = 0;
	int LanzamientosP1 = 0;
	int NumRondaP1 = 0;
	int MAX_RONDAS = 3;

	bool volverAlMenu = false;

	while (!volverAlMenu) {
		rlutil::cls();
		rlutil::setColor(rlutil::COLOR::CYAN);
		rlutil::locate(50, 3);
		cout << "MODO UN JUGADOR";
		rlutil::locate(45, 4);
		DibujarLineas(50, 2, 65, 2, (char)196);
		DibujarLineas(50, 4, 65, 4, (char)196);
		DibujarLineas(49, 2, 49, 2, (char)174);
		DibujarLineas(65, 4, 65, 4, (char)175);
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(50, 6);
		cout << "Ingresar Nombre: ";
		/* DibujarLineas(48, 9, 68, 9, (char)205);
		 DibujarLineas(47, 10, 47, 15, (char)186);
		 DibujarLineas(69, 10, 69, 15, (char)186);
		 DibujarLineas(48, 16, 68, 16, (char)205);
		 //rlutil::locate(53, 11);
		 //cout << "Max Rondas:";
		 //rlutil::locate(49, 10);
		 //cout << "(0 Predeterminado)";*/ //innecesario
		rlutil::locate(50, 8);
		cin >> Nombre1P;
		rlutil::locate(57, 13);
		cout << (char)175;
		rlutil::locate(49, 18);
		cout << "Enter para Jugar";
		rlutil::anykey();
		// rlutil::locate(58, 13);  
		 //cin >> MAX_RONDAS;  // innecesario

		while (MaxPuntajeP1 <= 500 && NumRondaP1 < MAX_RONDAS) {
			NumRondaP1++;
			LanzamientosP1 = 0;
			MaxPuntajeP1 = 0;

			while (LanzamientosP1 < 3) {
				LanzamientosP1++;

				rlutil::cls();
				Rectangulo1P();
				Esquinas();
				rlutil::locate(50, 3);

				// se crea un vector que representa el numero aleatorio asignado a cada dado (6 dados)
				int dados[6];
				for (int i = 0; i < 6; ++i) {
					int numeroAleatorio = numAleatorio1_6();
					dados[i] = numeroAleatorio;
					dibujarDado(1 + (i * 20), 11, numeroAleatorio, 19);
				}

				// Aca verificar los dados y las jugadas
				int puntaje = 0;
				if (Sexteto6MM(dados)) {
					puntaje = 0;
					rlutil::locate(50, 25);
					cout << "Combinacion Sexteto! Perdiste todo! ";
				}
				else if (Escalera(dados)) {
					puntaje = 500;
					rlutil::locate(50, 25);
					cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!";
				}
				else if (existeDadosIguales(dados))
				{
					puntaje = Sexteto(dados);
					rlutil::locate(50, 25);
					cout << "Combinacion Sexteto X";
				}
				else if (existeTresNumerosIgualesOMayor(dados)) {
					puntaje = MayorTrio(dados);
					puntaje = MayorTrio(dados);
					rlutil::locate(50, 25);
					cout << "Combinacion TRIO! ";
				}
				else if (existeDosNumerosIguales(dados)) {
					puntaje = SumaDeDados(dados);
					rlutil::locate(50, 25);
					cout << "Suma de dados! ";
				}

				// Actualizar el puntaje máximo 
				//if (puntaje > MaxPuntajeP1) {
				//	MaxPuntajeP1 = puntaje;
				//}
				MaxPuntajeP1 = puntaje;
				// Actualizar el puntaje total del jugador
				PuntajeTotalP1 += puntaje;

				// Verificar si se obtuvo escalera o sexteto 6 para terminar la ronda
				if (puntaje == 500 || puntaje == 0) {
					break;
				}

				rlutil::locate(50, 3);
				cout << "TURNO DE " << Nombre1P;
				rlutil::locate(46, 4);
				cout << "RONDA NUMERO: " << NumRondaP1;
				rlutil::locate(90, 3);
				cout << "PUNTUAJE TOTAL: " << PuntajeTotalP1;
				rlutil::locate(47, 6);
				cout << "LANZAMIENTO: " << LanzamientosP1;
				rlutil::locate(86, 6);
				cout << "MAXIMO PUNTAJE DE LA RONDA:";
				rlutil::locate(95, 7);
				cout << MaxPuntajeP1 << " PUNTOS" << endl << endl;


				// Mostrar los resultados parciales
				rlutil::locate(40, 10);
				cout << "Presionar Enter Para Tirar Los Dados";
				rlutil::anykey();
			}

			// Mostrar los resultados finales de la ronda
			rlutil::cls();
			Rectangulo1P();
			Esquinas();
			rlutil::locate(50, 3);
			cout << "TURNO DE " << Nombre1P;
			rlutil::locate(46, 4);
			cout << "RONDA NUMERO: " << NumRondaP1;
			rlutil::locate(90, 3);
			cout << "PUNTUAJE TOTAL: " << PuntajeTotalP1;
			rlutil::locate(47, 6);
			cout << "LANZAMIENTO: " << LanzamientosP1;
			rlutil::locate(86, 6);
			cout << "MAXIMO PUNTAJE DE LA RONDA:";
			rlutil::locate(95, 7);
			cout << MaxPuntajeP1 << " PUNTOS" << endl << endl;
			rlutil::locate(1, 20);
			cout << "CUANDO SALGA ESTE MENSAJE ACA DEBERIA DE ESTAR EL RESUMEN DE LA RONDA ";
			rlutil::anykey();
		}
		return;

	}
}

//Modo Dos Jugadores
//pasarlo a otra funcion de dos jugadores
void ModoDosJugadores() {
	//
}



//Esquinas
void Esquinas() {
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

//Titulo

void Titulo() {

	rlutil::setColor(rlutil::COLOR::WHITE); // COLOR TEXTO MENU

	rlutil::hidecursor(); // Sin Cursor

	rlutil::cls(); //Limpiar Consola

	rlutil::setColor(rlutil::COLOR::RED); // Titulo
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

	//Dibujar Linea superior (Opciones)
//Mofidica estas 4 para hacer la decoracion de las opciones, (1,2,3,4,(char)...); Siendo 1 el inicio de la linea del Eje X (------)
//3 es el final de la linea, por ejemplo 10 15, seria una linea q empieza en la fila 10 y termine en la 15, una linea de 2
//2 es el inicio en el eje Y y 4 el fin por ejemplo una linea que empiece en la fila 3 y termine en la 10
/*
*-------|
*
*
*
* |
* |
* |
* |
* |
* |
* |
* ***********
*/
}






