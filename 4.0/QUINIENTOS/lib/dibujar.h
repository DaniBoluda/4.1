#ifndef dibujar_h
#define dibujar_h
#include <vector>

int SeisNumeros(int min, int max);

int dibujarDado(int num);

int numAleatorio1_6();

std::vector<int> LanzarDados();

void Dado(int posx, int posy, int num, int tam);

void Cuadrado(int posx, int posy, int tam);

void DibujarLineas(int x1, int y1, int x2, int y2, char symbol);

#endif
