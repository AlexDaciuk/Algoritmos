#ifndef DATOSLLAMADA_H_
#define DATOSLLAMADA_H_

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
  int centralA, internoA, centralB, internoB, hora;
  

public:
  /**
   * Constructor
   * Inicializa los enteros en 0 y el string en un espacio
   */
  DatosLlamada();
  

  /**
   * Metodo que carga datos a los atributos, si ya tuviera datos, los sobre escribe
   * 
   */
  
  void cargarLlamada(std::string accionTemporal, std::string centralATemporal, std::string internoATemporal,
		     std::string centralBTemporal, std::string internoBTemporal, std::string horaInicioTemporal);

  /**
   * Metodos que devuelven los valores de los atributos de la clase
   */
  std::string obtenerAccion();

  int obtenerCentralA();
  int obtenerCentralB();
  
  int obtenerInternoA();
  int obtenerInternoB();

  int obtenerHora();
};

#endif
#endif
