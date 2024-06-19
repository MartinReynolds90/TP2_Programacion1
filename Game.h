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
	Sprite* sp_background;
	Texture* tx_background;
	int fps = 60;

	Timer* timer;
	Player* player;
	Vector2f pos_leap; //POSICION SALTANDO
	int platforms_pos[7];  //POSICIONES DE TODAS LAS PLATAFORMAS
  	int platform_current; //PLATAFORMA ACTUAL

	Enemy* enemy;
	Pila* pila;


public:
	Game();
	Game(int,int,String);
	void game_loop();
	void draw_game();
	void process_event();

};

