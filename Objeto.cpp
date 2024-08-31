    #include "Objeto.h"
    #include <iostream>
    
    //Constructor vacío
    Objeto::Objeto() {
    }
    
    //Getters
    std::string Objeto::obtenerNombreObjeto() {
        return this->nombreObjeto;
    }
    
    std::list<Cara> Objeto::obtenerCaras() {
        return this->listaCaras;
    }

    int Objeto::obtenerCantidadVerticesObj(){
        return this->cantidadVerticesObj;
    }
    
    //Setters
    void Objeto::fijarNombreObjeto(std::string objectName) {
        this->nombreObjeto = objectName;
    }
    
    void Objeto::fijarListaCaras(std::list<Cara> listaCaras) {
        this->listaCaras = listaCaras;
    }

    void Objeto::fijarCantidadVerticesObj(int cantVertices){
        this->cantidadVerticesObj=cantVertices;
    }
    
    // Método para agregar una cara a la lista
    void Objeto::agregarCara(Cara face) {
        listaCaras.push_back(face);
    }
    
    // Método para eliminar una cara de la lista
    void Objeto::eliminarCara(int faceIndex) {
        std::list<Cara>::iterator itCar;
        std::list<Cara>::iterator aux;
        itCar = listaCaras.begin();
        for(;itCar!=listaCaras.end();itCar++){
            if(itCar->obtenerIndiceCar()==faceIndex){
                aux = itCar;
                listaCaras.erase(aux);
            }
        }
    }
    
    
    // Método para contar el número de caras en la lista
    unsigned int Objeto::contarCaras() {
        return listaCaras.size();
    }
    
    //Método para imprimir el objeto
    void Objeto::imprimirObjeto() {
        std::cout << "Objeto: " << nombreObjeto << "\n";
        for (Cara& cara : listaCaras) {
            cara.imprimirCara();
        }
    }
    