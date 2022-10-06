#include <iostream>

using namespace std;
#include "Lista.h"
int main() {
    Lista<float> notas;

    cout << "Ingrese las notas, separadas por espacios y 0 para terminar"
         << endl;

    float nota;
    do {

        cin >> nota;
        notas.agregar(nota);

    } while (nota > 0);

    float promedio = 0;

    notas.iniciarCursor();
    while (notas.avanzarCursor()) {

        promedio += notas.obtenerCursor();
    }

    cout << "Promedio: " << promedio / notas.contarElementos() << endl;

    return 0;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
