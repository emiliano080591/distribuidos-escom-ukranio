//Programa para crear registros de votos [celular, CURP, partido, separador], con el campo "celular" como clave 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream> 
#include <list> 
#include <iterator> 

using namespace std; 

struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
};

int main(int argc, char *argv[]){
	char telefono[11], curp[19], t[11], sexo;
	int i, n, destino, j, opcion, inicial, elemento;;
	struct registro reg1;
	list <int> lista; 
    list<int>::iterator itr;

	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};

	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};

	if(argc != 2){
		printf("Forma de uso: programa numero_registros\n");
		exit(0);
	}

	//Numero de registros n
	n = atoi(argv[1]);

	//Llena una lista con numeros telefonicos de 9 digitos secuenciales creibles
	inicial = 500000000 + rand()%100000000;
	for (int i = inicial; i < inicial + n; i++) 
	{ 
		lista.push_back(i);
	} 
	
	for(j=0; j<n; j++){
		//Obtiene un elemento aleatorio de la lista de telefonos y lo elimina de la lista para evitar la repeticion
		i = n - j;
		elemento = rand()%i;		
		itr = lista.begin();
		for(int k = 0; k < elemento; k++)
			++itr;
		elemento = *itr;
		lista.erase(itr);
		sprintf(telefono, "5%9d", elemento);
		strcpy(reg1.celular, telefono);

		if(rand()%2 == 0)
			sexo = 77;
		else
			sexo = 72;

		i = rand()%32;
		sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand()%25 , 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, 
			sexo, entidad[i], 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48);
		strcpy(reg1.CURP, curp);

		i = rand()%9;
		strcpy(reg1.partido, partidos[i]);

		write(1, &reg1, sizeof(reg1));
		printf("\n");
	}
}