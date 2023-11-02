#include <iostream>
#include "lib/rlutil.h"
#include "FUNCIONES.h"
#include "lib/dibujar.h"
#include "lib/dados.h"

using namespace std;

int main() {
    int opcion = 1, y = -2;
    //1P
    string Nombre1P;
    int MaxPuntajeP1 = 0;
    int LanzamientosP1 = 0;

    do {
        Titulo();
        Esquinas();


        rlutil::setColor(y == -2 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 13);
        cout << "MODO UN JUGADOR" << endl;

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(46, 14);

        rlutil::setColor(y == 0 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 15);
        cout << "MODO DOS JUGADORES" << endl;

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(46, 16);

        rlutil::setColor(y == 2 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 17);
        cout << "PUNTUACION MAS ALTA" << endl;

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(46, 18);

        rlutil::setColor(y == 4 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 19);
        cout << "COMO SE JUEGA?" << endl;

        rlutil::setColor(y == 6 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 21);
        cout << "COMBINACIONES GANADORAS" << endl;

        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(46, 23);

        rlutil::setColor(y == 8 ? rlutil::COLOR::GREEN : rlutil::COLOR::WHITE);
        rlutil::locate(48, 23);
        cout << "SALIR DEL JUEGO" << endl;

        rlutil::setColor(rlutil::COLOR::LIGHTRED);
        rlutil::locate(1, 30);
        cout << "Agustin Bernal";

        rlutil::setColor(rlutil::COLOR::LIGHTRED);
        rlutil::locate(110, 30);
        cout << "Dana Claros";

        int Key = rlutil::getkey();

        switch (Key) {

        case rlutil::KEY_UP:
            // Navegar hacia arriba
            y -= 2;
            if (y < -2) {
                y = -2;
            }
            break;
        case rlutil::KEY_DOWN:
            // Navegar hacia abajo
            y += 2;
            if (y > 8) {
                y = 8;
            }
            break;
        case rlutil::KEY_ENTER:
            // Presionar Enter


            switch (y) {

            case -2:
                // Modo un jugador
            {
                ModoUnJugador();


            }
            break;


            case 0:
                // MODO DOS JUGADORES
                ModoDosJugadores();
                break;
            case 2:
                // MOSTRAR CALIFICACION MAXIMA

                rlutil::anykey();
                break;
            case 4:
                // AYUDA


                rlutil::anykey();
                break;
            case 6:
                // COMBINACIONES GANADORAS

                rlutil::anykey();

                break;
            case 8:
                // SALIR DEL JUEGO
                opcion = 0; // Terminar el programa
                break;
            }
            break;
        default:
            break;
        }

    } while (opcion != 0);


    return 0;
}
