#ifndef MENU_H
#define MENU_H

class menu
{
  private:
  
  Lista<Opciones>* punteroOpciones;
  int numeroDeOpciones; 
  
  public:
  
  Menu(int numeroDeOpciones);
  void cambiarPunteroOpciones(Lista<Opciones>* nuevoPuntero);
  Lista<Opciones>* obtenerPunteroOpcion();
  int obtenerNumeroDeOpciones();
  std::string mostrarOpciones();
  
  
};  
#endif
