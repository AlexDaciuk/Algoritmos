#include <string>
#include <sstream>


LectorArchivos::LectorArchivos (std::string rutaArchivoTemporal)
{
  this->archivo.open( ruta.c_str(rutaArchivoTemporal) );
  
  this->datosLlamadasTmp = new DatosLlamada();

  this->hayLlamadas = true;
  
}


DatosLlamada* LectorArchivos::obtenerDatosLlamada()
{
  if (! archivo.eof() )
    {
      
      getline(archivo, this->datosLlamadaTmp.accionTemporal,' ');
      
      getline(archivo, this->datosLlamadaTmp.centralATemporal,' ');
      
      getline(archivo, this->datosLlamadaTmp.internoATemporal,' ');
      
      getline(archivo, this->datosLlamadaTmp.centralBTemporal,' ');
      
      getline(archivo, this->datosLlamadaTmp.internoBTemporal,' ');
      
      getline(archivo, this->datosLlamadaTmp.horaTemporal,'\n');
    }
  else
    {
      this->hayLlamadas = false;
    }

}


LectorArchivos::~LectorArchivos()
{
  
  delete this->datosLlamadasTmp;
  
}
