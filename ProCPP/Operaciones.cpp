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
#include <stdlib.h>
#include <string>
#include <sstream>
#include "DB.h"

using namespace std;

Operaciones::Operaciones(DB * db) {
		this->db = db;

}

void Operaciones::asignar(){
	this->idCont = this->db->recuperarId();
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
		string nombre;
		int elec;
	FILE* eleccion;
	eleccion = fopen("ElecUsuario.txt", "r+");

	cout << "OPCIONES DE CONSTRUCCION\n" << endl;
	mostrarEmpresas();
	cout << endl;

	cout << "Introduzca el numero de la empresa que llevará a cabo la construcción: "<< endl;

	cin >> emp;

	if (emp == 2) {
		cout << "seleccione el color que se usará en los baños (1)blanco o 2)azul): " << endl;

		cin >> elec;
		if(elec == 1)
			colorB = (char *)"blanco";
		else
			colorB = (char *)"azul";

		cout << "seleccione el color que se usará en las habitaciones (1)blanco o 2)azul): " << endl;
		cin >> elec;
		if(elec == 1)
			colorH = (char *)"blanco";
		else
			colorH = (char *)"azul";

		cout << "seleccione el color que se usará en el salón (1)Blanco o 2)azul): " << endl;
		cin >> elec;
		if(elec == 1)
			colorS = (char *)"blanco";
		else
			colorS = (char *)"azul";


	} else if (emp == 3) {
		cout <<	"seleccione el color/material que se usará en los baños (1)Blanco, 2)azulejos o 3)azul)" << endl;
		cin >> elec;
		if(elec == 1)
			colorB = (char *)"blanco";
		else if(elec == 2)
			colorB = (char *)"azulejos";
		else
			colorB = (char *)"azul";

		cout <<	"seleccione el color/material que se usará en la cocina(1)Blanco o 2)azulejos)" << endl;
		cin >> elec;
		if(elec == 1)
			colorC = (char *)"blanco";
		else
			colorC = (char *)"azulejos";


		cout <<	"seleccione el color que se usará en las habitaciones (1)Blanco, 2)azulejos, 3)azul o 4)rojo)" << endl;
		cin >> elec;
		if(elec == 1)
			colorH = (char *)"blanco";
		else if(elec == 2)
			colorH = (char *)"azulejos";
		else if(elec == 3)
			colorH = (char *)"azul";
		else
			colorH = (char *)"rojo";

		cout <<"seleccione el color que se usará en el salón (1)Blanco, 2)azulejos, 3)azul o 4)rojo)" << endl;
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

	cout << "\nLugar donde se construirá la casa (1)playa, 2)montaña o 3)ciudad): " << endl;
	cin >> elec;
	if(elec == 1)
		lugar = (char *)"playa";
	else if(elec == 2)
		lugar = (char *)"montana";
	else
		lugar = (char *)"ciudad";

	cout << "Introduzca el número de habitaciones: " << endl;
	cin >> habitaciones;

	cout << "Introduzca el número de baños: " << endl;
	cin >> wc;

	cout << "Introduzca el nombre de usuario: " << endl;
	cin >> nombre;



	fclose(eleccion);
	//this->db->guardarPedido((char *)"verde",(char *)"verde", (char *)"verde",(char *) "playa", 5, 3, 17,(char *)"Borja");
	this->db->guardarPedido(colorB,colorH, colorS, lugar, habitaciones, wc, this->idCont,conversion(nombre));
	//cout << this->idCont << endl;
	this->idCont++;
	//cout << this->idCont << endl;
	this->db->subirId(this->idCont);

	//menuUsuario(); esto se queda así hasta nuevo aviso
}

char * Operaciones::conversion(string s){
	char * nombre1;
	//cout << s.length()<<endl;
	for(int i = 0;i < s.length();i++){
			nombre1[i] = s.at(i);
		}
	cout << "hola"<<endl;
	nombre1[s.length()] = '\0';
	return nombre1;
}

char * Operaciones::conversion2(string s){
	char tab2[1024];
	strcpy(tab2, s.c_str());
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

void Operaciones::menuPrincipal()
{
	int opPrincipal;

		cout << "Bienvenido/a al Sistema de Gestión de Viviendas:" << endl;
		cout << "================================================" << endl;

		do
		{
		cout << "1.- Empresa" << endl;
		cout << "2.- Usuario" << endl;
		cout << "3.- Administrador" << endl;
		cout << "4.- Salir" << endl;
		cout << endl;
		cout << "Introduzca una opción:" << endl;
		cin >> opPrincipal;

		switch(opPrincipal)
		{
		case 1:
			menuEmpresa();
			break;
		case 2:
			menuUsuario();
			break;
		case 3:
			menuAdministrador();
			break;
		case 4:
			cout << "Muchas gracias. Hasta la próxima.";
			exit(0);
			break;
		default: cout << "Opción incorrecta. Introduzca una opción válida." << endl;
		break;
		}

	}while(opPrincipal < 1 || opPrincipal > 4);
}

int Operaciones::seleccionarUsuario(){
	int sele;
	this->db->recuperarUsuarios();
	cout << endl;
	cout << "Introduzca el Id deseado: " << endl;
	cin >> sele;
	return sele;
}
void Operaciones::menuEmpresa()
{
	int opEmpresa;

	do
	{
		cout << "¿Qué desea hacer?" << endl;
		cout << "1.- Consultar Empresas" << endl;
		cout << "2.- Atrás" << endl;

		cin >> opEmpresa;


		switch(opEmpresa){

		case 1:
			mostrarEmpresas();
			menuEmpresa();
			break;
		case 2:
			menuPrincipal();
			break;
		default:
			cout << "Opción incorrecta." << endl;
		}

	}while(opEmpresa > 2 || opEmpresa < 1);
}

void Operaciones::crearUsuario(){
		char* nombre;
		int fecha_nacimiento;
		int telefono;
		char* ciudad_residencia;
		char* ciudad_construccion_casa;
		cout << "Registro nuevo usuario\n\n";
		cout << "Introduzca el nombre de usuario deseado: " << endl;
		cin >> nombre;
		cout << "Introduzca el año de nacimiento del usuario: " << endl;
		cin >> fecha_nacimiento;
		cout << "Introduzca el telefono del usuario: " << endl;
		cin >> telefono;
		cout << "Introduzca la ciudad de residencia del usuario: " << endl;
		cin >> ciudad_residencia;
		cout << "Introduzca la ciudad donde se construira la casa: " << endl;
		cin >> ciudad_construccion_casa;
		this->db->guardarUsuario(nombre,fecha_nacimiento,telefono,ciudad_residencia,ciudad_construccion_casa);
}
void Operaciones::menuUsuario()
{
	int opUsuario;
	string nombre;
	//cout << nombre << endl;
	do
	{
		cout << "¿Qué desea hacer?" << endl;
		cout << "1.- Registrarse" << endl;
		cout << "2.- Mostrar empresas" << endl;
		cout << "3.- Realizar pedido" << endl;
		cout << "4.- Consultar pedidos " << endl;
		cout << "5.- Mostrar Usuarios" <<endl;
		cout << "6.- Atrás" << endl;
		cin >> opUsuario;

		switch(opUsuario){
		case 1:
			//TODO
			crearUsuario();
			menuUsuario();
			break;
		case 2:
			mostrarEmpresas();
			menuUsuario();
			break;
		case 3:
			opcionesEmp();
			menuUsuario();
			break;
		case 4:
			cout << "Introduzca el nombre de usuario: " << endl;
			cin >> nombre;
			char tab2[1024];
			strcpy(tab2, nombre.c_str());
			this->db->recuperarPedidos(tab2);
			menuUsuario();
			break;
		case 5:
			this->db->recuperarUsuarios();
			menuUsuario();
			break;
		case 6:
			menuPrincipal();
			break;

		default:
			cout << "Opción incorrecta. Introduzca una opción correcta." << endl;
			break;
		}
	}while(opUsuario > 4 || opUsuario < 1);



}

void Operaciones::menuAdministrador()
{
	int opAdmin, codEmpElim, codPedElim, id;
	string nombre;
	do{
	cout << "¿Qué desea hacer?" << endl;
	cout << "1.- Eliminar usuario" << endl;
	cout << "2.- Consultar pedidos" << endl;
	cout << "3.- Eliminar pedido" << endl;
	cout << "4.- Mostrar administradores" << endl;
	cout << "5.- Mostrar usuarios" << endl;
	cout << "6.- Atrás" << endl;
	cin >> opAdmin;

	switch(opAdmin)
	{
	case 1:
		cout << "Introduzca el nombre de usuario que desea borrar: " << endl;
		cin >> nombre;
		char tab2[1024];
		strcpy(tab2, nombre.c_str());
		this->db->borrarUsuario(tab2);
		menuAdministrador();
		break;
	case 2:
		cout << "Introduzca el nombre de usuario: " << endl;
		cin >> nombre;
		tab2[1024];
		strcpy(tab2, nombre.c_str());
		this->db->recuperarPedidos(tab2);
		menuAdministrador();
		break;
	case 3:
		cout <<"Introduza el id del pedido a eliminar: " << endl;
		cin >> id;
		this->db->eliminarPedido(id);
		menuAdministrador();
		break;
	case 4:
		this->db->recuperarAdministradores();
		menuAdministrador();
		break;
	case 5:
		this->db->recuperarUsuarios();
		menuAdministrador();
		break;
	case 6:
		menuPrincipal();
		break;

	default:
		cout << "Opción incorrecta. Introduzca una opción correcta." << endl;
		break;
		}
	}while(opAdmin > 5 || opAdmin < 1);
}





