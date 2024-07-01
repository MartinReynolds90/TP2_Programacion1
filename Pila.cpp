#include "Pila.h"
#include "Game.h"

Pila::Pila() {
	cabeza = NULL;
}

void Pila::agregar(Nodo *&cab, Enemy valor) {

	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;
	nuevo->siguiente = cab;
	cab = nuevo;
	
}
void Pila::borrar(Nodo*& cab, Nodo*& temp) {
	if (cab != NULL) {
		temp = cab;
		cab = temp->siguiente;
		delete temp;
	}
	else {
		cout << "la pila esta vacia";
	}
}




/*void Pila::borrar(Nodo*& p, Enemy& d) {
	Nodo* borrar = p;
	d = borrar->dato;
	p = borrar->siguiente;
	delete borrar;
	cout << "se borro un nodo correctamente" << endl;
}*/


/*bool Pila::vacia() {
	bool vacia = false;
	if (cabeza == NULL) {
		vacia = true;
	}
	return vacia;
}*/

/*Sprite Pila::mostrar() {
	Sprite sp;
	if (cabeza == NULL) {
		cout << "vacia" << endl;

	}
	else {
		Nodo* reco = cabeza;
		cout << "listado"<<endl;
		
		while (reco != NULL) {
			sp =  reco->dato.get_sprite();
			reco = reco->siguiente;
			
		}
		
	}
	return sp;

}*/



