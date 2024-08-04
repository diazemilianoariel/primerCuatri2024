#pragma once
#include <iostream>
#include <string>
#include "TipoInfraccion.h"

using namespace std;

/* 2) Crear un m�todo que permita guardar un registro de la clase TipoInfraccion en un
archivo llamado tiposinfracciones.dat. Crear otro m�todo que permita leer un
registro de la clase TipoInfraccion a partir de la posici�n en el archivo
tiposinfracciones.dat.*/

class ArchivoTipoInfraccion{
public:
	
	
	//metodos
	void guardarRegistro(TipoInfraccion reg);
	TipoInfraccion leerRegistro(int pos);
	void listarRegistros();

	int CantidadRegistros();
	

private:

	// aca va el nombre del archivo a crear y leer
	// nombre del archivo : tiposinfracciones.dat

	string ruta = "tiposinfracciones.dat";

	
};


