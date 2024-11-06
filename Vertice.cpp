#include "Vertice.h"
#include <iostream>
#include <ostream>

// Constructor vacío
Vertice::Vertice() {
    x = 0;
    y = 0;
    z = 0;
    indiceVer = 0;
}
//Constructor con parametros
Vertice::Vertice(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;   
    }
// Getters
 float Vertice::obtenerX() {
    return x;
}

 float Vertice::obtenerY() {
    return y;
}

 float Vertice::obtenerZ() {
    return z;
}

 int Vertice::obtenerIndiceVer() {
    return indiceVer;
}

// Setters
void Vertice::fijarX( float x) {
    this->x = x;
}

void Vertice::fijarY( float y) {
    this->y = y;
}

void Vertice::fijarZ( float z) {
    this->z = z;
}

void Vertice::fijarIndiceVer(int index) {
    this->indiceVer = index;
}

void Vertice::imprimirVertice() {
    std::cout << "Vertice [indice: " << indiceVer << ", x: " << x << ", y: " << y << ", z: " << z << "]" << std::endl;
}

// Función para calcular las esquinas de la caja envolvente
std::vector<Vertice> Vertice::calcularEsquinasCaja( int xmin,  int xmax,  int ymin,  int ymax, int zmin, int zmax) {
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

bool operator==(const Vertice& v1, const Vertice& v2) {
    return  (v1.x == v2.x) &&(v1.y == v2.y) && (v1.z == v2.z);
}

std::ostream& operator<<(std::ostream& os, const Vertice& vertice) {
    os << "Indice: " << vertice.indiceVer << ", Coordenadas: (" 
       << vertice.x << ", " << vertice.y << ", " << vertice.z << ")";
    return os;
}