#include "ArchivoTipoInfraccion.h"


void ArchivoTipoInfraccion::guardarRegistro(TipoInfraccion reg)
{
	/* Crear un método que permita guardar un registro de la clase TipoInfraccion en un
archivo llamado tiposinfracciones.dat.*/
	FILE* P = fopen(ruta.c_str(), "ab"); // abro el archivo en modo append binario

	if (P == nullptr) // si no se pudo abrir
	{
		return;
	}

	bool pudoEscribir = fwrite(&reg, sizeof(TipoInfraccion), 1, P); // escribo el registro en el archivo

	fclose(P); // cierro el archivo
}


TipoInfraccion ArchivoTipoInfraccion::leerRegistro(int pos)
{/*Crear otro método que permita leer un
registro de la clase TipoInfraccion a partir de la posición en el archivo
tiposinfracciones.dat*/
	FILE* P = fopen(ruta.c_str(), "rb"); // abro el archivo en modo lectura binario
	if (P == nullptr) // si no se pudo abrir
	{
		return TipoInfraccion(); // devuelvo un registro vacio
	}

	TipoInfraccion aux; // creo un registro auxiliar
	fseek(P, pos * sizeof(TipoInfraccion), SEEK_SET); // me posiciono en la posicion indicada
	fread(&aux, sizeof(TipoInfraccion), 1, P); // leo el registro

	fclose(P); // cierro el archivo

	return aux; // devuelvo el registro leido

}

void ArchivoTipoInfraccion::listarRegistros()
{
	/*Crear un método que permita listar todos los registros de la clase TipoInfraccio*/
	FILE* P = fopen(ruta.c_str(), "rb"); // abro el archivo en modo lectura binario
	if (P == nullptr) // si no se pudo abrir
	{
		return;
	}

	TipoInfraccion aux; // creo un registro auxiliar

	while (fread(&aux, sizeof(TipoInfraccion), 1, P) > 0) // mientras pueda leer registros
	{
		aux.mostrar(); // muestro el registro
	}




}

int ArchivoTipoInfraccion::CantidadRegistros()
{
 // metodo que devuelve la cantidad de registro que hay en el archivo tiposinfracciones.dat
	FILE* P = fopen(ruta.c_str(), "rb"); // abro el archivo en modo lectura binario
	if (P == nullptr) // si no se pudo abrir
	{
		return 0;
	}

	fseek(P, 0, SEEK_END); // me posiciono al final del archivo

	int cant = ftell(P) / sizeof(TipoInfraccion); // obtengo la cantidad de registros

	fclose(P); // cierro el archivo

	return cant; // devuelvo la cantidad de registros
}

