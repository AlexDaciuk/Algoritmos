#ifndef LLAMADA_H_
#define LLAMADA_H_


#include "Llamada.h"



Llamada::Llamada (int receptorLlamadaTemporal)
{
	if (receptorLlamadaTemporal > 0 && receptorLlamadaTemporal =< 9999) {
		this->cantidadLlamadas = 0;
		this->duracionLlamadas = 0;
		this->cantidadOcupadosDados = 0;
		this->cantidadOcupadosRecibidos = 0;
		this->horaInicioLlamadaEnCurso =0;
		this->receptorLlamada = receptorLlamadaTemporal;
	}

}

void Llamada::empezarLlamada(int horaInicioLlamadaEnCursoTemporal)
{
	this->cantidadLlamadas++;
	this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
}

void Llamada::terminarLlamada (int horaFinLlamadaEnCursoTemporal)
{
	this->duracionLlamadas = (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso) + this-> duracionLlamadas;
	this->horaInicioLlamadaEnCurso = 0;
}

int Llamada::obtenerReceptorLlamada()
{
	return this->receptorLlamada;
}

int Llamada::obtenerDuracionLlamadas()
{
	return this->duracionLlamadas;
}

int Llamada::obtenerCantidadOcupadosDados()
{
	return this->cantidadOcupadosDados;
}


int Llamada::obtenerCantidadOcupadosRecibidos()
{
	return this->cantidadOcupadosRecibidos;
}

int Llamada::obtenerCantidadLlamadas()
{
	return this->cantidadLlamadas;
}

void Llamada::agregarOcupadoRecibido()
{
	this->cantidadOcupadosRecibidos++;
}

void Llamada::agregarOcupadoDado()
{
	this->cantidadOcupadosDados++;
}


#endif
