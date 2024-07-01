#pragma once
#include "Player.h"


class Enemy
{
private:
	Sprite* sp_enemy;
	Texture* tx_enemy;
	IntRect* rect_enemy;
	int counter_frame;
	int min;
	int max;

public:

	Enemy();
	Enemy(String, Vector2f,int,int); 
	Sprite get_sprite();
	Vector2f get_position();
	void set_position(Vector2f);
	void caminar(int);//la funcion recibe un entero que sirve como la magnitud del movimiento 
	int get_max_x(); //cada tortuga recibe al momento de ser creada un x maximo y un x minimo como limites a su rango de movimiento
	int get_min_x();
};

