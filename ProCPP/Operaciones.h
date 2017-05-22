/*
 * Operaciones.h
 *
 *  Created on: 19 may. 2017
 *      Author: DAVID
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <iostream>
#include <string.h>
#include "sqlite3.h"
#include "DB.h"
namespace std{

class Operaciones {
private:
	DB * db;
	int idCont;



public:
	Operaciones(DB * db);
	void mostrarEmpresas();
	void opcionesEmp();
	void mostrarEleccion();
	virtual ~Operaciones();
	void menuPrincipal();
	void menuEmpresa();
	void menuAdministrador();
	void menuUsuario();
	void crearUsuario();
	int seleccionarUsuario();
	char * conversion(string s);
	void asignar();
};


}

#endif /* OPERACIONES_H_ */
