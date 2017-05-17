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
		eliminarEmpresa();
		break;
	case 2:
		consultarPedidos();
		break;
	case 3:
		eliminarPedido();
		break;
	default:
		cout << ("Introduzca un valor correcto.") << endl;
		break;
	}
}

}
menuAdmin::~menuAdmin() {
	// TODO Auto-generated destructor stub
}

