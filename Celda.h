//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULAS_H
#define TP2_CELULAS_H
#include "Celula.h"


class Celda {
private:
    //Para 2 dimenciones // y para 3 dimensiones es Celda****vecinos
    Celda****vecinosAdyacentes;
    int estadoDeCelda; //estado que epuede variar
    Celula* celula;
public:
    /*
     * pre:
     * post:
     */
    Celda();
    /*
     * pre:
     * post:
     */
    Celda(int profundidad, int fila, int columna);
    /*
     * pre:
     * post:
     */
    void setyAplicarConportamiento();
    /*
     * pre:
     * post:
     */
    void aplicarEnvenenamiento();
    /*
     * pre:
     * post:
     */
    void aplicarContaminacion();
    /*
     * pre:
     * post:
     */
    void aplicarPortal();
    /*
     *pre:
     *post:
     */
    void aplicarProcreadora();
    /*
     *pre:
     *post:
     */
    void  aplicarRadioactividad();
    /*
     * pre:-
     * post: cambia el estado de la celda
     */
    void setCelula(Celula* celulaIngresada);
    /*
     * pre:Las coordenadas de vecinos van de  -1 (izquierda) a 1 (horizontal) y de -1 (arriba) a 1 (abajo) en vertical
     * post:
     */
    void asignarVecino(int ancho, int alto, int profundidad, Celda* celVecino);
    /*
     * pre: Las coordenadas de vecinos van de  -1 (izquierda) a 1 (horizontal) y de -1 (arriba) a 1 (abajo) en vertical
     * post: devulve el vecino o vacio.
     */
    Celda* obtenerVecino();
    /*
     * pre: Las coordenadas de vecinos van de  -1 (izquierda) a 1 (horizontal) y de -1 (arriba) a 1 (abajo) en vertical
     * post: devulve verdadero o falso en caso de que haya una celula.
     */
    bool tieneVecino(int ancho, int alto, int profundidad);

    /*
     * pre:
     * post:
     */
    Celula* obtenerCelula();

    /*
     * pre:
     * post:destuye la celda
     */
    ~Celda();


    bool tieneEstadoProcreadora();
};


//estado qu epuede variar
/*
int contaminada;//estado = 1:celda contaminada
int envenenada;//estado = 2 :celda envenenada
int procreadora;//estade = 3:celda preocreadora
int portal;//estado = 4:celda portal
//estado = 5 :celda radioactiva
int estadoDeCelda;
*/


#endif //TP2_CELULAS_H
