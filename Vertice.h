#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
#include <ostream>
#include <iostream>

class Vertice {
private:
    int indiceVer;
    float x;
    float y;
    float z;

public:
    // Constructor
    Vertice();
    Vertice(float x, float y, float z);

    // Getters
     float obtenerX();
     float obtenerY();
     float obtenerZ();
     int obtenerIndiceVer();
    
    // Setters
    void fijarX( float x);
    void fijarY( float y);
    void fijarZ( float z);
    void fijarIndiceVer( int index);

    // Método para imprimir el vértice
    void imprimirVertice();

    /*Sobrecarga para operador de igualdad*/
    friend bool operator==(const Vertice& v1, const Vertice& v2);

    /*Sobrecarga para operador de salida*/
    friend std::ostream& operator<<(std::ostream& os, const Vertice& vertice);

    // Método para calcular las esquinas de la caja envolvente
    std::vector<Vertice> calcularEsquinasCaja( int xmin,  int xmax,  int ymin,  int ymax,  int zmin,  int zmax);
};

#endif // VERTICE_H
