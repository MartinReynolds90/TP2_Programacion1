#pragma once
#include "iostream"
#include "Nodo.h"
#include "iostream"
#include "stdlib.h"
#include "Enemy.h"


using namespace std;

class Pila{
private:
	Nodo* cabeza;
public:
	
	Pila();
	void agregar(Nodo *&,Enemy);
	void borrar(Nodo*&, Nodo*&);

};

