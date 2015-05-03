#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void leerArchivo();
void procesarLlamadas(string accionTemporal, string centralATemporal, string internoATemporal, string centralBTemporal,
						string internoBTemporal, string horaTemporal);
void procesarEnlace(string accionTemporal, string centralATemporal, string centralBTemporal, string distanciaKmTemporal,
					string precioMinutoTemporal, string cantidadCanalesTemporal);

#endif
