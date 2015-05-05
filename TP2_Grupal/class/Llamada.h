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

  void empezarLlamada(int horaInicioLlamadaEnCursoTmp);

  void terminarLlamada(int horaFinLlamadaEnCursoTmp);
  
  Llamada* obtenerPunteroProximaLlamada();
  
  void cambiarPunteroProximaLlamada(Llamada* nuevoPunteroALlamada);
  
  int obtenerHoraInicioLlamadaEnCurso();
  
  std::string obtenerReceptorLlamada();
  
  /*int obtenerDuracionLlamadas();
  
  int obtenerCantidadOcupadosDados();
  
  int obtenerCantidadOcupadosRecibidos();
  */
  
  
  

  
};

#endif
