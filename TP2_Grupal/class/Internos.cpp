#include "Internos.h"
#include <cstddef>
#include <iostream>
using namespace std;

Interno::Interno(int numeroInternoTmp)
{
  numeroInterno=numeroInternoTmp;
  //*punteroASusLlammadas=NULL;
  internoSiguiente=NULL;
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

//*Interno::agregarLlamada()
//*{
  //*
//*};
