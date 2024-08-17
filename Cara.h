    #include "Arista.h"
    #include <list>

    class Cara{
        private:
        unsigned int indiceCar;
        unsigned int cantidadVertices;
        std::list<Arista> listaAristas;
    
        public:
        unsigned int obtenerIndiceCar();
        unsigned int obtenerCantidadVertices();
        std::list<Arista> obtenerListaAristas();

        void fijarIndiceCar(unsigned int indice);
        void fijarCantidadVertices(unsigned int cantVertices);
        void fijarListaAristas(std::list<Arista> lista);

        void imprimirCara() const;
        void agregarArista(Arista edge);
        void eliminarArista(Arista edge);
        unsigned int contarAristas(std::list<Arista> lista);
        Cara();
    };