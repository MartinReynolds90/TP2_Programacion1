#pragma once
#include "Player.h"


class Enemy
{
private:
	Sprite* sp_enemy;
	Texture* tx_enemy;
	IntRect* rect_enemy;
	Clock* clock_enemy;
	Time* time_enemy;
	int counter_frame;
	int min;
	int max;

public:

	Enemy();
	Enemy(String, Vector2f,int,int);
	Sprite get_sprite();
	Vector2f get_position();
	void set_position(Vector2f);
	void caminar(int);
	int get_max_x();
	int get_min_x();

	//void set_enemy(Enemy *&,Enemy);
	//void borrar_enemy();
};

