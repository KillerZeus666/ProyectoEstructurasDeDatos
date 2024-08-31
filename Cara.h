    #include "Arista.h"
    #include <list>

    class Cara{
        private:
        unsigned int indiceCar;
        unsigned int cantidadVerticesCar;
        std::list<Arista> listaAristas;
    
        public:
        unsigned int obtenerIndiceCar();
        unsigned int obtenerCantidadVerticesCar();
        std::list<Arista> obtenerListaAristas();

        void fijarIndiceCar(unsigned int indice);
        void fijarCantidadVerticesCar(unsigned int cantVertices);
        void fijarListaAristas(std::list<Arista> lista);

        void imprimirCara();
        void agregarArista(Arista edge);
        void eliminarArista(int edgeIndex);
        unsigned int contarAristas(std::list<Arista> lista);
        Cara();
    };