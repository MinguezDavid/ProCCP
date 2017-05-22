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


DB::DB(int idDb, char * nombre) {
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->idDb = idDb;
	this->db = db;
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
	char sql[] = "select Nombre, id from Usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;
			return result;
		}

	cout << "SQL query prepared (SELECT)" << endl;

	char name[100];
	int id;

		cout << endl;
		cout << endl;
		cout << "Mostrando usuarios:" << endl;
		do {
			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW) {
				strcpy(name, (char *) sqlite3_column_text(stmt, 0));
				id = sqlite3_column_int(stmt,1);
				cout << "Nombre: " << name << " Id: " << id << endl;
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

char * DB::recuperarUsuario(int id){
	char sql[] = "select Nombre from Usuario where id=?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
	}

	result = sqlite3_bind_int(stmt, 1, id);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	cout << "SQL query prepared (SELECT)" << endl;

	char * name;

	cout << endl;
	cout << endl;

	result = sqlite3_step(stmt);

	name = strcpy(name, (char *) sqlite3_column_text(stmt, 0));
	cout << name << endl;


	cout << endl;
	cout << endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout <<"Error finalizing statement (SELECT)" << endl;
		cout << sqlite3_errmsg(db) <<endl;
	}else{
		cout << "Prepared statement finalized (SELECT)" << endl;
	}

	return name;
}

int DB::recuperarAdministradores(){
	char sql[] = "select Nombre from Administrador";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
				cout << "Error preparing statement (SELECT)" << endl;
				return result;
			}

		cout << "SQL query prepared (SELECT)" << endl;

		char name[100];

			cout << endl;
			cout << endl;
			cout << "Mostrando Administradores:" << endl;
			do {
				result = sqlite3_step(stmt) ;
				if (result == SQLITE_ROW) {
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

int DB::guardarUsuario(char * nombre, int fechaNacimiento, int telefono, char * ciudad_residencia, char * ciudad_Construccion){
	char sql[] = "insert into Usuario values (?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, fechaNacimiento);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, telefono);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, ciudad_residencia, strlen(ciudad_residencia), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 5, ciudad_Construccion, strlen(ciudad_Construccion), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int DB::borrarUsuario(char * nombre){
	char sql[] = "delete from Usuario where Nombre=?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
			}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
			}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
}

int DB::guardarPedido(char * colorBano, char * colorHabitacion, char * colorSalon, char * lugarConstruccion, int numHabitaciones, int numBanos, int idPedido, char *nombre){
	char sql[] = "insert into Pedido values (?, ?, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, colorBano, strlen(colorBano), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, colorHabitacion, strlen(colorHabitacion), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 3, colorSalon, strlen(colorSalon), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, lugarConstruccion, strlen(lugarConstruccion), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 5, numHabitaciones);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 6, numBanos);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
		}

	result = sqlite3_bind_int(stmt, 7, idPedido);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
		}

	result = sqlite3_bind_text(stmt, 8, nombre, strlen(nombre), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}
	cout <<"STEP"<<endl;

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	cout <<"FINALIZED"<<endl;

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int DB::recuperarPrecio(char * nombre){
	char sql[] = "select Precio from Material where Nombre=?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
				cout << "Error preparing statement (SELECT)" << endl;
				return result;
			}

		result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}



		cout << "SQL query prepared (SELECT)" << endl;

		int precio;

			cout << endl;
			cout << endl;
			cout << "Mostrando Precio:" << endl;

				result = sqlite3_step(stmt) ;

					precio = sqlite3_column_int(stmt, 0);
					cout << precio << endl;


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

int DB::recuperarPedido(int idPedido){
	char sql[] = "select * from Pedido where IdPedido=?";

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
					cout << "Error preparing statement (SELECT)" << endl;
					return result;
				}

			result = sqlite3_bind_int(stmt, 1, idPedido);
				if (result != SQLITE_OK) {
					printf("Error binding parameters\n");
					printf("%s\n", sqlite3_errmsg(db));
					return result;
				}



			cout << "SQL query prepared (SELECT)" << endl;

			int id;
			int numHabitaciones;
			int numBanos;
			char colorBano[100];
			char colorHabitacion[100];
			char colorSalon[100];
			char lugarConstruccion[100];
			char nombreUsuario[100];


				cout << endl;
				cout << endl;
				cout << "Mostrando Pedido:" << endl;

					result = sqlite3_step(stmt) ;

						strcpy(colorBano, (char *) sqlite3_column_text(stmt, 0));
						strcpy(colorHabitacion, (char *) sqlite3_column_text(stmt, 1));
						strcpy(colorSalon, (char *) sqlite3_column_text(stmt, 2));
						strcpy(lugarConstruccion,(char *) sqlite3_column_text(stmt, 3));
						numHabitaciones = sqlite3_column_int(stmt, 4);
						numBanos = sqlite3_column_int(stmt, 5);
						id = sqlite3_column_int(stmt, 6);
						strcpy(nombreUsuario, (char *) sqlite3_column_text(stmt, 7));
						cout << "Color del baño = " << colorBano << endl;
						cout << "Color de la habitación = " << colorHabitacion << endl;
						cout << "Color del salón = " << colorSalon << endl;
						cout << "Lugar de construcción = " << lugarConstruccion << endl;
						cout << "Número de habitaciones = " << numHabitaciones << endl;
						cout << "Número de baños = " << numBanos << endl;
						cout << "Número de id = " << id << endl;
						cout << "Usuario pedido = " << nombreUsuario << endl;

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

int DB::recuperarPedidos(char * nombre){
	char sql[] = "select IdPedido, Usuario from Pedido where Usuario=?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
				cout << "Error preparing statement (SELECT)" << endl;
				return result;
		}

		result = sqlite3_bind_text(stmt, 1, nombre,strlen(nombre), SQLITE_STATIC);
			if (result != SQLITE_OK) {
				printf("Error binding parameters\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}



			cout << "SQL query prepared (SELECT)" << endl;

			int id;
			char nombreUsuario[100];
			cout << endl;
			cout << endl;
			cout << "Mostrando Pedidos: " << endl;
			//se salta la primera fila
			do {
				result = sqlite3_step(stmt);
				if (result == SQLITE_ROW) {
					id = sqlite3_column_int(stmt, 0);
					strcpy(nombreUsuario, (char *) sqlite3_column_text(stmt, 1));
					cout << "Numero de id = " << id << endl;
					cout << "Nombre usuario = " << nombreUsuario << endl;
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


		//	return SQLITE_OK;

}
int DB::recuperarId(){
	char sql[] = "select id from idCounter WHERE nombre='a'";

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
					cout << "Error preparing statement (SELECT)" << endl;
					return result;
				}
			cout << "SQL query prepared (SELECT)" << endl;

			int id;


					result = sqlite3_step(stmt) ;

						id = sqlite3_column_int(stmt, 0);

				result = sqlite3_finalize(stmt);
				if (result != SQLITE_OK) {
					cout <<"Error finalizing statement (SELECT)" << endl;
					cout << sqlite3_errmsg(db) <<endl;
				}else{
					cout << "Prepared statement finalized (SELECT)" << endl;
				}
				return id;


}
int DB::subirId(int id){
	char sql[] = "UPDATE idCounter SET id=? WHERE nombre='a'";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_int(stmt, 1, id);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
}
}/* namespace std */
