#include "Vertice.h"
    #include <iostream> 
    
    //Constructor vacío
    Vertice::Vertice() {
    }
    
    //Getters
    unsigned int Vertice::obtenerX() {
        return x;
    }
    
    unsigned int Vertice::obtenerY() {
        return y;
    }
    
    unsigned int Vertice::obtenerZ() {
        return z;
    }
    
    unsigned int Vertice::obtenerIndiceVer() {
        return indiceVer;
    }
    
    //Setters
    void Vertice::fijarX(unsigned int x) {
        this->x = x;
    }
    
    void Vertice::fijarY(unsigned int y) {
        this->y = y;
    }
    
    void Vertice::fijarZ(unsigned int z) {
        this->z = z;
    }
    
    void Vertice::fijarIndiceVer(unsigned int index) {
        indiceVer = index;
    }
    
    void Vertice::imprimirVertice() {
        std::cout<<"Vértice [índice: " << indiceVer << ", x: " << x << ", y: " << y << ", z: " << z << "]"<<std::endl;
    } 
    
    