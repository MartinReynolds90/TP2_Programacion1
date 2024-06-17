#pragma once
#include "Player.h"

class Enemy:public Player
{
private:
public:
	Enemy();
	Enemy(String asset, Vector2i pos_rect, Vector2i size_rect, Vector2f pos_enemy) :Player(asset, pos_rect, size_rect, pos_enemy) {};
};

