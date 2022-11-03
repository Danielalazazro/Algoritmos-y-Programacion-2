//
// Created by daniela on 08/10/22.
//

#ifndef TP2_TABLERO_H
#define TP2_TABLERO_H
#include "Celda.h"
#include "Lista.h"

class Tablero {

private:
    int cantidadMaximaPosX;

    int cantidadMaximaPosY;

    int cantidadMaximaPosZ;

    Lista<Lista<Lista<Celda*>*>*>* tableroCelda;

    int cantidadCelulaVivasActuales;

    int cantidadCelulasVecinasParaNacer;

    int cantidadCelulasVecinasParaSeguirViva1;

    int cantidadCelulaVecinasParaSeguirViva2;

    int cantidadCelulasMuertasTotales;

    int cantidadCelulasNacidasTotales;

    int cantCelNacidasTurno;

    int cantCelMuertasTurno;

    int cantTurno;

    Lista<char>* listaCaracteresCubo;





public:
    /*
     * pre:-
     * post:Inicializo los atributos de la clase tableroCelda.
     */
    Tablero();
    /*
     * pre: Los argumentos deben ser > 0
     * post: Crea un tableroCelda de dimensiones cantidadFilas x cantidad de columnas x cantidadMaximaPosZ = cantidad de celdas
     *      Te devulve una excepscion si no cumple con la precondicion.
     */

    Tablero(int cantidadFila,int cantidadClumnas, int cantidadProfundidad);

    /*
     * pre: filaIngresada , columnaIngresada , profundidadIngresada debe ser mayor a cero y debe estar dentro de las dimensione
     *      del tableroCelda
     * post:Retorna la posicion en memoria de la tableroCelda ubicado en las coordenadas introducidas.
     */
    Celda* obtenerCelda(int posicionZ, int posicionX, int poscionY);

    /*
     * pre:
     * post:
     */
    void setCelda(int cantidadFila, int cantidadColumna, int cantidadProfundida, char celula );

    /*
     * pre:
     * post: Destruye la memoria pedida para el tableroCelda , junto con las celdas que lo componen
     *       y pone todo los cojuntos de punteros a null.
     */
    virtual ~Tablero();
    /*
     * pre:
     * post:
     */
    void imprimirTableroyResumen();
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
    void  asignarValoresAleatoria(int *filaAleatoria, int *columnaAleatoria, int *profundidadAleatoria);
    /*
     * pre:
     * post:Nos verifica el numero ingresado por el usuario este entre el rango de 1 a el maximo de la dimensiones del tableroCelda
     */
    void verificarIngresoUsuario(int limiteSuperior, int* ingresoUsuario);
    /*
     * pre: el tableroCelda esta inicialmente vacio
     * post: nos devulve las celulas cargadas en ele tableroCelda
     */
    void cargarCelulaUsuario(int modoJuego);
    /*
     * pre: recibe el tableroCelda sin  celulas.
     * post: devuelve el tableroCelda con celulas
     */
    void cargarCelulasVivasyCargaRandom();
    /*
     * pre: recibe las variables ingresadas por el usuario
     * post: verifica que las variables ingresadas sean las correctas.
     */
    bool verificarIngresoDevariables();
    /*
     * pre:
     * post:
     */
    void setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer , int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2, int modoJuego);
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
     * post:nos devulve el maximo del las dimensiones del tableroCelda.
     */
    int minimoDeLasDimensionesTablero();
    /*
     * pre:-
     * pos:cambia la cantidad de celulas vivas para nacer.
     */
    void setCantCelulasVivasParaNacer(int cantCelulasParaNacer, int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2);
    /*
     * pre: el usuario debe ingresar las dimensiones del tableroCelda
     * post:devulve el analisis de con las celulas adyacentes a la tableroCelda a analizar.
     */
    void asignarCeldasAdayacentes(Celda*unaCelda);

    void cargarParametrosRandom();
    /*
     * pre:
     * post:
     */
    int minEntreFilaColumnaProfundidad();


    void asignarPosicionesUsuario();

    void setCantCelulasVivasActuale(int i);

    void aplicarLogicaDelJuego();


    bool puedeMantenerseConVida(int vivas);

    Lista<Celula*>* obtenerCelulasVivasActuales(Lista<Celda *> *pLista ,Lista<Celula*>* listaCelulas);
    /*
     * pre:
     * post:
     */
    void actualizarEstadoDeCeldas();

    void aumentarTurno();

    void imprimirTablero();

    bool listasCaracteresSonIguales(Lista<char> *nuevaListaCarct, Lista<char> *caracteresCuboAnt);

    void insertarCaracteresEnLista(Lista<char> *listaInsertar);

    void reporteSiseCongeloTablero();

};



#endif //TP2_TABLERO_H
