/*
 * Operaciones.h
 *
 *  Created on: 19 may. 2017
 *      Author: DAVID
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <iostream>

namespace Punto {

class Operaciones {
private:
	char *lugar;
	int habitaciones;
	int wc;
	int emp;
	char *colorB;
	char *colorS;
	char *colorH;
	char *colorC;



public:
	Operaciones();
	void mostrarEmpresas();
	void opcionesEmp();
	void mostrarEleccion();

	virtual ~Operaciones();
};

} /* namespace Punto */

#endif /* OPERACIONES_H_ */
