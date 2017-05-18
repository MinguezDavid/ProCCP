#include <stdio.h>
#include <iostream>
#include "DB.h"

using namespace std;

int main(){
	DB * bd = new DB(1, "baseDatos.sqlite");

	bd->open();
	bd->recuperarUsuarios();
	bd->close();

	return 0;
}

