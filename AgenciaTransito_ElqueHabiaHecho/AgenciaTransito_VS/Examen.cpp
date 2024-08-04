#include <iostream>
#include <string>
#include <cstdio>
#include "Examen.h"
#include "ArchivoTipoInfraccion.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"

using namespace std;




void Examen::Punto3(){
/*Hacer un método llamado Punto3 que solicite un ID Tipo de Infracción por
teclado. Luego verifique si el mismo existe en el archivo de tiposinfracciones.dat.
De existir, listar la cantidad de agentes distintos que hayan realizado al menos
una multa para este tipo de infracción. De lo contrario no mostrar nada.*/

	TipoInfraccion Tipoinf;
	ArchivoTipoInfraccion archivoTipoInf;

	Agente Agente;
	AgenteArchivo archivoAgente;

	Multa multa;
	MultaArchivo archivoMulta;



	int idTipoInfraccion;
	int CantTipoInfraccion = archivoTipoInf.CantidadRegistros();
	int CantAgentes = archivoAgente.getCantidadRegistros();
	int CantMultas = archivoAgente.getCantidadRegistros();

	cout << "Ingrese el ID del tipo de infraccion: ";
	cin >> idTipoInfraccion;

	int contador = 0; // este contador es para contar la cantidad de agentes distintos que hayan realizado al menos una multa para este tipo de infraccion

	for (int i = 0; i < CantTipoInfraccion; i++)
	{
		Tipoinf = archivoTipoInf.leerRegistro(i);




		for (int j = 0; j < CantAgentes; j++)
		{
			Agente = archivoAgente.leer(j);


			bool Bandera = false;
			for (int k = 0; k < CantMultas; k++)
			{
				multa = archivoMulta.leer(k);

				if (Agente.getIdAgente() == multa.getIDAgente() && multa.getTipoInfraccion() == idTipoInfraccion) {
					if(Bandera == false){
						contador++;
						Bandera = true;
					}
				

				}




			}

		}

	}

	cout << "La cantidad de agentes distintos que hayan realizado al menos una multa para este tipo de infraccion es: " << contador << endl;




}
