#ifndef PROCESADORLLAMADA_H
#define PROCESADORLLAMADA_H
#ifndef NULL
#define NULL 0



class ProcesadorLlamada
{
private:
  DatosLlamada* punteroDatosTemporal;
  DatosRecorrido* punteroRecorridoTemporal;
  Lista<Enlace>* punteroEnlaces;
  Lista<Central>* punteroCentrales;


public:

  ProcesadorLlamada();
  
  /** 
   * post:si no existe agrega la central a la lista de centrales y tambien les agrega
   * el interno a la lista de internos de la respectiva central
   * si ya existe la central no hace nada.
   * */
  void agregarCentralA(int numeroCentral);
  /** 
   * post:si no existe agrega la central a la lista de centrales y tambien les agrega
   * el interno a la lista de internos de la respectiva central.
   * si ya existe la central no hace nada.
   * */
  void agregarCentralB(int numeroCentral);
  
  buscaCentralMenorPrecio();

  buscaCentralMenorDistancia();

  void procesarLlamada(std:: rutaArchivoLlamadas);


};

#endif
#endif
