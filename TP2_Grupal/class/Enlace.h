#ifndef ENLACE_H
#define ENLACE_H
/**
 * Clase que define cada enlace entre 2 centrales
 */

class Enlace
{
private:
  int cantidadDeCanales, distanciaKm, costoPorMinuto, cantidadCanalesEnUso;
  Central* punteroCentralA, punteroCentralB;

public:

  /**
   * Constructor de la clase enlace
   * Post: Queda creado el enlace entre 2 centrales
   */
  
  Enlace(int centralATmp, int centralBTmp, int distanciaTmp, int cantidadEnlaceTmp);

  /**
   * Funciones varias que devuelven atributos del enlace
   * Post: se devuelve el dato del tipo correspondiente
   */

  int obtenerCentralA();
  int obtenerCentralB();
  int obtenerDistancia();
  int obtenerPrecio();
  int obtenerCantidadEnlacesEnUso();
  Central* obtenerPunteroCentralA();
  Central* obtenerPunteroCentralB();

};

#endif

  




}
