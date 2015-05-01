#ifndef LLAMADA_H
#define LLAMADA_H
class Llamada
{
private:

  int receptorLlamada, cantidadLlamadas, duracionLlamadas, cantidadOcupadosDados, cantidadOcupadosRecibidos, horaInicioLlamadaEnCurso;
  bool ocupado;
  
public:

  /**
   * Constructor de la clase llamada
   * Post: La llamada queda registrada
   */
  
  Llamada ();

  void empezarLlamada(int horaInicioLlamadaEnCursoTmp);

  void terminarLlamada(int horaFinLlamadaEnCursoTmp);

  
};

#endif
