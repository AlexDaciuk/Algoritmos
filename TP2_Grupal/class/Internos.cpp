#define NULL 0
#include "Llamada.h"
#include "Internos.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

Interno::Interno(int numeroInternoTmp)
{
  numeroInterno=numeroInternoTmp;
  punteroASusLlammadas= NULL;
};

int Interno::obtenerNumeroInterno()
{
  return numeroInterno;
};

Lamada* Interno::obtenerPunteroASusLlamadas();
{
	return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
	Llamada* buscarOcupado= Interno->obtenerPunteroASusLlamadas();
	int LlamadaEnCurso=0;
	
	while (LlamadaEnCurso=0) && (buscarOcupado != null)
	{
		LlamadaEnCurso=buscarOcupado->obtenerHoraInicioLlamadaEnCurso();
		buscarOcupado=buscarOcupado->obtenerPunteroProximaLlamada();
	}
	
	return (LlamadaEnCurso !=0);
};

void Interno::cambiarPunteroASusLlamadas(Llamada* nuevoPuntero)
{
	this->punteroAsusLlamadas=nuevoPuntero;
};

bool Interno::existeReceptor(string receptorLlamadaTmp)
{
	Llamada* buscarReceptor=Interno->obtenerPunteroASusLlamadas();
	string receptor="0";
	
	while (receptor != receptorLamadaTmp) && (buscarRecepor != null)
	{
		receptor=buscarReceptor->obtenerReceptorLlamada();
		buscarReceptor=buscarReceptor->obtenerPunteroProximaLlamada();
	}
	
	return (receptor=receptorLlamadaTmp);
};

void Interno::moverLlamadaAlFrente(string receptorLlamadaTmp);
{
	Llamada* llamadaAnterior=Interno->obtenerPunteroASusLlamadas();
	Llamada* llamadaAMover=llamadaAnterior->obtenerPunteroProximaLlamada() ;
	
	while (receptorLlamadaTmp != llamadaAMover->obtenerReceptorLlamada())
	{
		llamadaAnterior=llamadaAMover;
		llamadaAMover=llamadaAnterior->obtenerPunteroProximaLlamada();
	}
	llamadaAnterior->cambiarPunteroProximaLlamada(llamadaAMover->obtenerPunteroProximaLlamada());
	llamadaAMover->cambiarPunteroProximaLlamada(Interno->obtenerPunteroASusLlamadas());
	Interno->cambiarPunteroASusLlamadas(llamadaAMover);
};
	

void Interno::agregarLlamada(string receptorLlamadaTmp, int horaInicioLlamadaEnCursoTmp)
{
	if (! existeReceptor(receptorLlamadaTmp))
	{
		Llamada* nuevaLlamada= new Llamada (receptorLlamadaTmp);
		nuevallamada->cambiarPunteroProximaLlamada(Interno->obtenerPunteroASusLlamadas());
		interno->cambiarPunteroASusLlamadas(nuevaLlamada);
		delete nuevaLlamada;
	}
	else
	{
		//verifico que no sea el primer nodo
		if (this->punteroASusLlamadas->obtenerReceptorLlamada()!=receptorLlamadaTmp)
		{
			moverLlamadaAlFrente(receptorLlamadaTmp);
		{
	}
	//exista o no siempre va a quedar al frente 
	Interno->obtenerPunteroASusLlamadas()->empezarLlamada(horaInicioLlamadaEnCursoTmp);
};
	
	
	
	
	
	
	
	
	
	
	
