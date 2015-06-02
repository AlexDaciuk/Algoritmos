#include "Ordenar.h"


Ordenar::Ordenar ( int nombreNumerico,int valor)
{
	this->nombreNumerico=nombreNumerico;
	this->valorAOrdenar=valor;
}


int Ordenar::obtenerNombreNumerico()
{
	return(this->nombreNumerico);
}


int Ordenar::obtenerValorAOrdenar()
{
	return(this->valorAOrdenar);
}
