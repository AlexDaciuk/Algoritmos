
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
	 * de la llamada.
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

	/**
	 * El buscador aprovecha este atributo para informar si la llamada no pudo llegar a destino
	 * por saturacion delos enlaces.
	 */
	bool llamadaAnulada;


public:

	/**
	 * Pre: se inicia una llamda entre un interno y otro de distintas centrales.
	 * Se le da una lista con todas las centrales disponibles.
	 */
	Buscador(Lista<Central*>* centrales);

	/**
	 * Post: te otorga la ruta de enlaces que encontro.
	 * Sera nula cuando la llamada fue interna de una central o en el caso de que se hayan
	 * saturado los enlaces.
	 */
	Lista<Enlace*>* obtenerRuta();

	/**
	 * Post: devuelve el precio de la llamada. De no haber hecho la busqueda devuelve 0.
	 */
	int obtenerPrecioDeLaLlamada();

	/**
	 * Post: devuelve la distancia de la llamada. De no haber hecho la busqueda devuelve 0
	 */
	int obtenerDistanciaDeLaLlamada();

	/**
	 * Los siguientes metodos requieren de haber hecho la busqueda para que funcionen.
	 */
	Central* obtenerCentralEmisora(int centralEmisora);

	Central* obtenerCentralReceptora(int centralReceptora);

	Interno* obtenerInternoEmisor(int emisor);

	Interno* obtenerInternoReceptor(int receptor);

	/**
	 * Post: Indica si la llamada fue anulada.
	 */
	bool noEstaAnuladaLaLlamada();

	/**
	 * Post: hace el algoritmo de busqueda por mejor precio.
	 */
	void encontrarCaminoPorPrecio(int centralEmisora, int centralReceptora);

	/**
	 * Post: hace el algoritmo de busqueda por mejor distancia.
	 */
	void encontrarCaminoPordistancia(int centralEmisora, int centralReceptora);

	/**
	 *restaura los valores iniciales en todos los atributos.
	 */
	void resetDatos();

	/**
	 * Post: libera la memoria de los spots usados y la lista del mejor camino.
	 */
	~Buscador();

private:

	/**
	* Post: indica si ya visite a la central en el camino ya hecho.
	*/
	bool YaPasePorLaCentral(Central* central);

	/**
	 * Post: indica si La llamada es entre dos numeros de la misma central.
	 */
	bool esLlamadaInterna(int centralEmisora, int centralReceptora);

	/**
	 * Post: Marca que la llamada fue anulada por saturacion de enlaces.
	 */
	Interno* encontrarInternoEnLa(Central* central, int numeroDeInterno);

	/**
	 * Fija el precio y distancia que encontro el Buscador.
	 */
	void definirEstePrecioYDistancia();

	/**
	 * Si hay mas caminos devuelve true, sino devuelve false.
	 */
	bool hayMasCaminos();

	/**
	 * Avanza termina de usar un enlace para ir a la siguiente central acumulando el
	 * precio y la distancia del recorrido. Pero compara para ir por el
	 * precio mas barato.
	 */
	Spot* caminar(Enlace* enlaceActual, Spot* spotActual);

	/**
	 * Define la lista de enlaces usados para llegar de una central a otra.
	 */
	void definirEstaRuta();

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

	/**
	 * Devuelve la ruta Actual de Spots.
	 */
	Lista<Spot*>* obtenerRutaActual();

	/**
	 * Borra la ruta actual liberando la memoria.
	 */
	void borrarRutaActual();

	/**
	 * Borra el ultimo spot de la ruta actual y deja el cursor en la ultima posicion.
	 */
	void borrarUnSpot();

	/**
	 * Post: Marca que la llamada fue anulada por saturacion de enlaces.
	 */
	void anularLlamada();

	/**
	 * Post: realiza el proceso para encontrar el camino por precio.
	 */
	void ProcesoIterativoPorPrecio(Central* centralActual, int centralReceptora);

	/**
	 * Post: Realiza el proceso para encontrar el camino por distancia.
	 */
	void ProcesoIterativoPorDistancia(Central* centralActual, int centralReceptora);

	/**
	 * Post: Marca que la llamada fue anulada por saturacion de enlaces.
	 */
	bool visitasteLaCentral(Central* centralActual);

};

#endif
