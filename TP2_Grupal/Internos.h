#ifndef INTERNOS_H
#define INTERNOS_H
#include <iostream>


/**
 *Clase que define a cada interno de una central
 */

class Interno
{
private:
  int numeroInterno;
  

public:

  /**
   * Constructor de la clase Interno
   * Post: Queda creado el interno con el numero asignado
   */
  
  Interno(int numeroInternoTmp);

  int obtenerNumeroInterno();

  int agregarLlamada();


  




};

#endif
