  #include <list>
  #include "Vertice.h"

  class Arista{
  private: 
  unsigned int indiceAr;
  std::list<Vertice> listaVertices;

  public:
  unsigned int obtenerIndiceAr();
  std::list<Vertice> obtenerListaVertices();

  void fijarIndiceAr(unsigned int index);
  void fijarListaVertices(std::list<Vertice> lista);
  void fijarVertices(unsigned int x, unsigned int y, unsigned int z);

  void imprimirArista() const;
  void agregarVertice(Vertice vertex);
  void eliminarVertice(Vertice vertex);
  unsigned int contarVertices(std::list<Vertice> lista);
  Arista();
  
  };