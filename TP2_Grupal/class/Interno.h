#ifndef INTERNOS_H_
#define INTERNOS_H_

#ifndef NULL
#define NULL 0
#endif

#include "Llamada.h"
#include "Lista.h"
#include "Enlace.h"

/**
 *Clase que define a cada interno de una central
 */
class Llamada;
class Enlace;

class Interno
{
private:
	int numeroInterno;
	bool estaOcupado;
	Lista<Llamada*>* llamadas; //apunta siempre a la primer llamada

public:

	/**
	 * Constructor de la clase Interno
	 * Post: Queda creado el interno con el numero asignado
	 */
	Interno(int numeroInternoTemporal);

	/**
	 *post: devuelve el numero del interno.
	 */
	int obtenerNumero();

	/**
	 * post: agrega una nueva llamada a la lista de llamadas del interno que
	 * realiza la llamada y la ubica al principio de la lista.
	 * En el caso de que ya exista un nodo en la lista con el interno receptor se lleva
	 * ese nodo al principio y se suman
	 * los datos directamente ahi, no se crea ningun nodo.
	 */
	void agregarLlamadaEmisor(int receptorTemporal, int horaTemporal, Lista<Enlace*>* recorridoLlamadaTemporal);
	void agregarLlamadaReceptor(int emisorTemporal, int horaTemporal, Lista<Enlace*>* recorridoLlamadaTemporal);
	
	/**
	 * Termina la llamada entre 2 internos
	 */
	 
	void terminarLlamadaEmisor(int receptorTemporal,int horaTemporal, int precioMinutoTemporal);
	void terminarLlamadaReceptor(int emisorTemporal,int horaTemporal, int precioMinutoTemporal);

	/**
	 *post: devuelve el puntero a la lista de llamadas del interno
	 */

	Lista<Llamada*>* obtenerLlamadas();

	Lista<Enlace*>* devolverRecorridoLlamada(int receptorLlamadaTemporal);
	/**
	  *post: recorre la lista de llamadas del interno emisor y busca si ya existe un nodo
	  * con datos pertenecientes a interacciones con el interno receptor. En ese caso de no
	  * existir la llamada, la crea
	  */
	Llamada* creaReceptorLlamada(int receptorLlamadaTemporal);

	/**
	 *post: recorre la lista de llamadas del interno y se fija si en algun nodo la hora
	 * de inicio de una llamada es distinto de cero. En ese caso devuelve verdadero,
	 * si no falso.
	 */
	bool internoOcupado();
  /**
   * post: contabiliza todas las llamadas aunladas de la lista de llamadas y devuelve el totoal.
   * */
  int contarLlamadasAnuladas(Lista<Llamada*>* listaLlamadas);

};


#endif
