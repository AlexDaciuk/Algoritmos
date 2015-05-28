#ifndef OPCIONES_H_
#define OPCIONES_H_
#include <string>


class Opciones
{
  private:
  
  int numeroDeOpcion;
  //puntero a resolucion


  public:
  /**
   * La opcion queda creada con su numero, descripcion
   * y su puntero a descripcion apuntando a null
   * */
  Opciones(int numeroDeOpcion, std::string descripcion);
  int obternerNumeroDeOpcion();
  void cambiarNumeroDeOpcion(int nuevoNumero);
  std::string ObtenerDescripcion();
  void cambiarDescripcion(std::string nuevaDescripcion);
  //void cambiarResolucion(nuevo puntero a resolucion);
  //obtenerResolucion();
  

};
#endif
