#ifndef dados_h
#define dados_h
#include <vector>

//Combinaciones Ganadoras
bool Escalera(const std::vector<int>& dados);
bool existeDadosIguales(const std::vector<int>& dados);
bool existeTresNumerosIgualesOMayor(const std::vector<int>& dados);
bool existeDosNumerosIguales(const std::vector<int>& dados);
bool Sexteto6MM(const std::vector<int>& resultados);


int SumaDeDados(const std::vector<int>& resultados);

int MayorTrio(const std::vector<int>& resultados);

int Sexteto(const std::vector<int>& resultados);

int contarOcurrencias(const std::vector<int>& numeros, int numeroBuscado);


#endif


