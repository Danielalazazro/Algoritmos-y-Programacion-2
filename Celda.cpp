//
#include "Celda.h"
#include <iostream>
#include <stdlib.h>


using namespace std;
Celda::Celda() {
    posicionX = 0;
    posicionY = 0;
    posicionZ = 0;

    estadoDeCelda = 1 + rand() % 5;
}
Celda::Celda(int filaIngresa, int columnaIngresada, int profundidadIngresada){
   this->posicionX = filaIngresa;
   this->posicionY = columnaIngresada;
   this->posicionZ = profundidadIngresada;
   this->celula = new Celula();
   this->celdasAdyacentes = new Lista<Celda*> ;
    estadoDeCelda = 1 + rand() % 5;
}
int Celda::getPosX(){
    return posicionX;
}
int Celda::getPosY() {
    return posicionY;
}
int Celda::getPosZ(){
    return posicionZ;
}

Lista<Celda*>* Celda::getCeldasAdyacentes(){
    return celdasAdyacentes;
}

void Celda::aplicarConportamiento() {

        if (estadoDeCelda == 1){
            aplicarEnvenenamiento();
        }

        else if (estadoDeCelda == 3){
            aplicarPortal();
        }

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



void Celda::aplicarPortal(){

    celdasAdyacentes->iniciarCursor();
    while(celdasAdyacentes->avanzarCursor() ){
        if(celdasAdyacentes->obtenerCursor()->obtenerCelula()->haNacido()){
            revivirCelula();
        }
    }
}



int Celda::obtenerCantCelVivasAdy(){
    int cantCelVivas = 0;
    celdasAdyacentes->iniciarCursor();
    while (celdasAdyacentes->avanzarCursor()){
        if(celdasAdyacentes->obtenerCursor()->obtenerCelula()->estaViva()){
            cantCelVivas++;
        }
    }
    return cantCelVivas;
}




Celda::~Celda(){

}

bool Celda::tieneEstadoProcreadora() {

    return(estadoDeCelda == 4);

}

void Celda::agregarAdyacente(Celda *unaCelda) {
    celdasAdyacentes->insertarElemento(unaCelda);

}

void Celda::imprimirCelda() {
    cout << "estadoActual de celda:  "<< estadoDeCelda ;
    cout << "  posX: " << posicionX << "  posY: " <<posicionY << "  posZ: " << posicionZ<< endl;

}

void Celda::revivirCelula() {
    celdasAdyacentes->iniciarCursor();
    while (celdasAdyacentes->avanzarCursor()){
        if(celdasAdyacentes->obtenerCursor()->obtenerCelula()->estaMuerta()){
            celdasAdyacentes->obtenerCursor()->obtenerCelula()->revivir();
            return;
        }
    }

}

int Celda::getEstado() {

    return estadoDeCelda;
}

bool Celda::tieneEstadoContaminada() {
    return (estadoDeCelda == 2);
}

void Celda::setNuevoEstado() {
    estadoDeCelda = 1 + rand() % 5;
}


