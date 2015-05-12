#include <string>
#include <sstream>

void DatosLlamada::cargarLlamada(std::string accionTemporal, std::string centralATemporal, std::string internoATemporal, std::string centralBTemporal, std::string internoBTemporal, std::string horTaemporal)
{
  if (! accionTemporal.empty())
    {
      this->accion = accionTemporal;
      
      std::stringstream centralAStream(centralATemporal);
      centralAStream >> this->centralA;      

      std::stringstream internoAStream(internoATemporal);
      internoAStream >> this->internoA;
      
      std::stringstream centralBStream(centralBTemporal);
      centralBstream >> this->centralB;
    
      std::stringstream internoBStream(internoBTemporal);
      internoBStream >> this->internoB;  
        
      std::stringstream horaInicioStreamTemporal(horaTemporal);
      horaStreamTemporal >> this->hora;
      
    }
}

std::string DatosLlamada::obtenerAccion()
{
  return this->accion;
}

int DatosLlamada::obtenerCentralA()
{
  return this->centralA;
}
int DatosLlamada::obtenerCentralB()
{
  return this->centralB;
}

int DatosLlamada::obtenerInternoA()
{
  return this->internoA;
}

int DatosLlamada::obtenerInternoB()
{
  return this->internoB;
}

int DatosLlamada::obtenerHora()
{
  return this->hora
}
