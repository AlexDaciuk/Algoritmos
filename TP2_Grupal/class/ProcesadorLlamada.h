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
  
  void agregarCentralA(int numeroCentral);
  
  void agregarCentralB(int numeroCentral);
  
  buscaCentralMenorPrecio();

  buscaCentralMenorDistancia();

  void procesarLlamada(std:: rutaArchivoLlamadas);


};

#endif
#endif
