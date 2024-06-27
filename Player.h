#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


class Player
{
private:
	Sprite* sp_player;
	Texture* tx_player;
	IntRect* rect_player;

	Clock* clock_player;
	Time* time_player;
	int counter_frame;

public:
	Player();
	Player(String, Vector2i, Vector2i, Vector2f);
	Sprite get_sprite();
	Vector2f get_position();
	void set_position(Vector2f);
	void animation_player(int,int,int,int);
	float get_time();
	
};

