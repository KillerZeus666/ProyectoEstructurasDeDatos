#ifndef RESULTADOVERTICE_H
#define RESULTADOVERTICE_H

#include "Vertice.h"  // Incluye solo el encabezado, no el .cpp

class ResultadoVertice {
public:
    Vertice vertice; // El vértice más cercano
    double distancia; // Distancia asociada

    // Constructor
    ResultadoVertice(Vertice v, double d) : vertice(v), distancia(d) {}

    // Métodos para acceder a las coordenadas
    double obtenerX() { return vertice.obtenerX(); }
    double obtenerY() { return vertice.obtenerY(); }
    double obtenerZ() { return vertice.obtenerZ(); }
};

#endif // RESULTADOVERTICE_H
