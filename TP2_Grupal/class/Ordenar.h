#ifndef ORDENAR_H
#define ORDENAR_H

/**
 * Objeto que se va a usar en el caso que sea necesario utilizar una lista
 * para ordenar obtjetos segun un valor.
 */
class Ordenar
{
  private:
  int nombreNumerico;
  int valorAOrdenar;

  public:
/**
 * Constructor de la case ordenar. Va a inicializar el objeto con su nombre (identificador)
 * y el valor a tener en cuenta para ordenar.
 * */
Ordenar ( int nombreNumerico, int valor);
/**
 *Devuelve el identificador del objeto. 
 */

int obtenerNombreNumerico();
/*
 * Devuelve el valor a tener en cuenta para ordenarlo.
 * */
int obtenerValorAOrdenar();

};
#endif