
#include <cstddef>
#include <string>
#include <iostream>
#include "Llamada.h"
using namespace std;

Llamada::Llamada (int receptorLlamadaTemporal)
{
	if (receptorLlamadaTemporal < 0 || receptorLlamadaTemporal > 9999)
	{
		throw string("Numero de interno fuera de rango");
	}
	this->cantidadLlamadas = 0;
	this->duracionLlamadas = 0;
	this->cantidadOcupadosDados = 0;
	this->cantidadOcupadosRecibidos = 0;
	this->horaInicioLlamadaEnCurso =0;
	this->receptorLlamada =receptorLlamadaTemporal;
  
  
};

void Llamada::empezarLlamada(int horaInicioLlamadaEnCursoTemporal)
{
  this->cantidadLlamadas++;
  this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
};

void Llamada::terminarLlamada (int horaFinLlamadaEnCursoTemporal)
{
  this->duracionLlamadas = (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso) + this-> duracionLlamadas;
  this->horaInicioLlamadaEnCurso = 0;
};

int Llamada::obtenerReceptorLlamada()
{
  return (receptorLlamada);
}; 

int Llamada::obtenerDuracionLlamadas()
{
  return this->duracionLlamadas;
};

int Llamada::obtenerCantidadOcupadosDados()
{
  return this->cantidadOcupadosDados;
};


int Llamada::obtenerCantidadOcupadosRecibidos()
{
  return this->cantidadOcupadosRecibidos;
};
