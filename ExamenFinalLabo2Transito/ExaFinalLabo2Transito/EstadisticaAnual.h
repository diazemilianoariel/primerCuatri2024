#ifndef ESTADISTICAANUAL_H
#define ESTADISTICAANUAL_H
#include "Fecha.h"


/*Generar un archivo con las estad�sticas anuales para cada uno de los a�os desde
el 2000 hasta el a�o actual. Cada registro debe tener: A�o, cantidad de multas
realizadas, recaudaci�n en concepto de multas y cantidad de multas que fueron
eliminadas.
Luego de generar el archivo. Listarlo en su totalidad.*/

class EstadisticaAnual
{
    private:
        Fecha fecha;
        int CantMultas;
        float RecaudacionMultas;
        int MultasElimminadas;

    public:

        //setter
        void setFecha(Fecha f);
        void setCantMulta(int CMulta);
        void setRecMultas(float RM);
        void setMultasEliminadas(int ME);

        //getter
        Fecha getFecha();
        int getCantMulta();
        float getRecMultas();
        int getMultasEliminadas();

};

#endif // ESTADISTICAANUAL_H
