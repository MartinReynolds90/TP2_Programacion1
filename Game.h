#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include "iostream"
#include "stdlib.h"
#include "Pila.h"
#include "Cola.h"


using namespace sf;
using namespace std;

class Game
{
private:
	RenderWindow* w;
	Event* e;
	Clock* clock_game;
	Time* time_game;
	Clock* clock_player;
	Time* time_player;



	Sprite* sp_background;
	Texture* tx_background;
	Sprite* sp_puerta;
	Texture* tx_puerta;
	int fps = 60;

	Timer* timer;
	Player* player;

	Vector2f pos_leap; //POSICION SALTANDO
	int platforms_pos[7];  //POSICIONES DE TODAS LAS PLATAFORMAS
	int plataforma_actual; //PLATAFORMA ACTUAL
	int plataforma_destino;
	bool salto;

	Enemy* tortuga_cero;
	Enemy* tortuga_uno;
	Enemy* tortuga_dos;
	Enemy* tortuga_tres;

	Enemy* tortuga_cuatro;
	Enemy* tortuga_cinco;
	Enemy* tortuga_seis;
	Enemy* tortuga_siete;

	Enemy* tortuga_ocho;
	Enemy* tortuga_nueve;
	Enemy* tortuga_diez;
	Enemy* tortuga_once;

	Enemy* tortuga_doce;
	Enemy* tortuga_trece;
	Enemy* tortuga_catorce;
	Enemy* tortuga_quince;

	Enemy* tortuga_dieciseis;
	Enemy* tortuga_diecisiete;
	Enemy* tortuga_dieciocho;
	Enemy* tortuga_diecinueve;


	Enemy* tortugas[20];
	bool colision;
	FloatRect* rect_player;


	//int l_derecho;
	//int l_izquierdo;
	int arr_pos_x[8];


	Pila* pila;
	Nodo* cabeza;
	Nodo* borrar;


	Pila* pila_dos;
	Nodo* cabeza_dos;
	Nodo* borrar_dos;

	Pila* pila_tres;
	Nodo* cabeza_tres;
	Nodo* borrar_tres;

	Pila* pila_cuatro;
	Nodo* cabeza_cuatro;
	Nodo* borrar_cuatro;

	Pila* pila_cinco;
	Nodo* cabeza_cinco;
	Nodo* borrar_cinco;

	Pila* pila_seis;
	Nodo* cabeza_seis;
	Nodo* borrar_seis;

	Cola* cola_uno;
	Nodo* frente_uno;
	Nodo* fin_uno;

	Cola* cola_dos;
	Nodo* frente_dos;
	Nodo* fin_dos;

	//Nodo* recorrer;
	int vel;
	bool vuelven;
	//bool vuelven_dos;

	//Enemy array[4];


public:
	Game();
	Game(int, int, String);
	void game_loop();
	void draw_game();
	void process_event();

	
};