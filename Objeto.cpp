#include "Objeto.h"
#include <iostream>

// Constructor vacío
Objeto::Objeto() {
}

// Getters
std::string Objeto::obtenerNombreObjeto() {
    return this->nombreObjeto;
}

std::list<Cara> Objeto::obtenerCaras() {
    return this->listaCaras;
}

// Setters
void Objeto::fijarNombreObjeto(std::string objectName) {
    this->nombreObjeto = objectName;
}

void Objeto::fijarListaCaras(std::list<Cara> listaCaras) {
    this->listaCaras = listaCaras;
}

// Método para agregar una cara a la lista
void Objeto::agregarCara(Cara face) {
    listaCaras.push_back(face);
}

// Método para eliminar una cara de la lista
void Objeto::eliminarCara(Cara face) {
    listaCaras.remove(face);
}

// Método para contar el número de caras en la lista
unsigned int Objeto::contarCaras() {
    return listaCaras.size();
}

// Método para imprimir el objeto
void Objeto::imprimirObjeto() {
    std::cout << "Objeto: " << nombreObjeto << "\n";
    for (const auto& cara : listaCaras) {
        cara.imprimirCara();
    }
}
