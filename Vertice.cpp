#include "Vertice.h"
#include <iostream>

// Constructor vacío
Vertice::Vertice() {
    x = 0;
    y = 0;
    z = 0;
    indiceVer = 0;
}
//Constructor con parametros
Vertice::Vertice(unsigned int x, unsigned int y, unsigned int z){
        this->x = x;
        this->y = y;
        this->z = z;   
    }
// Getters
unsigned int Vertice::obtenerX() {
    return x;
}

unsigned int Vertice::obtenerY() {
    return y;
}

unsigned int Vertice::obtenerZ() {
    return z;
}

unsigned int Vertice::obtenerIndiceVer() {
    return indiceVer;
}

// Setters
void Vertice::fijarX(unsigned int x) {
    this->x = x;
}

void Vertice::fijarY(unsigned int y) {
    this->y = y;
}

void Vertice::fijarZ(unsigned int z) {
    this->z = z;
}

void Vertice::fijarIndiceVer(unsigned int index) {
    this->indiceVer = index;
}

void Vertice::imprimirVertice() {
    std::cout << "Vertice [indice: " << indiceVer << ", x: " << x << ", y: " << y << ", z: " << z << "]" << std::endl;
}

// Función para calcular las esquinas de la caja envolvente
std::vector<Vertice> Vertice::calcularEsquinasCaja(unsigned int xmin, unsigned int xmax, unsigned int ymin, unsigned int ymax, unsigned int zmin, unsigned int zmax) {
    std::vector<Vertice> esquinas(8);  // Crear un vector para las 8 esquinas

    // Definir cada vértice de la caja envolvente
    esquinas[0].fijarX(xmin); esquinas[0].fijarY(ymin); esquinas[0].fijarZ(zmin);
    esquinas[1].fijarX(xmax); esquinas[1].fijarY(ymin); esquinas[1].fijarZ(zmin);
    esquinas[2].fijarX(xmax); esquinas[2].fijarY(ymax); esquinas[2].fijarZ(zmin);
    esquinas[3].fijarX(xmin); esquinas[3].fijarY(ymax); esquinas[3].fijarZ(zmin);
    esquinas[4].fijarX(xmin); esquinas[4].fijarY(ymin); esquinas[4].fijarZ(zmax);
    esquinas[5].fijarX(xmax); esquinas[5].fijarY(ymin); esquinas[5].fijarZ(zmax);
    esquinas[6].fijarX(xmax); esquinas[6].fijarY(ymax); esquinas[6].fijarZ(zmax);
    esquinas[7].fijarX(xmin); esquinas[7].fijarY(ymax); esquinas[7].fijarZ(zmax);

    return esquinas;
}
