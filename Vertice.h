
    class Vertice{
        private:
        unsigned int indiceVer;
        unsigned int x;
        unsigned int y;
        unsigned int z;
    
        public:
        unsigned int obtenerX();
        unsigned int obtenerY();
        unsigned int obtenerZ();
        unsigned int obtenerIndiceVer();

        void fijarX(unsigned int x);
        void fijarY(unsigned int y);
        void fijarZ(unsigned int z);
        void fijarIndiceVer(unsigned int index);

        void imprimirVertice();
        Vertice();
    };
    
    