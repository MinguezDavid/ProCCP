/*
 * administrador.h
 *
 *  Created on: 17 de may. de 2017
 *      Author: Pablo
 */

#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

class administrador {
public:
	void eliminarEmpresa();
	void mostrarPedidos();
	void eliminarPedido();
	administrador();
	virtual ~administrador();
};

#endif /* ADMINISTRADOR_H_ */
