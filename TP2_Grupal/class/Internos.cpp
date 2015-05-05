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

 Llamada* Interno::agregarLlamada()
{
  
};

Lamada* Interno::obtenerPunteroASusLlamadas();
{
	return this->punteroASusLlamadas;
};

bool Interno::internoOcupado()
{
	Llamada* buscarOcupado= Interno->obtenerPunteroASusLlamadas();
	int LlamadaEnCurso=0;
	
	while (LlamadaEnCurso=0 && buscarOcupado != null)
	{
		LlamadaEnCurso=buscarOcupado->obtenerHoraInicioLlamadaEnCurso();
		buscarOcupado=buscarOcupado->obtenerPunteroProximaLlamada();
	}
	
	return (LlamadaEnCurso !=0);
}
	
	
	
	
	
	
	
	
	
	
	
	
