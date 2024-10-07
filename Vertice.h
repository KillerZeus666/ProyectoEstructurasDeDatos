#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

class Vertice {
private:
    unsigned int indiceVer;
    unsigned int x;
    unsigned int y;
    unsigned int z;

public:
    // Constructor
    Vertice(unsigned int x = 0, unsigned int y = 0, unsigned int z = 0, unsigned int indice = 0)
        : x(x), y(y), z(z), indiceVer(indice) {}

        // Vertice();

    // Getters
    unsigned int obtenerX();
    unsigned int obtenerY();
    unsigned int obtenerZ();
    unsigned int obtenerIndiceVer();

    // Setters
    void fijarX(unsigned int x);
    void fijarY(unsigned int y);
    void fijarZ(unsigned int z);
    void fijarIndiceVer(unsigned int index);

    void imprimirVertice();
};

#endif // VERTICE_H
