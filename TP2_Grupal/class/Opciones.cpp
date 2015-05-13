#include "Opciones.h"
#ifndef NULL
#define NULL 0

Opciones::Opciones(int numeroDeOpcion, std::string descripcion))
{
  this->numeroDeOpcion=numeroDeOpcion;
  this->descripcion=descripcion;
  //this->puntero a resolucion=NULL
};

int Opciones::obternerNumeroDeOpcion()
{
  return this->numeroDeOpcion;
};

void Opciones::cambiarNumeroDeOpcion(int nuevoNumero)
{
  this->numeroDeOpcion=nuevoNumero;
};

std::string Opciones::mostrarDescripcion()
{
  return this->descripcion;
};

void Opciones::cambiarDescripcion(std::string nuevaDescripcion){
{
  this->descripcion= nuevaDescripcion;
};

