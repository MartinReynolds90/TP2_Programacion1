#pragma once
#include "iostream"
#include "Nodo.h"

using namespace std;

class Pila
{
private:
	Nodo* cabeza;
public:
	Pila();
	void agregar(int valor);
	void borrar();
	void mostrar();

};

