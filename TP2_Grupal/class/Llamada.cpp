#include "Llamada.h"
#include <iostream>

Llamada::Llamada (int receptorLlamadaTemporal)
{
	if ((receptorLlamadaTemporal > 0) && (receptorLlamadaTemporal <= 9999)) {
		this->cantidadLlamadasHechas = 0;
		this->cantidadLlamadasRecibidas = 0;
		this->duracionLlamadasHechas = 0;
		this->duracionLlamadasRecibidas = 0;
		this->cantidadOcupadosDados = 0;
		this->cantidadOcupadosRecibidos = 0;
		this->horaInicioLlamadaEnCurso =0;
		this->llamadasAnuladas = 0;
		this->receptorLlamada = receptorLlamadaTemporal;
		this->recorridoLlamada = new Lista<Enlace*>;
		this->precioPorMinuto = 0;
	}
}


void Llamada::empezarLlamadaEmisor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada, int precioPorMinuto)
{
	if (! fueAnulada) {
		this->cantidadLlamadasHechas++;
		this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
		this->recorridoLlamada = recorridoLlamadaTemporal;
		this->precioPorMinuto = precioPorMinuto;
	} else {
		this->horaInicioLlamadaEnCurso=0;
		this->llamadasAnuladas++;
	}
}


void Llamada::empezarLlamadaReceptor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada, int precioPorMinuto)
{
	if (! fueAnulada) {
		this->cantidadLlamadasRecibidas++;
		this->horaInicioLlamadaEnCurso = horaInicioLlamadaEnCursoTemporal;
		this->recorridoLlamada = recorridoLlamadaTemporal;
		this->precioPorMinuto = precioPorMinuto;
	} else {
		this->horaInicioLlamadaEnCurso = 0;
		this->llamadasAnuladas++;
	}
}


void Llamada::cortarLlamadaEmisor(int horaFinLlamadaEnCursoTemporal)
{
	if (this->horaInicioLlamadaEnCurso != 0) {
		this->costoLlamadas += (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso) * this->precioPorMinuto;
		this->duracionLlamadasHechas += (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso);
		this->horaInicioLlamadaEnCurso = 0;
	}
}


void Llamada::cortarLlamadaReceptor(int horaFinLlamadaEnCursoTemporal)
{
	if (this->horaInicioLlamadaEnCurso != 0) {
		this->duracionLlamadasRecibidas += (horaFinLlamadaEnCursoTemporal - this->horaInicioLlamadaEnCurso);
		this->horaInicioLlamadaEnCurso = 0;
	}
}


int Llamada::obtenerLlamadasAnuladas()
{
	return this->llamadasAnuladas;
}


int Llamada::obtenerReceptorLlamada()
{
	return this->receptorLlamada;
}


int Llamada::obtenerCantidadLlamadasRecibidas()
{
	return this->cantidadLlamadasRecibidas;
}


int Llamada::obtenerDuracionLlamadasRecibidas()
{
	return this->duracionLlamadasRecibidas;
}


int Llamada::obtenerDuracionLlamadasHechas()
{
	return this->duracionLlamadasHechas;
}


int Llamada::obtenerCantidadOcupadosDados()
{
	return this->cantidadOcupadosDados;
}


int Llamada::obtenerCantidadOcupadosRecibidos()
{
	return this->cantidadOcupadosRecibidos;
}


int Llamada::obtenerCantidadLlamadasHechas()
{
	return this->cantidadLlamadasHechas;
}


int Llamada::obtenerCostoLlamadas()
{
	return this->costoLlamadas;
}


Lista<Enlace*>* Llamada::obtenerRecorridoLlamada()
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


void Llamada::contarLlamadaAnulada()
{
	this->llamadasAnuladas++;
}


Llamada::~Llamada()
{
	delete(this->recorridoLlamada);
}
