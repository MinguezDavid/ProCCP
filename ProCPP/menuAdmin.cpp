/*
 * menuAdmin.cpp
 *
 *  Created on: 17 de may. de 2017
 *      Author: Pablo
 */

#include "menuAdmin.h"
#include <iostream>
using namespace std;

menuAdmin::menuAdmin() {
	// TODO Auto-generated constructor stub

}

void menuAdmin:: mostrarMenu(){

	int opc = 0;
	while(opc > 3 && opc < 1){
	cout << "Menú de Administrador" << endl;
	cout << "=====================" << endl;
	cout << "1.- Eliminar empresa" << endl;
	cout << "2.- Consultar pedidos" << endl;
	cout << "3.- Eliminar pedido" << endl;
	cout << "Inserte la opción que desee: ";
	cin >> opc;

	switch(opc){

	case 1:
		//eliminarEmpresa();
		break;
	case 2:
		//consultarPedidos();
		break;
	case 3:
		//eliminarPedido();
		break;
	default:
		cout << ("Introduzca un valor correcto.") << endl;
		break;
	}
}

}

void menuAdmin::eliminarEmpresa(DB *bd){//Check menuAdmin.h for info

}

void menuAdmin::mostrarPedidos(DB *bd){//Check menuAdmin.h for info
	int id, opcion;
	char *nu;
	cout << "Va a introducir usted: \n1. Nombre de usuario\n2. ID de pedido " << endl;
	cin >> opcion;
	while(opcion>2||opcion<1){
		cout << "Introduzca una opcion correcta: " << endl;
		cin >> opcion;
	}
	if(opcion==1){
		cout << "Introduzca el nombre de usuario: " << endl;
		cin >> nu;
		bd->recuperarPedidos(nu);
	}
	else if(opcion==2){
		cout << "Introduzca el ID del pedido: " << endl;
		cin >> id;
		bd->recuperarPedido(id);
	}
}

void menuAdmin::eliminarPedido(DB *bd){//Check menuAdmin.h for info

}

menuAdmin::~menuAdmin() {
	// TODO Auto-generated destructor stub
}

