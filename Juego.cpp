#include "Juego.h"
#include <iostream>
#include "Tablero.h"
#include "cmath"

Juego::Juego(){}
int Juego::obtenerModoJuego(){
    return this->modoJuego;

}

void Juego::mostrarModoDeJuego(){
    int modoJuego  = 0;
    cout << "Bienvenido al juego de la vida";
    cout << "Modo de configuracion de Juego\n";
    cout << "1. El jugador  ingresa las dimensiones del tableroCelda, las posiciones de la celula viva, la cantidad de celula vivas, las cargas genetica.\n"
            "2. El todo es aleatorio \n"
            "3. El programador ingresa las posiciones de la celula viva , la carga genetica de cada celula\n  "
            "Ingrese el modo de juego : ";
    cin >> modoJuego;
    while( not (modoJuego <= 3 && modoJuego > 0)){
        std::cout<<"Error ingrese un modo de juego correcto: ";
        cin >>modoJuego;
    }
    this->modoJuego = modoJuego;

}


void Juego::iniciarJuego(){
    mostrarModoDeJuego();
    if(modoJuego == 1) {
        cargarDimensionesDelTableroUsuario();
        cargarCantCelulaVivaNacerySigaViva();
    }
    else if(modoJuego == 2){
        cargaDeDimensionesDeTableroAleatoria();
        tablero->cargarParametrosRandom();
        tablero->cargarCelulasVivasyCargaRandom();
    }
    else if(modoJuego == 3){
        cargarDimensionesDelTableroUsuario();
        cargarPosicionesyOtroParametros();
    }
    continuarJuego();
}
//Llamo a las celulas ingresada por el usuario segun el modo de juego elegido.
//
void Juego::continuarJuego(){
    char continuar = 's';
    while(continuar == 's'){
        tablero->actualizarTablero();
        cout << "Desea continuar el juego (s/n) ?:"<<endl;
        cin >> continuar;
    }

}


void Juego::cargarDimensionesDelTableroUsuario(){
    int fila = 0;
    int columna = 0;
    int profundidad = 0;

    cout << "Ingrese la fila del tableroCelda: ";
    verificadorEnRango(3, 100, &fila);
    cout << "Ingrese la columna del tableroCelda: ";
    verificadorEnRango(3, 100, &columna);
    cout << "Ingrese la profundidad del tableroCelda: ";
    verificadorEnRango(3, 100 ,&profundidad);

    tablero = new Tablero(fila, columna, profundidad);
    //delete tableroCelda;

}

void Juego::cargaDeDimensionesDeTableroAleatoria(){
    int anchoAleatorio = 3 + rand() %  20;
    int altoAleatorio = 3 + rand() % 20;
    int profundidadAleatorio = 3 + rand() % 20;
    tablero = new Tablero(anchoAleatorio, altoAleatorio, profundidadAleatorio);
    tablero->cargarCelulasVivasyCargaRandom();


}

void Juego::verificadorEnRango(int limiteinferior, int limiteSuperior, int *ingresoUsuario){
    *ingresoUsuario = -1;
    std::cout << "Debe estar entre limite inferior  "<< limiteinferior << " y limite superior  " << limiteSuperior << ": "<<std::endl;
    while((*ingresoUsuario > limiteSuperior ) || (*ingresoUsuario < limiteinferior)){
        std::cin >> *ingresoUsuario;
        if((*ingresoUsuario > limiteSuperior) || (*ingresoUsuario < limiteinferior )) {
            std::cout << "Error rango invalido" << std::endl;
            std::cout << "Debe estar entre limite inferior  "<< limiteinferior << " y limite superior  " << limiteSuperior << ": "<<std::endl;
        }
    }
}
int Juego::maxCantCelulasVivas(){
    int maximoGeneral = tablero->obtenerFila()* tablero->obtenerColumna() * tablero->obtenerProfundidad();
    return maximoGeneral;

}


void Juego::cargarCantCelulaVivaNacerySigaViva(){
    int cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1, cantidadCelulasSigaViva2, cantidadCelulasVivas;
    cout << "Ingrese la cantidad de celulas vivas (" <<minimoCantCelulaVivas << " a 26):"<<endl;

    verificadorEnRango(minimoCantCelulaVivas, maxCantCelulasVivas(),&cantidadCelulasVivas);
    tablero->setCantCelulasVivasActuale(cantidadCelulasVivas);

    //Tengo que hacer con un while y contador ingreso de posiciones de celulas vivas y la tableroCelda->celula->cargarCargaGenticaUsuario.
    cout << "Ingrese la cantidad de celulas vecinas vivas para que una celula nueva nazca: " <<endl;

    verificadorEnRango(1, tablero->minEntreFilaColumnaProfundidad(), &cantCelulasVecinasParaNacer);

    cout << "Ingrese la cantidad de celulas vecinas  para que una celula siga viva: "<<endl;

    verificadorEnRango(1, tablero->minEntreFilaColumnaProfundidad(), &cantidadCelulasSigaViva1);
    cout << "Ingrese la otra cantidad de celulas vecinas  para que una celula siga viva: "<<endl;

    verificadorEnRango(cantidadCelulasSigaViva1, cantidadCelulasSigaViva1 + 2, &cantidadCelulasSigaViva2);
    tablero->setearCantidadCelulasVivasParaNacer(cantCelulasVecinasParaNacer,cantidadCelulasSigaViva1,cantidadCelulasSigaViva2,1);
}


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


Juego::~Juego(){
    delete tablero;
}
//
void Juego::cargarPosicionesyOtroParametros() {
    int cantCelulasVecinasParaNacer, cantidadCelulasSigaViva1, cantidadCelulasSigaViva2, cantidadCelulasVivas;
    cout << "Ingrese la cantidad de celulas vivas (8 a 26):" ;

    verificadorEnRango(minimoCantCelulaVivas, maxCantCelulasVivas(),&cantidadCelulasVivas);
    tablero->setCantCelulasVivasActuale(cantidadCelulasVivas);
    //Tengo que hacer con un while y contador ingreso de posiciones de celulas vivas y la tableroCelda->celula->cargarCargaGenticaUsuario.

    cantCelulasVecinasParaNacer = 1 + rand() % tablero->minEntreFilaColumnaProfundidad();
    cantidadCelulasSigaViva1 = 1 + rand() % tablero->minEntreFilaColumnaProfundidad();
    cantidadCelulasSigaViva2 = cantidadCelulasSigaViva1 + 2;


    tablero->setearCantidadCelulasVivasParaNacer(cantCelulasVecinasParaNacer,cantidadCelulasSigaViva1,cantidadCelulasSigaViva2, 3);



}