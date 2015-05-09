#ifndef LLAMADA_H
#define LLAMADA_H
#include <string>

class Llamada
{
private:

  std::string receptorLlamada;
  int  cantidadLlamadas, duracionLlamadas, cantidadOcupadosDados, cantidadOcupadosRecibidos,horaInicioLlamadaEnCurso;
  Llamada* punteroProximaLlamada;
  
public:

  /**
   * Constructor de la clase llamada
   * Post: La llamada queda registrada
   * Si el receptor no esta en el rango, se deja en 0 el receptor de la llamada
   */
  
  Llamada (std::string receptorLlamadaTmp);
  
  /*post: guarda la hora de comienzo de la llamada y aumeta el numero de 
   * llamadas en uno.*/
  void empezarLlamada(int horaInicioLlamadaEnCursoTmp);
  
  /*pre: la llamada debe haber comenzado antes.
   * post: calcula la duracion de la llamada y vuelve a poner el horario de inicio
   * en cero.*/
  void terminarLlamada(int horaFinLlamadaEnCursoTmp);
  
  /*post: devuelve el puntero a la proxima llamada de la lista.*/
  Llamada* obtenerPunteroProximaLlamada();
  
  /*post: cambia la direccion donde apunta el puntero de un respectivo nodo
   * de la lista de llamadas.*/
  void cambiarPunteroProximaLlamada(Llamada* nuevoPunteroALlamada);
  
  /*post: devuelve la hora de inicio de la llamada.*/
  int obtenerHoraInicioLlamadaEnCurso();
  
  /*post: devuelve a que receptor pertenece el nodo de la listas de llamdas
   * del interno.*/
  std::string obtenerReceptorLlamada();
  
  /*post: devuelve la duracion acumulada todas las llamadas efectuadas por el interno.*/
  int obtenerDuracionLlamadas();
  
  /*post: devuelve la cantidad total de ocupados dados por el interno.*/
  int obtenerCantidadOcupadosDados();
  
  /*post: devuelve la cantidad total de ocupados recibidos por el interno.*/
  int obtenerCantidadOcupadosRecibidos();
     
};

#endif
