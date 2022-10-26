//
#include "Celda.h"
#include <iostream>
#include <stdlib.h>
#include <iostream>

using namespace std;
Celda::Celda() {

}

void Celda::setyAplicarConportamiento() {

        estadoDeCelda = 1 + rand() % 5;
        if (estadoDeCelda == 1){
            aplicarEnvenenamiento();
        }
        else if (estadoDeCelda == 2){
            aplicarContaminacion();
        }
        else if (estadoDeCelda == 3){
            aplicarPortal();
        }

        else if (estadoDeCelda == 5){
            aplicarRadioactividad();
        }
}

Celda::Celda(int columnaIngresada, int filaIngresada, int profundidadIngresada) {

    this->celula = new Celula();

}
void Celda::setCelula(Celula *celulaIngresada) {

    delete celula;
    celula = celulaIngresada;
}

void Celda::asignarVecino(int ancho, int alto, int profundidad, Celda *celVecino) {
    this->vecinosAdyacentes[ancho + 1][alto + 1][profundidad + 1];
}

Celula* Celda::obtenerCelula(){
    return this->celula;
}


void Celda::aplicarEnvenenamiento(){
    celula->matarUnGen();
}

void Celda::aplicarContaminacion(){
    celula->matarCelula();
}

void Celda::aplicarPortal(){

}

void Celda::aplicarRadioactividad() {

}



bool Celda::tieneVecino(int ancho, int alto, int profundidad) {}

Celda::~Celda(){

}

bool Celda::tieneEstadoProcreadora() {

    return(estadoDeCelda == 3);

}




/*
 *     int contaminada;//estado = 1:celda contaminada
    int envenenada;//estado = 2 :celda envenenada
    int procreadora;//estade = 3:celda preocreadora
    int portal;//estado = 4:celda portal
    //estado = 5 :celda radioactiva
    int estadoDeCelda;
 */