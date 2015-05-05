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
