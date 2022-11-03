#include <iostream>

#include "Juego.h"

int main() {
    Juego* juego = new Juego();
    juego->iniciarJuego();
    delete juego;

    return 0;
}
