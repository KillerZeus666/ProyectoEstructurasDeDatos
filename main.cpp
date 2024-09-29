//Proyecto Estructura de Datos
//Entrega 1
//Integrantes: Natalia Alexandra Jiménez Cañas - Miguel Ángel Laiton Ruiz - Katheryn Sofia Guasca Chavarro

///////////////////////////////////////////*IMPORTANCIA MÁXIMA DE LA ENTREGA 1*//////////////////////////////////////////////
//CAMBIAR TODOS LOS VECTORES POR LISTAS (AHORITA EL CÓDIGO NO ES FUNCIONAL POR ESE MOTIVO DE CAMBIO DE LAS CLASES////////////
//Gracias c:

  #include <iostream>
  #include <fstream>
  #include <sstream> //Librería para manipular cadenas de caracteres
  #include <string>
  #include <vector>
  #include "Objeto.h" // TAD objeto

  ///////////////////////////////////////////////COMPONENTE 1////////////////////////////////////////// 

  /*Funciones encargadas de subir un objeto a memoria,
  //en este caso, verificacionObjeto() y buscarObjeto()
  //son funciones complementarias*/
  void cargarArchivo(std::string nombreArchivo);
  bool verificacionObjeto(std::string nombreArchivo);
  bool localizarObjeto(std::string nombreArchivo);

  /*Funciones encargadas de listar los objetos presentes
  //en memoria, en este caso imprimirListado() es considerada
  //una función complementaria. Y se piensa desde que se sabe
  //cuantos objetos se tienen en memoria para facilidad del programa*/
  void listado(std::vector<Objeto>& listadoObjetos);
  void imprimirListado(std::vector<Objeto>& listadoObjetos);

  /*Funciones creadas con la intención de crear las envolventes correspondientes a un objeto
  //o a todos los objetos cargados en memoria*/
  void envolvente(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos);
  void envolvente(std::vector<Objeto>& listadoObjetos);

  /*Función encargada de liberar memoria de un objeto según su nombre*/
  int descargar(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos);

  /*Función la cual sirve para guardar un objeto definido en un archivo también definido por el usuario
  //teniendo en cuenta que se recorre el arraylist de los objetos que actualmente se encuentran en memoria*/
  void guardar(std::string nombreObjeto, std::string nombreArchivo, std::vector<Objeto>& listadoObjetos);
  Objeto encontrarObjeto(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos);

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


  int main() {
    try{
      std::cout << "    ________________________________________________________________________________" << std::endl;
      std::cout << "    |                        ¡Bienvenid@ a nuestro proyecto!                       |" << std::endl;
        
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
                        cargarArchivo(argumentosUsuario[0]);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda cargar' para más información.\n";
                    }
                    //Comando componente 1 (2/7)
                    } else if (comandoUsuario == "listado") {
                    //Salidas en pantalla error 
                    std::vector<Objeto> listadoObjetos; 
                    if(listadoObjetos.empty()){
                        std::cout << "(Memoria vacía) Ningún objeto ha sido cargado en memoria." << std::endl;
                    }else {
                        //Salida en pantalla resultadon exitoso 
                        std::cout << "(Resultado exitoso) Hay " << listadoObjetos.size() << " objetos en memoria:" << std::endl;
                        // ACA TENER DISPONIBLE LA LISTA DE OBJETOS y se imprimira lo siguiente:
                        // nombre_objeto_1 contiene n_1 vertices, a_1 aristas y c_1 caras.
                        listado(listadoObjetos);
                    }
                    //Comando componente (5/7)
                    } else if (comandoUsuario == "descargar") {
                    if (argumentosUsuario.size() == 1) {
                        std::vector<Objeto> listadoObjetos;  
                      // TODO TIENE Q ESTAR CARGADO EN MEMORIA
                        descargar(argumentosUsuario[0], listadoObjetos);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda descargar' para más información.\n";
                    }
                    } else if (comandoUsuario == "guardar") {
                    if (argumentosUsuario.size() == 2) {
                        std::vector<Objeto> listadoObjetos;  
                      //TODO TIENE QUE ESTAR CARGADO EN MEMORIA
                        guardar(argumentosUsuario[0], argumentosUsuario[1], listadoObjetos);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda guardar' para más información.\n";
                    }
                    } else if (comandoUsuario == "envolvente") {
                        std::vector<Objeto> listadoObjetos; 
                        //TODO DEBE ESTAR CARGADO EN MEMORIA
                    if (argumentosUsuario.size() == 1) {
                        envolvente(argumentosUsuario[0], listadoObjetos);
                    } else if (argumentosUsuario.empty()) {
                        envolvente(listadoObjetos);
                    } else {
                        std::cout<<"Error"<<std::endl;
                        std::cout << "Uso incorrecto, use 'ayuda envolvente' para más información.\n";
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
                        std::cout << "Error: Uso incorrecto. Use 'ayuda v_cercano' para mÃ¡s informaciÃ³n." << std::endl;
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
                        std::cout << "Error: Uso incorrecto. Use 'ayuda ruta_corta' para mÃ¡s informaciÃ³n." << std::endl;
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
                        std::cout << "Error: Uso incorrecto. Use 'ayuda ruta_corta_centro' para mÃ¡s informaciÃ³n." << std::endl;
                    }

                    } else if (comandoUsuario == "v_cercanos_caja") {
                    if (argumentosUsuario.size() == 1) {
                        std::string nombreObjeto = argumentosUsuario[0];
                        v_cercanos_caja(nombreObjeto);
                    } else {
                        std::cout << "Error: Uso incorrecto. Use 'ayuda v_cercanos_caja' para mÃ¡s informaciÃ³n." << std::endl;
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
        
        std::cout << "Uso: v_cercano nombreObjeto px py pz - Identifica el vértice más cercano al punto (px, py, pz) en el objeto nombreObjeto.\n";
        
        std::cout << "Uso: v_cercano px py pz - Identifica el vértice más cercano al punto (px, py, pz) entre todos los objetos cargados en memoria.\n";
        
    } else if (comando == "v_cercanos_caja" || comando == "V_cercanos_caja") {
        
        std::cout << "Uso: v_cercanos_caja nombreObjeto - Identifica los vértices más cercanos a las esquinas de la caja envolvente del objeto nombreObjeto.\n";
        
    } else if (comando == "ruta_corta" || comando == "Ruta_corta") {
        
        std::cout << "Uso: ruta_corta i1 i2 nombreObjeto - Encuentra la ruta más corta entre dos vértices de un objeto.\n";
        
    } else if (comando == "ruta_corta_centro" || comando == "Ruta_corta_centro") {
        
        std::cout << "Uso: ruta_corta_centro i1 nombreObjeto - Encuentra la ruta más corta entre un vértice y el centro del objeto.\n";
        
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
     std::cout << "    |  v_cercano nombreObjeto -> Identifica el vértice más cercano al punto.       |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ayuda comando -> Muestra información de ayuda sobre un comando específico.  |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  salir -> Termina la ejecución de la aplicación.                             |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercano px py pz nombreObjeto -> Identifica el vértice más                |\n";
     std::cout << "    |  cercano al punto (px, py, pz) en el objeto <nombreObjeto>                   |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercano px py pz -> Identifica el vértice más cercano al punto            |\n";
     std::cout << "    |  (px, py, pz) entre todos los objetos cargados en memoria.                   |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  v_cercanos_caja nombreObjeto -> Identifica los vértices más cercanos a      |\n";
     std::cout << "    |  las esquinas de la caja envolvente del objeto <nombreObjeto>.               |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ruta_corta i1 i2 nombreObjeto -> Encuentra la ruta más corta entre          |\n";
     std::cout << "    |  dos vértices de un objeto.                                                  |\n";
     std::cout << "    |                                                                              |\n";
     std::cout << "    |  ruta_corta_centro i1 nombreObjeto -> Encuentra la ruta más corta entre      |\n";
     std::cout << "    |  un vértice y el centro del objeto.                                          |\n";
     std::cout << "    |______________________________________________________________________________|\n";
 }

  /*La función se encarga de cargar un objeto desde un archivo,
  //en este caso se propone el uso de funciones auxiliares para 
  //tener en cuenta los casos de error propuestos en el
  //enunciado del proyecto*/
  void cargarArchivo(std::string nombreArchivo){

    std::ifstream archivo(nombreArchivo);
    bool confirmacionObjeto;
    bool existenciaObjeto;

    if(!archivo.is_open()){
      std::cout<<"El archivo "<<nombreArchivo<< " no existe o es ilegible"<<std::endl;
    }

    confirmacionObjeto = verificacionObjeto(nombreArchivo);
    existenciaObjeto = localizarObjeto(nombreArchivo);

    if(confirmacionObjeto == true && existenciaObjeto == false){
      //Lógica para cargar objeto
      std::cout<<"El objeto << nombreObjeto<<  ha sido cargado exitosamente desde el archivo" << nombreArchivo << std::endl;
    }
    if(confirmacionObjeto == false){
      std::cout<<"El objeto no es válido";
      std::cout<<"El objeto ya existe en memoria";
    }
    if(existenciaObjeto == true){
    }

    archivo.close();

  }

  /*Función encargada de verificar si hay al menos un objeto en lo
  //que provisionalmente se supone que se guardan objetos en memoria
  //en un vector con fines prácticos. Además tiene la responsabilidad
  //de imprimir la información de los objetos que encuentre*/
  void listado(std::vector<Objeto>& listadoObjetos) {
      if(listadoObjetos.size()==0) {
          std::cout<<"Ningún objeto ha sido cargado en memoria\n";
      }else{
          std::cout<<"Se encuentran "<<listadoObjetos.size()<<" objetos cargados en memoria:\n";
          imprimirListado(listadoObjetos);
      }
  }


  /*Función encargada de crear la envolvente de un objeto seleccionado, empleando comparación para saber si primero
  //existe el objeto, en el caso que no, se imprime un mensaje de error, en el caso que sí, se crea la envolvente*/
  void envolvente(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos){
      Objeto objetoBuscado = encontrarObjeto(nombreObjeto, listadoObjetos);
      if(objetoBuscado.obtenerNombreObjeto() == ""){
        std::cout<<"No se encuentra el objeto en memoria";
      }else{
        //LÓGICA PARA CREAR ENVOLVENTE DEL OBJETO SELECCIONADO
        std::cout<<"Se ha creado el envolvente del objeto seleccionado";
      }
  }

  void envolvente(std::vector<Objeto>& listadoObjetos){
    if(sizeof(listadoObjetos) == 0){
      std::cout<<"Ningun objeto ha sido cargado en memoria";
    }else{
      //LÓGICA PARA CREAR ENVOLVENTE DE TODOS LOS OBJETOS\
        //Usar la funcion anterior, pero con un for que recorra el vector de objetos y lo haga i veces (cant. objetos)
      std::cout<<" La caja envolvente de los objetos en memoria se ha generado con el nombre env_global y se ha agregado a los objetos en memoria.";
    }
  }

  /*Función encargada de liberar el espacio en memoria correspondiente al objetodeseado por el usuario según
  //el nombre indicado*/
  int descargar(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos){
      for(int i=0; i<listadoObjetos.size(); i++){
        if(listadoObjetos[i].obtenerNombreObjeto() == nombreObjeto){
          //Lógica para descargar objetos y toda su información relacionada
          std::cout<<"El objeto "<<nombreObjeto<<" ha sido eliminado de la memoria de trabajo"<<std::endl;
          return 0;
        }
      }
    std::cout<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria";
    return 1;
  }

  /*La función emplea formas estándares de abrir y cerrar archivos con lógica sin implementar para guardar un objeto,
  //valiéndose de una función la cual ayuda a encontrar el objeto en memoria que se quiere guardar*/
  void guardar(std::string nombreObjeto, std::string nombreArchivo, std::vector<Objeto>& listadoObjetos){

    std::ofstream archivo(nombreArchivo.c_str());

    if(!archivo.is_open()){
      std::cout<<"El archivo no se pudo abrir";
    }else{
      Objeto objetoGuardar = encontrarObjeto(nombreObjeto, listadoObjetos);
      //LÓGICA PARA GUARDAR EN EL ARCHIVO, EL OBJETO DESEADO
      std::cout<<"La informacion del objeto "<<nombreObjeto<<" ha sido guardada exitosamente en el archivo "<<nombreArchivo;
      archivo.close();
    }
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
      std::cout<<"El vertice i ("<<"cordenada(vx,vy,vz)"<<") del objeto "<<nombreObjeto<<" es el más cercano al punto ("<<px<<", "<<py<<", "<<pz<<"), a una distancia de: "<<"valor_distancia"<<std::endl;
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
      std::cout<<"El vertice i ("<<"cordenada(vx,vy,vz)"<<") del objeto "<<"nombreObjeto"<<" es el más cercano al punto ("<<px<<", "<<py<<", "<<pz<<"), a una distancia de: "<<"valor_distancia"<<std::endl;
  } else {
      std::cerr<<"Ningun objeto ha sido cargado en memoria"<<std::endl;
  }
}

void v_cercanos_caja(std::string nombreObjeto) {
  // Aqui faltaria colocar la logica para encontrar el objeto

//si ya esta el objeto
  //Implementación mensaje de exito o fracaso en dado caso que se encuentre el objeto

  if (nombreObjeto!="") {
      std::cout<<"O Los vertices del objeto "<<nombreObjeto<<" más cercanos a las esquinas de su caja envolvente son:"<<std::endl;
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
      std::cout<<"La ruta más corta que conecta los vertices "<<"(coordenada i1 del objeto)"<<" hasta "<<"(cordenada i2 del vertice)"<<" del objeto "<<nombreObjeto<<", pasa por:"<<"(co ordenada i1 , v1,v2,vn, i2..."<<" con una longitud de: "<<"valor_distancia"<<std::endl;
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
      std::cout<<"La ruta más corta que conecta el vertice "<<"(cordenada del vertice i1)"<<" con el centro del objeto "<<nombreObjeto<<", ubicado en "<<"cordenada(ctx,cty,ctz)"<<", pasa por:"<<"cordenada i1, v1,v2,...ct"<<" con una longitud de "<<"valor_distancia"<< std::endl;
  }/*else if(i1.!=""){//indices no existen
      std::cout<<"El indice de vertice esta fuera de rango para el objeto "<<nombreObjeto<<std::endl;
  }*/ else {
      std::cerr<<"El objeto "<<nombreObjeto<<" no ha sido cargado en memoria."<<std::endl;

  }
}

  /*Función de búsqueda auxiliar para encontrar un objeto tipo Objeto (malla) por medio de un ciclo for, si no encuentra nada,
  //se devuelve un objeto vacio*/
  Objeto encontrarObjeto(std::string nombreObjeto, std::vector<Objeto>& listadoObjetos){
    for(int i=0; i<listadoObjetos.size(); i++){
      if(listadoObjetos[i].obtenerNombreObjeto() == nombreObjeto){
        return listadoObjetos[i];
      }
    }
    return Objeto(); 
  }

  /*Función auxiliar para la impresión de objetos encontrados //provisionalmente en un vector(con fines de interacción de usuario),
  //donde se emplea la biblioteca vector, suponiendo que hay un array //estático y no dinámico que contiene a todos los objetos tipo      //Objetocargados en memoria*/
  void imprimirListado(std::vector<Objeto>& listadoObjetos){
      /*Lógica para imprimir el listado, la siguiente impresión es     
      //provisional*/
      std::cout<<"nombre_objeto_1, contiene n_1 vertices, a_1 aristas y c_1 caras";
  }

  /*Función auxiliar encargada de verificar si un objeto es válido
  //para ser cargado en memoria y trabajar con este en el programa*/
  bool verificacionObjeto(std::string nombreArchivo){
    //Lógica para verificar si el objeto es válido (puede ser leído)

    /*Por el momento, siempre se retornará true para verificar     
    funcionamiento del programa*/

    return true;
  }

  /*Función auxiliar encargada de verificar si el objeto que se intentó
  //cargar en la ejecución del programa, se encuentra o no ya subido en
  //memoria*/
  bool localizarObjeto(std::string nombreArchivo){
    //Lógica para buscar si el objeto ya existe en memoria

    /*Por el momento siempre se retornará false para verificar de que el
    objeto no está replicado en memoria*/

    return false;
  }
