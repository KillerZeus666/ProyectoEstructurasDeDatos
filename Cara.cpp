    #include "Cara.h"
    #include <iostream>
    
    //Constructor vacío
    Cara::Cara() {
        // Inicialización si es necesario
    }
    
    //Getters
    unsigned int Cara::obtenerIndiceCar() {
        return indiceCar;
    }
    
    unsigned int Cara::obtenerCantidadVerticesCar() {
        return cantidadVerticesCar;
    }
    
    std::list<Arista> Cara::obtenerListaAristas() {
        return listaAristas;
    }
    
    //Setters
    void Cara::fijarIndiceCar(unsigned int indice) {
        this->indiceCar = indice;
    }
    
    void Cara::fijarCantidadVerticesCar(unsigned int cantVertices) {
        this->cantidadVerticesCar = cantVertices;
    }
    
    void Cara::fijarListaAristas(std::list<Arista> lista) {
        this->listaAristas = lista;
    }
    
    //Método para imprimir la cara
    void Cara::imprimirCara(){
        std::cout << "Cara [índice: " << indiceCar << ", cantidad de vértices: " << cantidadVerticesCar << "]\n";
        for (Arista& arista : listaAristas) {
            arista.imprimirArista();
        }
    }
    
    //Método para agregar una arista a la lista
    void Cara::agregarArista(Arista edge) {
        listaAristas.push_back(edge);
    }
    
    //Método para eliminar una arista de la lista
    void Cara::eliminarArista(int edgeIndex) {

        std::list<Arista>::iterator itAris;
        std::list<Arista>::iterator aux;
        itAris = listaAristas.begin();

        for(;itAris!=listaAristas.end();itAris++){
            if(itAris->obtenerIndiceAr()==edgeIndex){
                aux = itAris;
                listaAristas.erase(aux);
            }
        }
    }
    
    //Método para contar el número de aristas en la lista
    unsigned int Cara::contarAristas(std::list<Arista> lista) {
        return lista.size();
    }
    