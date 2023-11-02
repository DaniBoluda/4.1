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

int contarOcurrencias(const std::vector<int>& numeros, int numeroBuscado) {
	int contador = 0;

	for (int i = 0; i < numeros.size(); ++i) {
		if (numeros[i] == numeroBuscado) {
			contador++;
		}
	}

	return contador;
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

