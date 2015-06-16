#ifndef INTERNOS_H_
#define INTERNOS_H_

#ifndef NULL
#define NULL 0
#endif

#include "Llamada.h"
#include "Lista.h"
#include "Enlace.h"

class Llamada;
class Enlace;


/**
 * Clase que define a cada interno de una central, que tiene una lista propia de llamadas
 * y un numero unico
 */
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
	 * Devuelve el numero del interno.
	 */
	int obtenerNumero();


	/**
	 * Agrega una nueva llamada a la lista de llamadas del interno que
	 * realiza la llamada y la ubica al principio de la lista.
	 * En el caso de que ya exista un nodo en la lista con el interno receptor se lleva
	 * ese nodo al principio y se suman
	 * los datos directamente ahi, no se crea ningun nodo.
	 */
	void agregarLlamadaEmisor(int receptorTemporal, int horaTemporal , int  centralReceptoraTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada, int precioPorMinuto);
	void agregarLlamadaReceptor(int emisorTemporal, int horaTemporal, int centralEmisoraTemporal , Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada, int precioPorMinuto);


	/**
	 * Termina la llamada del tipo de interno correspondiente
	 */
	void terminarLlamadaEmisor(int receptorTemporal,int horaTemporal);
	void terminarLlamadaReceptor(int emisorTemporal,int horaTemporal);


	/**
	 * Devuelve el puntero a la lista solicitada
	 */
	Lista<Llamada*>* obtenerLlamadas();
	Lista<Enlace*>* devolverRecorridoLlamada(int receptorLlamadaTemporal);


	/**
	 * Recorre la lista de llamadas del interno emisor y busca si ya existe un nodo
	 * con datos pertenecientes a interacciones con el interno receptor. En ese caso de no
	 * existir la llamada, la crea.
	 */
	Llamada* creaReceptorLlamada(int receptorLlamadaTemporal, int centralReceptoraTemporal);


	/**
	 * Recorre la lista de llamadas del interno y se fija si en algun nodo la hora
	 * de inicio de una llamada es distinto de cero. En ese caso devuelve verdadero,
	 * si no falso.
	 */
	bool internoOcupado();


	/**
	 * Contabiliza todas las llamadas aunladas de la lista de llamadas y devuelve el totoal.
	 */
	int contarLlamadasAnuladas(Lista<Llamada*>* listaLlamadas);
	
		/**
	 * Pre: debe esxistir la lista de punteros a llamadas.
	 * post: devuelve la sumatoria de todas las duraciones de llamadas de cada llamada en la lista del interno.
	 */
	int sumaDeDuracionDeLlamadas(Lista<Llamada*>* listaLlamadas);
	
		/**
	  * Pre: debe esxistir la lista de punteros a llamadas.
	  * post: devuelve la sumatoria de los gastos por llamadas del interno..
	  */
	int sumaDeGastos(Lista<Llamada*>* listaLlamadas);
	
		/**
	* Pre: debe esxistir la lista de punteros a llamadas.
	* post: devuelve la sumatoria de las cantidades de llamadas del interno..
	*/
	int sumaDeLlamadasEmitidas(Lista<Llamada*>* listaLlamadas);
	
		/**
	* Pre: debe esxistir la lista de punteros a llamadas.
	* post: devuelve la sumatoria de las cantidades dellamadas recibidas del interno..
	*/
	int sumaDeLlamadasRecibidas(Lista<Llamada*>* listaLlamadas);
	
		/**
	  * Pre: debe esxistir la lista de punteros a llamadas.
	  * post: devuelve la sumatoria de los ocupados dados de cada interno.
	  */
	int sumaDeOcupadosDados(Lista<Llamada*>* listaLlamadas);
	
		/**
	* Pre: debe esxistir la lista de punteros a llamadas.
	* post: devuelve la sumatoria de las cantidades de ocupados recibidos del interno..
	*/
	int sumaDeOcupadosRecibidos(Lista<Llamada*>* listaLlamadas);
	
		/**
	 * Pre: debe esxistir la lista de punteros a llamadas.
	 * post: devuelve la sumatoria de las duraciones de llamadas recibidas del interno.
	 */
	int sumaDuracionDeRecibidas(Lista<Llamada*>* listaLlamadas);



	/**
	 * Destructor que libera el espacio pedido para la lista de llamadas
	 */
	~Interno();

};

#endif
