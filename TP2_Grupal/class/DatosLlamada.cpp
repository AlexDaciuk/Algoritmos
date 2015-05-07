#include <string>
#include <sstream>

void DatosLlamada::cargarLlamada(std::string accionTmp, std::string centralATmp, std::string internoATmp, std::string centralBTmp, std::string internoBTmp, std::string horaInicioTmp)
{
  if (! accionTmp.empty())
    {
      this->accion = accionTmp;
      
      this->centralA = centralATmp;

      this->internoA = internoATmp;

      this->centralB = centralBTmp;
      
      this->internoB = internoBTmp;
      
      std::stringstream horaInicioStreamTmp(horaInicioTmp);
      
      horaInicioStreamTmp >> this-> horaInicio;
      
    }
}
