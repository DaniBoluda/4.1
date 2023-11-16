#include "lib/unJugador.h"
#include "lib/dibujar.h"
#include "lib/dados.h"
#include "rlutil.h"
#include <windows.h>
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
			// Se reinicia puntaje ronda al comenzar una nueva
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

				// Actualizar el puntaje por ronda
				puntajeRondaP1 += puntaje;
				// Actualizar el puntaje total del jugador
				puntajeTotalP1 += puntaje;

				rlutil::locate(15, 3);
				cout << "TURNO DE: " << Nombre1P;
				rlutil::locate(15, 5);
				cout << "RONDA NUMERO: " << NumRondaP1;
				rlutil::locate(15, 7);
				cout << "LANZAMIENTO: " << lanzamientosP1;
				rlutil::locate(60, 3);
				cout << "PUNTUAJE TOTAL: " << puntajeTotalP1;
				rlutil::locate(60, 5);
				cout << "PUNTAJE DE LA RONDA: " << puntajeRondaP1 << " PUNTOS" << endl << endl;
				rlutil::locate(60, 7);
				cout << "PUNTAJE DEL LANZAMIENTO: "<< puntaje << " PUNTOS" << endl << endl;

				// Verificar si se obtuvo escalera o sexteto 6 para terminar la ronda
				if (puntajeTotalP1 >= 500 || puntajeTotalP1 == 0) {
					rlutil::locate(40, 28);
					//cout << "Presionar Enter para volver al menu principal";
					rlutil::anykey();
					break; // el break sale del while
				}



				// Mostrar los resultados parciales
				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(42, 28);
				cout << "Presione enter para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);
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
			cout << "PUNTAJE DE LA RONDA: " << puntajeRondaP1 << " PUNTOS"  << endl;
			if (puntajeTotalP1 < 500 && puntajeTotalP1 != 0) {
				rlutil::locate(48, 17);
				cout << "SIGUIENTE RONDA N" << NumRondaP1 + 1; //cambiaar
			} 
			else {
				//cls y mostrar otra pantalla de final de jugada
				rlutil::setColor(rlutil::COLOR::LIGHTRED);
				rlutil::locate(48, 16);
				cout << "PUNTUAJE FINAL: " << puntajeTotalP1; 
				rlutil::setColor(rlutil::COLOR::WHITE);
				rlutil::locate(40, 20);
				cout << "Presione cualquier tecla para volver al menu principal";
			}

			rlutil::setColor(rlutil::COLOR::WHITE);

			rlutil::anykey();
		}
		return;

	}
}

//Modo Dos Jugadores
//pasarlo a otra libreria de dos jugadores
void modoDosJugadores()  {
	string Nombre1P;
	string Nombre2P;
	int puntajeTotalP1 = 0, puntajeTotalP2 = 0;
	int puntajeRondaP1 = 0, puntajeRondaP2 = 0;
	int lanzamientosP1 = 0, lanzamientosP2 = 0;
	int NumRondaP1 = 0, NumRondaP2 = 0;


	bool volverAlMenu = false;

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

		rlutil::locate(59, 18);
		cout << (char)175;
		rlutil::locate(43, 20);
		cout << "Presione cualquier letra para jugar";
		rlutil::anykey();

		

		while (puntajeTotalP1 <= 500 && puntajeTotalP2 <= 500) {
			
			lanzamientosP1 = 0, lanzamientosP2 = 0;
			// Se reinicia puntaje ronda al comenzar una nueva
			puntajeRondaP1 = 0, puntajeRondaP2 = 0; //tal vez da error

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

				puntajeRondaP1 += puntaje;
				// Actualizar el puntaje total del jugador
				puntajeTotalP1 += puntaje;

				rlutil::locate(15, 3);
				cout << "TURNO DE: " << Nombre1P;
				rlutil::locate(15, 5);
				cout << "RONDA NUMERO: " << NumRondaP1;
				rlutil::locate(15, 7);
				cout << "LANZAMIENTO: " << lanzamientosP1;
				rlutil::locate(60, 3);
				cout << "PUNTUAJE TOTAL: " << puntajeTotalP1;
				rlutil::locate(60, 5);
				cout << "PUNTAJE DE LA RONDA: " << puntajeRondaP1 << " PUNTOS" << endl << endl;
				rlutil::locate(60, 7);
				cout << "PUNTAJE DEL LANZAMIENTO: " << puntaje << " PUNTOS" << endl << endl;

				// Verificar si se obtuvo escalera o sexteto 6 para terminar la ronda
				if (puntajeTotalP1 >= 500 || puntajeTotalP1 == 0) {
					rlutil::locate(40, 28);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::anykey();
					break; // el break sale del while
				}

				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(40, 28);
				cout << "Presione cualquier tecla para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);
			}
			

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
			//rlutil::setColor(rlutil::COLOR::LIGHTRED);
			cout << "PUNTAJE DE " << Nombre1P << ": " << puntajeTotalP1 << " PUNTOS" << endl;
			rlutil::locate(48, 19);
			//rlutil::setColor(rlutil::COLOR::LIGHTRED);
			cout << "PUNTAJE DE " << Nombre2P << ": " << puntajeTotalP2 << " PUNTOS" << endl;
			rlutil::anykey();

			rlutil::setColor(rlutil::COLOR::WHITE);

			//aca va el while del player 2
			while (lanzamientosP2 < 3) {
				lanzamientosP2++;

				if (puntajeTotalP1 >= 500 || puntajeTotalP1 == 0) {
					rlutil::locate(40, 28);
					rlutil::anykey();
					break; 
				}

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
				int puntaje = 0;
				if (esSexteto(dados)) {
					puntaje = 0;
					rlutil::locate(50, 25);
					cout << "¡Combinacion Sexteto! ¡Perdiste todo! " << endl;
				}
				else if (esEscalera(dados)) {
					puntaje = 500;
					rlutil::locate(50, 25);
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

				puntajeRondaP2 += puntaje;
				
				puntajeTotalP2 += puntaje;

				rlutil::locate(15, 3);
				cout << "TURNO DE: " << Nombre2P;
				rlutil::locate(15, 5);
				cout << "RONDA NUMERO: " << NumRondaP2;
				rlutil::locate(15, 7);
				cout << "LANZAMIENTO: " << lanzamientosP2;
				rlutil::locate(60, 3);
				cout << "PUNTUAJE TOTAL: " << puntajeTotalP2;
				rlutil::locate(60, 5);
				cout << "PUNTAJE DE LA RONDA: " << puntajeRondaP2 << " PUNTOS" << endl << endl;
				rlutil::locate(60, 7);
				cout << "PUNTAJE DEL LANZAMIENTO: " << puntaje << " PUNTOS" << endl << endl;

				// Verificar si se obtuvo escalera o sexteto 6 para terminar la ronda
				if (puntajeTotalP2 >= 500 || puntajeTotalP2 == 0) {
					rlutil::locate(40, 28);
					cout << "Presione cualquier tecla para volver al menu principal";
					rlutil::anykey();
					break; // el break sale del while
				}

				// Mostrar los resultados parciales
				rlutil::setColor(rlutil::COLOR::DARKGREY);
				rlutil::locate(40, 28);
				cout << "Presione enter para tirar los dados";
				rlutil::anykey();
				rlutil::setColor(rlutil::COLOR::WHITE);
			}

			rlutil::anykey();
		}
		return;

	}
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
	cout<< "o sacar una escalera en un lanzamiento. " << endl;
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

