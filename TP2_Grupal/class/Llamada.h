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

	int  cantidadLlamadasRecibidas, llamadasAnuladas, cantidadLlamadasHechas, duracionLlamadasHechas, duracionLlamadasRecibidas, cantidadOcupadosDados, cantidadOcupadosRecibidos, horaInicioLlamadaEnCurso, receptorLlamada, costoLlamadas;
	Lista<Enlace*>* recorridoLlamada;

public:

	/**
	 * Constructor de la clase llamada
	 * Post: La llamada queda registrada
	 * Si el receptor no esta en el rango, se deja en 0 el receptor de la llamada
	 */

	Llamada(int receptorLlamadaTemporal);

	/*post: guarda la hora de comienzo de la llamada y aumeta el numero de
	 * llamadas en uno.*/
	void empezarLlamadaEmisor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal);
	void empezarLlamadaReceptor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal);
	
	/*pre: la llamada debe haber comenzado antes.
	 * post: calcula la duracion de la llamada y vuelve a poner el horario de inicio
	 * en cero.*/
	void cortarLlamadaEmisor(int horaFinLlamadaEnCursoTemporal, int precioMinuto);
	void cortarLlamadaReceptor(int horaFinLlamadaEnCursoTemporal, int precioMinuto)

	/*post: devuelve la hora de inicio de la llamada.*/
	int obtenerHoraInicioLlamadaEnCurso();

	/*post: devuelve a que receptor pertenece el nodo de la listas de llamdas
	 * del interno.*/
	int obtenerReceptorLlamada();

	/*post: devuelve la duracion acumulada todas las llamadas efectuadas por el interno.*/
	int obtenerDuracionLlamadasHechas();
  /*post: devuelve la duracion acumulada todas las llamadas recibidas del interno.*/
	int obtenerDuracionLlamadasRecibidas();

	/*post: devuelve la cantidad total de ocupados dados al interno.*/
	int obtenerCantidadOcupadosDados();

	/*post: devuelve la cantidad total de ocupados recibidos por el interno.*/
	int obtenerCantidadOcupadosRecibidos();
  /*post: devuelve la cantidad total de llamadas anuladas realizadas por interno.*/
	int obtenerLlamadasAnuladas();
  /*post: devuelve la cantidad total de llamadas realizadas al interno.*/
	int obtenerCantidadLlamadasHechas();
  /*post: devuelve la cantidad total de llamadas recibidas por el interno.*/
	int obtenerCantidadLlamadasRecibidas();
  /*post: devuelve la cantidad total de gastos por las llamadas al interno.*/
	int obtenerCostoLlamadas();
  /** 
   * Incrementa en una unidad el atributo llamadasAnuladas.
   * */
  void contarLlamadaAnulada();

	
	Lista<Enlace*>* obtenerRecorridoLlamada();
	/** 
   * Incrementa en una unidad el atributo cantidadOcupadosRecibidos.
   * */
	void agregarOcupadoRecibido();
	/** 
   * Incrementa en una unidad el atributo cantidadOcupadosDados.
   * */
	void agregarOcupadoDado();

};

#endif
