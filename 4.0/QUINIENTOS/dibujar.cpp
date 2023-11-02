#include "lib/dibujar.h"
#include <random>
#include "rlutil.h"
#include <windows.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Genera 6 numeros aleatorios Utilizando las funcion srand, incluida en la bilioteca estandar de c++, (Iniciar la semilla srand(time(0)) para numeros aleatorios.)
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