#pragma once
#include "Nodo.h"
#include "iostream"
#include "stdlib.h"
#include "Enemy.h"

using namespace std;
class Cola
{
private:
	Nodo* frente;
	Nodo* fin;
public:
	Cola();
	void agregar(Nodo*&, Nodo*&, Enemy);
	Enemy borrar( );
	bool cola_vacia();
};

