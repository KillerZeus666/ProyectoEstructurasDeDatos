#include "Cara.h"
#include <iostream>

// Constructor vacío
Cara::Cara() {
    // Inicialización si es necesario
}

// Getters
unsigned int Cara::obtenerIndiceCar() {
    return indiceCar;
}

unsigned int Cara::obtenerCantidadVertices() {
    return cantidadVertices;
}

std::list<Arista> Cara::obtenerListaAristas() {
    return listaAristas;
}

// Setters
void Cara::fijarIndiceCar(unsigned int indice) {
    indiceCar = indice;
}

void Cara::fijarCantidadVertices(unsigned int cantVertices) {
    cantidadVertices = cantVertices;
}

void Cara::fijarListaAristas(std::list<Arista> lista) {
    listaAristas = lista;
}

// Método para imprimir la cara
void Cara::imprimirCara () const{
    std::cout << "Cara [índice: " << indiceCar << ", cantidad de vértices: " << cantidadVertices << "]\n";
    for (const auto& arista : listaAristas) {
        arista.imprimirArista();
    }
}

// Método para agregar una arista a la lista
void Cara::agregarArista(Arista edge) {
    listaAristas.push_back(edge);
}

// Método para eliminar una arista de la lista
void Cara::eliminarArista(Arista edge) {
    listaAristas.remove(edge);
}

// Método para contar el número de aristas en la lista
unsigned int Cara::contarAristas(std::list<Arista> lista) {
    return lista.size();
}
