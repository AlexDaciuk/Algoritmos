#ifndef LLAMADA_H
#define LLAMADA_H
class Llamada
{
private:

  int cantidadLlamadas, duracionLlamadas, cantidadOcupados, horaInicioLlamadaEnCurso;
  bool ocupado;
  
public:

  Llamada (int duracionLlamadaTmp);

  void empezarLlamada(int horaInicioLlamadaEnCursoTmp);

  void terminarLlamada(int horaFinLlamadaEnCursoTmp);

  
};

#endif
