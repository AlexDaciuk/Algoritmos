#include "Llamada.h"

Llamada::Llamada (std::string receptorLlamadaTmp)
{
  this->cantidadLlamadas = 0;
  this->duracionLlamadas = 0;
  this->cantidadOcupadosDados = 0;
  this->cantidadOcupadosRecibidos = 0;
  this->horaInicioLlamadaEnCurso =0;
  this->ocupado = false;
  this->receptorLlamada = "0000";
  
  if (receptorLlamadaTmp > 0 && receptorLlamadaTmp < 10000)
    {
      this->receptorLlamada = receptorLlamadaTmp;
    }
}

Llamada::empezarLlamada(int horaInicioLlamadaEnCursoTmp)
{
  this->cantidadLlamadas++;
  this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTmp;
  this->ocupado = true;
}

Llamada::terminarLlamada (int horaFinLlamadaEnCursoTmp)
{
  this->duracionLlamadas = horaFinLlamadaEnCursoTmp - this->horaInicioLlamadaEnCurso;
  this->ocupado = false;
  this->horaInicioLlamadaEnCurso = 0;
}
