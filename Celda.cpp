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

void Celda::aplicarConportamiento(int *cantCelNacidasTurno) {

        if (estadoDeCelda == 1){
            aplicarEnvenenamiento();
        }

        else if (estadoDeCelda == 3){
            aplicarPortal(cantCelNacidasTurno);
        }

}

void Celda::setCelula(Celula *celulaIngresada) {


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



void Celda::aplicarPortal(int *cantCelNacidasTurno) {

    bool nacioCelula = false;
    int i = 0;
    int j = 0;
    while ((i < 1) && (j < celdasAdyacentes->getTamanioLista())){
        if( celdasAdyacentes->obtenerSegunPosicionDato(j)->obtenerCelula()->haNacido() ){
            nacioCelula = true;
            i++;
        }
        j++;
    }
    if(nacioCelula == false){
        return;
    }

    i = 0, j = 0 ;

    while(( i < 1  ) && ( j < celdasAdyacentes->getTamanioLista())){
        if(celdasAdyacentes->obtenerSegunPosicionDato(j)->obtenerCelula()->estaMuerta()){
            celdasAdyacentes->obtenerSegunPosicionDato(j)->obtenerCelula()->revivir();
            (*cantCelNacidasTurno) +=1;
            i++;
        }
        j++;
    }
}
void Celda::revivirCelula() {

    for(int i = 0; i < celdasAdyacentes->getTamanioLista(); i++){
        if(celdasAdyacentes->obtenerSegunPosicionDato(i)->obtenerCelula()->estaMuerta()){
            celdasAdyacentes->obtenerSegunPosicionDato(i)->obtenerCelula()->revivir();
        }
    }


}



int Celda::obtenerCantCelVivasAdy(){
    int cantCelVivas = 0;
    for(int i = 0; i < celdasAdyacentes->getTamanioLista() ; i++ ){
        if(celdasAdyacentes->obtenerSegunPosicionDato(i)->obtenerCelula()->estaViva()){
            cantCelVivas++;
        }
    }
    return cantCelVivas;
}




Celda::~Celda(){
    delete celdasAdyacentes;
    delete celula;
}

bool Celda::tieneEstadoProcreadora() {

    return(estadoDeCelda == 4);

}

void Celda::agregarAdyacente(Celda *unaCelda) {
    celdasAdyacentes->insertarElemento(unaCelda);

}

void Celda::imprimirCelda() {
    if(this!= NULL){
        cout << "estadoActual de tableroCelda:  "<< estadoDeCelda ;
        cout << "  posX: " << posicionX << "  posY: " <<posicionY << "  posZ: " << posicionZ<< endl;
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


