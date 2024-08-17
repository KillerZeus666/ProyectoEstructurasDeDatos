#include <string>
#include <list>
#include "Cara.h"

class Objeto {
    private:
        std::string nombreObjeto;
        std::list<Cara> listaCaras;

    public:
        // Getters
        std::string obtenerNombreObjeto(); 
        std::list<Cara> obtenerCaras();

        // Setters
        void fijarNombreObjeto(std::string objectName);  
        void fijarListaCaras(std::list<Cara> listaCaras);

        // Otros métodos
        void agregarCara(Cara face);
        void eliminarCara(Cara face);
        unsigned int contarCaras();

        void imprimirObjeto();

        // Constructor
        Objeto();
};
