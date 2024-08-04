#ifndef MULTA_H
#define MULTA_H

#include <string>
#include "Fecha.h"

class Multa {
public:

  // constructor por defecto
  Multa();

  // constructor por parametro
  Multa(std::string patente, int idMulta, Fecha fechaMulta, float monto, int idAgente,
        int tipoInfraccion, int idLocalidad, bool pagada, bool eliminado);


  // getters
  std::string getPatente();
  int getIDMulta();
  Fecha getFechaMulta();
  float getMonto();
  int getIDAgente();
  int getTipoInfraccion();
  int getIDLocalidad();
  bool getPagada();
  bool getEliminado();



  //setter
  void setPatente(std::string patente);
  void setIDMulta(int idMulta);
  void setFechaMulta(Fecha fechaMulta);
  void setMonto(float monto);
  void setIDAgente(int idAgente);
  void setTipoInfraccion(int tipoInfraccion);
  void setIDLocalidad(int idLocalidad);
  void setPagada(bool pagada);
  void setEliminado(bool eliminado);

private:

    // atributos
  char _patente[10];
  int _idMulta;
  Fecha _fechaMulta;
  float _monto;
  int _idAgente;
  int _tipoInfraccion;
  int _idLocalidad;
  bool _pagada;
  bool _eliminado;
};

#endif
