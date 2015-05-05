#include "Llamada.h"
#include <cstddef>
#include <string>
#include <iostream>
#include "Llamada.h"
using namespace std;

Llamada::Llamada (std::string receptorLlamadaTmp)
{
	if (receptorLlamadaTmp < 0 || receptorLlamadaTmp > 9999)
	{
		throw string("Numero de interno fuera de rango");
	}
	
	this->cantidadLlamadas = 0;
	this->duracionLlamadas = 0;
	this->cantidadOcupadosDados = 0;
	this->cantidadOcupadosRecibidos = 0;
	this->horaInicioLlamadaEnCurso =0;
	this->ocupado = false;
	this->receptorLlamada = receptorLlamadaTmp;
	this->punteroProximaLlamada=null;
  
  
};

void Llamada::empezarLlamada(int horaInicioLlamadaEnCursoTmp)
{
  this->cantidadLlamadas++;
  this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTmp;
  this->ocupado = true;
};

void Llamada::terminarLlamada (int horaFinLlamadaEnCursoTmp)
{
  this->duracionLlamadas = horaFinLlamadaEnCursoTmp - this->horaInicioLlamadaEnCurso;
  this->ocupado = false;
  this->horaInicioLlamadaEnCurso = 0;
};

Llamada* Llamada::obtenerPunteroProximaLlamada();
{
	return this->punteroProximaLlamada;
};

void Llamada::cambiarPunteroProximaLlamada(Llamada* nuevoPunteroALlamada)
{
	this->punteroProximaLLamada=nuevoPunteroALlamada;
};
