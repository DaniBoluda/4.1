#include "lib/dados.h"
#include <random>
#include "rlutil.h"
#include <windows.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

//Combinaciones Ganadoras


//Escalera
bool Escalera(int dados[6]) {
	// ordena con metodo burbuja
	for (int i = 0; i < 6 - 1; ++i) {
		for (int j = 0; j < 6 - i - 1; ++j) {
			if (dados[j] > dados[j + 1]) {
				// Intercambiar los elementos si están en el orden incorrecto
				int temp = dados[j];
				dados[j] = dados[j + 1];
				dados[j + 1] = temp;
			}
		}
	}

	if (dados[0] == 1 &&
		dados[1] == 2 &&
		dados[2] == 3 &&
		dados[3] == 4 &&
		dados[4] == 5 &&
		dados[5] == 6)
		return true;
	else
		return false;
}

//Suma de Dados
int SumaDeDados(int dados[6]) {
	int suma = 0;

	for (int i = 0; i < 6; i++) {
		suma += dados[i];
	}

	return suma;
}

//trio
int MayorTrio(int dados[6]) {
	int valor = dados[0];
	// TODO: buscar el numero q coincide

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

//Sexteto de dados, 6 dados iguales EXCEPTO EL SEIS
int Sexteto(int dados[6]) {
	int Dado = dados[0];


	bool sexteto = true;
	for (int i = 1; i < 6; i++) {
		if (dados[i] != Dado || Dado == 6) {
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

// se comprueba que los dados recibidos sean igual 6 (sexteto) por lo que se devuelve true caso contrario false
bool Sexteto6MM(int dados[6]) {
	for (int i = 0; i < 6; i++) {
		if (dados[i] != 6) {
			return false; //no hay sexteto
		}
	}

	return true; //es verdadero
}

bool existeDadosIguales(int dados[6])
{
	int valor = dados[0];
	// hacer un for y comparar con cada elemento == valor si es verdad true

	return false;
}

int contarOcurrencias(int dados[6], int numeroBuscado) {
	int contador = 0;

	for (int i = 0; i < 6; ++i) {
		if (dados[i] == numeroBuscado) {
			contador++;
		}
	}

	return contador;
}

bool existeTresNumerosIgualesOMayor(int dados[6])
{
	for (int i = 0; i < 6; ++i) {
		int cantidad = contarOcurrencias(dados, dados[i]); // se le pasa el vector y cada elemento del vector dentro del for
		if (cantidad > 2 && cantidad < 6) // cantidad sea 3, 4 o 5
		{
			return true;
		}
	}

	return false;  // No se encontró ninguna ocurrencia de igualdad
}

bool existeDosNumerosIguales(int dados[6])
{
	for (int i = 0; i < 6; ++i) {
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

