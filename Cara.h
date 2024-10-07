#ifndef CARA_H
#define CARA_H

#include "Arista.h"
#include <list>
#include "Vertice.h" // Asegúrate de incluir esta cabecera

class Cara {
private:
    unsigned int indiceCar;
    unsigned int cantidadVerticesCar;
    std::list<Arista> listaAristas;

public:
    // Constructor
    Cara();

    // Getters
    unsigned int obtenerIndiceCar();
    unsigned int obtenerCantidadVerticesCar();
    std::list<Arista> obtenerListaAristas();
    std::list<Vertice> obtenerVertices(); // Nuevo método para obtener vértices

    // Setters
    void fijarIndiceCar(unsigned int indice);
    void fijarCantidadVerticesCar(unsigned int cantVertices);
    void fijarListaAristas(std::list<Arista> lista);

    // Métodos
    void imprimirCara();
    void agregarArista(Arista edge);
    void eliminarArista(int edgeIndex);
    unsigned int contarAristas(std::list<Arista> lista);
};

#endif // CARA_H
