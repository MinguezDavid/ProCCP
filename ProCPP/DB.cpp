/*
 * DB.cpp
 *
 *  Created on: 18 May 2017
 *      Author: Borja
 */

#include "DB.h"
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"

namespace std {

int contadorId = 0;

DB::DB(int idDb, char * nombre) {
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->idDb = idDb;
	this->db = db;
	contadorId++;
}

DB::~DB() {
	delete[] nombre;
}

int DB::open(){
	int result = sqlite3_open(this->nombre, &db);
	if (result != SQLITE_OK) {
		cout <<"Error opening database" << endl;
		}
	else{
		cout << "Database opened" << endl;
	}
	return result;
}

int DB::close(){
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout <<"Error closing database" << endl;
	}else{
		cout << "Database closed" << endl;
	}
	return result;
}

int DB::recuperarUsuarios(){
	char sql[] = "select Nombre from Usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;
			return result;
		}

	cout << "SQL query prepared (SELECT)" << endl;

	int id;
	char name[100];

		cout << endl;
		cout << endl;
		cout << "Showing usuarios:" << endl;
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				id = sqlite3_column_int(stmt, 0);
				strcpy(name, (char *) sqlite3_column_text(stmt, 0));
				cout << name << endl;
			}
		} while (result == SQLITE_ROW);

		cout << endl;
		cout << endl;

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout <<"Error finalizing statement (SELECT)" << endl;
			cout << sqlite3_errmsg(db) <<endl;
		}else{
			cout << "Prepared statement finalized (SELECT)" << endl;
		}
		return result;


		return SQLITE_OK;
}

} /* namespace std */
