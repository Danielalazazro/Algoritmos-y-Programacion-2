//
// Created by daniela on 12/10/22.
//

#ifndef TP2_JUEGO_H
#define TP2_JUEGO_H

#include "Tablero.h"
static const unsigned int maximaCelulasVecinasAdy = 26;
static const unsigned int minimoCantCelulaVivas = 2;
class Juego {
private:

    Tablero* tablero;
    int ingresoUsuarioMenu;
    int modoJuego;



public:
    /*
     * pre:
     * post: Devulve la configuracion del juego.
     */
     void mostrarModoDeJuego();
    /*
     * pre:
     * post:
     */
    Juego();
    /*
     * pre:  Necesita  como parametros el alto , el ancho y la posicionZ del tableroCelda.
     * post: Devulve la dimensiones del tableroCelda del juego
     */
    void cargarDimensionesDelTableroUsuario();
    /*
     * pre:
     * post:Destruye el tableroCelda
     */
    ~Juego();
    /*
     * pre:
     * post:
     */
    int obtenerModoJuego();
    /*
     * pre:ingresa el modo de juego.
     * post:nos devuelve las dimensiones del tableroCelda con las dimensiones aleatorias.
     */
    void cargaDeDimensionesDeTableroAleatoria();

    /*
     * pre: juego no iniciado
     * post: inicia el juego c
     */
    void configuracionDeJuego();
    /*
     * pre:el juego debe estar iniciado
     * post: el juego de carga con las celulas en el tableroCelda y continua
     */
    void continuarJuego();
    /*
     * pre:
     * post:
     */
    void cargarCantCelulaVivaNacerySigaViva();
    /*
    * pre:  el usuario ingresa la cantidad de celulas vecinas para que una celula nazca , permanezca viva
    * post: se verifica qu los numeros ingresados sean correctos.
    */

    void verificarCargasCelulasVecinasNazcaCelula(int *cantidadCelulasVecinasParaNacer);

    /*
     * pre:  recibe la cantidad de celulas vecinas para nacer , ingresdas por el usuario.
     * post: verifica que lo ingresado por el usuario sea correcto.
     */
    void verificarCargasCelulasVecinasSigaViva(int limiteSigaViva, int *cantidadCelulasSigaViva );
    /*
     * pre: recibe un tableroCelda
     * post: asigna al tableroCelda algunos atributos.
     */
    void setearTablero(int cantidadCelulas);
    /*
     * pre:
     * post:
     */
    void obtenerTablero();

    /*
     * pre:
     * post:
     */
    void cargarCeldasUsuario();
    /*
     * pre:
     * post:nos devulve verdadero o falso si cumple con el rafngo de celulas vivas.
     */
    void  verificadorEnRango(int limiteinferior, int limiteSuperior, int *ingresoUsuario);
    /*
     * pre:
     * post:devuelve el maximo entre la dimensiones del tableroCelda.
     */
    int maxCantCelulasVivas();
    /*
     * pre:
     * post: Le solcitamos al usuario el ingrseo de  cantidad de celulas vivas, cantidad de celulas vecinas para que nazca otra y para que continue viva.
     */
    void cargarPosicionesyOtroParametros();
    /*
     * pre:-
     * post:una vez iniciado el juego se imprime el menu para que el usuario continue con el juego o no o terminar.
     */
    void mostrarMenuJuego();
    /*
     * pre:-
     * post:actualiza el tablero segun las reglas del juego
     */
    void ejecutarOtroTurno();

    void reiniciarJuego();

    void terminarJuego();


    void iniciarJuego();
};


#endif //TP2_JUEGO_H
