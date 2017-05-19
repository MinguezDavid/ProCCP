#include <stdio.h>
#include <iostream>
#include "DB.h"

using namespace std;

int main(){
	DB * bd = new DB(1, "baseDatos.sqlite");

	bd->open();
	bd->recuperarUsuarios();
	bd->guardarUsuario("Pedro", 1978,854124578,"Madrid", "Pamplona");
	//bd->borrarUsuario("Pedro");
	bd->recuperarUsuarios();
	bd->recuperarPedidos("Borja");
	bd->recuperarPrecio("Madera");
	bd->close();

	return 0;
}

