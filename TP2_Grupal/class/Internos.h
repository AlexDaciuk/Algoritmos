#ifndef INTERNOS_H
#define INTERNOS_H
#include "Llamada.h"
#include <iostream>
#include <cstddef> 
/**
 *Clase que define a cada interno de una central
 */

class Interno
{
 private:
  int numeroInterno;
  Llamada* punteroASusLlamadas; //apunta siempre a la primer llamada
  Interno* internoSiguiente;
  

 public:

  /**
   * Constructor de la clase Interno
   * Post: Queda creado el interno con el numero asignado
   */
  
  Interno(int numeroInternoTmp);

  int obtenerNumeroInterno();

  void agregarLlamada(std::string receptorLlamadaTmp, int horaInicioLlamadaEnCursoTmp);
  
  Llamada* obtenerPunteroASusLlamadas();
  
  void cambiarPunteroASusLlamadas(Llamada* nuevoPuntero);
  
  void moverLlamadaAlFrente(std::string receptorLlamadaTmp);
  
  bool existeReceptor(std::string receptor);
  
  bool internoOcupado();
};

#endif
