#include "Cara.h"

// Constructor vacío
Cara::Cara() : indiceCar(0), cantidadVerticesCar(0) {}

// Getters
unsigned int Cara::obtenerIndiceCar() {
    return this->indiceCar;
}

unsigned int Cara::obtenerCantidadVerticesCar() {
    return this->cantidadVerticesCar;
}

std::list<Arista> Cara::obtenerListaAristas() {
    return this->listaAristas;
}

// Nuevo método para obtener los vértices de las aristas
std::list<Vertice> Cara::obtenerVertices() {
    std::list<Vertice> vertices;

    // Aquí se debe suponer que cada arista tiene un método que devuelve sus vértices
    for (const Arista& arista : listaAristas) {
        vertices.push_back(arista.obtenerVertice1()); // Suponiendo que hay un método para obtener el vértice 1
        vertices.push_back(arista.obtenerVertice2()); // Suponiendo que hay un método para obtener el vértice 2
    }

    return vertices;
}

// Setters
void Cara::fijarIndiceCar(unsigned int indice) {
    this->indiceCar = indice;
}

void Cara::fijarCantidadVerticesCar(unsigned int cantVertices) {
    this->cantidadVerticesCar = cantVertices;
}

void Cara::fijarListaAristas(std::list<Arista> lista) {
    this->listaAristas = lista;
}

// Métodos para agregar y eliminar aristas
void Cara::agregarArista(Arista edge) {
    listaAristas.push_back(edge);
}

void Cara::eliminarArista(int edgeIndex) {
    std::list<Arista>::iterator itCar;
    for (itCar = listaAristas.begin(); itCar != listaAristas.end(); itCar++) {
        if (itCar->obtenerIndiceArista() == edgeIndex) { // Asumiendo que hay un método para obtener el índice de la arista
            listaAristas.erase(itCar);
            break;
        }
    }
}

// Método para contar el número de aristas en la lista
unsigned int Cara::contarAristas(std::list<Arista> lista) {
    return lista.size();
}

// Método para imprimir la cara
void Cara::imprimirCara() {
    std::cout << "Cara [indice: " << indiceCar << ", cantidad de vertices: " << cantidadVerticesCar << "]" << std::endl;
}
