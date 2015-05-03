#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>


void leerArchivo();
void procesarLlamadas(std::string accionTemporal, std::string centralATemporal, std::string internoATemporal, std::string centralBTemporal, std::string internoBTemporal, std::string horaTemporal);
void procesarEnlace(std::string accionTemporal, std::string centralATemporal, std::string centralBTemporal, std::string distanciaKmTemporal, std::string precioMinutoTemporal, std::string cantidadCanalesTemporal);
void menu();

#endif
