#pragma once
#include <iostream>


using namespace std;

/*Crear una clase llamada TipoInfraccion que permita registrar un Tipo de
Infracción. Debe poder registrar el ID de tipo de infracción, la descripción del tipo
de infracción,el costo base de la infracción y el nivel de severidad de la infracción.
Crear un constructor que reciba parámetros para cada atributo de la clase
Crear un constructor vacío para la clase que establezca 0 a los valores numéricos
y vacío a los de texto.
Crear setters y getters para cada atributo de la clase*/

class TipoInfraccion
{
public:
	// cosntructor con parametros 
	TipoInfraccion(int IdTIpo, string Desc, float CostoInf, int NivelInf);


	// constructor sin parametros
	TipoInfraccion();

	void mostrar();

	

	//setter
	void setIdTipoInfraccion( int TipoInf);
	void setDescripcion(string Desc);
	void setCostoInfraccion( float Costo);
	void setNivelInfraccion( int Nivel);

	//getter
	int getTipoInfraccion();
	string getDescripcion();
	float getCostoInfraccion();
	int getNivelInfraccion();


private:
	int IdTipoInfraccion;
	string Descripcion;
	float CostoInfraccion;  
	int NivelSeveridad; // nivel de severidad de 0 a 10, siendo 10 muy severo y 0 poco severo

};



