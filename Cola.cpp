#include "Cola.h"

Cola::Cola() {
	frente = NULL;
	fin = NULL;
}

void Cola::agregar(Nodo*& frente,Nodo*& fin,Enemy tort) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = tort;
	nuevo_nodo->siguiente = NULL;

	if (cola_vacia(frente)) {
		frente == nuevo_nodo;
	}
	else {
		fin->siguiente = nuevo_nodo;
	}
}

bool Cola::cola_vacia(Nodo*& frente) {
	return (frente == NULL) ? true : false;
}

void Cola::borrar(Nodo*& frente, Nodo*& fin, Enemy &tort) {
	tort = frente->dato;
	Nodo* aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente == frente->siguiente;
	}
	delete aux;
}
