//
// Created by daniela on 01/10/22.
//

#include "Gen.h"
#include <iostream>

using namespace std;
Gen::Gen() {}
Gen::Gen(unsigned int cargaGen) {
    verificarEnRango(cargaGen);
    if (verificarEnRango(cargaGen)){
        this->cargaGenetica = cargaGen;
    }
    else {
        cargaGenetica =  rand() % 255;
    }
}
Gen::~Gen(){}

unsigned int Gen::getCargaGenetica() {
    return this->cargaGenetica;
}

void Gen::setCargaGenetica(unsigned int cargaGenetica) {
    this->cargaGenetica = cargaGenetica;
}

bool Gen::verificarEnRango(unsigned int cargaGenetica) {
    return ((cargaGenetica >= 0) && (cargaGenetica <= maximaCargaGenetica));
}

void Gen::insertarCargaUsuario(){
    unsigned int cargaGeneticaIngreso = 300;
    cout << "Ingrese la  carga genetica  de la celula:"<< endl;

    while(not (verificarEnRango(cargaGeneticaIngreso))){
        cin >> cargaGeneticaIngreso;
        if(not verificarEnRango(cargaGeneticaIngreso)){
            cout << "Error, ingrese una carga genetica valida o dentro del rango"<<endl;
        }
    }
    this->cargaGenetica = cargaGeneticaIngreso;
}

void Gen::insertarCargaAleatoria(){
    int cargaGeneticaAleatoria = rand() % maximaCargaGenetica;
    this->cargaGenetica = cargaGeneticaAleatoria;

}
bool Gen::estaVivoGen(){
    {
        return (cargaGenetica > 0);
    }
}
void Gen::matarGen(){

    cargaGenetica = 0;

}