//
// Created by daniela on 29/09/22.
//

#include "Celula.h"
#include <cstdlib>
# include <iostream>
#include "AdministradorGen.h"
#include "Gen.h"

Celula ::Celula() {}

void Celula::setearCargaGeneticaUsuario(){
    arrayGen[0].insertarCargaUsuario();
    arrayGen[1].insertarCargaUsuario();
    arrayGen[3].insertarCargaUsuario();
}
void Celula::setearCargaGeneticaAleatoria(){
    arrayGen[0] = Gen(rand()% maximaCargaGenetica);
    arrayGen[1] = Gen(rand() % maximaCargaGenetica);
    arrayGen[3] = Gen(rand() % maximaCargaGenetica);
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
    return (estado == 1);
}

void Celula::dibujar(){
    if(estado == 1){
        std::cout<<"*";
    }
    else{
        std::cout<<" ";
    }

}

void Celula::revivir(){
    estado = 1;
}

void Celula::matarUnGen(){
    int i = 0;
    while(i < 3 ){
        if(arrayGen[i].estaVivoGen()){
            arrayGen[i].matarGen();
        }
        else{
            i++;
        }
    }

}
Celula::~Celula() {}

void Celula::matarCelula() {
    estado = 0;
}
