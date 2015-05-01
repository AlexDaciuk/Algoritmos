
class Llamada
{
private:

  int cantidadLlamadas, duracionLlamadas, cantidadOcupados, horaInicioLlamadaEnCurso;
  bool ocupado;
  
public:

  Llamada (int duracionLlamadaTmp);

  void empezarLlamada(int horaInicioLlamadaEnCursoTmp);

  void terminarLlamada(int horaFinLlamadaEnCursoTmp);

  
}
