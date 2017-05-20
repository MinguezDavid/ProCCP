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
#include <string>
#include <sstream>
#include "DB.h"

using namespace std;

Operaciones::Operaciones(DB * db) {
		this->db = db;

}


void Operaciones::opcionesEmp() {
	//remove("ElecUsuario.txt")==0;

		char * lugar;
		int habitaciones;
		int wc;
		int emp;
		char * colorB;
		char * colorS;
		char * colorH;
		char * colorC;
		int elec;
	FILE* eleccion;
	eleccion = fopen("ElecUsuario.txt", "r+");

	cout << "OPCIONES DE CONSTRUCCION\n" << endl;
	mostrarEmpresas();
	cout << endl;

	cout << "Introduzca el numero de la empresa que llevar� a cabo la construcci�n: "<< endl;

	cin >> emp;

	if (emp == 2) {
		cout << "seleccione el color que se usar� en los ba�os (1)blanco o 2)azul): " << endl;

		cin >> elec;
		if(elec == 1)
			colorB = (char *)"blanco";
		else
			colorB = (char *)"azul";

		cout << "seleccione el color que se usar� en las habitaciones (1)blanco o 2)azul): " << endl;
		cin >> elec;
		if(elec == 1)
			colorH = (char *)"blanco";
		else
			colorH = (char *)"azul";

		cout << "seleccione el color que se usar� en el sal�n (1)Blanco o 2)azul): " << endl;
		cin >> elec;
		if(elec == 1)
			colorS = (char *)"blanco";
		else
			colorS = (char *)"azul";


	} else if (emp == 3) {
		cout <<	"seleccione el color/material que se usar� en los ba�os (1)Blanco, 2)azulejos o 3)azul)" << endl;
		cin >> elec;
		if(elec == 1)
			colorB = (char *)"blanco";
		else if(elec == 2)
			colorB = (char *)"azulejos";
		else
			colorB = (char *)"azul";

		cout <<	"seleccione el color/material que se usar� en la cocina(1)Blanco o 2)azulejos)" << endl;
		cin >> elec;
		if(elec == 1)
			colorC = (char *)"blanco";
		else
			colorC = (char *)"azulejos";


		cout <<	"seleccione el color que se usar� en las habitaciones (1)Blanco, 2)azulejos, 3)azul o 4)rojo)" << endl;
		cin >> elec;
		if(elec == 1)
			colorH = (char *)"blanco";
		else if(elec == 2)
			colorH = (char *)"azulejos";
		else if(elec == 3)
			colorH = (char *)"azul";
		else
			colorH = (char *)"rojo";

		cout <<"seleccione el color que se usar� en el sal�n (1)Blanco, 2)azulejos, 3)azul o 4)rojo)" << endl;
		cin >> elec;
		if(elec == 1)
			colorS = (char *)"blanco";
		else if(elec == 2)
			colorS = (char *)"azulejos";
		else if(elec == 3)
			colorS = (char *)"azul";
		else
			colorS = (char *)"rojo";

	}

	cout << "\nLugar donde se construir� la casa (1)playa, 2)monta�a o 3)ciudad): " << endl;
	cin >> elec;
	if(elec == 1)
		lugar = (char *)"playa";
	else if(elec == 2)
		lugar = (char *)"montana";
	else
		lugar = (char *)"ciudad";

	cout << "Introduzca el n�mero de habitaciones: " << endl;
	cin >> habitaciones;

	cout << "Introduzca el n�mero de ba�os: " << endl;
	cin >> wc;




	fclose(eleccion);
	this->db->guardarPedido((char *)"verde",(char *)"verde", (char *)"verde",(char *) "playa", 5, 3, 17,(char *)"Borja");
	this->db->guardarPedido(colorB,colorH, colorS, lugar, habitaciones, wc, 14,(char *)"Borja");

	//menuUsuario(); esto se queda as� hasta nuevo aviso
}

//Va con algo de retraso
void Operaciones::mostrarEleccion() {
	FILE *eleccion;
	int caracter;

	eleccion = fopen("ElecUsuario.txt", "r");

	if (eleccion == NULL) {
		cout << "\nError de apertura del archivo. \n" << endl;
	} else {
		cout << "\nINFORME \n" << endl;
		while ((caracter = fgetc(eleccion)) != EOF) {
			printf("%c", caracter);
		}
	}
	fclose(eleccion);

}

void Operaciones::mostrarEmpresas() {
	FILE *archivo;
	int caracter;

	archivo = fopen("empresas.txt", "r");

	if (archivo == NULL) {
		cout <<"\nError de apertura del archivo. \n\n";
	} else {
		cout << "\nEMPRESAS DISPONIBLES \n\n";
		while ((caracter = fgetc(archivo)) != EOF) {
			printf("%c", caracter);
		}
		printf("\n\n");
	}
	fclose(archivo);
}

Operaciones::~Operaciones() {
	delete(db);
}




