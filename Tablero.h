//
// Created by daniela on 08/10/22.
//

#ifndef TP2_TABLERO_H
#define TP2_TABLERO_H
#include "Celda.h"
#include "Lista.h"

class Tablero {

private:
    int cantidadFilaMaximaTablero;

    int cantidadColumnasMaximaTablero;

    int cantidadProfundidadMaximaTablero;

    Lista<Lista<Lista<Celda*>*>*>* tablero;

    int cantidadCelulaVivasActuales;

    int cantidadCelulasVecinasParaNacer;

    int cantidadCelulasVecinasParaSeguirViva1;

    int cantidadCelulaVecinasParaSeguirViva2;




public:
    /*
     * pre:-
     * post:Inicializo los atributos de la clase tablero.
     */
    Tablero();
    /*
     * pre: Los argumentos deben ser > 0
     * post: Crea un tablero de dimensiones cantidadFilas x cantidad de columnas x cantidadProfundidadMaximaTablero = cantidad de celdas
     *      Te devulve una excepscion si no cumple con la precondicion.
     */

    Tablero(int cantidadFila,int cantidadClumnas, int cantidadProfundidad);

    /*
     * pre: filaIngresada , columnaIngresada , profundidadIngresada debe ser mayor a cero y debe estar dentro de las dimensione
     *      del tablero
     * post:Retorna la posicion en memoria de la celda ubicado en las coordenadas introducidas.
     */
    Celda* obtenerCelda(int fila, int columna, int profundidad);

    /*
     * pre:
     * post:
     */
    void setCelda(int cantidadFila, int cantidadColumna, int cantidadProfundida, char celula );

    /*
     * pre:
     * post: Destruye la memoria pedida para el tablero , junto con las celdas que lo componen
     *       y pone todo los cojuntos de punteros a null.
     */
    virtual ~Tablero();
    /*
     * pre:
     * post:
     */
    void imprimirTablero();
    /*
     * pre:
     * post
     */
    int obtenerFila();
    /*
     *
     *
     */
    int obtenerColumna();
    /*
     * pre:
     * post:
     */
    int obtenerProfundidad();

    /*
    * pre:-
    * post:Nos devuleve las posiciones aleatoria.
    */
    void  obtenerCelulaVivaEnPosicionAleatoria(int *filaAleatoria, int *columnaAleatoria, int *profundidadAleatoria);
    /*
     * pre:
     * post:Nos verifica el numero ingresado por el usuario este entre el rango de 1 a el maximo de la dimensiones del tablero
     */
    void verificarIngresoUsuario(int limiteSuperior, int* ingresoUsuario);
    /*
     * pre: el tablero esta inicialmente vacio
     * post: nos devulve las celulas cargadas en ele tablero
     */
    void cargarCelulaUsuario(int modoJuego);
    /*
     * pre: recibe el tablero sin  celulas.
     * post: devuelve el tablero con celulas
     */
    void cargarCelulasAleatoria();
    /*
     * pre: recibe las variables ingresadas por el usuario
     * post: verifica que las variables ingresadas sean las correctas.
     */
    bool verificarIngresoDevariables();
    /*
     * pre:
     * post:
     */
    void setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer , int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2);
    /*
     * pre:-
     * pos:-
     */
    void actualizarTablero();

    /*
     * pre:
     * pos:
     */
    void setCantCelulasVivasParaNacer();
    /*
     * pre:
     * post:nos devulve el maximo del las dimensiones del tablero.
     */
    int maximoDeLasDimensionesTablero();
    /*
     * pre:-
     * pos:cambia la cantidad de celulas vivas para nacer.
     */
    void setCantCelulasVivasParaNacer(int cantCelulasParaNacer, int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2);
};



#endif //TP2_TABLERO_H
