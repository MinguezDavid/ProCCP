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

namespace std {

Operaciones::Operaciones() {


}


void opcionesEmp() {
	char* lugar;
	int habitaciones;
	int wc;
	int emp;
	char* colorB;
	char* colorS;
	char* colorH;
	char* colorC;
	//remove("ElecUsuario.txt")==0;

	FILE* eleccion;
	eleccion = fopen("ElecUsuario.txt", "r+");

	cout << "OPCIONES DE CONSTRUCCION\n" << endl;
	mostrarEmpresas();
	cout << endl;

cout << "Introduzca el numero de la empresa que llevar� a cabo la construcci�n: "<< endl;

	//cin << emp;

	if (emp == 2) {
		cout << "seleccione el color que se usar� en los ba�os (blanco o azul): \n" << endl;
		//fflush(stdout);
		cin >> colorB;
		if(colorB != "blanco" || colorB != "azul" || colorB != "BLANCO" || colorB != "AZUL"){
			cout << "introduzca un color v�lido: " << endl;
					//fflush(stdout);
					cin >> colorB;
		}
		//fprintf(eleccion, "\nColor ba�os %s ", colorB);
		cout << "seleccione el color que se usar� en las habitaciones (blanco o azul): " << endl;
		//fflush(stdout);
		cin >> colorH;
		if(colorH != "blanco" || colorH != "azul" || colorH != "BLANCO" || colorH != "AZUL"){
					cout << "introduzca un color v�lido: " << endl;
							//fflush(stdout);
							cin >> colorH;
				}
		//fprintf(eleccion, "\nColor habitaciones %s ", colorH);
		cout << "seleccione el color que se usar� en el sal�n (Blanco o azul): " << endl;
		//fflush(stdout);
		cin >> colorS;

		if(colorS != "blanco" || colorS != "azul" || colorS != "BLANCO" || colorS != "AZUL"){
					cout <<"introduzca un color v�lido: " << endl;
							//fflush(stdout);
							cin >> colorS;
				}
		//fprintf(eleccion, "\nColor sal�n %s", colorS);

	} else if (emp == 3) {
		cout <<	"seleccione el color/material que se usar� en los ba�os (Blanco, azulejos o azul)" << endl;
		//fflush(stdout);
		cin >> colorB;
		if(colorB != "blanco" || colorB != "azul" || colorB != "BLANCO" || colorB != "AZUL" || colorB != "azulejos" || colorB != "AZULEJOS"){
					cout << "introduzca un color v�lido: " << endl;
							//fflush(stdout);
							cin >> colorB;
				}
		cout <<	"seleccione el color/material que se usar� en la cocina(Blanco o azulejos)" << endl;
		//fflush(stdout);
		cin >> colorC;
		if(colorC != "blanco" || colorC != "azulejos" || colorC != "BLANCO" || colorC != "AZULEJOS"){
							cout <<"introduzca un color v�lido: " << endl;
									//fflush(stdout);
									cin >> colorC;
						}

		//fprintf(eleccion, "\nColor/material cocina %s ", colorC);
		cout <<	"seleccione el color que se usar� en las habitaciones (cualquiera)" << endl;
		//fflush(stdout);
		cin >> colorH;
		//fprintf(eleccion, "\nColor habitaciones %s ", colorH);
		cout <<"seleccione el color que se usar� en el sal�n (cualquiera)" << endl;
		//fflush(stdout);
		cin >> colorS;
		//fprintf(eleccion, "\nColor sal�n %s", colorS);
	}

	cout << "\nLugar donde se construir� la casa (playa, monta�a o ciudad): " << endl;
	//fflush(stdout);
	cin >> lugar;
	if(lugar != "playa" || lugar != "PLAYA" || lugar != "monta�a" || lugar != "MONTA�A" || lugar != "playa" || lugar != "PLAYA"){
						cout << "introduzca un lugar v�lido: " << endl;
							//	fflush(stdout);
								cin >> lugar;
					}
	//fprintf(eleccion, "\nLugar de construccion: %s", lugar);
	cout << "Introduzca el n�mero de habitaciones: " << endl;
	//fflush(stdout);
	cin >> habitaciones;
	//fprintf(eleccion, "\nHabitaciones: %i", habitaciones);
	cout << "Introduzca el n�mero de ba�os: " << endl;
	//fflush(stdout);
	cin >> wc;
	//fprintf(eleccion, "\nBa�os: %i \n", wc);
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
		cout << "\nError de apertura del archivo. \n" << endl;
	} else {
		cout << "\nINFORME \n" << endl;
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

} /* namespace Punto */

