#include "Llamada.h"
#include "Internos.h"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

Interno::Interno(int numeroInternoTmp)
{
  numeroInterno=numeroInternoTmp;
  punteroASusLlammadas=0;
  internoSiguiente=0;
};

int Interno::obtenerNumeroInterno()
{
  return numeroInterno;
};

void Interno::cambiarInternoSiguiente(Interno* nuevoSiguiente)
{
  internoSiguiente= nuevoSiguiente;
};

Interno* Interno::obtenerInternoSiguiente()
{
  return internoSiguiente;
};

 Llamada* Interno::agregarLlamada()
{
  
};
