//
// Created by daniela on 05/10/22.
//

#ifndef EJERCICIO_1_LISTA_H
#define EJERCICIO_1_LISTA_H
#include "Nodo.h"
#include <string>
#include <iostream>

using namespace std;


template <class T> class Lista {

private:

    Nodo<T>* primero;
    Nodo<T>* ultimo;

    unsigned int tamanio;

    Nodo<T>* cursor;//cursor = auxiliar

public:

    /*
    * post: Lista vacía.
    */
    Lista();

    /*
    * post: Lista que tiene los mismos elementos que otraLista.
    *       La instancia resulta en una copia de otraLista.
    */
    Lista(Lista<T>& otraLista);

    /*
    * post: indica si la Lista tiene algún elemento.
    */
    bool estaVacia();

    /*
    * post: devuelve la cantidad de elementos que tiene la Lista.
    */
    unsigned int contarElementos();

    /*
    * pre: laposicion puede pertenecer al intevalo:: [1, contarElementos() + 1], o puede estar vacia
    * post: agrega el elemento al final de la Lista, en la posición:
    *       contarElementos() + 1, en una posicion indicada
    */
    void insertarElemento(T elemento);


        /*
         * post: agrega todos los elementos de otraLista
         *       a partir de la posición contarElementos() + 1.
         */
    void agregar(Lista<T> &otraLista);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posición indicada.
         */
    T obtenerSegunPosicionDato(unsigned int posicion);

        /*
         * pre : posicioó pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posición indicada por el
         *       elemento dado.
         */
    void asignar(T elemento, unsigned int posicion);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posición indicada.
         */
    void eliminarDatosLista( int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
    void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedó posicionado
         *       sobre un elemento o no (en caso de que la Lista esté vacía o
         *       no existan más elementos por recorrer.)
         */
    bool avanzarCursor();

        /*
         * pre : el cursor está posicionado sobre un elemento de la Lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * post: devuelve el elemento en la posición del cursor.
         *
         */
    T obtenerCursor();

        /*
         * post: libera los recursos asociados a la Lista.
         */
    ~Lista();
    /*
     * pre:
     * post:
     */
    int getTamanioLista();

    /*
     * pre:
     * post:devuelve el contenido de la lista.
     */
    void imprimirLista();

private:

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el nodo en la posición indicada.
         */
    Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
    this->ultimo = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otraLista) {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

        /* copia los elementos de otraLista */
    this->insertarElemento(otraLista);
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::insertarElemento(T elemento) {
    Nodo<T> *nuevoElemento = new Nodo<T>(elemento);

    if( (primero == NULL) && (ultimo == NULL) ){
        //primero apunta al nuevo elemento
        primero = nuevoElemento;
    }
    else{
        ultimo->cambiarSiguiente(nuevoElemento);
    }
    ultimo = nuevoElemento;
    tamanio++;

}



template<class T> void Lista<T>::agregar(Lista<T> &otraLista) {

    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor()) {
        this->insertarElemento(otraLista.obtenerCursor());
    }
}

template<class T> T Lista<T>::obtenerSegunPosicionDato(unsigned int posicion) {
    Nodo<T> * aux = primero;
    int cont = 0;
    if((posicion >= tamanio) ){
        return NULL;
    }
    while ((aux != NULL) && (cont != posicion)){
        aux = aux->obtenerSiguiente();
        cont++;
    }
    if(aux != NULL){
        return aux->obtenerDato();
    }
    return NULL;
}


template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}


template<class T> void Lista<T>::eliminarDatosLista( int posicion) {
    if((posicion >= tamanio) || (posicion < 0) || tamanio == 0 ){
        return;
    }
    if( posicion == 0 ){
        Nodo<T>*aux = primero->getSig();
        Nodo<T>* removido = primero;
        delete removido; // ver
        primero = aux;
    }
    else if(posicion == tamanio - 1){
        Nodo<T>* aux = primero;
        while (aux->getSig() != ultimo){
            aux = aux->getSig();
        }
        Nodo<T>* removido = ultimo;
        delete ultimo;
        ultimo  = aux;
        ultimo->setSig(NULL);
    }
    else {
        int cont = 0;
        Nodo<T>* aux= primero;
        while (cont != posicion -1){
            aux = aux->getSig();
            cont++;
        }
        Nodo<T>* aux2 = aux->getSig()->getSig();
        Nodo<T>*removido = aux->getSig();
        delete removido;
        aux->setSig(aux2);
    }
    tamanio--;

}

template<class T> void Lista<T>::iniciarCursor() {

     this->cursor = NULL;


}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    }
    else {

            this->cursor = this->cursor->obtenerSiguiente();
    }


    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}


template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {
    int i = 0;
    //Lo meto en una varible auxiiar para que no cambie(back up)
    int tamanioOrigin = tamanio;
    while ( i < tamanioOrigin){
        eliminarDatosLista(0);
        i++;
    }

}
template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

        Nodo<T>* actual = this->primero;
        for (unsigned int i = 1; i < posicion; i++) {

            actual = actual->obtenerSiguiente();
        }

        return actual;
}

template<class T> int Lista<T>::getTamanioLista(){
    return tamanio;
}
template <class T> void Lista<T>::imprimirLista(){
    Nodo<T>* aux = primero;
    while ( aux != NULL){
        std::cout <<  aux->getDato()<<std::endl;
        aux = aux->getSig();
    }

}

#endif //EJERCICIO_1_LISTA_H
