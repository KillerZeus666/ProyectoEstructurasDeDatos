#ifndef KDTREE_HXX
#define KDTREE_HXX

#include "Nodo.hxx"
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include <queue>

template <class T>
class KdTree {
private:
    Nodo<T>* raiz;
    int dimensiones;

    Nodo<T>* insertar(Nodo<T>* nodo, const std::vector<T>& punto, const std::string& nombre_objeto, unsigned int profundidad);
    Nodo<T>* buscarMasCercanoRecursivo(Nodo<T>* nodo, const std::vector<T>& punto, unsigned int profundidad, Nodo<T>* mejorNodo, T& mejorDistancia);
    void preOrden(Nodo<T>* nodo);
    void inOrden(Nodo<T>* nodo);
    void posOrden(Nodo<T>* nodo);
    void nivelOrden(Nodo<T>* nodo);

public:
    KdTree(int dim);
    ~KdTree();

    void insertar(const std::vector<T>& punto, const std::string& nombre_objeto);
    Nodo<T>* buscarMasCercano(const std::vector<T>& punto);

    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();

    // Función para mostrar la raíz
    void mostrarRaiz();
};

// Constructor
template <class T>
KdTree<T>::KdTree(int dim) : raiz(nullptr), dimensiones(dim) {}

// Destructor
template <class T>
KdTree<T>::~KdTree() {
    delete raiz;
}

// Insertar un nuevo punto en el Kd-Tree
template <class T>
void KdTree<T>::insertar(const std::vector<T>& punto, const std::string& nombre_objeto) {
    raiz = insertar(raiz, punto, nombre_objeto, 0);
}

template <class T>
Nodo<T>* KdTree<T>::insertar(Nodo<T>* nodo, const std::vector<T>& punto, const std::string& nombre_objeto, unsigned int profundidad) {
    if (nodo == nullptr) {
        return new Nodo<T>(punto, nombre_objeto);
    }

    unsigned int indice = profundidad % 3;  // Solo trabajamos con 3 dimensiones (x, y, z)
    if (punto[indice] < nodo->punto[indice]) {
        nodo->izquierda = insertar(nodo->izquierda, punto, nombre_objeto, profundidad + 1);
    } else {
        nodo->derecha = insertar(nodo->derecha, punto, nombre_objeto, profundidad + 1);
    }

    return nodo;
}

// Función para buscar el nodo más cercano en 3D
template <class T>
Nodo<T>* KdTree<T>::buscarMasCercano(const std::vector<T>& punto) {
    T mejorDistancia = std::numeric_limits<T>::max();
    return buscarMasCercanoRecursivo(raiz, punto, 0, nullptr, mejorDistancia);
}

template <class T>
Nodo<T>* KdTree<T>::buscarMasCercanoRecursivo(Nodo<T>* nodo, const std::vector<T>& punto, unsigned int profundidad, Nodo<T>* mejorNodo, T& mejorDistancia) {
    if (nodo == nullptr) {
        return mejorNodo;
    }

    // Calcular la distancia euclidiana entre el punto dado y el nodo actual
    T distanciaActual = 0;
    for (unsigned int i = 0; i < 3; i++) {  // Solo usamos las 3 dimensiones (x, y, z)
        distanciaActual += pow(punto[i] - nodo->punto[i], 2);
    }
    distanciaActual = sqrt(distanciaActual);

    // Actualizamos el nodo más cercano si encontramos una mejor distancia
    if (distanciaActual < mejorDistancia) {
        mejorDistancia = distanciaActual;
        mejorNodo = nodo;
    }

    // Determinar si se debe mirar el lado izquierdo o derecho
    unsigned int dimension = profundidad % 3;
    Nodo<T>* ladoCercano = (punto[dimension] < nodo->punto[dimension]) ? nodo->izquierda : nodo->derecha;
    Nodo<T>* ladoLejano = (punto[dimension] < nodo->punto[dimension]) ? nodo->derecha : nodo->izquierda;

    // Buscar en el lado más cercano
    mejorNodo = buscarMasCercanoRecursivo(ladoCercano, punto, profundidad + 1, mejorNodo, mejorDistancia);

    // Si la distancia en la dimensión actual es menor que la mejor distancia, buscamos en el otro lado
    if (pow(punto[dimension] - nodo->punto[dimension], 2) < mejorDistancia) {
        mejorNodo = buscarMasCercanoRecursivo(ladoLejano, punto, profundidad + 1, mejorNodo, mejorDistancia);
    }

    return mejorNodo;
}

// Recorridos
template <class T>
void KdTree<T>::preOrden() {
    preOrden(raiz);
}

template <class T>
void KdTree<T>::preOrden(Nodo<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << "(";
        for (auto& coord : nodo->punto) {
            std::cout << coord << " ";
        }
        std::cout << ")";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

template <class T>
void KdTree<T>::inOrden() {
    inOrden(raiz);
}

template <class T>
void KdTree<T>::inOrden(Nodo<T>* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->izquierda);
        std::cout << "(";
        for (auto& coord : nodo->punto) {
            std::cout << coord << " ";
        }
        std::cout << ")";
        inOrden(nodo->derecha);
    }
}

template <class T>
void KdTree<T>::posOrden() {
    posOrden(raiz);
}

template <class T>
void KdTree<T>::posOrden(Nodo<T>* nodo) {
    if (nodo != nullptr) {
        posOrden(nodo->izquierda);
        posOrden(nodo->derecha);
        std::cout << "(";
        for (auto& coord : nodo->punto) {
            std::cout << coord << " ";
        }
        std::cout << ")";
    }
}

template <class T>
void KdTree<T>::nivelOrden() {
    nivelOrden(raiz);
}

template <class T>
void KdTree<T>::nivelOrden(Nodo<T>* nodo) {
    if (nodo == nullptr) return;

    std::queue<Nodo<T>*> q;
    q.push(nodo);

    while (!q.empty()) {
        Nodo<T>* current = q.front();
        q.pop();
        std::cout << "(";
        for (auto& coord : current->punto) {
            std::cout << coord << " ";
        }
        std::cout << ")";

        if (current->izquierda) q.push(current->izquierda);
        if (current->derecha) q.push(current->derecha);
    }
}

// Mostrar la raíz
template <class T>
void KdTree<T>::mostrarRaiz() {
    if (raiz != nullptr) {
        std::cout << "Raíz: (";
        for (auto& coord : raiz->punto) {
            std::cout << coord << " ";
        }
        std::cout << ")" << std::endl;
    } else {
        std::cout << "El árbol está vacío." << std::endl;
    }
}

#endif // KDTREE_HXX
