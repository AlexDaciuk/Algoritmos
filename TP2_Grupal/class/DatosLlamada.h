#ifndef DATOSLLAMADA_H
#define DATOSLLAMADA_H
#ifndef NULL
#define NULL 0
#include <string>
#include <sstream>

/**
 * Clase que contiene atributos temporales de las llamadas
 * leidas por LectorArchivos y luego procesadas por
 * ProcesadorLlamadas
 */


class DatosLlamada
{
private:
  std::string accion;
  int centralA, internoA, centralB, internoB, horaInicio;
  

public:

  void cargarLlamada(std::string accionTemporal, std::string centralATemporal, std::string internoATemporal,
		     std::string centralBTemporal, std::string internoBTemporal, std::string horaInicioTemporal);

};

#endif
#endif
