    #ifndef GRAFOML_H
    #define GRAFOML_H
    #include <vector>
    #include <list>
    #include <algorithm>
    #include <utility>
    #include <iostream>
    #include <queue>    
    #include <stack>
    #include <unordered_map>
    
    template <class T, class U> 
    class GrafoML{
        private:
        /*Lista de vertices que me dan el indice en el vector*/
        std::vector<T> vertices;
        /*Lista de listas de aristas*/
        std::vector< std::list< std::pair<int,U> > > aristas; 

        public:
        /*Canónicos*/
        GrafoML(); 
        void setVertices(std::vector<T> v);
        void setAristas(std::vector<std::list<std::pair<int, U>>> a);
        std::vector<T> getVertices();
        std::vector<std::list<std::pair<int, U>>> getAristas();

        /*Funciones con guía*/
        int cantVertices(); //CHECK
        int cantAristas(); //CHECK
        int buscarVertice(T vert); //CHECK
        bool insertarVertice(T vert); //CHECK

        bool insertarArista(T ori, T des, U cos); //CHECK
        bool insertarAristaNoDirigida(T ori, T des, U cos); //CHECK

        U buscarArista(T ori, T des); //CHECK
        bool eliminarVertice(T vert); //CHECK
        void reindexarAristas(int vertEliminado); //CHECK

        bool eliminarArista(T ori, T des); //CHECK
        bool eliminarAristaNoDirigida(T ori, T des); //CHECK

        /*Funciones desarrolladas*/
        void imprimir(); //CHECK

        void DFS(T inicio); //CHECK
        void DFSAuxiliar(T vertice, std::unordered_map<T, bool>& visitado); //CHECK

        void BFS(T inicio); //CHECK

        void recorridoCC(int v, std::vector<bool>& visitado, std::vector<T>& componente); //CHECK
        void componentesConectados(); //CHECK

        int grado(int v); //CHECK
        bool esPuente(int u, int v, std::vector<std::list<std::pair<int, U>>>& aristasCopia); //CHECK
        int contarComponentes(int v, std::vector<bool>& visitado, const std::vector<std::list<std::pair<int, U>>>& aristasCopia); //CHECK
        void algoritmoFleury(T origen); //CHECK
        bool eliminarAristaNoDirigidaFleury(T ori, T des, std::vector<std::list<std::pair<int, U>>>& aristasTarget); //CHECK
        bool insertarAristaNoDirigidaFleury(T ori, T des, U cos, std::vector<std::list<std::pair<int, U>>>& aristasTarget); //CHECK

        void encontrarCaminoHamilton(T inicio); //CHECK
        bool caminoHamilton(int pos, std::vector<bool>& visitado, std::vector<T>& camino); //CHECK

        int minDistancia(const std::vector<int>& dist, const std::vector<bool>& visitado); //CHECK
        void mostrarDistancias(const std::vector<int>& dist, const std::vector<int>& predecesores, int inicioIdx); //CHECK
        void algoritmoDijkstra(T origen); //CHECK
        void mostrarCamino(const std::vector<int>& predecesores, int j); //CHECK
        
    };

    //Constructor Base
    template<class T, class U>
    GrafoML<T, U>::GrafoML() {}

    //Setter de Vértices
    template<class T, class U>
    void GrafoML<T, U>::setVertices(std::vector<T> v) {
        /*Se iguala al vertice ingresado y se ponen las aristas del tamaño del vértice*/
          vertices = v;
          aristas.resize(vertices.size());
      }

    //Setter de Aristas
    template<class T, class U>
    void GrafoML<T, U>::setAristas(std::vector<std::list<std::pair<int, U>>> a) {
        /*Se revisa que las aristas que se quieren ingresar son el mismo número
        //del del vértice y lo iguala si es el caso, de lo contrario sale un mensaje de error*/
          if (a.size() == vertices.size()) {
              aristas = a;
          } else {
              std::cout<<"No ha sido posible establecer las aristas"<<std::endl;
          }
      }

    //Getter de Vértices
    template<class T, class U>
    std::vector<T> GrafoML<T, U>::getVertices() {
          return vertices;
      }

    //Getter de Aristas
    template<class T, class U>
    std::vector<std::list<std::pair<int, U>>> GrafoML<T, U>::getAristas() {
          return aristas;
      }

    //Cantidad de Vértices
    template<class T, class U>
    int GrafoML<T, U>::cantVertices() {
        /*Simplemente vertices.size()*/
          return vertices.size();
      }

    //Cantidad de Aristas
    template<class T, class U>
    int GrafoML<T, U>::cantAristas(){
          int suma = 0;
        /*Se realiza un acumulador que va aumentando en # de aristas 
        //por cada vértice*/
          for (int i=0; i<cantVertices(); i++) {
              suma += aristas[i].size();
          }
          return suma;
      }

    //Buscar Vértice
    template<class T, class U>
    int GrafoML<T, U>::buscarVertice(T vert) {
        /*Se establece que si no se encuentra el vértice se retorna -1*/
          int ind = -1;
          for (int i=0; i<cantVertices(); i++) {
              if (vertices[i] == vert){
                  ind = i;
              }
          }
        /*Si es encontrado se retorna el indice del vértice*/
          return ind;
      }

    //Insertar Vértice
    template<class T, class U>
    bool GrafoML<T, U>::insertarVertice(T vert) {
        /*Se añade confirmación de inserción en caso de insertar*/
          bool res = false;
        /*Se revisa que no se encuentre repetido (buscarVertice == -1)*/
          if (buscarVertice(vert) == -1) {
              /*Se ingresa el vértice en el vector y se le crea su sección la lista de aristas*/
              vertices.push_back(vert);
              aristas.push_back(std::list<std::pair<int, U>>()); 
              res = true;
          }
        /*Se retorna la confirmación*/
          return res;
    }

    //Insertar Arista No Dirigida (Insertarla en ambos vértices)
    template<class T, class U>
    bool GrafoML<T,U>::insertarAristaNoDirigida(T ori, T des, U cos){
        /*Se buscan los índices de ambos vértices*/
        int u = buscarVertice(ori);
        int v = buscarVertice(des);

        /*Si alguno de los dos no se encuentra se retorna falso*/
        if (u==-1 || v==-1){
            return false;
        }

        /*Se añaden las aristas en su respectivo espacio de ambos
        //vertices con el mismo valor para hacer un grafo no dirigido*/
        aristas[u].push_back({v, cos});
        aristas[v].push_back({u, cos}); 
        return true;
    }

    //Insertar Arista No Dirigida (Auxiliar para caminos de Hamilton)
    template<class T, class U>
    bool GrafoML<T,U>::insertarAristaNoDirigidaFleury(T ori, T des, U cos, std::vector<std::list<std::pair<int, U>>>& aristasTarget) {

        /*Se realiza lo mismo que en insertarAristaNoDirigida
        //pero se añade a la lista de aristas que se pasa por referencia 
        //que corresponde al backup del grafo*/
        int u = buscarVertice(ori);
        int v = buscarVertice(des);
        if (u == -1 || v == -1) return false;
        aristasTarget[u].push_back({v, cos});
        aristasTarget[v].push_back({u, cos});
        return true;
    }

    //Insertar Arista Dirigida
    template<class T, class U>
    bool GrafoML<T, U>::insertarArista(T ori, T des, U cos) {
          bool res = false;
          int i_ori = buscarVertice(ori);
          int i_des = buscarVertice(des);

        /*Se realiza la búsqueda de los índices de los vértices
        //y la confirmación de que si se encuentra*/
          if (i_ori != -1 && i_des != -1) {
              bool esta = false;
              for (const auto& arista : aristas[i_ori]) {
                  if (arista.first == i_des) {
                      esta = true;
                      break;
                  }
              }
              /*Si no se encuentra, significa que no está repetida y se realiza
              //la inserción*/
              if (!esta) {
                  aristas[i_ori].push_back(std::make_pair(i_des, cos));
                  res = true;
              }
          }
        /*Se retorna la confirmación de inserción*/
          return res;
      }

    //Buscar Arista
    template<class T, class U>
    U GrafoML<T, U>::buscarArista(T ori, T des) {
        U res = -1; 
        int i_ori = buscarVertice(ori);
        int i_des = buscarVertice(des);

        /*Se establece que si no se encuentra el vértice se retorna -1*/
        /*Se realiza la búsqueda de los índices de los vértices y de ahí
        //se iguala en el de origen para buscar en la lista*/
        if (i_ori != -1 && i_des != -1) {            
            typename std::list<std::pair<int, U>>::iterator itList = aristas[i_ori].begin();
    
            for (; itList != aristas[i_ori].end(); ++itList) {
                if (itList->first == i_des) {
                    res = itList->second; 
                    break;
                }
            }
        }
        
        /*Se retorna el peso de la arista entre origen y destino si se encuentra*/
        return res;
    }

    //Eliminar Vértice
    template<class T, class U>
    bool GrafoML<T,U>::eliminarVertice(T vert) {
        bool res = false;
        int i_vert = buscarVertice(vert); 

        /*Se revisa el índice del vértice y si es válido se procede a eliminar*/
        if (i_vert != -1) { 
            typename std::vector<std::list<std::pair<int, U>>>::iterator itA, posE;
            int ind = 0;
    
            /*Se itera sobre la lista de aristas hasta llegar a la indicada,
            // y se almacena la posición*/
            for (itA = aristas.begin(); itA != aristas.end(); itA++, ind++) {
                if (ind == i_vert) { 
                    posE = itA; 
                } else {
                    /*Se tiene el iterador interno para la lista de aristas del vértice
                    //cuando coincide, se elimina la arista a la que apunta el vértice
                    //y se va avanzando al siguiente elemento dentro de la lita*/
                    for (auto itList = itA->begin(); itList!=itA->end(); ) {
                        if (itList->first == i_vert) {
                            itList = itA->erase(itList); 
                        } else {
                            ++itList; 
                        }
                    }
                }
            }
    
            /*Se elimina la lista relacionada en el vértice*/
            aristas.erase(posE);
            res = true; 
        }

        /*Se procede a borrar el vértice del vector de vértices*/
        vertices.erase(vertices.begin() + i_vert);

        /*Se utiliza una función auxiliar para reacomodar las aristas*/
        reindexarAristas(i_vert);

        return res;
    }

    //Reindexar aristas (Auxiliar de eliminar vértice)
    template<class T, class U>
    void GrafoML<T,U>::reindexarAristas(int vertEliminado) {
        /*Con el índice del vértice eliminado se revisa si coresponde al índice
        //del vertice eliminado, si es así, se decrementa el índice para
        //las aristas que vienen y se va iterando*/
        for (auto& lista : aristas) {
            for (auto it = lista.begin(); it != lista.end(); ) {
                if (it->first > vertEliminado) {
                    it->first--; 
                }
                ++it; 
            }
        }
    }

    //Eliminar Arista
    template<class T, class U>
    bool GrafoML<T,U>::eliminarArista(T ori, T des) {
        bool res = false;
        int i_ori = buscarVertice(ori); 
        int i_des = buscarVertice(des);

        /*Se buscan los vértices y se verifican de que existen, y de ahí se comieza a iterar
        //en la lista, revisando si coindide con el índice del vértice, si es así se elimina 
        //esa posición*/
        if (i_ori != -1 && i_des != -1) {
            typename std::list< std::pair<int,U> >::iterator itList, posE; 
            for (itList = aristas[i_ori].begin(); itList != aristas[i_ori].end(); itList++) { 
                if (itList->first == i_des){
                    posE = itList;
                }
            }
            aristas[i_ori].erase(posE); 
        }
        /*Se retorna la confirmación de eliminación*/
        return res;
    }

    //Eliminar Arista No Dirigida
    template<class T, class U>
    bool GrafoML<T,U>::eliminarAristaNoDirigida(T ori, T des) {
        /*Se obtienen los índices de los vértices y se verifica que existan*/
        int u = buscarVertice(ori);
        int v = buscarVertice(des);
        if (u==-1 || v==-1){
            return false;
        }
        /*Y se eliminan los pares de las aristas*/
        //de origen a destino y de destino a origen correspondientemente*/

        /*Se itera sobre la lista de aristas del vértice origen y se elimina la arista
        //si no se encuentra en el momento, sigue avanzando*/
        aristas[u].remove_if([&](const std::pair<int, U>& arista) { return arista.first == v; });

        /*Se repite lo mismo en la de destino*/
        aristas[v].remove_if([&](const std::pair<int, U>& arista) { return arista.first == u; });

        /*Se retorna la confirmación de eliminación*/
        return true;
    }

    //Eliminar Arista No Dirigida (Auxiliar para caminos de Hamilton)
    template<class T, class U>
    bool GrafoML<T,U>::eliminarAristaNoDirigidaFleury(T ori, T des, std::vector<std::list<std::pair<int, U>>>& aristasTarget) {
        /*Se realiza lo mismo que en eliminarAristaNoDirigida pero
        //sobre la copia de el grafo pra no perder datos*/
        int u = buscarVertice(ori);
        int v = buscarVertice(des);
        if (u == -1 || v == -1) return false;

        aristasTarget[u].remove_if([v](const std::pair<int, U>& p) { return p.first == v; });
        aristasTarget[v].remove_if([u](const std::pair<int, U>& p) { return p.first == u; });

        return true;
    }

    //Imprimir el grafo
    template<class T, class U>
    void GrafoML<T,U>::imprimir() {
        /*Se imprime el encabezado del grafo y se comeinza a iterar*/
        std::cout<<"---- Grafo ----"<<std::endl; 
        for (size_t i=0; i<vertices.size(); ++i) {
            std::cout<<"Vértice "<<vertices[i]<<" tiene aristas a: ";
            
            /*Se utiliza una confirmación para saber si es el primero y no poner , 
            //se hace un for each de cada arista y se va poniendo la coma*/
            bool primero = true; 
            for (const auto& arista : aristas[i]) {
                if (!primero) {
                    std::cout<<", "; 
                }
                /*Se accede al peso y se imrpime, y se cambia la bandera de primera
                //impresión*/
                std::cout << vertices[arista.first]<<"(peso: "<<arista.second<<")";
                primero = false; 
            }
            std::cout<<std::endl; 
        }
        /*Se hace salto por vértice y se cierra la impresión*/
        std::cout<<"----------------"<<std::endl; 
    }

    //Recorrido por Profundidad
    template<class T, class U>
    void GrafoML<T,U>::DFS(T inicio) {
        /*Se usa un mapa no ordenado para no permitir repetir elementos
        //e indicar que ya fueron visitados*/
        std::unordered_map<T, bool> visitado; 
        /*Se usa recursividad para ir imprimiendo iniciando por el principo*/
        DFSAuxiliar(inicio, visitado);
    }

    //Recorrido por Profundidad (Función auxiliar de DFS)
    template<class T, class U>
    void GrafoML<T,U>::DFSAuxiliar(T vertice, std::unordered_map<T, bool>& visitado) {
        /*Se marca el vértice actual como visitado y se imprime*/
        visitado[vertice]=true; 
        std::cout<<vertice<<" "; 

        /*Se busca el índice del vértice y se itera sobre la lista de aristas
        //con un for each, si el vértice no ha sido visitado se llama a la función*/
        int i_vert = buscarVertice(vertice); 
        for (const auto& arista : aristas[i_vert]) {
            if (!visitado[vertices[arista.first]]) {
                DFSAuxiliar(vertices[arista.first], visitado); 
            }
        }
    }

    //Recorrido por Amplitud
    template<class T, class U>
    void GrafoML<T,U>::BFS(T inicio) {
        /*Se usa el mapa para marcar los ya visitados y no repetir elementos
        //y se hace la cola que habíamos quedado para el algoritmo*/
        std::unordered_map<T, bool> visitado; 
        std::queue<T> cola; 

        /*Se marca el vértice inicial como visitado y se agrega a la cola*/
        visitado[inicio] = true; 
        cola.push(inicio);

        /*Y se comienza a iterar sobre la cola, si el vértice no ha sido visitado
        //se agrega a la cola, se saca y se imprime*/
        while (!cola.empty()) {
            T vertice = cola.front();
            cola.pop();
            std::cout<<vertice<<" "; // Procesa el vértice

            /*Y se comienza a iterar sobre la lista de aristas, si el vértice no ha sido
            //visitado se marca como visitado, se visita
            //y se encola el vértice de destino*/
            int i_vert = buscarVertice(vertice);
            for (const auto& arista : aristas[i_vert]) {
                if (!visitado[vertices[arista.first]]) { 
                    visitado[vertices[arista.first]] = true; 
                    cola.push(vertices[arista.first]); 
                }
            }
        }
    }

    //Recorrido de Componentes Conectados (Auxiliar)
    template<class T, class U>
    void GrafoML<T,U>::recorridoCC(int v, std::vector<bool>& visitado, std::vector<T>& componente) {
        /*Se marca el vértice como visitado y se agrega a la lista de componentes conectados*/
        visitado[v] = true; 
        componente.push_back(vertices[v]); 

        /*Se procede a recorrer las aristas, y si no ha sido visitado el vértice se vuelve a llamar*/
        for (const auto& arista : aristas[v]) {
            if (!visitado[arista.first]) { 
                recorridoCC(arista.first, visitado, componente);
            }
        }
    }

    //Componentes Conectados
    template<class T, class U>
    void GrafoML<T,U>::componentesConectados() {
        /*Se tiene el vector de vectores para almacenar los componentes conectados 
        //dados los vértiecs y los vértices ya visitados*/
        std::vector<bool> visitado(vertices.size(), false); 
        std::vector<std::vector<T>> componentes; 

        /*Se revisa cada vértice y si no ha sido visitado se llama a la función
        //del recorrido que va revisando los componentes, y se agrega a la lista de componentes
        //así diferenciando cada componente*/
        for (size_t i=0; i<vertices.size(); ++i) {
            if (!visitado[i]) { 
                std::vector<T> componente; 
                recorridoCC(i, visitado, componente); 
                componentes.push_back(componente); 
            }
        }

        /*Ya con los componentes conectados se imprimen los que pertenecen*/
        std::cout<<"Componentes conectados:"<<std::endl;
        for (const auto& comp : componentes){
            std::cout<<"[";
            for (const auto& vert : comp) {
                std::cout<<vert<<"";
            }
            std::cout<<"]"<<std::endl;
        }
    }

    //Contar Componentes (Auxiliar para algoritmo de Fleury)
    template<class T, class U>
    int GrafoML<T,U>::contarComponentes(int v, std::vector<bool>& visitado, const std::vector<std::list<std::pair<int, U>>>& aristasCopia) {
        /*Se marca el vértice como visitado y si no coincide con el vértice 
        //la arsita que se está revisando se añade un nuevo componente
        //y se realiza recursividad para contar un nuevo componenet*/
        visitado[v] = true;
        int contador = 1;
        
        for (const auto& arista : aristasCopia[v]) {
            if (!visitado[arista.first]) {
                contador += contarComponentes(arista.first, visitado, aristasCopia);
            }
        }
            return contador;
    }

    //Es Puente (Auxiliar para algoritmo de Fleury)
    template<class T, class U>
    bool GrafoML<T,U>::esPuente(int u, int v, std::vector<std::list<std::pair<int, U>>>& aristasCopia) {

        /*Se crea una copia de las aristas y se comienza a iterar sobre ellas, obteniendo el peso original
        //para después reasignarlo*/
        auto it = std::find_if(aristasCopia[u].begin(), aristasCopia[u].end(), 
        [v](const std::pair<int, U>& p) { return p.first == v; });
        
        U pesoOriginal = it->second;
    
        /*Se elimina el par de aristas para revisar si es puente en la copia del
        //grafo para no dañar los datos*/
        eliminarAristaNoDirigidaFleury(vertices[u], vertices[v], aristasCopia);
    
        /*Se revisan los componentes conectados antes y después de hacer la eliminación
        //si el número de componentes después es mayor a antes de hacer la copia significa
        //que era una arista puente*/
        std::vector<bool> visitado(vertices.size(), false);
        int componentesOriginal = contarComponentes(u, visitado, aristasCopia);

        /*Se pone todo en falso para volver a realizar la iteración*/
        visitado.assign(vertices.size(), false);
        int componentesDespues = contarComponentes(u, visitado, aristasCopia);
        
        /*Se regresa el peso original para no perderlo junto con la arista eliminada*/
        insertarAristaNoDirigidaFleury(vertices[u], vertices[v], pesoOriginal, aristasCopia);

        /*Se retorna un true o un false según la expresión y lo indicado anteriormente*/
        return componentesDespues>componentesOriginal;
    }

    //Algoritmo de Fleury
    template<class T, class U>
    void GrafoML<T,U>::algoritmoFleury(T origen) {
        /*Se hace una copia de aristas para no dañar los datos
        //y se busca el vértice de origen*/
        std::vector<std::list<std::pair<int, U>>> aristasCopia = aristas;
        int u = buscarVertice(origen);

        /*Mientras de que no se vacié la copia del grafo se va revisando cada
        //arista e inficando si es puente o no, en caso de que sea puente no se
        //toma el camino y se sigue avanzando; cuando ya quedan menos de 1
        //arista ahí si se toma el puente*/
            while (!aristasCopia[u].empty()) {
                auto it = aristasCopia[u].begin();
                int v = it->first;
                U peso = it->second;

                if (esPuente(u, v, aristasCopia) && aristasCopia[u].size() > 1) {
                    ++it;
                    v = it->first;
                    peso = it->second;
                }

                /*Se va imprimiendo el camino y se elimina la arista para no pasar por el
                //mismo lado*/
                std::cout<<"Camino: "<<vertices[u]<<" - "<<vertices[v]<<"(peso: "<<peso<< ")\n";
                eliminarAristaNoDirigidaFleury(vertices[u], vertices[v], aristasCopia);
                u = v;
            }
    }

    //Grado de un Vértice
    template<class T, class U>
    int GrafoML<T,U>::grado(int v) {
        /*Se retorna la cantidad de aristas que tiene el vértice*/
        return aristas[v].size();
    }

    //Recorrido de Hamilton (Auxiliar de algoritmo de Hamilton)
    template <class T, class U>
    bool GrafoML<T, U>::caminoHamilton(int pos, std::vector<bool>& visitado, std::vector<T>& camino) {

        /*Se verifica que todos los vértices se hayan visitado una vez 
        //revisando el tamaño del camino*/
        if(camino.size()==vertices.size()){
            return true; 
        }

        /*Se itera en cada arista por sus posiciones y se verifica si el vecino
        //no ha sido visitado al obtener su índice, si es así se agrega al camino
        //y se llama de nuevo a la función*/
        for (const auto& arista : aristas[pos]) {
            int vecino = arista.first;
            if (!visitado[vecino]) {
                /*Adicionalmente se va añadiendo al camino cada vértice que se visita*/
                visitado[vecino] = true;
                camino.push_back(vertices[vecino]);

                /*En caso de que se encuentre un camino se retorna true*/
                if(caminoHamilton(vecino, visitado, camino)==true){
                    return true;
                }

                /*En caso de que no se encuentre un camino, se pone el vecino en
                //falso y se retorna que no se pdo encontrar el camino*/
                visitado[vecino] = false;
                camino.pop_back();
            }
        }
        return false;
    }

    //Camino de Hamilton
    template <class T, class U>
    void GrafoML<T, U>::encontrarCaminoHamilton(T inicio) {
        /*Se lleva la revisión del camino y de los vértices ya revisados*/
        std::vector<bool> visitado(vertices.size(), false);
        std::vector<T> camino;

        /*Se busca el vértice de inicio*/
        int inicioIdx = buscarVertice(inicio);
        if (inicioIdx == -1) {
            std::cout<<"El vértice de inicio no existe en el grafo.\n";
            return;
        }

        /*Y se marca como visitado, iniciando el camino*/
        visitado[inicioIdx] = true;
        camino.push_back(inicio);

        /*Se revisa el retorno dado por el recorrido de Hamilton y se imprime*/
        if(caminoHamilton(inicioIdx, visitado, camino)) {
            std::cout<<"Camino de Hamilton encontrado: ";
            for(const auto& vertice : camino) {
                std::cout<<vertice<<" ";
            }
            std::cout<<std::endl;
        } else {
            std::cout<<"No se encontró un camino de Hamilton.\n";
        }
    }

    //Distancia mínima (Auxiliar de algoritmo de Dijkstra)
    template <class T, class U>
    int GrafoML<T, U>::minDistancia(const std::vector<int>& dist, const std::vector<bool>& visitado) {
        int min = 99999999, min_index=-1;

        /*Se establece la distancia por default de 99999999, y se itera en cada vértice
        //para obtener el vértice con la distancia mínima, haciendo un reemplazo
        //de la distancia mínima anterior si es encontrada y se cambia el índica*/
        for (int v=0; v<vertices.size(); v++) {
            if (!visitado[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    //Impresión de Distancias desde el Origen
    template <class T, class U>
    void GrafoML<T, U>::mostrarDistancias(const std::vector<int>& dist, const std::vector<int>& predecesores, int inicioIdx) {
        std::cout<<"Distancias mínimas desde el origen:\n";
        /*Se imprimen las distancias, si es igual a la máxima se pone el mensaje de
        //inalcanzable, de resto se imprimen los vértiecs y se imprime el camino de 
        //precedesores*/
        for (int i=0; i<vertices.size(); i++) {
            if (dist[i] == 99999999) {
                std::cout<<"No hay camino desde "<<vertices[inicioIdx]<<" a "<<vertices[i]<<"\n";
            } else {
                std::cout<<"Distancia a "<<vertices[i]<<" : "<<dist[i]<<" | Camino: ";
                mostrarCamino(predecesores, i);
                std::cout<<"\n";
            }
        }
    }

    //Impresión de Camino 
    template <class T, class U>
    void GrafoML<T, U>::mostrarCamino(const std::vector<int>& predecesores, int j) {
        /*Si es -1 se imprime el vértice de inicio*/
        if (predecesores[j] == -1) {
            std::cout<<vertices[j];
            return;
        }
        /*Si no es -1 se imprime el vértice de inicio y se llama a la función
        //para imprimir de nuevo pero con un índice mayor como va dentro del
        //ciclo de impresión de distancias, así imprimiendo los siguientes
        //del camino*/
        mostrarCamino(predecesores, predecesores[j]);
        std::cout<<"->"<<vertices[j];
    }

    //Algoritmo de Dijkstra
    template <class T, class U>
    void GrafoML<T, U>::algoritmoDijkstra(T origen) {
        /*Se introduce el máximo como n,
        //un vector con las distancias, 
        //un vector de visitados
        //y un vector de predecesores para revisar el camino, comenzando desde el origen*/
        int n = vertices.size();
        std::vector<int> dist(n, 99999999);
        std::vector<bool> visitado(n, false);
        std::vector<int> predecesores(n, -1); 

        /*Control de erroers*/
        int inicioIdx = buscarVertice(origen);
        if (inicioIdx==-1) {
            std::cout<<"El vértice de inicio no existe en el grafo.\n";
            return;
        }

        /*Se marca la distancia de inicio como 0*/
        dist[inicioIdx] = 0;

        /*Se lleva el contador de todos los vértices visitados - 1 el de origen*/
        for(int count=0; count<n-1; count++) {

            /*Se obtiene la distancia mínima y se marca como visitado el vértice
            //correspondiente*/
            int u = minDistancia(dist, visitado);

            /*Si en la iteración se encuentra un retorno de -1 significa que no
            //hay más vertices alcanzables*/
            if (u == -1) break; 

            visitado[u] = true;

            /*Se revisa arista por arista para obtener el índice y el peso
            //revisando que no sea la distancia infinita, que ya esté visitado
            //y que sea menor a la distancia actual*/
            for (const auto& arista : aristas[u]) {
                int v = arista.first;
                U peso = arista.second;

                /*Se realiza la sumatoria de distancias para añadir a los precesores
                //en caso de que sea menor*/
                if (!visitado[v] && dist[u] != 99999999 && dist[u]+peso<dist[v]) {
                    dist[v] = dist[u] + peso;
                    predecesores[v] = u;  // Registrar el predecesor de v como u
                }
            }
        }

        /*Se muestran las distancias :D*/
        mostrarDistancias(dist, predecesores, inicioIdx);
    }
    #endif