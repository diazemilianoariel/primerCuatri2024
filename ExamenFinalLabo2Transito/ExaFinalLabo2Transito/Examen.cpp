#include "Examen.h"
#include "Multa.h"
#include "Agente.h"
#include "ArchivoAgente.h"
#include "ArchivoMulta.h"
#include <iomanip>  // Para std::fixed y std::setprecision

using namespace std;
#include <iostream>



 // constructor
Examen::Examen(){

}


void Examen::Punto1(){
    /*Definir una bonificaci�n anual para el a�o 2023 a partir de las multas labradas
por los agentes. Las condiciones de las bonificaci�n se detallan a continuaci�n:
Condici�n de bonificaci�n Bonificaci�n
Hasta 5 multas 10% del sueldo y 5% del total de multas
M�s de 5 multas y hasta 10 multas 20% del sueldo y 40% del total de
multas
M�s de 10 multas 100% del sueldo y 50% del total de
multas
Listar apellidos y nombres de los agentes, cantidad de multas realizadas y
bonificaci�n a otorgar. Solamente mostrar aquellos agentes que reciban
bonificaci�n*/

 AgenteArchivo AgeArchivo;
 Agente agente;
 int cantAgente = AgeArchivo.getCantidadRegistros();


 MultaArchivo mulArchivo;
 Multa multa;
 int CantMulta = mulArchivo.getCantidadRegistros();


    for(int i=0;i< cantAgente;i++){
        agente = AgeArchivo.leer(i);

        int contadorMultas = 0;
        float acumuladorMontoMultas = 0.0f;

        // Recorrer todas las multas para contar las del agente actual
        for(int j=0;j<CantMulta;j++){
            multa = mulArchivo.leer(j);

            if(multa.getIDAgente() == agente.getIdAgente()){
                contadorMultas++;
                acumuladorMontoMultas+= multa.getMonto();
            }


        }
        // Calcular la bonificaci�n
        float bonificacion = 0;
        if(contadorMultas >0){
            if(contadorMultas<=5){
                bonificacion = 0.1f * agente.getSueldo() + 0.05f * acumuladorMontoMultas;
            }
            else{
                if(contadorMultas<=10){
                    bonificacion = 0.2f * agente.getSueldo() + 0.40f * acumuladorMontoMultas;
                }
                else{
                    bonificacion =  1.0f * agente.getSueldo() + 0.50f * acumuladorMontoMultas;
                }
            // Mostrar la informaci�n del agente y su bonificaci�n
            cout << "-------------------------------" << endl;
            cout << "Agente: " << agente.getApellidos() << ", " << agente.getNombres() << endl;
            cout << "Cantidad de multas: " << contadorMultas << endl;
            cout << "Bonificacion: $" << bonificacion << endl;
            cout << "-------------------------------" << endl;

            }
        }
    }
}



void Examen::Punto2(){
/*Listar la cantidad de localidades que registren m�s multas pagadas que multas
no pagadas.*/

    MultaArchivo mulArchivo;
    Multa multa;
    int CantRegistro = mulArchivo.getCantidadRegistros();

    int localidadPaga=0;
    int localidadNoPaga =0;

    for(int i=0;i<CantRegistro;i++){
        multa = mulArchivo.leer(i);
        if(multa.getPagada()==true){
            localidadPaga++;
        }
        else{
            localidadNoPaga++;
        }

    }


    cout << "las ciudades que pagaron mas multas son: " << localidadPaga <<endl;
}



void Examen::Punto3(){
/*Generar un archivo con las estad�sticas anuales para cada uno de los a�os desde
el 2000 hasta el a�o actual. Cada registro debe tener: A�o, cantidad de multas
realizadas, recaudaci�n en concepto de multas y cantidad de multas que fueron
eliminadas.
Luego de generar el archivo. Listarlo en su totalidad.*/






}



