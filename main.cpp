#include <iostream>

#include "Juego.h"

int main() {
    Juego* juego = new Juego();
    juego->iniciarJuego();
    delete juego;

    return 0;
}
/*Tablero* untablero = new Tablero(6,6,6);
untablero->asignarCeldasAdayacentes( untablero->obtenerCelda(5, 5, 5) );
Lista<Celda*>* listaCeldas = untablero->obtenerCelda(5,5,5)->getCeldasAdyacentes();
listaCeldas->iniciarCursor();
while( listaCeldas->avanzarCursor() ){
    listaCeldas->obtenerCursor()->imprimirCelda();
}
*/