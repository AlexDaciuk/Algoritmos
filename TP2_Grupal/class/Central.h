#ifndef CENTRAL_H_
#define CENTRAL_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Internos.h"
#include "Enlace.h"

/**
 * Clase que maneja cada central 
 */


class Central
{
private:
  
  int numeroCentral;
  
  Lista<Internos>* internos;
  // Puntero a la lista de enlaces general
  Lista<Enlaces>* enlaces;

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
  
  void crearInterno(int numeroInterno);

  /**
   * Metodo que devuelve el numero de la central
   */
  Interno* obtenerPunteroAInterno(int numeroInterno);


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
