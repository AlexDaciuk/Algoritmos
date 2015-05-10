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
  std::string accion, centralA, internoA, centralB, internoB;
  int horaInicio;


public:

  void cargarLlamada(std::string accionTmp, std::string centralATmp, std::string internoATmp, std::string centralBTmp, std::string internoBTmp, std::string horaInicioTmp);

};

#endif
#endif
