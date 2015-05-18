#ifndef CENTRAL_H_
#define CENTRAL_H_

#ifndef NULL
#define NULL 0
#endif

#include "Internos.h"
#include "Lista.h"
#include "Enlace.h"

/**
 * Clase que maneja cada central 
 */


class Central
{
private:
  
  int Central;
  
  Lista<Internos>* listaInternos;
  // Puntero a la lista de enlaces general
  Lista<Enlaces>* listaEnlaces;

public:

  /**
   * Constuctor de la clase
   * Post: Va a quedar creada el nodo en la lista de centrales 
   */
  
  Central(int numeroCentralTemporal);
  

  /**
   * Metodo que crea un interno dentro de la central, para usarse cuando entra una llamada de 
   * otra central y el interno en cuestion no existe
   */
  
  void crearInterno(int numeroCentral, int numeroInterno);
  

  /**
   * Metodo que devuelve el numero de la central
   */

  int obtenerNumero();
  
  /**
   * destructor de Central
   * */
  ~Central();


};



#endif
