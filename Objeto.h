#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <list>
#include "Cara.h"
#include "Vertice.h"  

class Objeto {
private:
    std::string nombreObjeto;
    std::list<Cara> listaCaras;
    unsigned int cantidadVerticesObj;
    Vertice esquinas[8];  // Array para almacenar las ocho esquinas del objeto envolvente.

public:
    Objeto();  // Constructor
    std::string obtenerNombreObjeto();
    std::list<Cara> obtenerCaras();
    int obtenerCantidadVerticesObj();

    void fijarNombreObjeto(std::string objectName);
    void fijarListaCaras(std::list<Cara> listaCaras);
    void fijarCantidadVerticesObj(int cantVertices);

    void agregarCara(Cara face);
    void eliminarCara(int faceIndex);
    unsigned int contarCaras();

    void imprimirObjeto();
    std::vector<Vertice> obtenerEsquinas() ;
    void imprimirEsquinas();  // Método para imprimir las esquinas
};

#endif // OBJETO_H
