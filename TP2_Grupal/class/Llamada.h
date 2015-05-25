#ifndef LLAMADA_H_
#define LLAMADA_H_

#ifndef NULL
#define NULL 0
#endif


class Llamada
{
private:

	int  cantidadLlamadasRecibidas, cantidadLlamadasHechas, duracionLlamadas, cantidadOcupadosDados, cantidadOcupadosRecibidos, horaInicioLlamadaEnCurso, receptorLlamada, costoLlamadas;
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
	void empezarLlamadaReceptor(int horaInicioLlamadaEnCursoTemporal, Lista<Enlace*>* recorridoLlamadaTemporal)
	/*pre: la llamada debe haber comenzado antes.
	 * post: calcula la duracion de la llamada y vuelve a poner el horario de inicio
	 * en cero.*/
	void terminarLlamada(int horaFinLlamadaEnCursoTemporal);

	/*post: devuelve la hora de inicio de la llamada.*/
	int obtenerHoraInicioLlamadaEnCurso();

	/*post: devuelve a que receptor pertenece el nodo de la listas de llamdas
	 * del interno.*/
	int obtenerReceptorLlamada();

	/*post: devuelve la duracion acumulada todas las llamadas efectuadas por el interno.*/
	int obtenerDuracionLlamadas();

	/*post: devuelve la cantidad total de ocupados dados por el interno.*/
	int obtenerCantidadOcupadosDados();

	/*post: devuelve la cantidad total de ocupados recibidos por el interno.*/
	int obtenerCantidadOcupadosRecibidos();
	
	int obtenerCantidadLlamadas();
	
	int obtenerCostoLlamadas();
	
	Lista<Enlace*>* obtenerRecorridoLlamada();
	
	void agregarOcupadoRecibido();
	
	void agregarOcupadoDado();

};

#endif
