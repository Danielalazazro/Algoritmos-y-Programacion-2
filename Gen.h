//
// Created by daniela on 01/10/22.
//

#ifndef TP2_GEN_H
#define TP2_GEN_H

static const unsigned int maximaCargaGenetica = 255;

class Gen{
private:
    unsigned int cargaGenetica;
public:
    /*
     * pre:
     * post:
     */
    Gen();
    /*
     * pre:
     * post:
     */
    Gen(unsigned int cargaGenetica);
    /*
     * pre:
     * post:destruye el tableroCelda creado con memoria dinamica.
     */
    virtual ~Gen();
    /*
     * pre:
     * post:
     */
    unsigned int getCargaGenetica();
    /*
     *pre:
     *post:
     */
    unsigned int getMaximoDeCargaGenetica();
    /*
     * pre:
     * post:
     */
    void setCargaGenetica(unsigned int cargaGenetica);
    /*
     * pre:
     * post:
     */
    bool verificarEnRango(unsigned int cargaGenetica );
    /*
     * pre: nesecita las posiciones de la celula.
     * post: devuelve las celulas celulas cargadas con sus cargas geneticas.
     */
    void insertarCargaUsuario();
    /*
     * pre:recibe las celulas sin carga genetica.
     * post: devulve las celulas con las cargas aleatorias.
     */
    void insertarCargaAleatoria();
    /*
     * pre:-
     * post:nos devuelve true o false  para virificar si esta vivo.
     */
    bool estaVivoGen();
    /*
     * pre: por lo menos una carga genetica de la celula tiene que ser mayor a 0.
     * post: convierte la carga genetica a 0.
     */
    void matarGen();
};
#endif //TP2_GEN_H