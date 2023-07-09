#include "lib/FUNCIONES.h"
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




//Combinaciones Ganadoras


//Escalera
bool Escalera(const std::vector<int>& dados) {
	std::vector<int> Ordenados = dados;
	std::sort(Ordenados.begin(), Ordenados.end());

	if (Ordenados == std::vector<int>{1, 2, 3, 4, 5, 6}) {
		return true;
	}
	return false;
}

//Suma de Dados
int SumaDeDados(const std::vector<int>& resultados) {
	int suma = 0;
	std::map<int, int> contador;

	for (int valor : resultados) {
		suma += valor;
		contador[valor]++;
	}

	return suma;
}

//trio
int MayorTrio(const std::vector<int>& resultados) {
	int valor = resultados[0];
	// buscar el numero q coincide

	return valor * 10;
} //verificar este metodo 

//Trío X++
/*int MayorTrio(const std::vector<int>& resultados) {

	int MayorTrio = 0;

	for (int valor = 1; valor <= 6; ++valor) {
		int contador = 0;

		for (int dado : resultados) {
			if (dado == valor) {
				contador++;
			}
		}

		if (contador >= 3 && valor > MayorTrio) {
			MayorTrio = valor;
		}
	}

	return MayorTrio;
}
//otra version -> empieza aca
int MayorTrio(const std::vector<int>& resultados) {

	int MayorTrio = 0;

int calcularPuntaje( int dados[]) {
	int puntaje = 0;
	int repeticiones = 1;

for (int i = 1; i < 6; ++i) {
	if (dados[i] == dados[i - 1]) {
		repeticiones++;
	}
	else {
		if (repeticiones >= 3) {
			puntaje += repeticiones * 10;
		}
		repeticiones = 1;
	}
}

if (repeticiones >= 3) {
	puntaje += repeticiones * 10;
}

return puntaje;
}*/
//otra version

//Sexteto X
int Sexteto(const std::vector<int>& resultados) {
	int Dado = resultados[0];


	bool sexteto = true;
	for (int i = 1; i < 6; i++) {
		if (resultados[i] != Dado || Dado == 6) {
			sexteto = false;
			break;
		}
	}


	if (sexteto) {
		return Dado * 50;
	}
	else {
		return 0;
	}
}

//Seis 6
bool Sexteto6MM(const std::vector<int>& resultados) {
	for (int valor : resultados) {
		if (valor != 6) {
			return false;
		}
	}
	return true;
}

bool existeDadosIguales(const std::vector<int>& dados)
{
	int valor = dados[0];
	// hacer un for y comparar con cada elemento == valor si es verdad true

	return false;
}

bool existeTresNumerosIgualesOMayor(const std::vector<int>& dados)
{
	for (int i = 0; i < dados.size(); ++i) {
		int cantidad = contarOcurrencias(dados, dados[i]); // se le pasa el vector y cada elemento del vector dentro del for
		if (cantidad > 2 && cantidad < 6) // cantidad sea 3, 4 o 5
		{
			return true;
		}
	}

	return false;  // No se encontró ninguna ocurrencia de igualdad
}

bool existeDosNumerosIguales(const std::vector<int>& dados)
{
	for (int i = 0; i < dados.size(); ++i) {
		int cantidad = contarOcurrencias(dados, dados[i]); // se le pasa el vector y cada elemento del vector dentro del for
		if (cantidad == 2)
		{
			return true;
		}
	}

	return false;  // No se encontró ninguna ocurrencia de igualdad

	//for (int i = 0; i < dados.size(); ++i) {
	//	for (int j = 0; j < dados.size(); ++j) {
	//		if (i != j && dados[i] == dados[j]) {
	//			return true;  // Se encontró una ocurrencia de igualdad
	//		}
	//	}
	//}

	//return false;  // No se encontró ninguna ocurrencia de igualdad
}


//______________________________________________________________________     

							 //Menu 1P

void ModoUnJugador() {
	string Nombre1P;
	int PuntajeTotalP1 = 0;
	int MaxPuntajeP1 = 0;
	int LanzamientosP1 = 0;
	int NumRondaP1 = 0;
	int MAX_RONDAS = 0;

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

		if (MAX_RONDAS == 0) {
			MAX_RONDAS = 3;
		}

		while (MaxPuntajeP1 <= 500 && NumRondaP1 < MAX_RONDAS) {
			NumRondaP1++;
			LanzamientosP1 = 0;
			MaxPuntajeP1 = 0;

			while (LanzamientosP1 < 3) {
				LanzamientosP1++;

				// Tirar los dados y guardar en resultados
				//std::vector<int> resultados;
				//for (int i = 0; i < 6; ++i) {
				//	int resultado = numAleatorio1_6();
				//	resultados.push_back(resultado);
				//}

				rlutil::cls();
				Rectangulo1P();
				Esquinas();
				rlutil::locate(50, 3);

				std::vector<int> resultados;
				for (int i = 0; i < 6; ++i) {
					int resultado = numAleatorio1_6();
					resultados.push_back(resultado);
					Dado(1 + (i * 20), 11, resultado, 19);
				}

				// Aca verificar los dados y las jugadas
				int puntaje = 0;
				if (Sexteto6MM(resultados)) {
					puntaje = 0;
					rlutil::locate(50, 25);
					cout << "Combinacion Sexteto! Perdiste todo! ";
				}
				else if (Escalera(resultados)) {
					puntaje = 500;
					rlutil::locate(50, 25);
					cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!";
				}
				else if (existeDadosIguales(resultados))
				{
					puntaje = Sexteto(resultados);
					rlutil::locate(50, 25);
					cout << "Combinacion Sexteto X";
				}
				else if (existeTresNumerosIgualesOMayor(resultados)) {
					puntaje = MayorTrio(resultados);
					rlutil::locate(50, 25);
					cout << "Combinacion TRIO! ";
				}
				else if (existeDosNumerosIguales(resultados)) {
					puntaje = SumaDeDados(resultados);
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


	}
}

//Modo Dos Jugadores

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




//Genera 6 numeros aleatorios Utilizando las funcion srand, incluida en la bilioteca estandar de c++, (Iniciar la semilla srand(time(0)) para numeros aleatorios.)
int SeisNumeros(int min, int max) {
	return rand() % (max - min + 1) + min;
}

//Con esta funcion creamos un Vector de 6 Vacio, utilizando la funcion de SeisNumeros se  llena el vector con los numeros aleatorios(almacena los dados)
/*Push_back hace que LanzarDados se Almacene en Resultados*/
std::vector<int> LanzarDados() {
	std::vector<int> Resultados;
	for (int i = 0; i < 6; i++) {
		int numero = SeisNumeros(1, 6);
		Resultados.push_back(numero);
	}
	return Resultados;
}

//Genera Lineas, siendo x1 La linea principal del Eje X
//x2 Siendo el punto final de la linea x1
//y1 Seria La linea del eje Y
//y2 Siendo el punto final de la linea y2
//DIbujando el caracter seleccionado 
void DibujarLineas(int x1, int y1, int x2, int y2, char symbol) {
	for (int x = x1; x <= x2; x++) {
		for (int y = y1; y <= y2; y++) {
			rlutil::locate(x, y);
			std::cout << symbol;
		}
	}
}

//Genera el recuadro de los dados
void Cuadrado(int posx, int posy, int tam) {
	for (int y = 1; y <= tam / 2; y++) {
		for (int x = 1; x <= tam; x++) {
			rlutil::locate(x + posx, y + posy);
			cout << (char)219;
		}
	}
}


//Genera Graficamente 6 Dados 
void Dado(int posx, int posy, int num, int tam) {
	Cuadrado(posx, posy, tam);

	switch (num) {
	case 1:
		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;
		break;

	case 2:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;
		break;

	case 3:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;
		break;

	case 4:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;
		break;

	case 5:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;
		break;

	case 6:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;
		break;

	default:
		break;
	}
}

//Genera 6 numeros aleatorios Utilizando las funciones de Random, devolviendo 6 numeros Totalmente aleatorios.
int numAleatorio1_6() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	return dis(gen);
}
int dibujarDado(int num) {
	return num;
}

int contarOcurrencias(const std::vector<int>& numeros, int numeroBuscado) {
	int contador = 0;

	for (int i = 0; i < numeros.size(); ++i) {
		if (numeros[i] == numeroBuscado) {
			contador++;
		}
	}

	return contador;
}