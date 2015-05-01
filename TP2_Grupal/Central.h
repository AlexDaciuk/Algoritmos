/**
 * Clase que maneja cada central 
 */


class Central
{
private:
  int numeroCentral;

  ListaEnlaces* listaEnlaces;

public:

  /**
   *Constuctor de la clase
   *Post: Va a quedar creada la central 
   */
  
  Central(int numeroCentralTmp);

  void agregarInterno(int numeroInterno);

  void empezarLlamada(int numeroInterno, int numeroReceptorTmp, int centralReceptoraTmp, int horaInicioTmp);

  void cortarLlamada(int numeroInterno, int numeroReceptorTmp, int centralReceptoraTmp, int horaFinTmp);

   


}
