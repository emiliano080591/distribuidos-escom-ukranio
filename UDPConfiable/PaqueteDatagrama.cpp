#include "PaqueteDatagrama.h"

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int lon, char * ipDir, int puert){
	datos = new char[lon];
	memcpy(datos, dat, sizeof(char)*lon);
    memcpy(ip, ipDir, sizeof(char)*16);
    longitud = lon;
    puerto = puert;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int lon){
	datos = new char[lon];
	longitud = lon;
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete [] datos;
}

char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puert){
	puerto = puert;
}

void PaqueteDatagrama::inicializaIp(char * ipDir){
	memcpy(ip, ipDir, sizeof(char)*16);
}

void PaqueteDatagrama::inicializaDatos(char * dat){
	memcpy(datos, dat, longitud);
}
