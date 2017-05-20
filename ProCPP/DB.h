/*
 * DB.h
 *
 *  Created on: 18 May 2017
 *      Author: Borja
 */

#ifndef DB_H_
#define DB_H_

#include "sqlite3.h"
#include <iostream>

namespace std {

class DB {

private:
	sqlite3 * db;
	sqlite3_stmt * stmt;
	int idDb;
	char * nombre;


public:
	DB(int idDb, char * nombre);
	virtual ~DB();

	int open();
	int close();
	int recuperarUsuarios();
	int recuperarAdministradores();
	int recuperarPrecio(char * nombre);
	int recuperarPedido(int idPedido);
	int recuperarPedidos(char * nombreUsuario);
	int guardarPedido(char * colorBano, char * colorHabitacion, char * colorSalon, char * lugarConstruccion, int numHabitaciones, int numBanos, int idPedido, char* nombre);
	int borrarUsuario(char * nombreUsuario);
	int guardarUsuario(char * nombre, int fechaNacimiento, int telefono, char * ciudad_residencia, char * ciudad_Construccion);
	char * recuperarUsuario(int id);
};

} /* namespace std */

#endif /* DB_H_ */
