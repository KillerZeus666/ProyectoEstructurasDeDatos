#ifndef NODO_HXX
#define NODO_HXX

#include <vector>
#include <string>

template <typename T>
class Nodo {
public:
    std::vector<T> punto; // Almacena las coordenadas del punto
    std::string nombre_objeto; // Almacena el nombre del objeto
    Nodo* izquierda; // Puntero al hijo izquierdo
    Nodo* derecha; // Puntero al hijo derecho

    Nodo(const std::vector<T>& p, const std::string& nombre)
        : punto(p), nombre_objeto(nombre), izquierda(nullptr), derecha(nullptr) {}
};

#endif // NODO_HXX
