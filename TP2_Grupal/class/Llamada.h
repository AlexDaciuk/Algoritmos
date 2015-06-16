#ifndef LLAMADA_H_
#define LLAMADA_H_

#ifndef NULL
#define NULL 0
#endif

#include "Lista.h"
#include "Enlace.h"

class Enlace;

class Llamada
{
private:
	int  cantidadLlamadasRecibidas, llamadasAnuladas, cantidadLlamadasHechas, duracionLlamadasHechas, duracionLlamadasRecibidas, cantidadOcupadosDados,
	     cantidadOcupadosRecibidos, horaInicioLlamadaEnCurso, receptorLlamada, costoLlamadas, precioPorMinuto, otraCentral;
	Lista<Enlace*>* recorridoLlamada;

public:
	/**
	 * Constructor de la clase llamada
	 * Post: La llamada queda registrada
	 * Si el receptor no esta en el rango, no se hace nada
	 */
	Llamada(int receptorLlamadaTemporal, int centralReceptoraTemporal);


	/**
	 * Guarda la hora de comienzo de la llamada y aumeta el numero de
	 * llamadas en uno.
	 */
	void empezarLlamadaEmisor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada,int precioPorMinuto );
	void empezarLlamadaReceptor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal, bool fueAnulada,int precioPorMinuto);


	/**
	 * Calcula la duracion de la llamada y vuelve a poner el horario de inicio
	 * en cero.
	 */
	void cortarLlamadaEmisor(int horaFinLlamadaEnCursoTemporal);
	void cortarLlamadaReceptor(int horaFinLlamadaEnCursoTemporal);


	/**
	 * Devuelve la hora de inicio de la llamada.
	 */
	int obtenerHoraInicioLlamadaEnCurso();


	/**
	 * Devuelven los atributos especificados en los nombres de cada metodo.
	 */
	int obtenerReceptorLlamada();
	int obtenerDuracionLlamadasHechas();
	int obtenerDuracionLlamadasRecibidas();
	int obtenerCantidadOcupadosDados();
	int obtenerCantidadOcupadosRecibidos();
	int obtenerLlamadasAnuladas();
	int obtenerCantidadLlamadasHechas();
	int obtenerCantidadLlamadasRecibidas();
	int obtenerCostoLlamadas();
	int obtenerOtraCentral();


	/**
	 * Incrementa en una unidad el atributo llamadasAnuladas.
	 */
	void contarLlamadaAnulada();


	/**
	 * Devuelve el recorrido de la llamada
	 */
	Lista<Enlace*>* obtenerRecorridoLlamada();


	/**
	* Incrementa en una unidad el atributo cantidadOcupadosRecibidos.
	* */
	void agregarOcupadoRecibido();


	/**
	* Incrementa en una unidad el atributo cantidadOcupadosDados.
	* */
	void agregarOcupadoDado();

	/**
	 * Destructor de la clase que libera el espacio pedido para la lista de enlaces (recorrido de la llamada)
	 */
	~Llamada();

};

#endif
