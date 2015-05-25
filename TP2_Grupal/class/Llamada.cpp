#ifndef LLAMADA_H_
#define LLAMADA_H_

#include "Llamada.h"

Llamada::Llamada (int receptorLlamadaTemporal)
{
	if (receptorLlamadaTemporal > 0 && receptorLlamadaTemporal =< 9999) {
		this->cantidadLlamadasHechas = 0;
		this->cantidadLlamadasRecibidas = 0;
		this->duracionLlamadas = 0;
		this->cantidadOcupadosDados = 0;
		this->cantidadOcupadosRecibidos = 0;
		this->horaInicioLlamadaEnCurso =0;
		this->receptorLlamada = receptorLlamadaTemporal;
		this->recorridoLlamada = NULL;
	}
}

void Llamada::empezarLlamadaEmisor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal)
{
	this->cantidadLlamadasHechas++;
	this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
	this->recorridoLlamada = recorridoLlamadaTemporal;
}

void Llamada::empezarLlamadaReceptor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal)
{
	this->cantidadLlamadasRecibidas++;
	this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
	this->recorridoLlamada = recorridoLlamadaTemporal;
}

void Llamada::terminarLlamada (int horaFinLlamadaEnCursoTemporal)
{
	this->duracionLlamadas = (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso) + this-> duracionLlamadas;
	this->horaInicioLlamadaEnCurso = 0;
	this->recorridoLlamada = NULL;
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

int Llamada::obtenerCostoLlamadas()
{
	return this->costoLlamadas;
}

Lista<Enlace*>* obtenerRecorridoLlamada()
{
	return this->recorridoLlamada;
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
