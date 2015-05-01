#ifndef CENTRAL_H
#define CENTRAL_h

/**
 * Clase que maneja cada central 
 */


class Central
{
private:
  
  int numeroCentral;

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
  
  /**
   * Metodo que va a empezar una llamada entre 2 internos
   * Va a crear un interno si no existe, o los 2 en el caso que no existan los 2
   * Post: La llamada va a quedar registrada y en curso
   */
  void empezarLlamada(int numeroInterno, int numeroReceptorTmp, int centralReceptoraTmp, int horaInicioTmp);


  /**
   * Metodo que va a terminar una llamada
   * Post: La llamada va a terminarse y va a quedar registrado el tiempo en los internos
   */
  void cortarLlamada(int numeroInterno, int numeroReceptorTmp, int centralReceptoraTmp, int horaFinTmp);
  
   


};

#endif
