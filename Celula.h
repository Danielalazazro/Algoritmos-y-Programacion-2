//
// Created by daniela on 29/09/22.
//

#ifndef TP2_CELULA_H
#define TP2_CELULA_H
#include "Gen.h"


class Celula {
private:
    int estado;

    Gen arrayGen[3];

    char celula;

public:
    int cuantificarGenes();
    int obtenerCargaGeneticaPredominante();
    /*
     * pre:
     * post: convierte la cargagenetica en 0.
     */
    void matarUnGen();
    /*
     * pre:
     * post:
     */
    Celula();

    Celula(int  gen1,int  gen2, int  gen3);
    /*
     * pre:
     * post:
     */
    ~Celula();
    /*
     * pre:
     * post:
     */
    void dibujar();
    /*
     * pre: -
     * post: devulve 0 o 1 si esta viva o muerta.
     */
    bool estaViva();
    /*
     * pre: previmente el estado de la celula es 0 , lo cual indica que esta muerta.
     * post: cambia el estado de la celula a 1.
     */
    void revivir();
    /*
     * pre: recibe la celula sin carga genetica
     * post: cambia el valor de la carga genetica.
     */
    void setearCargaGeneticaAleatoria();
    /*
     * pre: recibe el tablero con celulas muertas
     * post: devulve el tablero con las carga geneticas ingresadas por el usuario.
     */
    void setearCargaGeneticaUsuario();

    void matarCelula();
};


#endif //TP2_CELULA_H
