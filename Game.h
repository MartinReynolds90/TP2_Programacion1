#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include "iostream"
#include "stdlib.h"
#include "Pila.h"


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
	int fps = 60;

	Timer* timer;
	Player* player;

	Vector2f pos_leap; //POSICION SALTANDO
	int platforms_pos[7];  //POSICIONES DE TODAS LAS PLATAFORMAS
	int platform_current; //PLATAFORMA ACTUAL

	Enemy* enemy;
	Enemy* enemi_uno;
	Enemy* enemi_dos;
	Enemy* enemi_tres;
	Enemy* enemi_cuatro;
	Enemy* enemi_cinco;
	Enemy* enemi_seis;
	Enemy* enemi_siete;


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