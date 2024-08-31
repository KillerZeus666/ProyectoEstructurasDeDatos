#include <string>
#include <list>
#include "Cara.h"

class Objeto {
    private:
        std::string nombreObjeto;
        std::list<Cara> listaCaras;
        unsigned int cantidadVerticesObj;

    public:
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
        Objeto();
};
