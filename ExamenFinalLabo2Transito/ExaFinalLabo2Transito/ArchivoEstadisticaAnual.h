#ifndef ARCHIVOESTADISTICAANUAL_H
#define ARCHIVOESTADISTICAANUAL_H


#include <iostream>
using namespace std;


class ArchivoEstadisticaAnual
{
    private:

        string nombre = "estadisticas.dat";
    public:


        void Guardar();
        void listar();


};

#endif // ARCHIVOESTADISTICAANUAL_H
