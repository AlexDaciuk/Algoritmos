
#include "Llamada.h"
#include "Internos.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

Interno::Interno(int numeroInternoTmp)
{
  numeroInterno=numeroInternoTmp;
  punteroASusLlamadas= null;
};

int Interno::obtenerNumeroInterno()
{
  return numeroInterno;
};

Llamada* Interno::obtenerPunteroASusLlamadas()
{
	return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
	Llamada* buscarOcupado=punteroASusLlamadas;
	int LlamadaEnCurso=0;
	
	while (LlamadaEnCurso=0 && buscarOcupado != null)
	{
		LlamadaEnCurso=buscarOcupado->obtenerHoraInicioLlamadaEnCurso();
		buscarOcupado=buscarOcupado->obtenerPunteroProximaLlamada();
	}
	
	return (LlamadaEnCurso !=0);
};

void Interno::cambiarPunteroASusLlamadas(Llamada* nuevoPuntero)
{
	this->punteroASusLlamadas=nuevoPuntero;
};

bool Interno::existeReceptor(string receptorLlamadaTmp)
{
	Llamada* buscarReceptor=punteroASusLlamadas;
	string receptor="0";
	
	while (receptor != receptorLlamadaTmp && buscarReceptor != null)
	{
		receptor=buscarReceptor->obtenerReceptorLlamada();
		buscarReceptor=buscarReceptor->obtenerPunteroProximaLlamada();
	}
	
	return (receptor==receptorLlamadaTmp);
};

void Interno::moverLlamadaAlFrente(string receptorLlamadaTmp)
{
	Llamada* llamadaAnterior=punteroASusLlamadas;
	Llamada* llamadaAMover=llamadaAnterior->obtenerPunteroProximaLlamada() ;
	
	while (receptorLlamadaTmp != llamadaAMover->obtenerReceptorLlamada())
	{
		llamadaAnterior=llamadaAMover;
		llamadaAMover=llamadaAnterior->obtenerPunteroProximaLlamada();
	}
	llamadaAnterior->cambiarPunteroProximaLlamada(llamadaAMover->obtenerPunteroProximaLlamada());
	llamadaAMover->cambiarPunteroProximaLlamada(punteroASusLlamadas);
	punteroASusLlamadas=llamadaAMover;
};
	

void Interno::agregarLlamada(string receptorLlamadaTmp, int horaInicioLlamadaEnCursoTmp)
{
	if (! existeReceptor(receptorLlamadaTmp))
	{
		Llamada* nuevaLlamada= new Llamada (receptorLlamadaTmp);
		nuevaLlamada->cambiarPunteroProximaLlamada(punteroASusLlamadas);
		punteroASusLlamadas=nuevaLlamada;
		delete nuevaLlamada;
	}
	else
	{
		//verifico que no sea el primer nodo
		if (this->punteroASusLlamadas->obtenerReceptorLlamada()!=receptorLlamadaTmp)
		{
			moverLlamadaAlFrente(receptorLlamadaTmp);
		}
	}
	//exista o no siempre va a quedar al frente 
	punteroASusLlamadas->empezarLlamada(horaInicioLlamadaEnCursoTmp);
}
	
	
	
	
	
	
	
	
	
	
	
