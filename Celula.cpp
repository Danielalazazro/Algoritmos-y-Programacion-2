//
// Created by daniela on 29/09/22.
//

#include "Celula.h"
#include <cstdlib>
# include <iostream>
#include "AdministradorGen.h"
#include "Gen.h"
#include "Lista.h"
#include "cmath"
#include <math.h>

Celula ::Celula() {
    //CUando creo una celula la inicializo en 0.
    arrayGen[0] = Gen(0);
    arrayGen[1] = Gen(0);
    arrayGen[2] = Gen (0);
    estadoActual = 0;
    estadoAnterior = 0;
}

void Celula::setearCargaGeneticaUsuario(){
    arrayGen[0].insertarCargaUsuario();
    arrayGen[1].insertarCargaUsuario();
    arrayGen[3].insertarCargaUsuario();
}
void Celula::setearCargaGeneticaAleatoria(){
    arrayGen[0] = Gen(rand() % maximaCargaGenetica);
    arrayGen[1] = Gen(rand() % maximaCargaGenetica);
    arrayGen[2] = Gen(rand() % maximaCargaGenetica);
}
int Celula::obtenerCargaGeneticaPredominante()
{
    AdministradorGen adminGen = AdministradorGen( arrayGen[0], arrayGen[1], arrayGen[2]);
    return adminGen.obtenerGen().getCargaGenetica();

}

Celula::Celula(int gen1, int gen2, int gen3) {
    arrayGen[0] = Gen(gen1);
    arrayGen[1] = Gen(gen2);
    arrayGen[2] = Gen (gen3);
}
bool Celula::estaViva(){
    return (estadoActual == 1);
}

void Celula::dibujar(){
    if(estadoActual == 1){
        std::cout<<"*";
    }
    else{
        std::cout<<"o";
    }
}

void Celula::revivir(){
    if(estadoActual == 0){
        estadoActual = 1;
    }
}

void Celula::matarUnGen(){
    int i = 0;
    while(i < maximoGenes ){
        if(arrayGen[i].estaVivoGen()){
            arrayGen[i].matarGen();
            return;
        }
        else{
            i++;
        }
    }
}
Celula::~Celula() {}

void Celula::matarCelula() {
    estadoActual = 0;
}
bool Celula::haNacido(){
    return ((estadoAnterior == 0) && (estadoActual == 1));

}

bool Celula::estaMuerta() {
    return (estadoActual == 0);

}

void Celula::heredarCargaGenetica(Lista<Celula *> *celulasVivas, int estadoCelda) {
    int carga1, carga2, carga3;
    int modoCalcularCargas = 1 + rand() % 3;
    if(modoCalcularCargas == 1){
        promedioDeCargas(celulasVivas, &carga1, &carga2, &carga3);
    }
    else if(modoCalcularCargas == 2){
        minimoDeCargas(celulasVivas, &carga1, &carga2, &carga3);
    }
    else if(modoCalcularCargas == 3){
        maximoDeCargas(celulasVivas, &carga1, &carga2, &carga3);
    }
    if(estadoCelda == 5){
        carga1 = sqrt( carga1);
        carga2 = sqrt( carga2);
        carga3 = sqrt( carga3);
    }
    this->arrayGen[0] =  carga1;
    this->arrayGen[1] = carga2;
    this->arrayGen[2] = carga3;
}

Gen* Celula::getArrayGen(){
    return arrayGen;

}
void Celula::promedioDeCargas(Lista<Celula *> *celulasVivas, int *cargaGen1, int *cargaGen2, int *cargaGen3) {
    int i = 0, carga1 = 0, carga2 = 0, carga3 = 0;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 += genes[0].getCargaGenetica();
        carga2 += genes[1].getCargaGenetica();
        carga3 += genes[2].getCargaGenetica();
        i++;
    }
    *cargaGen1 = carga1/i;
    *cargaGen2 = carga2/i;
    *cargaGen3 = carga3/i;
}

void Celula::minimoDeCargas(Lista<Celula *> *celulasVivas, int *cargaGen1, int *cargaGen2, int *cargaGen3) {

    int  carga1 = 255, carga2 = 255, carga3 = 255;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 = min((int) genes[0].getCargaGenetica() , carga1);
        carga2 = min((int) genes[1].getCargaGenetica() , carga2);
        carga3 = min((int) genes[2].getCargaGenetica() , carga3);

    }
    *cargaGen1 = carga1;
    *cargaGen2 = carga2;
    *cargaGen3 = carga3;
}
void Celula::maximoDeCargas(Lista<Celula *> *celulasVivas, int *cargaGen1, int *cargaGen2, int *cargaGen3) {
    int  carga1 = 10, carga2 = 10, carga3 = 10;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 = max((int) genes[0].getCargaGenetica() , carga1);
        carga2 = max((int) genes[1].getCargaGenetica() , carga2);
        carga3 = max((int) genes[2].getCargaGenetica() , carga3);

    }
    *cargaGen1 = carga1;
    *cargaGen2 = carga2;
    *cargaGen3 = carga3;
}

void Celula::antesVivaAhoraMuerta() {
    estadoAnterior = 1;
    estadoActual = 0;
}
