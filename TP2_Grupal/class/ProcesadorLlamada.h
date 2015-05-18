#ifndef PROCESADORLLAMADA_H
#define PROCESADORLLAMADA_H
#ifndef NULL
#define NULL 0

#include "DatosLlamada.h"
#include "Lista.h"
#include "Enlace.h"
#include "Central.h"
#include <string>

class ProcesadorLlamada
{
private:
  DatosLlamada* punteroDatosTemporal;
  DatosRecorrido* punteroRecorridoTemporal;
  Lista<Enlace>* punteroListaEnlaces;
  Lista<Central>* punteroListaCentrales;
  std::string rutaArchivosLlamadas;

public:
  /**
   * Se crea el procesador de llamadas con sus punteros apuntando a null
   * 
   * */
  ProcesadorLlamada();
  
  /** 
   * post:si no existe agrega la central a la lista de centrales y tambien les agrega
   * el interno a la lista de internos de la respectiva central
   * si ya existe la central no hace nada.
   * */
  void agregarCentralA(int numeroCentral);
  /** 
   * post:si no existe agrega la central a la lista de centrales 
   * si ya existe la central no hace nada.
   * */
  void agregarCentralB(int numeroCentral);
  
  DatosRecorrido* buscaCentralMenorPrecio();

  DatosRecorrido* buscaCentralMenorDistancia();
  
  /** 
   * Pre: la ruta donde se encuentra el archivo con los datos de llamadas debe existir.
   * Post: carga los datos de cada linea del txt de llamadas ya sea datos de enlaces como de inicio
   * y fin de llamadas
   * */
  void procesarLlamada(std::string rutaArchivoLlamadasTemporal);


  /** 
   * post:si no existe agrega la enlace a la lista de centrales 
   * si ya existe la enlace no hace nada.
   * */
  void agregarEnlace(int numeroCentralA, int numeroCentralB);


};

#endif
#endif
