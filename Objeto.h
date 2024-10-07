#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <list>
#include "Cara.h"
#include "Vertice.h" // Asegúrate de incluir esta cabecera

class Objeto {
private:
    std::string nombreObjeto;
    std::list<Cara> listaCaras;
    unsigned int cantidadVerticesObj;

public:
    // Constructor
    Objeto();

    // Getters
    std::string obtenerNombreObjeto(); 
    std::list<Cara> obtenerCaras();
    int obtenerCantidadVerticesObj();
    std::list<Vertice> obtenerVertices(); // Método para obtener los vértices
    Vertice obtenerPmin(); // Método para obtener el punto mínimo
    Vertice obtenerPmax(); // Método para obtener el punto máximo

    // Setters
    void fijarNombreObjeto(std::string objectName);  
    void fijarListaCaras(std::list<Cara> listaCaras);
    void fijarCantidadVerticesObj(int cantVertices);

    // Métodos
    void agregarCara(Cara face);
    void eliminarCara(int faceIndex);  
    unsigned int contarCaras();
    void imprimirObjeto();
};

#endif // OBJETO_H
