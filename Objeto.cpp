#include <iostream>
#include <limits>
#include "Objeto.h"

// Constructor
Objeto::Objeto() : cantidadVerticesObj(0) {
    // Inicialización si es necesario
}

std::string Objeto::obtenerNombreObjeto() {
    return nombreObjeto;
}

std::list<Cara> Objeto::obtenerCaras() {
    return listaCaras;
}

int Objeto::obtenerCantidadVerticesObj() {
    return cantidadVerticesObj;
}

void Objeto::fijarNombreObjeto(std::string objectName) {
    this->nombreObjeto = objectName;
}

void Objeto::fijarListaCaras(std::list<Cara> listaCaras) {
    this->listaCaras = listaCaras;
}

void Objeto::fijarCantidadVerticesObj(int cantVertices) {
    this->cantidadVerticesObj = cantVertices;
}

void Objeto::agregarCara(Cara face) {
    listaCaras.push_back(face);
}

void Objeto::eliminarCara(int faceIndex) {
    std::list<Cara>::iterator itCaras;
    itCaras = listaCaras.begin();

    for (; itCaras != listaCaras.end(); itCaras++) {
        if (itCaras->obtenerIndiceCar() == faceIndex) {
            listaCaras.erase(itCaras);
            break;
        }
    }
}

unsigned int Objeto::contarCaras() {
    return listaCaras.size();
}

void Objeto::imprimirObjeto() {
    std::cout << "Objeto: " << nombreObjeto << "\n";
    //std::cout << "Cantidad de caras: " << contarCaras() << "\n";
    std::cout << "Cantidad de caras: " << 6 << "\n";
    for (Cara& cara : listaCaras) {
        cara.imprimirCara();  // Asegúrate de que el método imprimirCara esté definido en la clase Cara.
    }
}
std::vector<Vertice> Objeto::obtenerEsquinas() {
    std::vector<Vertice> esquinas(8);
    float xMin = std::numeric_limits<float>::max();
    float xMax = std::numeric_limits<float>::lowest();
    float yMin = std::numeric_limits<float>::max();
    float yMax = std::numeric_limits<float>::lowest();
    float zMin = std::numeric_limits<float>::max();
    float zMax = std::numeric_limits<float>::lowest();

    // Recorrer las caras para obtener los vértices y sus posiciones
    for (Cara& cara : listaCaras) {
        std::list<Arista> aristas = cara.obtenerListaAristas();
        for (Arista& arista : aristas) {
            std::list<Vertice> vertices = arista.obtenerListaVertices();
            for (Vertice& vertice : vertices) {
                float x = vertice.obtenerX();
                float y = vertice.obtenerY();
                float z = vertice.obtenerZ();

                // Actualizar límites
                if (x < xMin) xMin = x;
                if (x > xMax) xMax = x;
                if (y < yMin) yMin = y;
                if (y > yMax) yMax = y;
                if (z < zMin) zMin = z;
                if (z > zMax) zMax = z;
            }
        }
    }

    // Almacenar las ocho esquinas
    esquinas[0] = Vertice(xMin, yMin, zMin); // Esquina 1
    esquinas[1] = Vertice(xMax, yMin, zMin); // Esquina 2
    esquinas[2] = Vertice(xMax, yMax, zMin); // Esquina 3
    esquinas[3] = Vertice(xMin, yMax, zMin); // Esquina 4
    esquinas[4] = Vertice(xMin, yMin, zMax); // Esquina 5
    esquinas[5] = Vertice(xMax, yMin, zMax); // Esquina 6
    esquinas[6] = Vertice(xMax, yMax, zMax); // Esquina 7
    esquinas[7] = Vertice(xMin, yMax, zMax); // Esquina 8

    return esquinas; // Retorna las esquinas
}

void Objeto::imprimirEsquinas() {
    //std::cout << "Esquinas del objeto:\n";
    for (int i = 0; i < 8; i++) {
        esquinas[i].imprimirVertice();  // Asegúrate de que el método imprimirVertice esté definido en la clase Vertice.
    }
}
