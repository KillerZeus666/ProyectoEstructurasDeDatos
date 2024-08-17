#include "Arista.h"
#include <iostream>

// Constructor vacío
Arista::Arista() {
    // Inicialización si es necesario
}

// Getters
unsigned int Arista::obtenerIndiceAr() {
    return indiceAr;
}

std::list<Vertice> Arista::obtenerListaVertices() {
    return listaVertices;
}

// Setters
void Arista::fijarIndiceAr(unsigned int index) {
    indiceAr = index;
}

void Arista::fijarListaVertices(std::list<Vertice> lista) {
    listaVertices = lista;
}

void Arista::fijarVertices(unsigned int x, unsigned int y, unsigned int z) {
    Vertice vertex;
    vertex.fijarX(x);
    vertex.fijarY(y);
    vertex.fijarZ(z);
    listaVertices.push_back(vertex);
}

// Método para imprimir la arista
void Arista::imprimirArista() const{
    std::cout << "Arista [índice: " << indiceAr << "]\n";
    for (const auto& vertice : listaVertices) {
        vertice.imprimirVertice();
    }
}

// Método para agregar un vértice a la lista
void Arista::agregarVertice(Vertice vertex) {
    listaVertices.push_back(vertex);
}

// Método para eliminar un vértice de la lista
void Arista::eliminarVertice(Vertice vertex) {
    listaVertices.remove(vertex);
}

// Método para contar el número de vértices en la lista
unsigned int Arista::contarVertices(std::list<Vertice> lista) {
    return lista.size();
}
