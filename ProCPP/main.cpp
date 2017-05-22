#include <stdio.h>
#include <iostream>
#include "DB.h"
#include "Operaciones.h"

using namespace std;

int main(){
	DB * bd = new DB(1, "baseDatos.sqlite");
	Operaciones * op = new Operaciones(bd);

	bd->open();
	op->menuPrincipal();
	//op->opcionesEmp();

	/**bd->recuperarUsuarios();
	bd->guardarUsuario("Pedro", 1978,854124578,"Madrid", "Pamplona");
	//bd->borrarUsuario("Pedro");
	bd->recuperarUsuarios();
	bd->recuperarPedido(1);
	//bd->recuperarPrecio("Madera");

	 */
	//bd->guardarPedido("Rosa", "pink", "violeta", "montaña", 3, 2, 3,"Federico");
	bd->close();

	return 0;
}

