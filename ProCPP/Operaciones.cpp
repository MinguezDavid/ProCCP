/*
 * Operaciones.cpp
 *
 *  Created on: 19 may. 2017
 *      Author: DAVID
 */

#include "Operaciones.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

namespace Punto {

Operaciones::Operaciones() {
	// TODO Auto-generated constructor stub

}


void opcionesEmp() {
	/**char* lugar = malloc(sizeof(*lugar));
	int habitaciones;
	int wc;
	int emp;
	this->colorB = colorB;
	char* colorS = malloc(sizeof(*colorS));
	char* colorH = malloc(sizeof(*colorH));
	char* colorC = malloc(sizeof(*colorC));
	//remove("ElecUsuario.txt")==0;

	FILE* eleccion;
	eleccion = fopen("ElecUsuario.txt", "r+");

	printf("OPCIONES DE CONSTRUCCION\n\n");
	mostrarEmpresas();
	printf("\n");
*/
cout << "Introduzca el numero de la empresa que llevar� a cabo la construcci�n: "<< endl;

	//cin << emp;

	/**if (emp == 2) {
		printf("seleccione el color que se usar� en los ba�os (blanco o azul): \n");
		fflush(stdout);
		scanf("%s", colorB);
		if(colorB != "blanco" || colorB != "azul" || colorB != "BLANCO" || colorB != "AZUL"){
			printf("introduzca un color v�lido: \n");
					fflush(stdout);
					scanf("%s", colorB);
		}
		fprintf(eleccion, "\nColor ba�os %s ", colorB);
		printf("seleccione el color que se usar� en las habitaciones (blanco o azul): \n");
		fflush(stdout);
		scanf("%s", colorH);
		if(colorH != "blanco" || colorH != "azul" || colorH != "BLANCO" || colorH != "AZUL"){
					printf("introduzca un color v�lido: \n");
							fflush(stdout);
							scanf("%s", colorH);
				}
		fprintf(eleccion, "\nColor habitaciones %s ", colorH);
		printf("seleccione el color que se usar� en el sal�n (Blanco o azul): \n");
		fflush(stdout);
		scanf("%s", colorS);
		if(colorS != "blanco" || colorS != "azul" || colorS != "BLANCO" || colorS != "AZUL"){
					printf("introduzca un color v�lido: \n");
							fflush(stdout);
							scanf("%s", colorS);
				}
		fprintf(eleccion, "\nColor sal�n %s", colorS);

	} else if (emp == 3) {
		printf(
				"seleccione el color/material que se usar� en los ba�os (Blanco, azulejos o azul)\n");
		fflush(stdout);
		scanf("%s", colorB);
		if(colorB != "blanco" || colorB != "azul" || colorB != "BLANCO" || colorB != "AZUL" || colorB != "azulejos" || colorB != "AZULEJOS"){
					printf("introduzca un color v�lido: \n");
							fflush(stdout);
							scanf("%s", colorB);
				}
		printf(
				"seleccione el color/material que se usar� en la cocina(Blanco o azulejos)\n");
		fflush(stdout);
		scanf("%s", colorC);
		if(colorC != "blanco" || colorC != "azulejos" || colorC != "BLANCO" || colorC != "AZULEJOS"){
							printf("introduzca un color v�lido: \n");
									fflush(stdout);
									scanf("%s", colorC);
						}

		fprintf(eleccion, "\nColor/material cocina %s ", colorC);
		printf(
				"seleccione el color que se usar� en las habitaciones (cualquiera)\n");
		fflush(stdout);
		scanf("%s", colorH);
		fprintf(eleccion, "\nColor habitaciones %s ", colorH);
		printf("seleccione el color que se usar� en el sal�n (cualquiera)\n");
		fflush(stdout);
		scanf("%s", colorS);
		fprintf(eleccion, "\nColor sal�n %s", colorS);
	}

	printf(
			"\nLugar donde se construir� la casa (playa, monta�a o ciudad): \n");
	fflush(stdout);
	scanf("%s", lugar);
	if(lugar != "playa" || lugar != "PLAYA" || lugar != "monta�a" || lugar != "MONTA�A" || lugar != "playa" || lugar != "PLAYA"){
						printf("introduzca un lugar v�lido: \n");
								fflush(stdout);
								scanf("%s", lugar);
					}
	fprintf(eleccion, "\nLugar de construccion: %s", lugar);
	printf("Introduzca el n�mero de habitaciones: \n");
	fflush(stdout);
	scanf("%i", &habitaciones);
	fprintf(eleccion, "\nHabitaciones: %i", habitaciones);
	printf("Introduzca el n�mero de ba�os: \n");
	fflush(stdout);
	scanf("%i", &wc);
	fprintf(eleccion, "\nBa�os: %i \n", wc);
//	printf("Esta es la elecci�n final");



	fclose(eleccion);

	menuUsuario();
}

//Va con algo de retraso
void mostrarEleccion() {
	FILE *eleccion;
	int caracter;

	eleccion = fopen("ElecUsuario.txt", "r");

	if (eleccion == ) {
		printf("\nError de apertura del archivo. \n\n");
	} else {
		printf("\nINFORME \n\n");
		while ((caracter = fgetc(eleccion)) != EOF) {
			printf("%c", caracter);
		}
	}
	fclose(eleccion);

}

Operaciones::~Operaciones() {
	delete(lugar);
		delete(colorB);
		delete(colorS);
		delete(colorH);
		delete(colorC);
}
*/
} /* namespace Punto */
}
