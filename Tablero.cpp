//
// Created by daniela on 08/10/22.
//

#include "Tablero.h"
#include "Celda.h"
#include "Lista.h"
#include <string>
using namespace std;
#include <iostream>
#include <cmath>
#include <math.h>

Celda* Tablero::obtenerCelda(int profundidad , int fila, int columna ){
    cout << profundidad;
    cout <<fila;
    cout << columna;
    return this->tablero->obtener(profundidad)->obtener(fila)->obtener(columna);
}

void Tablero::obtenerCelulaVivaEnPosicionAleatoria(int *profundiaRandom, int *filaRandom, int* columnaRandom ){
   *profundiaRandom =  rand() % cantidadProfundidadMaximaTablero;
   *filaRandom = rand() % cantidadColumnasMaximaTablero;
   *columnaRandom = rand() % cantidadFilaMaximaTablero;

}

void Tablero::verificarIngresoUsuario(int limiteSuperior, int* ingresoUsuario){
    //*numero = 10;
    while( (*ingresoUsuario > limiteSuperior) && (*ingresoUsuario <= 0) ){
        cin >>*ingresoUsuario;
        if(*ingresoUsuario > limiteSuperior){
            std::cout<<"ERROR RANGO INVALIDO\n";
        }
    }
}
void Tablero::cargarCelulasAleatoria(){

    cantidadCelulaVivasActuales = 20;
    int i = 0;
    while(i < cantidadCelulaVivasActuales){
        int filaRandom, columnaRandom, profundidadRandom;
        obtenerCelulaVivaEnPosicionAleatoria(&profundidadRandom, &columnaRandom, &filaRandom);
        Celda * celdaAleatoria = obtenerCelda(profundidadRandom, filaRandom, columnaRandom);
        if( not celdaAleatoria->obtenerCelula()->estaViva()){
            celdaAleatoria->obtenerCelula()->revivir();
            celdaAleatoria->obtenerCelula()->setearCargaGeneticaAleatoria();
            i++;
        }
    }
}
void Tablero::cargarCelulaUsuario(int modoJuego) {
    int cantidadCelulaViva;
    cout << "Ingrese la cantidad de celulas vivas";
    cin >> cantidadCelulaViva;
    int planoCelulaViva, columnaCelulaViva, filaCelulaViva;
    int i = 0;
    while ( i < cantidadCelulaViva ){

        cout << "Ingrese la fila de la celula viva";
        verificarIngresoUsuario(cantidadFilaMaximaTablero, &filaCelulaViva);
        cout << "Ingrese la columna de la celula viva";
        verificarIngresoUsuario(cantidadColumnasMaximaTablero,&columnaCelulaViva);
        cout << "Ingrese la profundidad de la celula viva";
        verificarIngresoUsuario(cantidadProfundidadMaximaTablero,&planoCelulaViva);
        i++;
        Celda* celdaUsuario = obtenerCelda(filaCelulaViva,columnaCelulaViva, planoCelulaViva);
        if(not celdaUsuario->obtenerCelula()->estaViva()){
            celdaUsuario->obtenerCelula()->revivir();
            if(modoJuego == 3){
                celdaUsuario->obtenerCelula()->setearCargaGeneticaAleatoria();
            }
            else if(modoJuego==1){
                celdaUsuario->obtenerCelula()->setearCargaGeneticaUsuario();
            }
            i++;
        }
    }
}



int Tablero::obtenerFila() {
    return this->cantidadColumnasMaximaTablero;
}

int Tablero::obtenerColumna(){
    return this->cantidadColumnasMaximaTablero;
}

int Tablero::obtenerProfundidad() {
    return this->cantidadProfundidadMaximaTablero;
}
Tablero::Tablero(int cantidadFila, int cantidadColumnas, int cantidaProfundiad) {
    //creo todas las celdas
    if((cantidadFila < 2)||(cantidadColumnas < 2) ||(cantidaProfundiad < 2)){
        std::string excepcionDimensionesInvalidas = "dimensiones de tableros invalidas";

        cout << excepcionDimensionesInvalidas;

    }
    this->tablero = new Lista< Lista <Lista<Celda*> *> *>();
    this->cantidadFilaMaximaTablero = cantidadFila;
    this->cantidadColumnasMaximaTablero = cantidadColumnas;
    this->cantidadProfundidadMaximaTablero = cantidaProfundiad;

    // tablero->obtener(profundida4)->obtener(fila7)->obtener(columna9)
    for(int i = 0; i < this->cantidadProfundidadMaximaTablero; i++){
        Lista<Lista<Celda*>*>* columna = new Lista<Lista<Celda*>*>();
        for(int j = 0; j < this->cantidadFilaMaximaTablero ; j++){
            Lista<Celda*>* fila = new Lista< Celda* >();
            for(int k = 0; k < this->cantidadColumnasMaximaTablero; k++){
                    Celda* celda = new Celda(i, j, k);
                fila->agregar(celda);
            }
            columna->agregar(fila);
        }
        this->tablero->agregar(columna);

    }
    //Asina los vecinos
    //Recorro el tablero
    //Me define la fila
    for(int i = 0; i < obtenerFila(); i++ ){
        //me define la columna:
        for(int j = 0; j < obtenerColumna(); j++ ){
            for(int k = 0; k <  obtenerProfundidad(); k++){
                Celda* celda = obtenerCelda( i, j, k);
                for(int x = 1; x < 2 ; x++){
                    for ( int y = 1 ; y < 2 ; y++) {
                        for (int z = 0; z < 26; z++) {
                            Celda *celdaVecina = obtenerCelda(i + x, j + y, k + z);
                            if (!celdaVecina->tieneVecino(x, y, z)) {
                                celdaVecina->asignarVecino(-1 * x, -1 * y, -1 * z, celda);
                            }
                            celda->asignarVecino(x, y, z, celdaVecina);
                        }
                    }
                }
            }
        }
    }
}
void Tablero::imprimirTablero(){
    Celda* celda;
    this->tablero->iniciarCursor();
    for(int i = 0; i < this->cantidadFilaMaximaTablero; i++){
        this->tablero->avanzarCursor();
        Lista<Lista<Celda*> *>* columna= this->tablero->obtenerCursor();
        columna->iniciarCursor();
        for(int j =  0;j < this->cantidadProfundidadMaximaTablero; j++){
            columna->avanzarCursor();
            Lista<Celda*>* fila = columna->obtenerCursor();
            fila->iniciarCursor();
            for(int k = 0;k < this->cantidadColumnasMaximaTablero;k++){
                celda->obtenerCelula()->dibujar();
                fila->avanzarCursor();
            }
            cout << endl<< endl;
        }
    }
}
void Tablero::setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer, int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2){

    this->cantidadCelulasVecinasParaNacer = cantCelulasParaNacer;
    this->cantidadCelulasVecinasParaSeguirViva1 = cantCelulasParaSeguirViva1;
    this->cantidadCelulaVecinasParaSeguirViva2 = cantCelulasParaSeguirViva2;

}

void Tablero::actualizarTablero(){

    for(int i = 0; i < cantidadFilaMaximaTablero; i++){
        for(int j = 0; j < cantidadColumnasMaximaTablero ; j++){
            for(int k = 0; k < cantidadProfundidadMaximaTablero ; k++){
                obtenerCelda(k, i, j)->setyAplicarConportamiento();
                if(obtenerCelda(k,i,j)->tieneEstadoProcreadora()){
                    setCantCelulasVivasParaNacer();
                }
            }
        }
    }

}

void Tablero::setCantCelulasVivasParaNacer(){
    this->cantidadCelulasVecinasParaNacer = maximoDeLasDimensionesTablero()   ;
}
int Tablero::maximoDeLasDimensionesTablero(){
    int maximo1, maximo2 ;
    maximo1 = max(cantidadColumnasMaximaTablero, cantidadFilaMaximaTablero);

    maximo2 = max(maximo1,cantidadProfundidadMaximaTablero);
    return maximo2;
}


Tablero::~Tablero() {}

