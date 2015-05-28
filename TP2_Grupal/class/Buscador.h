#ifndef BUSCADOR_H_
#define BUSCADOR_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"
#include "Interno.h"
#include "Spot.h"
#include "Central.h"


/**
 * Esta clase se ocupará de encontrar el camino con la menor distacia
 * o con el precio mas bajo de una central a otra.
 * Modo de uso: Luego de crear el buscador, lo primero que se debe hacer es buscar el
 * camino, ya sea por precio o distancia, antes de pedirle cualquiera de las operaciones.
 */
class Spot;
 
class Buscador
{

private:

	/**
	 * Se guardara la lista de enlaces recorridos en la llamada.
	 */
	Lista<Enlace*>* mejorCamino;

	/**
	 * Esta lista la utiliza el buscador para ir recorriendo todos los caminos posibles para
	 * asegurarse de encontrar el mejor camino pedido.
	 */
	Lista<Spot*>* rutaActual;

	/**
	 * Es la lista de todas las centrales que existen.
	 */
	Lista<Central*>* centralesTotales;

	/**
	 * Pre: Debe ser mayor a 0 y entero porque es en centavos. Guardara el precio final
	 * de la llamada
	 */
	int precioDeLaLlamada;

	/**
	 * Pre:debe ser mayor a 0. Guardara la distancia final recorrida.
	 */
	int distanciaDeLaLlamada;

	/**
	 * El buscador aprovecha este atributo para saber si buscar por distancia o por precio.
	 */
	int tipoDeBusqueda;

public:

	/**
	 * Pre: se inicia una llamda entre un interno y otro de distintas centrales.
	 * Se le da una lista con todas las centrales disponibles.
	 */
	Buscador(Lista<Central*>* centrales);

	/**
	 * Post: te otorga la ruta de enlaces que encontro.
	 * Sera nula cuando la llamada fue interna de una central
	 */
	Lista<Enlace*>* obtenerRuta();

	/**
	 * Post: devuelve el precio de la llamada. De no haber hecho la busqueda devuelve 0
	 */
	int obtenerPrecioDeLaLlamada();

	/**
	 * Post: devuelve la distancia de la llamada. De no haber hecho la busqueda devuelve 0
	 */
	int obtenerDistanciaDeLaLlamada();

	/**
	 * Los siguientes metodos requieren de haber hecho la busqueda para que funcionen.
	 */
	Central* obtenerCentralEmisora();

	Central* obtenerCentralReceptora();

	Interno* obtenerInternoEmisor(int emisor);

	Interno* obtenerInternoReceptor(int receptor);

	/**
	 * Post: hace el algoritmo de busqueda por mejor precio
	 */
	void encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora);

	/**
	 * Post: hace el algoritmo de busqueda por mejor distancia
	 */
	void encontrarCaminoPordistancia(int centralEmisora, int centralReceptora);

	/**
	 * Post: libera la memoria de los spots usados y la lista del mejor camino
	 */
	~Buscador();

private:

	/**
	* Post: indica si ya visite a la central en el camino ya hecho
	*/
	bool YaPasePorLaCentral(Central* central);

	/**
	 * Post: indica si La llamada es entre dos numeros de la misma central
	 */
	bool esLlamadaInterna(int centralEmisora, int centralReceptora);

	Interno* encontrarInternoEnLa(Central* central, int numeroDeInterno);

	/**
	 * Fija el precio y distancia que encontro el Buscador.
	 */
	void definirEstePrecioYDistancia();

	/**
	 * Si hay mas caminos devuelve true, sino devuelve false
	 */
	bool hayMasCaminos();

	/**
	 * Desde una central inicia el algoritmo para moverse a otra. Si llego al final del camino guarda
	 * la informacion y establece el mejor camino, precio y distancia.
	 */
	void avanzarBusquedaDesde(Central* centralActual, int buscoMejorValor, int precioActual, int centralReceptora);

	/**
	 * Realiza los pasos necesarios para ir de una central a otra.
	 * En cada central se asegura de recorrer todos los enlaces posibles de recorrer.
	 */
	bool caminarEnlace(Central* centralActual, int centralReceptora);

	/**
	 * Avanza termina de usar un enlace para ir a la siguiente central acumulando el
	 * precio y la distancia del recorrido. Pero compara para ir por el
	 * precio mas barato
	 */
	void caminarPorPrecio(Enlace* enlaceActual, Spot* spotActual, int centralReceptora);

	/**
	 * Avanza termina de usar un enlace para ir a la siguiente central acumulando el
	 * precio y la distancia del recorrido. Pero compara para ir por la distancia mas corta.
	 */
	void caminarPorDistancia(Enlace* enlaceActual, Spot* spotActual, int centralReceptora);

	/**
	 * Define la lista de enlaces usados para llegar de una central a otra.
	 */
	Lista<Enlace*>* definirEstaRuta();

	/**
	 * Indica si la busqueda es por precio o distancia.
	 */
	int obtenerTipoDeBusqueda();

	/**
	 * Establece que la busqueda por precio.
	 */
	void establecerBusquedaPorPrecio();

	/**
	 * Establece la busqueda por distancia.
	 */
	void establecerBusquedaPorDistancia();

	/**
	 * Encuentra en la lista de centrales dada al buscador la central pedida.
	 * Pre: se debe ingresar el numero de la central.
	 * Post: devuelve un puntero a esa central.
	 */
	Central* encontrarLaCentral(int central);
};
#endif

