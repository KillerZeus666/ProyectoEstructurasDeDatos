 //Proyecto Estructura de Datos
  //Entrega 1
  //Integrantes: Natalia Alexandra Jiménez Cañas - Miguel Ángel Laiton Ruiz - Katheryn Sofia Guasca Chavarro

  #include <iostream>
  #include <fstream>
  #include <sstream> 
  #include <string>
  #include <limits>
  #include <vector>
  #include "Objeto.h" // TAD objeto

  ///////////////////////////////////////////////COMPONENTE 1////////////////////////////////////////// 

  /*Funciones encargadas de subir un objeto a memoria,
  //en este caso, verificacionObjeto()
  //es una función complementaria*/
  void cargarArchivo(std::string nombreArchivo, std::list<Objeto>& listadoObjetos);
  bool verificacionObjeto(std::string nombreArchivo, std::list<Objeto>& listadoObjetos);

  /*Funciones encargadas de listar los objetos presentes
  //en memoria, en este caso imprimirListado() es considerada
  //una función complementaria. Y se piensa desde que se sabe
  //cuantos objetos se tienen en memoria para facilidad del programa*/
  void listado(std::list<Objeto>& listadoObjetos);
  void imprimirListado(std::list<Objeto>& listadoObjetos);

  /*Funciones creadas con la intención de crear las envolventes correspondientes a un objeto
  //o a todos los objetos cargados en memoria*/
  void envolvente(std::string nombreObjeto);
  void envolvente();

  /*Función encargada de liberar memoria de un objeto según su nombre*/
  void descargar(std::string nombreObjeto, std::list<Objeto>& listadoObjetos);

  /*Función la cual sirve para guardar un objeto definido en un archivo también definido por el usuario
  //teniendo en cuenta que se recorre el arraylist de los objetos que actualmente se encuentran en memoria*/
  void guardar(std::string nombreObjeto, std::string nombreArchivo, std::list<Objeto>& listadoObjetos);
  Objeto encontrarObjeto(std::string nombreObjeto, std::list<Objeto>& listadoObjetos);

  /*Función la cual simplemente sirve para salir del programa
  //de manera elegante y segura*/
  void salir();

  ///////////HACE FALTA DEFINIR COMO SE VA A MANEJAR EL TEMA CUANDO EL PROGRAMA LLEVE A ESTE FLUJO////////////////////
  ///////////////////////////////////////////////COMPONENTE 2//////////////////////////////////////////
  void v_cercano(int px, int py, int pz, std::string nombreObjeto);
  void v_cercano(int px, int py, int pz);
  void v_cercanos_caja(std::string nombreObjeto);

  ///////////////////////////////////////////////COMPONENTE 3//////////////////////////////////////////
  void ruta_corta(Vertice i1, Vertice i2, std::string nombreObjeto);
  void ruta_corta_centro(Vertice i1, std::string nombreObjeto);

  ///////////////////////////////////////////////COMPONENTE 4//////////////////////////////////////////
  void ayuda(std::string comando);
  void comandosDisponibles(); 

std::list<Objeto> objetosPrograma;

  int main() {
      //LISTA DE OBJETOS QUE ADMINISTRA EL SISTEMA
      
    try{
      std::cout << "    ________________________________________________________________________________" << std::endl;
      std::cout << "    |                        Bienvenid@ a nuestro proyecto                         |" << std::endl;
        
      //Variable del comando como tal empleado por el usuario
      std::string comandoUsuario;
      /*Se emplea vector para guardar los argumentos ingresados por el usuario
      //y se utiliza una variable para ir guardando los argumentos en el vector
      //uno por uno*/
        
      std::vector<std::string> argumentosUsuario; 
      std::string argumento;

      //Bucle para que se le pida constantemente comandos al usuario
      while (true) {
            std::cout << "    ________________________________________________________________________________"<<std::endl;
            std::cout << "    |                                                                              |" << std::endl;
            std::cout << "    |     Por favor, ingrese el comando ayuda para ver los comandos disponibles    |" << std::endl;
            std::cout << "    |______________________________________________________________________________|" << std::endl;
            std::cout << "$";
            std::getline(std::cin, comandoUsuario);
               
            //Se toma la primera entrada por el usuario como el comando 
            std::istringstream stream(comandoUsuario);
            stream >> comandoUsuario;

            /*Se toma el resto de la línea ingresada como argumentos por
            //medio del .pushback() que va metiendo lo leído dentro de
            //argumentosUsuario*/
            argumentosUsuario.clear();
            while (stream >> argumento) {
                    argumentosUsuario.push_back(argumento);
            }
          
            //Comando componente 1 (7/7)
            if (comandoUsuario == "salir") {
                    salir();
                    break;
                //Componente parte interaccion con el usuario 
            } else if (comandoUsuario == "ayuda") {
                    if (!argumentosUsuario.empty()) {
                        ayuda(argumentosUsuario[0]);
                    } else {
                        comandosDisponibles();
                    }
                    //Comando componente 1 (1/7)
                    } else if (comandoUsuario == "cargar") {
                    if (argumentosUsuario.size() == 1) {
                        cargarArchivo(argumentosUsuario[0], objetosPrograma);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda cargar' para más informacion.\n";
                    }
                    //Comando componente 1 (2/7)
                    } else if (comandoUsuario == "listado") {
                    //Salidas en pantalla error 
                    if(objetosPrograma.empty()){
                        std::cout << "(Memoria vacía) Ningun objeto ha sido cargado en memoria." << std::endl;
                    }else {
                        //Salida en pantalla resultadon exitoso
                        
                        std::cout << "\n(Resultado exitoso) Hay " <<objetosPrograma.size() << " objetos en memoria:" <<std::endl;
                        // ACA TENER DISPONIBLE LA LISTA DE OBJETOS y se imprimira lo siguiente:
                        // nombre_objeto_1 contiene n_1 vertices, a_1 aristas y c_1 caras.
                        listado(objetosPrograma);
                    }
                    //Comando componente (5/7)
                    } else if (comandoUsuario == "descargar") {
                    if (argumentosUsuario.size() == 1) {  
                      // TODO TIENE Q ESTAR CARGADO EN MEMORIA
                        descargar(argumentosUsuario[0], objetosPrograma);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout<<"Uso incorrecto, use 'ayuda descargar' para más informacion.\n";
                    }
                    } else if (comandoUsuario == "guardar") {
                    if (argumentosUsuario.size() == 2) {
                      //TODO TIENE QUE ESTAR CARGADO EN MEMORIA
                        guardar(argumentosUsuario[0], argumentosUsuario[1], objetosPrograma);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda guardar' para más informacion.\n";
                    }
                    } else if (comandoUsuario == "envolvente") {
                        //TODO DEBE ESTAR CARGADO EN MEMORIA
                    if (argumentosUsuario.size() == 1) {
                        envolvente(argumentosUsuario[0]);
                    } else if (argumentosUsuario.empty()) {
                        envolvente();
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda envolvente' para más informacion.\n";
                    }
                    }else if (comandoUsuario == "v_cercano") {
                    if (argumentosUsuario.size() == 3) {
                        int px=0;
                        int py=0;
                        int pz=0;
                        v_cercano(px, py, pz);
                    } else if (argumentosUsuario.empty()) {
                        int px;
                        int py;
                        int pz;
                        std::string nombreObjeto;
                        std::cout<<" Ingreselas posiciones x, y, z y el nombre del objeto: "<<std::endl;
                        std::cin>>px>>py>>pz>>nombreObjeto;
                        v_cercano(px, py, pz, nombreObjeto);
                    } else {
                        std::cout << "Error: Uso incorrecto. Use 'ayuda v_cercano' para más informacion." << std::endl;
                    }

                    } else if (comandoUsuario == "ruta_corta") {
                    if (argumentosUsuario.size() == 3) {
                        Vertice i1, i2;
                        std::string nombreObjeto = argumentosUsuario[2];
                        ruta_corta(i1, i2, nombreObjeto);
                    } else if (argumentosUsuario.empty()) {
                        Vertice i1, i2;
                        std::string nombreObjeto;
                        std::cout<<"Ingrese la posicion de los indices y el nombre del objeto"<<std::endl;
                        std::cin>>nombreObjeto;
                        ruta_corta(i1, i2, nombreObjeto);
                    } else {
                        std::cout << "Error: Uso incorrecto. Use 'ayuda ruta_corta' para más informacion." << std::endl;
                    }

                    } else if (comandoUsuario == "ruta_corta_centro") {
                    if (argumentosUsuario.size() == 2) {
                        Vertice i1;
                        std::string nombreObjeto = argumentosUsuario[1];
                        ruta_corta_centro(i1, nombreObjeto);
                    } else if (argumentosUsuario.empty()) {
                        Vertice i1;
                        std::string nombreObjeto;
                        ruta_corta_centro(i1, nombreObjeto);
                    } else {
                        std::cout << "Error: Uso incorrecto. Use 'ayuda ruta_corta_centro' para más informacion." << std::endl;
                    }

                    } else if (comandoUsuario == "v_cercanos_caja") {
                    if (argumentosUsuario.size() == 1) {
                        std::string nombreObjeto = argumentosUsuario[0];
                        v_cercanos_caja(nombreObjeto);
                    } else {
                        std::cout << "Error: Uso incorrecto. Use 'ayuda v_cercanos_caja' para más informacion." << std::endl;
                    }

                    } else {
                        std::cout<<"    ________________________________________________________________________________\n";
                        std::cout<<"    |                            Comando no reconocido.                            |\n";
                        std::cout<<"    |            Use 'ayuda' para ver la lista de comandos disponibles.            |\n";
                        std::cout<<"    |______________________________________________________________________________|\n";
                }
            }

    }catch(const std::runtime_error& e ){
            std::cout << "Error: " << e.what() << '\n';
    }
          return 0;
  }


   /*Función encargada de indicar la forma correcta de hacer el 
    llamado a un determinado comando que se pasa como parametro */
void ayuda(std::string comando) {
    
    if (comando == "cargar" || comando == "Cargar") {
        
        std::cout << "Uso: cargar nombreArchivo - Carga un archivo en memoria.\n";
        
    } else if (comando == "listado" || comando == "Listado") {
        
        std::cout << "Uso: listado - Muestra todos los objetos cargados en memoria.\n";
        
    } else if (comando == "descargar" || comando == "Descargar") {
        
        std::cout << "Uso: descargar nombreObjeto - Descarga un objeto de la memoria.\n";
        
    } else if (comando == "guardar" || comando == "Guardar") {
        
        std::cout << "Uso: guardar nombreObjeto nombreArchivo - Guarda un objeto en un archivo.\n";
        
    } else if (comando == "envolvente" || comando == "Envolvente") {
        
        std::cout << "Uso: envolvente - Calcula y agrega una caja envolvente global que incluye todos los objetos cargados en memoria.\n";
        
    } else if (comando == "v_cercano" || comando == "V_cercano") {
        
        std::cout << "Uso: v_cercano nombreObjeto px py pz - Identifica el vertice más cercano al punto (px, py, pz) en el objeto nombreObjeto.\n";
        
        std::cout << "Uso: v_cercano px py pz - Identifica el vertice más cercano al punto (px, py, pz) entre todos los objetos cargados en memoria.\n";
        
    } else if (comando == "v_cercanos_caja" || comando == "V_cercanos_caja") {
        
        std::cout << "Uso: v_cercanos_caja nombreObjeto - Identifica los vertices más cercanos a las esquinas de la caja envolvente del objeto nombreObjeto.\n";
        
    } else if (comando == "ruta_corta" || comando == "Ruta_corta") {
        
        std::cout << "Uso: ruta_corta i1 i2 nombreObjeto - Encuentra la ruta más corta entre dos vertices de un objeto.\n";
        
    } else if (comando == "ruta_corta_centro" || comando == "Ruta_corta_centro") {
        
        std::cout << "Uso: ruta_corta_centro i1 nombreObjeto - Encuentra la ruta mas corta entre un vertice y el centro del objeto.\n";
        
    } else {
        
        std::cout << "El comando no es identificado, por favor use 'ayuda' para ver la lista de comandos disponibles.\n";
    }
}

  /*Función encargada de indicar una lista de comandos disponibles en el momento*/
 void comandosDisponibles() {
     std::cout << "     _______________________________________________________________________________\n";
     std::cout << "    |                             COMANDOS DISPONIBLES                             |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  cargar nombreArchivo -> Carga un archivo en memoria.                        |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  listado -> Muestra todos los objetos cargados en memoria.                   |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  descargar nombreObjeto -> Descarga un objeto de la memoria.                 |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  guardar nombreObjeto nombreArchivo -> Guarda un objeto en un archivo.       |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  envolvente nombreObjeto -> Crea una envolvente para un objeto.              |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  envolvente -> Calcula y agrega una caja envolvente global que incluye       |\n";
     std::cout << "    |  todos los objetos cargados en memoria.                                      |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercano nombreObjeto -> Identifica el vertice mas cercano al punto.       |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ayuda comando -> Muestra informacion de ayuda sobre un comando especifico.  |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  salir -> Termina la ejecucion de la aplicacion.                             |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercano px py pz nombreObjeto -> Identifica el vertice mas               |\n";
     std::cout << "    |  cercano al punto (px, py, pz) en el objeto <nombreObjeto>                   |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercano px py pz -> Identifica el vertice más cercano al punto           |\n";
     std::cout << "    |  (px, py, pz) entre todos los objetos cargados en memoria.                   |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercanos_caja nombreObjeto -> Identifica los vertices mas cercanos a      |\n";
     std::cout << "    |  las esquinas de la caja envolvente del objeto <nombreObjeto>.               |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ruta_corta i1 i2 nombreObjeto -> Encuentra la ruta mas corta entre          |\n";
     std::cout << "    |  dos vertices de un objeto.                                                  |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ruta_corta_centro i1 nombreObjeto -> Encuentra la ruta mas corta entre      |\n";
     std::cout << "    |  un vertice y el centro del objeto.                                          |\n";
     std::cout << "    |______________________________________________________________________________|\n";
 }

  /*La función se encarga de cargar un objeto desde un archivo,
  //en este caso se propone el uso de funciones auxiliares para 
  //tener en cuenta los casos de error propuestos en el
  //enunciado del proyecto*/
  void cargarArchivo(std::string nombreArchivo, std::list<Objeto>& listadoObjetos){

    std::ifstream archivo(nombreArchivo);
    bool confirmacionObjeto;
    bool existenciaObjeto=false;

    if(!archivo.is_open()){
      std::cout<<"El archivo "<<nombreArchivo<< " no existe o es ilegible"<<std::endl;
      archivo.close();
    }else{
        confirmacionObjeto = verificacionObjeto(nombreArchivo, listadoObjetos);

        Objeto objetoAux;
        if(confirmacionObjeto == true){

              std::ifstream archivo(nombreArchivo);
              std::string linea;

              //SE OBTIENE EL NOMBRE DEL OBJETO
              if (std::getline(archivo, linea)) {
                  objetoAux.fijarNombreObjeto(linea);
                  std::cout<<"Se ha obtenido el nombre del objeto: "<<objetoAux.obtenerNombreObjeto()<<std::endl;
              }

                if(confirmacionObjeto == false){
                  std::cout<<"El objeto no es valido";

                }
                if(existenciaObjeto == true){
                    std::cout<<"El objeto ya existe en memoria"<<std::endl;
                }

              std::list<Objeto>::iterator iteradorObj;
              iteradorObj = listadoObjetos.begin();

              for(;iteradorObj!=listadoObjetos.end();iteradorObj++){
                  if(objetoAux.obtenerNombreObjeto() == iteradorObj->obtenerNombreObjeto()){
                      existenciaObjeto = true;
                      break;
                  }
              }

             if(existenciaObjeto == false){

                 //SE LEE EL NÚMERO DE VERTICES QUE CONFORMAN EL OBJETO
                   int n = 0;
                   if (std::getline(archivo, linea)) {
                       std::istringstream texto(linea);
                       texto>>n;
                       objetoAux.fijarCantidadVerticesObj(n);
                       std::cout<<"Se ha obtenido el numero de vertices del objeto: "<<n<<std::endl;
                   }
                 objetoAux.fijarCantidadVerticesObj(n);

                   //Se crea una lista de vértices temporal porque aún no se han definido las aristas en el archivo primero
                   //se insertan los vertices
                   std::vector<Vertice> verticesAux;
                   verticesAux.reserve(n);

                   //Se leen los vertices y se van metiendo en la lista de vértices temporal
                     for (int i = 0; i < n; ++i) {
                         if (std::getline(archivo, linea)) {
                             std::istringstream texto(linea);
                             unsigned int x, y, z;
                             texto>>x>>y>>z;

                             Vertice vertice;
                             vertice.fijarX(x);
                             vertice.fijarY(y);
                             vertice.fijarZ(z);
                             vertice.fijarIndiceVer(i);

                             verticesAux.push_back(vertice);
                         }
                     }

                 std::cout<<std::endl;

                 //IMPRESIÓN DE PRUEBA SI SE ESTÁN GUARDANDO CORRECTAMENTE LOS VERTICES
                 std::vector<Vertice>::iterator itVerAux = verticesAux.begin();
                 for(; itVerAux!=verticesAux.end(); itVerAux++){
                     std::cout<<"Index vertice: "<<itVerAux->obtenerIndiceVer()<<std::endl;
                     std::cout<<"X:"<<itVerAux->obtenerX()<<std::endl;
                     std::cout<<"Y:"<<itVerAux->obtenerY()<<std::endl;
                     std::cout<<"Z:"<<itVerAux->obtenerZ()<<std::endl;
                 }

                 int indiceCara = 0;
                   while (std::getline(archivo, linea)) {
                       std::istringstream iss(linea);
                       std::vector<unsigned int> indices;
                       unsigned int indice;

                       //Se van leyendo todos los índices correspondientes a los vertices
                       std::cout<<std::endl;
                       while (iss>>indice) {
                            if (indice < verticesAux.size()) {
                           indices.push_back(indice);
                           std::cout<<"Se ha ingresado el indice "<<indice<<" a la cara"<<std::endl;
                           }else{
                               std::cerr<<"Indice de vertice fuera de rango: "<<indice<<std::endl;
                               std::cout<<"No se ha agregado ninguna cara tras este mensaje"<<std::endl;
                           }
                       }

                       //Si se encuentra el -1 o no hay datos, se acaba el ciclo y por lo tanto
                       //la función
                       if (indices.empty() || indices[0] == static_cast<unsigned int>(-1)) {
                           break;  
                       }

                       //Se crea una cara temporal para ir asignándole los vértices
                       Cara cara;
                       cara.fijarCantidadVerticesCar(indices.size()/2);

                       std::list<Arista> aristas;

                       std::cout<<std::endl;

                       //Se crean aristas que van tomando las posicones de dos en 2
                       //Así agarrando las parejas correspondientes
                       for (size_t i=0; i<indices.size(); i+=2) {

                           //Se revisa que no se pase del límite del vector
                           //con tal de no tomar basura
                           if (i+1< indices.size()) { 
                               unsigned int indiceInicio = indices[i];
                               unsigned int indiceFin = indices[i+1];

                               //No se crean aristas si se encuentran con el mismo vertice según el indice
                               if (indiceInicio != indiceFin) {  
                                   Arista arista;
                                   //Se divide el indice como i va avanzando en 2 * 2
                                   arista.fijarIndiceAr(i/2); 
                                   arista.agregarVertice(verticesAux[indiceInicio]);
                                   arista.agregarVertice(verticesAux[indiceFin]);

                                   aristas.push_back(arista);

                                   std::cout<<"Se ha ingresado: "<<std::endl;
                                   arista.imprimirArista();
                               }
                           }
                       }
                       //Se terminan de asignar los datos a la cara del objeto
                       cara.fijarIndiceCar(indiceCara);
                       cara.fijarListaAristas(aristas);
                       objetoAux.agregarCara(cara);

                       indiceCara++;
                 }

                 listadoObjetos.push_back(objetoAux);
                 std::cout<<std::endl;
                 std::cout<<"El objeto "<<objetoAux.obtenerNombreObjeto()<<" ha sido cargado exitosamente desde el archivo " 
                 <<nombreArchivo<<std::endl;
             }

        archivo.close();

        }
    }
  }

  /*Función encargada de verificar si hay al menos un objeto en lo
  //que provisionalmente se supone que se guardan objetos en memoria
  //en un vector con fines prácticos. Además tiene la responsabilidad
  //de imprimir la información de los objetos que encuentre*/
  void listado(std::list<Objeto>& listadoObjetos) {
        
      if(listadoObjetos.size()==0) {
          std::cout<<"Ningun objeto ha sido cargado en memoria\n";
      }else{
          std::cout<<"Se encuentran "<<objetosPrograma.size()<<" objetos cargados en memoria:\n";
          imprimirListado(listadoObjetos);
      }
  }


  /*Función encargada de crear la envolvente de un objeto seleccionado, empleando comparación para saber si primero
  //existe el objeto, en el caso que no, se imprime un mensaje de error, en el caso que sí, se crea la envolvente*/
  // Función para calcular la caja envolvente de un objeto específico

void envolvente(std::string nombreObjeto) {    
    // Buscar el objeto en la lista
    Objeto objetoEnMemoria;
    bool objetoEncontrado = false;
    // Recorrer la lista de objetos
    for (std::list<Objeto>::iterator it = objetosPrograma.begin(); it != objetosPrograma.end(); ++it) {
        if (it->obtenerNombreObjeto() == nombreObjeto) {
            objetoEnMemoria = *it;
            objetoEncontrado = true;
            break;
        }
    }
    //No encontro el objeto en la lista
    if (!objetoEncontrado) {
        std::cout << "(Objeto no existe) El objeto " << nombreObjeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    //Se inicializa en un valor muy grande para que se pueda comparar con los demás
    float xmin = std::numeric_limits<float>::max();
    float xmax = -std::numeric_limits<float>::max();
    float ymin = std::numeric_limits<float>::max();
    float ymax = -std::numeric_limits<float>::max();
    float zmin = std::numeric_limits<float>::max();
    float zmax = -std::numeric_limits<float>::max();

    std::list<Cara> caras = objetoEnMemoria.obtenerCaras();//obtener las caras del objeto

    for (std::list<Cara>::iterator itCara = caras.begin(); itCara != caras.end(); itCara++) {//recorrer las caras del objeto

        std::list<Arista> aristas = itCara->obtenerListaAristas();//obtener las aristas de la cara

        for (std::list<Arista>::iterator itArista = aristas.begin(); itArista != aristas.end(); itArista++) {//recorrer las aristas de la cara

            std::list<Vertice> vertices = itArista->obtenerListaVertices();//obtener los vertices de la arista

            for (std::list<Vertice>::iterator itVertice = vertices.begin(); itVertice != vertices.end(); itVertice++) {//recorrer los vertices de la arista
                float x = static_cast<float>(itVertice->obtenerX());//obtener el valor de x del vertice
                float y = static_cast<float>(itVertice->obtenerY());//obtener el valor de y del vertice
                float z = static_cast<float>(itVertice->obtenerZ());//obtener el valor de z del vertice

                if (x < xmin){//se compara el valor de x con el valor minimo actual
                    xmin = x;
                } 
                if (x > xmax){//se compara el valor de x con el valor maximo actual
                    xmax = x;
                } 
                if (y < ymin){//se compara el valor de y con el valor minimo actual
                    ymin = y;
                } 
                if (y > ymax){//se compara el valor de y con el valor maximo actual
                    ymax = y;
                } 
                if (z < zmin){//se compara el valor de z con el valor minimo actual
                    zmin = z;
                } 
                if (z > zmax){//se compara el valor de z con el valor maximo actual
                    zmax = z;
                } 
            }
        }
    }

    // Crear un nuevo objeto para la caja envolvente
    Objeto cajaEnvolvente;
    std::string nuevoNombre = "env_" + nombreObjeto;

    cajaEnvolvente.fijarNombreObjeto(nuevoNombre);//Esto es para que el nombre del objeto sea el nombre del objeto mas el prefijo "env_"    

    // Definir los 8 vértices de la caja envolvente
    //En este punto todo estava bien
    std::vector<Vertice> verticesAux;
    verticesAux.reserve(8);
    Vertice v1, v2, v3, v4, v5, v6, v7, v8;
    //Primer vertice
    v1.fijarX(static_cast<unsigned int>(xmin));
    std::cout<<"__________________________________________";
    std::cout << "\n| Vertice 1:[ x = " << v1.obtenerX() << ", y = "; 
    v1.fijarY(static_cast<unsigned int>(ymin));
    std::cout<< v1.obtenerY() << ", " << "z = ";; 
    v1.fijarZ(static_cast<unsigned int>(zmin));
    std::cout << v1.obtenerZ() << "] " << "v1 |"<<std::endl; 
    v1.fijarIndiceVer(0);//v1
    verticesAux.push_back(v1);
    //--------------------------------------------
    //Segundo vertice
    v2.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 2:[ x = " << v2.obtenerX() << ", " << "y = "; 
    v2.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v2.obtenerY() << ", " << "z = "; 
    v2.fijarZ(static_cast<unsigned int>(zmin));
    std::cout  << v2.obtenerZ() << "] " << "v2 |"<<std::endl; 
    v2.fijarIndiceVer(1);//v2
    verticesAux.push_back(v2);
    //--------------------------------------------
    //Tercer vertice
    v3.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 3:[ x = " << v3.obtenerX() << ", " <<"y= ";
    v3.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v3.obtenerY() << ", " << "z= ";
    v3.fijarZ(static_cast<unsigned int>(zmin));
    std::cout << v3.obtenerZ() << "] " << " v3 |"<<std::endl;
    v3.fijarIndiceVer(2);//v3
    verticesAux.push_back(v3);
    //--------------------------------------------
    //Cuarto vertice
    v4.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 4:[ x = " << v4.obtenerX() << ", " <<"y = ";
    v4.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v4.obtenerY() << ", " << "z= ";
    v4.fijarZ(static_cast<unsigned int>(zmin)); 
    std::cout << v4.obtenerZ() << "] " << " v4 |"<<std::endl;
    v4.fijarIndiceVer(3);//v4
    verticesAux.push_back(v4);
    //--------------------------------------------
    //Quinto vertice
    v5.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 5:[ x = " << v5.obtenerX() << ", " <<"y = ";
    v5.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v5.obtenerY() << ", " << "z = ";
    v5.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v5.obtenerZ() << "] " << " v5 |"<<std::endl;
    v5.fijarIndiceVer(4);//v5
    verticesAux.push_back(v5);
    //--------------------------------------------
    //Sexto vertice
    v6.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 6:[ x = " << v6.obtenerX() << ", " <<"y = ";
    v6.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v6.obtenerY() << ", " << " z = ";
    v6.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v6.obtenerZ() << "] " << " v6 |"<<std::endl;
    v6.fijarIndiceVer(5);//v6
    verticesAux.push_back(v6);
    //--------------------------------------------
    //Septimo vertice
    v7.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 7:[ x = " << v7.obtenerX() << ", " <<"y = ";
    v7.fijarY(static_cast<unsigned int>(ymax)); 
    std::cout << v7.obtenerY() << ", " << "z = ";
    v7.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v7.obtenerZ() << "] " << " v7 |"<<std::endl;
    v7.fijarIndiceVer(6);//v7
    verticesAux.push_back(v7);
    //--------------------------------------------
    //Octavo vertice
    v8.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 8:[ x = " << v8.obtenerX() << ", " <<" y = ";
    v8.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v8.obtenerY() << ", " << "z = ";
    v8.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v8.obtenerZ() << "] " << " v8 |"<<std::endl;
    std::cout<<"_________________________________________"<<std::endl;
    v8.fijarIndiceVer(7);//v8
    verticesAux.push_back(v8);
    //--------------------------------------------
    std::vector<unsigned int> indices;
        indices.reserve(6); //Reservar espacio para evitar realineaciones innecesarias

        std::cout << std::endl;

        //Recorre los primeros 6 elementos o el tamaño de verticesAux si es menor
        for (size_t i = 0; i < std::min<size_t>(6, verticesAux.size()); ++i) {
            unsigned int indice = verticesAux[i].obtenerIndiceVer();

            if (indice < verticesAux.size()) {
                indices.push_back(indice);
                std::cout << "Se ha ingresado el indice " << indice << " a la cara" << std::endl;
            } else {
                std::cerr << "Indice de vertice fuera de rango: " << indice << std::endl;
                std::cout << "No se ha agregado ninguna cara tras este mensaje" << std::endl;
                return; // Salir de la función en caso de error
            }

            // Se encuentra el -1 o la lista está vacía, se acaba el ciclo
            if (indices.empty() || indices[0] == static_cast<unsigned int>(-1)) {
                return;
            }
        }

        // Se crea una cara temporal para ir asignándole los vértices
        Cara cara;
        cara.fijarCantidadVerticesCar(indices.size() / 2);

        std::list<Arista> aristas;
        std::cout << std::endl;

        // Se crean aristas tomando las posiciones de dos en dos
        for (size_t i = 0; i + 1 < indices.size(); i += 2) {
            unsigned int indiceInicio = indices[i];
            unsigned int indiceFin = indices[i + 1];

            // No se crean aristas si se encuentran con el mismo vértice según el índice
            if (indiceInicio != indiceFin) {
                Arista arista;
                arista.fijarIndiceAr(i / 2);
                arista.agregarVertice(verticesAux[indiceInicio]);
                arista.agregarVertice(verticesAux[indiceFin]);

                aristas.push_back(arista);

                std::cout<<"\nSe ha ingresado: "<<std::endl;
                arista.imprimirArista();
            }
        }

        // Se terminan de asignar los datos a la cara del objeto
        static int indiceCara = 0; // Variable estática para mantener el índice entre llamadas
        cara.fijarIndiceCar(indiceCara++);
        cara.fijarListaAristas(aristas);
        cajaEnvolvente.agregarCara(cara);
    


    // Agregar la caja envolvente a la lista de objetos en memoria
    objetosPrograma.push_back(cajaEnvolvente);
    std::cout<<"_____________________________________________________________________________"<<std::endl;
    std::cout << "\n(Resultado exitoso) La caja envolvente del objeto " << nombreObjeto << " se ha generado con el nombre " << nuevoNombre << " y se ha agregado a los objetos en memoria." << std::endl;
}

 /*Función encargada de crear la envolvente de todos los objetos que se encuentren en la lista,
 empleando comparación para saber si primero, existe el objeto, en el caso que no, se imprime un mensaje de error,
 en el caso que sí, se crea la envolvente*/
void envolvente() {

    if (objetosPrograma.empty()) {
        std::cout << "(Memoria vacia) Ningun objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    // Inicializar los límites de la caja envolvente
    float xmin = std::numeric_limits<float>::max();
    float xmax = -std::numeric_limits<float>::max();
    float ymin = std::numeric_limits<float>::max();
    float ymax = -std::numeric_limits<float>::max();
    float zmin = std::numeric_limits<float>::max();
    float zmax = -std::numeric_limits<float>::max();

    // Recorrer todos los objetos en memoria     
        for (std::list<Objeto>::iterator itObj = objetosPrograma.begin(); itObj != objetosPrograma.end(); itObj++) {

            std::list<Cara> caras = itObj->obtenerCaras();

            for (std::list<Cara>::iterator itCara = caras.begin(); itCara != caras.end(); itCara++) {//se recorre cada cara del objeto

                std::list<Arista> aristas = itCara->obtenerListaAristas();

                for (std::list<Arista>::iterator itArista = aristas.begin(); itArista != aristas.end(); itArista++) {//se recorre cada arista de la cara

                    std::list<Vertice> vertices = itArista->obtenerListaVertices();

                    for (std::list<Vertice>::iterator itVertice = vertices.begin(); itVertice != vertices.end(); itVertice++) {//se recorre cada vertice de la arista
                        float x = static_cast<float>(itVertice->obtenerX());//se obtiene el valor de x del vertice
                        float y = static_cast<float>(itVertice->obtenerY());//se obtiene el valor de y del vertice
                        float z = static_cast<float>(itVertice->obtenerZ());//se obtiene el valor de z del vertice

                        if (x < xmin){//se compara el valor de x con el valor minimo actual
                            xmin = x;
                        } 
                        if (x > xmax){//se compara el valor de x con el valor maximo actual
                            xmax = x;
                        } 
                        if (y < ymin){//se compara el valor de y con el valor minimo actual
                            ymin = y;
                        } 
                        if (y > ymax){//se compara el valor de y con el valor maximo actual
                            ymax = y;
                        } 
                        if (z < zmin){//se compara el valor de z con el valor minimo actual
                            zmin = z;
                        } 
                        if (z > zmax){//se compara el valor de z con el valor maximo actual
                            zmax = z;
                        } 
                    }
                }
            }
        }


    // Crear un nuevo objeto para la caja envolvente global
    Objeto cajaEnvolvente;
    std::string nuevoNombre = "env_global";
    cajaEnvolvente.fijarNombreObjeto(nuevoNombre);

    std::vector<Vertice> verticesAux;
    verticesAux.reserve(8);
    Vertice v1, v2, v3, v4, v5, v6, v7, v8;
    //Primer vertice
    v1.fijarX(static_cast<unsigned int>(xmin));
    std::cout<<"________________________________________";
    std::cout << "\n| Vertice 1:[ x = " << v1.obtenerX() << ", y = "; 
    v1.fijarY(static_cast<unsigned int>(ymin));
    std::cout<< v1.obtenerY() << ", " << "z = ";; 
    v1.fijarZ(static_cast<unsigned int>(zmin));
    std::cout << v1.obtenerZ() << "] " << "v1 |"<<std::endl; 
    v1.fijarIndiceVer(0);//v1
    verticesAux.push_back(v1);
    //--------------------------------------------
    //Segundo vertice
    v2.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 2:[ x = " << v2.obtenerX() << ", " << "y = "; 
    v2.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v2.obtenerY() << ", " << "z = "; 
    v2.fijarZ(static_cast<unsigned int>(zmin));
    std::cout  << v2.obtenerZ() << "] " << "v2 |"<<std::endl; 
    v2.fijarIndiceVer(1);//v2
    verticesAux.push_back(v2);
    //--------------------------------------------
    //Tercer vertice
    v3.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 3:[ x = " << v3.obtenerX() << ", " <<"y= ";
    v3.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v3.obtenerY() << ", " << "z= ";
    v3.fijarZ(static_cast<unsigned int>(zmin));
    std::cout << v3.obtenerZ() << "] " << " v3 |"<<std::endl;
    v3.fijarIndiceVer(2);//v3
    verticesAux.push_back(v3);
    //--------------------------------------------
    //Cuarto vertice
    v4.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 4:[ x = " << v4.obtenerX() << ", " <<"y = ";
    v4.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v4.obtenerY() << ", " << "z= ";
    v4.fijarZ(static_cast<unsigned int>(zmin)); 
    std::cout << v4.obtenerZ() << "] " << " v4 |"<<std::endl;
    v4.fijarIndiceVer(3);//v4
    verticesAux.push_back(v4);
    //--------------------------------------------
    //Quinto vertice
    v5.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 5:[ x = " << v5.obtenerX() << ", " <<"y = ";
    v5.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v5.obtenerY() << ", " << "z = ";
    v5.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v5.obtenerZ() << "] " << " v5 |"<<std::endl;
    v5.fijarIndiceVer(4);//v5
    verticesAux.push_back(v5);
    //--------------------------------------------
    //Sexto vertice
    v6.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 6:[ x = " << v6.obtenerX() << ", " <<"y = ";
    v6.fijarY(static_cast<unsigned int>(ymin));
    std::cout << v6.obtenerY() << ", " << " z = ";
    v6.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v6.obtenerZ() << "] " << " v6 |"<<std::endl;
    v6.fijarIndiceVer(5);//v6
    verticesAux.push_back(v6);
    //--------------------------------------------
    //Septimo vertice
    v7.fijarX(static_cast<unsigned int>(xmax));
    std::cout << "| Vertice 7:[ x = " << v7.obtenerX() << ", " <<"y = ";
    v7.fijarY(static_cast<unsigned int>(ymax)); 
    std::cout << v7.obtenerY() << ", " << "z = ";
    v7.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v7.obtenerZ() << "] " << " v7 |"<<std::endl;
    v7.fijarIndiceVer(6);//v7
    verticesAux.push_back(v7);
    //--------------------------------------------
    //Octavo vertice
    v8.fijarX(static_cast<unsigned int>(xmin));
    std::cout << "| Vertice 8:[ x = " << v8.obtenerX() << ", " <<" y = ";
    v8.fijarY(static_cast<unsigned int>(ymax));
    std::cout << v8.obtenerY() << ", " << "z = ";
    v8.fijarZ(static_cast<unsigned int>(zmax));
    std::cout << v8.obtenerZ() << "] " << " v8 |"<<std::endl;
    std::cout<<"________________________________________"<<std::endl;
    v8.fijarIndiceVer(7);//v8
    verticesAux.push_back(v8);
    //--------------------------------------------
    std::vector<unsigned int> indices;
        indices.reserve(6); // Reservar espacio para evitar realineaciones innecesarias

        std::cout << std::endl;

        // Recorre los primeros 6 elementos o el tamaño de verticesAux si es menor
        for (size_t i = 0; i < std::min<size_t>(6, verticesAux.size()); ++i) {
            unsigned int indice = verticesAux[i].obtenerIndiceVer();

            if (indice < verticesAux.size()) {
                indices.push_back(indice);
                std::cout << "Se ha ingresado el índice " << indice << " a la cara" << std::endl;
            } else {
                std::cerr << "Indice de vertice fuera de rango: " << indice << std::endl;
                std::cout << "No se ha agregado ninguna cara tras este mensaje" << std::endl;
                return; // Salir de la función en caso de error
            }

            // Se encuentra el -1 o la lista está vacía, se acaba el ciclo
            if (indices.empty() || indices[0] == static_cast<unsigned int>(-1)) {
                return;
            }
        }

        // Se crea una cara temporal para ir asignándole los vértices
        Cara cara;
        cara.fijarCantidadVerticesCar(indices.size() / 2);

        std::list<Arista> aristas;
        std::cout << std::endl;

        // Se crean aristas tomando las posiciones de dos en dos
        for (size_t i = 0; i + 1 < indices.size(); i += 2) {
            unsigned int indiceInicio = indices[i];
            unsigned int indiceFin = indices[i + 1];

            // No se crean aristas si se encuentran con el mismo vértice según el índice
            if (indiceInicio != indiceFin) {
                Arista arista;
                arista.fijarIndiceAr(i / 2);
                arista.agregarVertice(verticesAux[indiceInicio]);
                arista.agregarVertice(verticesAux[indiceFin]);

                aristas.push_back(arista);

                std::cout << "\nSe ha ingresado: " << std::endl;
                arista.imprimirArista();
            }
        }

        // Se terminan de asignar los datos a la cara del objeto
        static int indiceCara = 0; // Variable estática para mantener el índice entre llamadas
        cara.fijarIndiceCar(indiceCara++);
        cara.fijarListaAristas(aristas);
        cajaEnvolvente.agregarCara(cara);
    
    // Agregar la caja envolvente a la lista de objetos en memoria
    objetosPrograma.push_back(cajaEnvolvente);

    std::cout << "\n(Resultado exitoso) La caja envolvente de los objetos en memoria se ha generado con el nombre " << nuevoNombre << " y se ha agregado a los objetos en memoria." << std::endl;
}

  /*Función encargada de liberar el espacio en memoria correspondiente al objetodeseado por el usuario según
  //el nombre indicado*/
    void descargar(std::string nombreObjeto, std::list<Objeto>& listadoObjetos) {

        std::list<Objeto>::iterator iteradorBorrar;
        std::list<Objeto>::iterator iteradorBorrar2;
        iteradorBorrar = listadoObjetos.begin();
        
        bool confirmacion=false;

        for (; iteradorBorrar != listadoObjetos.end();) {
            
            if (iteradorBorrar->obtenerNombreObjeto() == nombreObjeto) {
                
                iteradorBorrar = listadoObjetos.erase(iteradorBorrar);
                std::cout<<"El objeto "<<nombreObjeto<<" ha sido eliminado de la memoria de trabajo"<<std::endl;
                confirmacion = true; 
                break; 
            } else {
                iteradorBorrar++;
            }
        }

        if (confirmacion==false) {
            std::cout<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria"<<std::endl;
        }
    }
    

  /*La función emplea formas estándares de abrir y cerrar archivos con lógica sin implementar para guardar un objeto,
  //valiéndose de una función la cual ayuda a encontrar el objeto en memoria que se quiere guardar*/
  void guardar(std::string nombreObjeto, std::string nombreArchivo, std::list<Objeto>& listadoObjetos){

    std::ofstream archivo(nombreArchivo.c_str());

    if(!archivo.is_open()){
      std::cout<<"El archivo no se pudo abrir";
        
    }else{
        std::list<Objeto>::iterator itGuardar;
        itGuardar = listadoObjetos.begin();
        bool confirmacion=false;
        Objeto objetoAux;

        for(;itGuardar!=listadoObjetos.end(); itGuardar++){
            if(nombreObjeto == itGuardar->obtenerNombreObjeto()){
                objetoAux = *(itGuardar);
                confirmacion=true;
                break;
            }

            }

        if(confirmacion==true){

            //Se escribe el nombre del objeto
            archivo<<objetoAux.obtenerNombreObjeto()<<std::endl;

            //Se escribe el número de vertices dentro del archivo
            archivo<<objetoAux.obtenerCantidadVerticesObj()<<std::endl;

            std::list<Cara> listaCarasObjetos = objetoAux.obtenerCaras();
            std::list<Cara>::iterator itCara = listaCarasObjetos.begin();
            std::vector<Vertice> listaVerticesAux;
            
            //Iterar sobre cada cara
            for (; itCara != listaCarasObjetos.end(); itCara++) {

                //Obtener las aristas de la cara
                std::list<Arista> listaAristasCaras = itCara->obtenerListaAristas();
                std::list<Arista>::iterator itAris = listaAristasCaras.begin();

                //Iterar sobre cada arista
                for (; itAris!=listaAristasCaras.end(); itAris++){

                    //Obtener los vértices de la arista
                    std::list<Vertice> listaVerticesAristas = itAris->obtenerListaVertices();
                    std::list<Vertice>::iterator itVer = listaVerticesAristas.begin();

                    //Iterar sobre cada vértice
                    for (; itVer != listaVerticesAristas.end(); itVer++) {

                        //Verificar si el vértice ya está en la lista auxiliar
                        bool verticeYaGuardado = false;
                        for (Vertice& vertice : listaVerticesAux) {
                            if (vertice.obtenerIndiceVer() == itVer->obtenerIndiceVer()) {
                                verticeYaGuardado = true;
                                break;
                            }
                        }

                        //Si el vértice no ha sido guardado, se agrega a la lista y se guarda en el archivo
                        if (!verticeYaGuardado) {
                            listaVerticesAux.push_back(*itVer);
                            archivo<<itVer->obtenerX()<<" "<<itVer->obtenerY()<<" "<<itVer->obtenerZ()<<std::endl;
                        }
                    }
                }
            }

            //Escribir las caras con los índices de los vértices correspondientes
            itCara = listaCarasObjetos.begin();
            for (; itCara != listaCarasObjetos.end(); itCara++) {

                std::list<Arista> listaAristasCaras = itCara->obtenerListaAristas();
                std::list<Arista>::iterator itAris = listaAristasCaras.begin();

                std::vector<unsigned int> indicesCaras;

                //Iterar sobre las aristas de la cara
                for (; itAris != listaAristasCaras.end(); itAris++) {
                    std::list<Vertice> listaVerticesAristas = itAris->obtenerListaVertices();
                    std::list<Vertice>::iterator itVer = listaVerticesAristas.begin();

                    //Escribir los índices de los vértices de la cara
                    for (; itVer != listaVerticesAristas.end(); itVer++) {
                        indicesCaras.push_back(itVer->obtenerIndiceVer());
                    }
                }

                std::vector<unsigned int>::iterator itIndex;
                itIndex = indicesCaras.begin();
                
                for (; itIndex != indicesCaras.end(); itIndex++) {
                    archivo<<*(itIndex)<<" ";
                }
                archivo<<std::endl;
            }

            //Se pone el -1 al final del objeto
            archivo << -1 << std::endl;
            std::cout<<"La informacion del objeto "<<nombreObjeto<<" ha sido guardada exitosamente en el archivo "<<nombreArchivo;
            archivo.close();
        }else{
            std::cout<<"El objeto "<<nombreObjeto<<" se encuentra en memoria";
        }
            
    }
      archivo.close();
  }
  

  void salir(){
    std::cout<<"\t\t\t\t\t\t\t¡Gracias por usar nuestro programa!";
    exit(0);                                 
  }
//////////////////////////////////COMPONENTE 2///////////////////////////////
void v_cercano(int px, int py, int pz, std::string nombreObjeto) {
    // Aqui faltaria colocar la logica para encontrar el objeto y  
    // cualcular el valor de la distancia (valor_distancia) 
    //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

  if (nombreObjeto!="") {
      std::cout<<"El vertice i ("<<"cordenada(vx,vy,vz)"<<") del objeto "<<nombreObjeto<<" es el mas cercano al punto ("<<px<<", "<<py<<", "<<pz<<"), a una distancia de: "<<"valor_distancia"<<std::endl;
  } else {
      std::cerr<<"El objeto "<<nombreObjeto<<" no ha sido encontrado en memoria"<<std::endl;
  }
}

void v_cercano(int px, int py, int pz) {
    // Aqui faltaria colocar la logica para encontrar el objeto y  
    // cualcular el valor de la distancia (valor_distancia) 

  bool exito=true;

  //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

  if (exito) {
      std::cout<<"El vertice i ("<<"cordenada(vx,vy,vz)"<<") del objeto "<<"nombreObjeto"<<" es el mas cercano al punto ("<<px<<", "<<py<<", "<<pz<<"), a una distancia de: "<<"valor_distancia"<<std::endl;
  } else {
      std::cerr<<"Ningun objeto ha sido cargado en memoria"<<std::endl;
  }
}

void v_cercanos_caja(std::string nombreObjeto) {
  // Aqui faltaria colocar la logica para encontrar el objeto

//si ya esta el objeto
  //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

  if (nombreObjeto!="") {
      std::cout<<"O Los vertices del objeto "<<nombreObjeto<<" mas cercanos a las esquinas de su caja envolvente son:"<<std::endl;
  } else {
      std::cerr<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria."<<std::endl;
  }
}



//////////////////////////////////COMPONENTE 3///////////////////////////////
void ruta_corta(Vertice i1, Vertice i2, std::string nombreObjeto) {
  // Aqui faltaria colocar la logica para encontrar el objeto y  
  // cualcular el valor de la distancia (valor_distancia) que conecta los vertices



  //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

  /* Verificar si los índices de los vértices son iguales
      if (i1 == i2) {
          std::cerr<<"Los índices de los vértices dados son iguales para el objeto "<<nombreObjeto<<std::endl;

      }*/
    
    //No me dejaba comparar los indices de los vertices, por lo que no se como hacerlo y deje comentariado. wazaaaaaa
    /*if(i1==i2){//indices iguales
        std::cout<<"Los índices de los vértices dados son iguales"<<std::endl;
    } else if(i1!=""&&i2!=""){//indices no existen
        std::cout<<"Algunos de los indices de vertices estan fuera de rango para el objeto "<<nombreObjeto<<std::endl;
    } else*/ if (nombreObjeto!="") {
      std::cout<<"La ruta mas corta que conecta los vertices "<<"(coordenada i1 del objeto)"<<" hasta "<<"(cordenada i2 del vertice)"<<" del objeto "<<nombreObjeto<<", pasa por:"<<"(co ordenada i1 , v1,v2,vn, i2..."<<" con una longitud de: "<<"valor_distancia"<<std::endl;
  } else {
      std::cerr<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria."<<std::endl;

  }
}


void ruta_corta_centro(Vertice i1, std::string nombreObjeto) {
  // Aqui faltaria colocar la logica para encontrar el objeto y  
  // cualcular el valor de la distancia (valor_distancia) que conecta los vertices



  //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

    //Verificacion si los indices estan dentro del objeto 
    // dentro de un if std::cerr<<" Algunos de los índices de vértices están fuera de rango para el objeto "<<nombreObjeto<<std::endl;

    //indice fuera del rango
    
  if (nombreObjeto!="") {
      std::cout<<"La ruta mas corta que conecta el vertice "<<"(cordenada del vertice i1)"<<" con el centro del objeto "<<nombreObjeto<<", ubicado en "<<"cordenada(ctx,cty,ctz)"<<", pasa por:"<<"cordenada i1, v1,v2,...ct"<<" con una longitud de "<<"valor_distancia"<< std::endl;
  }/*else if(i1.!=""){//indices no existen
      std::cout<<"El indice de vertice esta fuera de rango para el objeto "<<nombreObjeto<<std::endl;
  }*/ else {
      std::cerr<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria."<<std::endl;

  }
}

  /*Función de búsqueda auxiliar para encontrar un objeto tipo Objeto (malla) por medio de un ciclo for, si no encuentra nada,
  //se devuelve un objeto vacio*/
      Objeto encontrarObjeto(std::string nombreObjeto, std::list<Objeto>& listadoObjetos) {
          // Recorrer la lista usando un iterador
          for (auto it = listadoObjetos.begin(); it != listadoObjetos.end(); ++it) {
              if (it->obtenerNombreObjeto() == nombreObjeto) {
                  return *it;
              }
          }
          // Retornar un objeto vacío si no se encuentra el objeto buscado
          return Objeto();
      }


  /*Función auxiliar para la impresión de objetos encontrados //provisionalmente en un vector(con fines de interacción de usuario),
  //donde se emplea la biblioteca vector, suponiendo que hay un array //estático y no dinámico que contiene a todos los objetos tipo      //Objetocargados en memoria*/
  void imprimirListado(std::list<Objeto>& listadoObjetos){
      std::cout<<std::endl;

      std::list<Objeto>::iterator itListado;
      itListado = listadoObjetos.begin();

      for(;itListado!=listadoObjetos.end(); itListado++){
          std::cout<<"______________________________________"<<std::endl;
          itListado->imprimirObjeto();
          std::cout<<std::endl;
      }
  }

  /*Función auxiliar encargada de verificar si un objeto es válido
  //para ser cargado en memoria y trabajar con este en el programa*/
  bool verificacionObjeto(std::string nombreArchivo, std::list<Objeto>& listadoObjetos){
      std::ifstream archivo(nombreArchivo);
      
      if (!archivo.is_open()) {
          std::cout<< "El archivo "<<nombreArchivo <<"no se pudo abrir (Desde verificacion objeto)."<<std::endl;
          return false;
      }

      std::string linea;

      //Se valida que el titulo del objeto no tenga 
      //espacios en el primer renglón
      if (!std::getline(archivo, linea)) {
          std::cout<<"El archivo esta vacio (como mi corazon)"<<std::endl;
          return false;
      }
      
      if (linea.find(' ') != std::string::npos) {
          std::cout<<"El nombre del objeto tiene espacios"<<std::endl;
          return false;
      }

      //Revisar que está el número de vertices
      if (!std::getline(archivo, linea)) {
          std::cout<<"No existe el numero de vertices"<<std::endl;
          return false;
      }

      //Se revisa que realmente se esté ingrensando un número de vertices
      //que sea un entero positivo y que sea un número 
      int numVertices;
      std::istringstream entrada(linea);
      if (!(entrada>>numVertices) || numVertices<=0) {
          std::cout<<"El numero de vertices no es un numero o no es una entrada valida"<<std::endl;
          return false;
      }

      //Se valida que existan siempre las 3 coordenadas insertadas en los vertices
      for (int i=0; i<numVertices; i++) {
          if (!std::getline(archivo, linea)){
              //Se revisa primero que en la siguiente línea hayan vertices
              std::cout<<"No hay vertices en el archivo"<<std::endl;
              return false;
          }

          //Se va tomando cada línea y verificando que se encuentren todas las coordenadas
          std::istringstream lineaVertices(linea);
          int x, y, z;
          if (!(lineaVertices>>x>>y>>z)) {
              std::cout<<"Error: El renglon "<<i+3<<" no se tienen las coordenadas necesarias"<<std::endl;
              return false;
          }
      }

      //Se activa un booleando que nos indica si el
      //archivo termina en menos -1
      bool hayMenos1 = false;
      while(std::getline(archivo, linea)){
          //Nos vamos a la línea final en donde se toma el valor
          std::istringstream lineaFinal(linea);
          int valor;
          //En caso de que la línea sea de menos 1, se activa el booleano
          if(lineaFinal>>valor && valor==-1) {
              hayMenos1 = true;
              break;
          }
      }

      if (hayMenos1==false) {
          std::cout<<"El archivo no termina en -1"<<std::endl;
          return false;
      }

      std::cout<<"Los datos del objeto son validos"<<std::endl;
      return true;
  }

  