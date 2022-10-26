#include "Juego.h"
#include <iostream>
#include "Tablero.h"

Juego::Juego(){}
int Juego::obtenerModoJuego(){
    return this->modoJuego;

}

void Juego::mostrarModoDeJuego(){
    int modoJuego  = 0;
    cout << "Bienvenido al juego de la vida";
    cout << "Modo de configuracion de Juego\n";
    cout << "1. El jugador  ingresa las dimensiones del tablero, las posiciones de la celula viva, la cantidad de celula vivas, las cargas genetica.\n"
            "2. El jugador  ingresa las dimensiones del tablero  y las posiciones de las celulas vivas \n"
            "3. El programador ingresa las dimensiones del tablero, las posiciones de la celula viva , la carga genetica de cada celula\n  "
            "Ingrese el modo de juego : ";
    cin >> modoJuego;
    while( not (modoJuego <= 3 && modoJuego > 0)){
        std::cout<<"Error ingrese un modo de juego correcto";
        cin >>modoJuego;
    }
    this->modoJuego = modoJuego;

}
void Juego::creacionTablero(){
    if ((modoJuego == 1) || (modoJuego == 3))
        cargarDimensionesDelTableroUsuario();


    else if (modoJuego == 2) {
        cargaDeDimensionesDeTableroAleatoria();
    }

}

void Juego::iniciarJuego(){
    mostrarModoDeJuego();
    creacionTablero();
}

void Juego::cargarDimensionesDelTableroUsuario(){
    int ancho = 0;
    int alto = 0;
    int profundidad = 0;
    bool dimensionesCorrectas = false;
    while(  not (dimensionesCorrectas) ) {

        cout << "Ingrese el  ancho del tablero:  ";
        cin >> ancho;
        cout << "Ingrese el alto del tablero: ";
        cin >> alto;
        cout << "Ingrese la profundidad del tablero: ";
        cin >> profundidad;
        if((ancho > 0) && (alto > 0) &&( profundidad >0)){
            dimensionesCorrectas = true;
        }
        else{
            cout << "Ingrese deimensiones positiva y enteras";
        }
    }
    tablero = new Tablero(ancho,alto,profundidad);

}
void Juego::cargaDeDimensionesDeTableroAleatoria(){
    int anchoAleatorio = rand() %  20;
    int altoAleatorio = rand() % 20;
    int profundidadAleatorio = rand() % 20;
    tablero = new Tablero(anchoAleatorio, altoAleatorio, profundidadAleatorio);
    tablero->cargarCelulasAleatoria();

}

void Juego::cargarCantCelulaVivaNacerySigaViva(){
    int cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1, cantidadCelulasSigaViva2;

    cout << "Ingrese la cantidad de celulas vicinas para que una celula nueva nazca: ";
    cin >> cantCelulasVecinasParaNacer;
    verificarCargasCelulasVecinasNazcaCelula(&cantCelulasVecinasParaNacer);

    cout << "Ingrese la cantidad de celulas vecinas  para que una celula siga viva: ";
    cin >> cantidadCelulasSigaViva1;
    verificarCargasCelulasVecinasSigaViva(cantCelulasVecinasParaNacer, &cantidadCelulasSigaViva1);
    cout << "Ingrese la otra cantidad de celulas vecinas  para que una celula siga viva: ";
    cin >> cantidadCelulasSigaViva2;
    verificarCargasCelulasVecinasSigaViva(cantidadCelulasSigaViva1,&cantidadCelulasSigaViva2);
    tablero->setearCantidadCelulasVivasParaNacer(cantCelulasVecinasParaNacer,cantidadCelulasSigaViva1,cantidadCelulasSigaViva2);
}
void Juego::continuarJuego(){}

void Juego::verificarCargasCelulasVecinasNazcaCelula(int *cantidadCelulasVecinasParaNacer){
    while((*cantidadCelulasVecinasParaNacer < 0) && (*cantidadCelulasVecinasParaNacer > maximaCelulasVecinasAdy)){
        cin >> *cantidadCelulasVecinasParaNacer;
        if((*cantidadCelulasVecinasParaNacer < 0) && (*cantidadCelulasVecinasParaNacer > maximaCelulasVecinasAdy)){
            cout << "ERROR, el valor ingresado no es valido ; ingrese una cantidad entre (1-26): \n";
        }
    }
}
void Juego::verificarCargasCelulasVecinasSigaViva(int limiteSigaViva, int *cantidadCelulasSigaViva ){
    while((*cantidadCelulasSigaViva >limiteSigaViva) && (*cantidadCelulasSigaViva < 0)){
        cin >> *cantidadCelulasSigaViva;
        if((*cantidadCelulasSigaViva < 0) && (*cantidadCelulasSigaViva > limiteSigaViva)){
            cout << "ERROR , el valor ingresado no es valido ;ingrese una cantidad entre ( 1-26):";
        }
    }

}

void Juego::setearTablero(int cantidadCelulas){
    Tablero*  tablero = tablero;
}
void Juego::obtenerTablero(){
    this->tablero;
}

Juego::~Juego(){}
