#include "Pila.h"

Pila::Pila(){
	cabeza = NULL;
}

void Pila::agregar(int valor) {
	Nodo* nuevo = new Nodo();
	nuevo->info = valor;
	if (cabeza == NULL) {//si es el primer valor que ingreso
		cabeza = nuevo;
	}
	else {//si ya tiene al menos un valor la pila
		
		nuevo->sig = cabeza;
		cabeza = nuevo;
	}
}

void Pila::borrar(){
	Nodo* borrar = cabeza;
	if (cabeza == NULL) {
		cout << "no hay nada que borrar"<<endl;
	}
	else {
		cabeza = cabeza->sig;//se vuelve una posicion para atras y desprende (borra) la que estaba arriba
		delete borrar;
		cout << "borrando"<<endl;
	}
}

void Pila::mostrar() {
	if (cabeza == NULL) {
		cout << "no hay nada que mostrar"<<endl;
	}
	else {
		Nodo* recorrer = cabeza;//empieza en la parte superior
		cout << "recorriendo la pila"<<endl;
		while (recorrer != NULL) {
			cout << recorrer->info << endl;
			recorrer = recorrer->sig;
		}
	}

}