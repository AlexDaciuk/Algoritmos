#ifndef ENLACE_H
#define ENLACE_H
#ifndef NULL
#define NULL 0

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
  
  Enlace(int centralATemporal, int centralBTemporal, int distanciaTemporal, int cantidadEnlaceTemporal, int costoPorMinutoTemporal);

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

  /**
   * Metodos que van a cambiar la disponibilidad de cada enlace
   * ya sea agregando una llamada o eliminandola
   */
  void agregarLlamadaEnCurso();

  void eliminarLlamadaEnCurso();
  
};

#endif
#endif
  




