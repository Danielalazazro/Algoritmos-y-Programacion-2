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
    estadoActual = 1;
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
    Gen* nuevoArrayGen ;
    int modoCalcularCargas = 1 + rand() % 3;
    if(modoCalcularCargas == 1){
        nuevoArrayGen = promedioDeCargas(celulasVivas);
    }
    else if(modoCalcularCargas == 2){
        nuevoArrayGen = minimoDeCargas(celulasVivas);
    }
    else if(modoCalcularCargas == 3){
        nuevoArrayGen = maximoDeCargas(celulasVivas);
    }
    if(estadoCelda == 5){
        nuevoArrayGen[0].setCargaGenetica( sqrt( nuevoArrayGen[0].getCargaGenetica()));
        nuevoArrayGen[1].setCargaGenetica( sqrt( nuevoArrayGen[1].getCargaGenetica()));
        nuevoArrayGen[2].setCargaGenetica( sqrt( nuevoArrayGen[2].getCargaGenetica()));
    }
    this->arrayGen[0] =  nuevoArrayGen[0];
    this->arrayGen[1] = nuevoArrayGen[1];
    this->arrayGen[2] = nuevoArrayGen[2];


}

Gen* Celula::getArrayGen(){
    return arrayGen;

}
Gen* Celula::promedioDeCargas(Lista<Celula *> *celulasVivas){
    Gen unosGenes[3];
    int i = 0, carga1 = 0, carga2 = 0, carga3 = 0;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 += genes[0].getCargaGenetica();
        carga2 += genes[1].getCargaGenetica();
        carga3 += genes[2].getCargaGenetica();
        i++;
    }
    unosGenes[0] = Gen(carga1/i);
    unosGenes[1] = Gen(carga2/i);
    unosGenes[2] = Gen(carga3/i);
    return unosGenes;
}
Gen* Celula::minimoDeCargas(Lista<Celula *> *celulasVivas){

    Gen unosGenes[3];
    int  carga1 = 10, carga2 = 10, carga3 = 10;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 = min((int) genes[0].getCargaGenetica() , carga1);
        carga2 = min((int) genes[1].getCargaGenetica() , carga2);
        carga3 = min((int) genes[2].getCargaGenetica() , carga3);

    }
    unosGenes[0] = Gen(carga1);
    unosGenes[1] = Gen(carga2);
    unosGenes[2] = Gen(carga3);
    return unosGenes;
}
Gen* Celula::maximoDeCargas(Lista<Celula *> *celulasVivas){
    Gen unosGenes[3];
    int  carga1 = 10, carga2 = 10, carga3 = 10;
    celulasVivas->iniciarCursor();
    while(celulasVivas->avanzarCursor()){
        Gen* genes = celulasVivas->obtenerCursor()->getArrayGen();
        carga1 = max((int) genes[0].getCargaGenetica() , carga1);
        carga2 = max((int) genes[1].getCargaGenetica() , carga2);
        carga3 = max((int) genes[2].getCargaGenetica() , carga3);

    }
    unosGenes[0] = Gen(carga1);
    unosGenes[1] = Gen(carga2);
    unosGenes[2] = Gen(carga3);
    return unosGenes;
}