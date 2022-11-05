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
     * post: Destruye la memoria pedida para el tableroCelda , junto con las celdas que lo componen
     *       y pone todo los cojuntos de punteros a null.
     */
    virtual ~Tablero();
    /*
     * pre:
     * post:nos devulve el tablero impreso en la terminal.
     */
    void imprimirTableroyResumen();
    /*
     * pre:-
     * post:obtenemos la fila .
     */
    int obtenerFila();
    /*
     *pre:-
     *pos:nos devulve el valor de la columna.
     */
    int obtenerColumna();
    /*
     * pre:-
     * post:nos devulve el valor de la profundidad.
     */
    int obtenerProfundidad();

    /*
    * pre:-
    * post:Nos devuleve las posiciones aleatoria.
    */
    void  asignarValoresAleatoria(int *filaAleatoria, int *columnaAleatoria, int *profundidadAleatoria);
    /*
     * pre:-
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
     * pre:-
     * post:cambio los valores de los atributos
     */
    void setearCantidadCelulasVivasParaNacer(int cantCelulasParaNacer , int cantCelulasParaSeguirViva1, int cantCelulasParaSeguirViva2, int modoJuego);
    /*
     * pre:-
     * pos:actualizo el tablero cona las reglas del juego.
     */
    void actualizarTablero();

    /*
     * pre:
     * pos:cambio la cantidad de celulas vivas para nacer
     */
    void setCantCelulasVivasParaNacer();
    /*
     * pre:
     * post:nos devulve el maximo del las dimensiones del tableroCelda.
     */
    int minimoDeLasDimensionesTablero();

    /*
     * pre: el usuario debe ingresar las dimensiones del tableroCelda
     * post:devulve el analisis de con las celulas adyacentes a la tableroCelda a analizar.
     */
    void asignarCeldasAdayacentes(Celda*unaCelda);
    /*
     * pre:-
     * pos:devulve una catidad alatoria para las variables.
     */
    void cargarParametrosRandom();
    /*
     * pre:-
     * post:buscamos el minimo entre filas y columnas.
     */
    int minEntreFilaColumnaProfundidad();
    /*
     * pre: -
     * pos:cambiamos la cantidad de filas actuales.
     */
    void setCantCelulasVivasActuale(int i);
    /*
     * pre:-
     * pos: devolvemos o aplicamos las reglas del juego.
     */
    void aplicarLogicaDelJuego();
    /*
     * pre: se debe ingresar la cantidad de celulas vivas.
     * pos:devulve verdadero si la cantidad de celulas se encuentras entre esas variables.
     */

    bool puedeMantenerseConVida(int vivas);
    /*
     * pre:-
     * pos:recorremos el tablero cona las celdas adyacentes y lo guardamos en una lista.
     */

    Lista<Celula*>* obtenerCelulasVivasActuales(Lista<Celda *> *celdaAdyacentes ,Lista<Celula*>* listaCelulas);
    /*
     * pre:el tablero tiene que estar creado.
     * post: recorremos el tablero y le asiganamos un estado.
     */
    void actualizarEstadoDeCeldas();
    /*
     * pre:-
     * pos: invrementamos la cantidad de turnos.
     */
    void aumentarTurno();
    /*
     * pre:-
     * pos:imprime el tablero .
     */
    void imprimirTablero();
    /*
     * pre: tenemos 2 listas con caracteres del tablero .
     * pos: retorna verdadero  si los caracteres del 1ª tablero guardados en una lista son iguales .
     */

    bool listasCaracteresSonIguales(Lista<char> *nuevaListaCarct, Lista<char> *caracteresCuboAnt);
    /*
     * pre:-
     * pos:recorremos el tablero e insertamos en la lista la celda con sus caracteristicas.
     */
    void insertarCaracteresEnLista(Lista<char> *listaInsertar);
    /*
     * pre: tenemos dos lista con los caracteres del tablero.
     * pos:evaluamos si el juego se congelo e imprimimos un mensaje .
     */
    void reporteSiseCongeloTablero();

};



#endif //TP2_TABLERO_H
