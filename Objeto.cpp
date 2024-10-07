#include "Objeto.h"
#include <iostream>
#include <limits> // Para std::numeric_limits

// Constructor vacío
Objeto::Objeto() : cantidadVerticesObj(0) {}

// Getters
std::string Objeto::obtenerNombreObjeto() {
    return this->nombreObjeto;
}

std::list<Cara> Objeto::obtenerCaras() {
    return this->listaCaras;
}

int Objeto::obtenerCantidadVerticesObj() {
    return this->cantidadVerticesObj;
}

// Método para obtener los vértices de todas las caras
std::list<Vertice> Objeto::obtenerVertices() {
    std::list<Vertice> vertices;
    std::set<unsigned int> indices; // Para evitar duplicados

    for (const Cara& cara : listaCaras) {
        std::list<Vertice> verts = cara.obtenerVertices();
        for (const Vertice& vertice : verts) {
            if (indices.find(vertice.obtenerIndiceVer()) == indices.end()) { // Evitar duplicados
                vertices.push_back(vertice);
                indices.insert(vertice.obtenerIndiceVer());
            }
        }
    }
    return vertices;
}

// Métodos para obtener los puntos mínimo y máximo
Vertice Objeto::obtenerPmin() {
    unsigned int minX = std::numeric_limits<unsigned int>::max();
    unsigned int minY = std::numeric_limits<unsigned int>::max();
    unsigned int minZ = std::numeric_limits<unsigned int>::max();
    unsigned int indice = 0; // Para almacenar el índice del vértice mínimo

    for (const Cara& cara : listaCaras) {
        for (const Vertice& vertice : cara.obtenerVertices()) {
            if (vertice.obtenerX() < minX) {
                minX = vertice.obtenerX();
                indice = vertice.obtenerIndiceVer();
            }
            if (vertice.obtenerY() < minY) {
                minY = vertice.obtenerY();
            }
            if (vertice.obtenerZ() < minZ) {
                minZ = vertice.obtenerZ();
            }
        }
    }

    Vertice pMin(minX, minY, minZ, indice);
    return pMin;
}

Vertice Objeto::obtenerPmax() {
    unsigned int maxX = std::numeric_limits<unsigned int>::min();
    unsigned int maxY = std::numeric_limits<unsigned int>::min();
    unsigned int maxZ = std::numeric_limits<unsigned int>::min();
    unsigned int indice = 0; // Para almacenar el índice del vértice máximo

    for (const Cara& cara : listaCaras) {
        for (const Vertice& vertice : cara.obtenerVertices()) {
            if (vertice.obtenerX() > maxX) {
                maxX = vertice.obtenerX();
                indice = vertice.obtenerIndiceVer();
            }
            if (vertice.obtenerY() > maxY) {
                maxY = vertice.obtenerY();
            }
            if (vertice.obtenerZ() > maxZ) {
                maxZ = vertice.obtenerZ();
            }
        }
    }

    Vertice pMax(maxX, maxY, maxZ, indice);
    return pMax;
}

// Setters
void Objeto::fijarNombreObjeto(std::string objectName) {
    this->nombreObjeto = objectName;
}

void Objeto::fijarListaCaras(std::list<Cara> listaCaras) {
    this->listaCaras = listaCaras;
}

void Objeto::fijarCantidadVerticesObj(int cantVertices) {
    this->cantidadVerticesObj = cantVertices;
}

// Métodos para agregar y eliminar caras
void Objeto::agregarCara(Cara face) {
    listaCaras.push_back(face);
}

void Objeto::eliminarCara(int faceIndex) {
    std::list<Cara>::iterator itFace;
    for (itFace = listaCaras.begin(); itFace != listaCaras.end(); itFace++) {
        if (itFace->obtenerIndiceCar() == faceIndex) { // Asumiendo que hay un método para obtener el índice de la cara
            listaCaras.erase(itFace);
            break;
        }
    }
}

// Método para contar el número de caras
unsigned int Objeto::contarCaras() {
    return listaCaras.size();
}

// Método para imprimir el objeto
void Objeto::imprimirObjeto() {
    std::cout << "Objeto [nombre: " << nombreObjeto << ", cantidad de caras: " << listaCaras.size() << "]" << std::endl;
}
