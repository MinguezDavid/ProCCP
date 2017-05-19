/*
 * menuAdmin.h
 *
 *  Created on: 17 de may. de 2017
 *      Author: Pablo
 */

#ifndef MENUADMIN_H_
#define MENUADMIN_H_
#include "DB.h"
using namespace std;



class menuAdmin {
public:
	void mostrarMenu();
	menuAdmin();
	//Se le pasa la BD a estos tres metodos para no tener que abrirla en la implementacion y que no cree conflicto con
	//el main, es decir, que no se abra la BD dos veces(la del main y la del metodo)
	void eliminarEmpresa(DB *bd);
	void mostrarPedidos(DB *bd);
	void eliminarPedido(DB *bd);
	virtual ~menuAdmin();
};

#endif /* MENUADMIN_H_ */
