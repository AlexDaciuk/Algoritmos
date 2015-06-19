#ifndef CENTRAL_H_
#define CENTRAL_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"
#include "Interno.h"

class Interno;
class Enlace;

/**
 * Clase que maneja cada central
 */

class Central
{
private:

	int numeroCentral;
	Lista<Interno*>* internos;
	Lista<Enlace*>* enlaces;
	Lista<Recorrido*>* mejoresCaminos;

public:
	/**
	 * Constuctor de la clase
	 * Post: Va a quedar creada la central con su lista de internos y enlaces vacias
	 */
	Central(int numeroCentralTemporal);


	/**
	 * Metodo que crea un interno dentro de la central, si ya existe el interno, no hace nada
	 */
	void crearInterno(int numeroInterno);


	/**
	 * Precondicion: El interno debe existir.
	 * Postcondicion: Devuelve el puntero al interno solicitado.
	 */
	Interno* obtenerInterno(int numeroInterno);


	/**
	 * Metodo que devuelve la lista de internos
	 */
	Lista<Interno*>* obtenerInternos();


	/**
	 * Metodo que devuelve la lista de enlaces
	 */
	Lista<Enlace*>* obtenerEnlaces();

	/**
	 * Metodo que agrega un enlace a la lista de enlaces de la central
	 */
	void agregarEnlace(Enlace* enlaceTemporal);


	/**
	 * Metodo que devuelve el numero de la central
	 */
	int obtenerNumero();


	/**
	 * Devuelve el total de llamadas anuladas de toda la lista de internos.
	 */
	int obtenerTotalDeLlamadasAnuladasDeInternos(Lista<Interno*>* internos);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor duracion total de llamadas recibidas y esa duracion.
	*/
	void internoQueMasLeHablaronEnLaCentral(Lista<Interno*>* listaInternos,int& maximoInternoQueMasLeHablaronEnLaCentral,
	                                        int& internoQueMasHablaronPorCentral);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor numero de ocupados dados y ese numero,
	* por central
	*/
	void internoQueMasDioOcuapadoEnLaCentral(Lista<Interno*>* listaInternos,int& maximoNumeroDeOcupadosDadosEnLaCentral,
	        int& internoQueMasDioOcupadoPorCentral);


	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor costos por llamadas y ese numero de gastos.
	*/
	void internoQueMasGastoEnLaCentral(Lista<Interno*>* listaInternos,int& maximoGastoEnLaCentral,
	                                   int& internoQueMasGastoPorCentral);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor duracion de llamadas totales (recibidas mas hechas).
	*/
	void internoQueMasHabloEnLaCentral(Lista<Interno*>* listaInternos,
	                                   int& maximaDuracionEnLaCentral,
	                                   int& internoQueMasHabloPorCentral);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor numero de llamadas recibidas y ese numero de llamadas.
	*/
	void internoQueMasLlamadasRecibioEnLaCentral(Lista<Interno*>* listaInternos,int& maximoLlamadasRecibidasEnLaCentral,
	        int& internoQueMasLlamaronPorCentral);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor numero de llamadas y ese numero de llamadas.
	*/
	void internoQueMasLlamoEnLaCentral(Lista<Interno*>* listaInternos,
	                                   int& maximoNumeroLLamadasEnLaCentral,
	                                   int& internoQueMasLlamoPorCentral);

	/**
	* pre: debe existir la lista de punteros a internos.
	* post: devuleve el numero del interno con mayor numero de ocupados recibidos y ese numero de ocupados.
	*/
	void internoQueMasOcupadosRecibioEnLaCentral(Lista<Interno*>* listaInternos,
	        int& maximoNumeroOcupadosEnLaCentral,
	        int& internoQueMasRecibioOcupadosPorCentral);

	/*
	 * Metodo que agrega recorridos a la central 
	 */
	void agregarRecorrido(Recorrido* nuevoRecorrido);


	/**
	 * Destructor de Central, libera el espacio pedido para la lista de enlaces y de internos
	 * */
	~Central();

};

#endif
