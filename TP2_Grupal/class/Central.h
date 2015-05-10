#ifndef CENTRAL_H
#define CENTRAL_H
#ifndef NULL
#define NULL 0


/**
 * Clase que maneja cada central 
 */


class Central
{
private:
  
  int Central;
  
  ListaInternos* listaInternos;
  // Puntero a la lista de enlaces general
  ListaEnlaces* listaEnlaces;

public:

  /**
   * Constuctor de la clase
   * Post: Va a quedar creada la central 
   */
  
  Central(int numeroCentralTmp);
  

  /**
   * Metodo que crea un interno dentro de la central, para usarse cuando entra una llamada de 
   * otra central y el interno en cuestion no existe
   */
  
  void crearInterno(int numeroInterno);
  
};

#endif
#endif
