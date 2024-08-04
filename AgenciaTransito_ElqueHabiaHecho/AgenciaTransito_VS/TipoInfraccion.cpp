#include "TipoInfraccion.h"
#include <iostream>
using namespace std;


// constructor con parametros 
TipoInfraccion::TipoInfraccion(int IdTipo, string Desc, float CostoInf, int NivelInf)
{
	IdTipoInfraccion = IdTipo;
	Descripcion = Desc;
	CostoInfraccion = CostoInf;
	NivelSeveridad = NivelInf;
}

// constructor sin paramentros 
TipoInfraccion::TipoInfraccion()
{
	IdTipoInfraccion = 0;
	Descripcion = "";
	CostoInfraccion = 0;
	NivelSeveridad = 0;
}

void TipoInfraccion::mostrar()
{
	cout << "ID Tipo de Infraccion: " << IdTipoInfraccion << endl;
	cout << "Descripcion: " << Descripcion << endl;
	cout << "Costo de la Infraccion: " << CostoInfraccion << endl;
	cout << "Nivel de Severidad: " << NivelSeveridad << endl;
	cout << endl;
}



//setter
void TipoInfraccion::setIdTipoInfraccion( int IdTipoInf ){IdTipoInfraccion = IdTipoInf;}
void TipoInfraccion::setDescripcion( string  Desc){Descripcion = Desc;}
void TipoInfraccion::setCostoInfraccion( float Costo){CostoInfraccion = Costo;}
void TipoInfraccion::setNivelInfraccion(int Nivel ){NivelSeveridad = Nivel;}

//getter
int TipoInfraccion::getTipoInfraccion(){return IdTipoInfraccion;}
string TipoInfraccion::getDescripcion(){return Descripcion;}
float TipoInfraccion::getCostoInfraccion(){return CostoInfraccion;}
int TipoInfraccion::getNivelInfraccion(){return NivelSeveridad;}

