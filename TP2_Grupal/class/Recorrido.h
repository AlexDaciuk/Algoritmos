#ifndef _RECORRIDO_H_
#define _RECORRIDO_H_


/*
* Clase que define un recorrido de una llamada desde una central a otra
*/

#include "Lista.h"
#include "Enlace.h"

class Enlace;

class Recorrido
{

	unsigned int precio, centralLlegada;

	Lista<Enlace*>* enlacesRecorridos;


public:
	/*
	 *  Constructor de la clase, inicializa los atributos de precio a 32768 (reemplazo del infinito)
	 *  centralLlegada a 0 y crea una lista de enlaces vacia
	 */
	Recorrido();


	/*
	 * Metodo que define el precio del recorrido a algo mas bajo
	 */
	void definirPrecioRecorrido(unsigned int nuevoPrecio);


	/*
	 * Metodo que define la central de llegada del camino
	 */
	void definirCentralDeLlegada(unsigned int nuevaCentral);


	/*
	 * Metodo que agrega un enlace a los enlaces recorridos en el camino
	 */
	void agregarEnlaceRecorrido(Enlace* enlaceAAgregar);


	/*
	 * Metodos que devuelven atributos del recorrido
	 */
	int obtenerPrecioRecorrido();
	int obtenerCentralDeLlegada();
	Lista<Enlace*>* obtenerEnlacesRecorridos();


	/*
	 * Destrtructor. Libera la memoria de la lista de enlaces recorridos.
	*/
	~Recorrido();

};

#endif

