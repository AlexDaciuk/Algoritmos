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
<<<<<<< HEAD
  Llamada* punteroASusLlammadas; //apunta siempre a la primer llamada
  Interno* internoSiguiente;
=======
  Llamada* punteroASusLlammadas;
>>>>>>> 680b1b9e02bdce04c73b3929c196972c9a066993
 public:

  /**
   * Constructor de la clase Interno
   * Post: Queda creado el interno con el numero asignado
   */
  
  Interno(int numeroInternoTmp);

  int obtenerNumeroInterno();

  Llamada* agregarLlamada();
  
  Lamada* obtenerPunteroASusLlamadas();
  
  bool internoOcupado();
};

#endif
