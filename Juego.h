//
// Created by daniela on 12/10/22.
//

#ifndef TP2_JUEGO_H
#define TP2_JUEGO_H

#include "Tablero.h"
static const unsigned int maximaCelulasVecinasAdy = 26;
static const unsigned int minimoCantCelulaVivas = 8;
class Juego {
private:

    Tablero* tablero;

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
     * pre:  Necesita  como parametros el alto , el ancho y la posicionZ del tablero.
     * post: Devulve la dimensiones del tablero del juego
     */
    void cargarDimensionesDelTableroUsuario();
    /*
     * pre:
     * post:Destruye el tablero
     */
    ~Juego();
    /*
     * pre:
     * post:
     */
    int obtenerModoJuego();
    /*
     * pre:ingresa el modo de juego.
     * post:nos devuelve las dimensiones del tablero con las dimensiones aleatorias.
     */
    void cargaDeDimensionesDeTableroAleatoria();

    /*
     * pre: juego no iniciado
     * post: inicia el juego c
     */
    void iniciarJuego();
    /*
     * pre:el juego debe estar iniciado
     * post: el juego de carga con las celulas en el tablero y continua
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
     * pre: recibe un tablero
     * post: asigna al tablero algunos atributos.
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
     * post:devuelve el maximo entre la dimensiones del tablero.
     */
    int maxCantCelulasVivas();

    void cargarPosicionesyOtroParametros();
};


#endif //TP2_JUEGO_H
