#include "lib/dados.h"
#include <random>
#include "rlutil.h"
#include <windows.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

//Escalera
bool esEscalera(int dados[6]) {
	bool uno = false;
	bool dos = false;
	bool tres = false;
	bool cuatro = false;
	bool cinco = false;
	bool seis = false;

	for (int i = 0; i < 6; i++) {
		if (dados[i] == 1) {
			uno = true;
		}

		if (dados[i] == 2) {
			dos = true;
		}

		if (dados[i] == 3) {
			tres = true;
		}

		if (dados[i] == 4) {
			cuatro = true;
		}

		if (dados[i] == 5) {
			cinco = true;
		}

		if (dados[i] == 6) {
			seis = true;
		}
	}

	return uno && dos && tres && cuatro && cinco && seis;
}

// se comprueba que los dados recibidos sean igual 6 (sexteto) por lo que se devuelve true caso contrario false
bool esSexteto(int dados[6]) {
	for (int i = 0; i < 6; i++) {
		if (dados[i] != 6) {
			return false; //no hay sexteto
		}
	}

	return true; //es verdadero
}

bool esSextetoX(int dados[6])
{
	int valor = dados[0];
	// hacer un for y comparar con cada elemento == valor si es verdad true
	for (int i = 0; i < 6; ++i) {
		if (dados[i] == 1) {
			return true;
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == 2) {
			return true;
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == 3) {
			return true;
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == 4) {
			return true;
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == 5) {
			return true;
		}
	}

	return false;
}

bool esTrio(int dados[6])
{
	for (int i = 0; i < 6; ++i) {
		// obtengo la cantidad de ocurrencias del numero del dado. 4 3 2 1 2 2 cantidad = 3
		int cantidad = contarOcurrencias(dados, dados[i]);
		if (cantidad > 2 && cantidad < 6) {
			return true;
		}
	}

	return false;  // No se encontró ninguna ocurrencia de igualdad
}

int contarOcurrencias(int dados[6], int numeroBuscado) {
	int ocurrencias = 0;

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == numeroBuscado) {
			ocurrencias++;
		}
	}

	return ocurrencias;
}

// En el caso que haya 2 ternas de dados se debe elegir la que otorgue el puntaje mayor.
int puntajeTrio(int dados[6]) {
	int maxOcurrencia = 0;
	int numeroOcurrencia = 0;

	for (int i = 0; i < 6; ++i) {
		// obtengo la cantidad de ocurrencias del numero del dado.
		int numeroDado = dados[i];
		int ocurrencia = contarOcurrencias(dados, numeroDado);

		// 2 2 5 5 5 5
		if (ocurrencia > maxOcurrencia) {
			maxOcurrencia = ocurrencia;
			numeroOcurrencia = numeroDado;
		}

		// 1 1 1 2 2 2
		if (ocurrencia == maxOcurrencia && numeroDado > numeroOcurrencia) {
			numeroOcurrencia = numeroDado;
		}
	}

	return numeroOcurrencia * 10;
}

bool esSumaDeDados(int dados[6])
{
	for (int i = 0; i < 6; ++i) {
		int cantidad = contarOcurrencias(dados, dados[i]); 
		if (cantidad == 2) {
			return true;
		}
	}

	return false;
}

// Suma de Dados
int puntajeSumaDeDados(int dados[6]) {
	int suma = 0;

	for (int i = 0; i < 6; i++) {
		suma += dados[i];
	}

	return suma;
}
