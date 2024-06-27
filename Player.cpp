#include "Player.h"

Player::Player() {}


Player::Player(String asset, Vector2i pos_rect,Vector2i size_rect, Vector2f pos_player) {
	tx_player = new Texture;
	sp_player = new Sprite;
	tx_player->loadFromFile(asset);
	sp_player->setTexture(*tx_player);
	rect_player = new IntRect(pos_rect.x,pos_rect.y,size_rect.x, size_rect.y);
	sp_player->setTextureRect(*rect_player);
	sp_player->setPosition(pos_player);

	clock_player = new Clock();
	time_player = new Time();
	counter_frame = 0;
	//sp_player->setScale(sp_player->getScale().x * 2, sp_player->getScale().y * 2);
}

Sprite Player::get_sprite() {
	return *sp_player;
}
Vector2f Player::get_position() {
	return sp_player->getPosition();
}

void Player::set_position(Vector2f new_pos) {
	sp_player->setPosition(new_pos);
}


void Player::animation_player(int x_initial, int y_initial, int size_frame, int amount_frames) {
	*time_player = clock_player->getElapsedTime();
	if (time_player->asSeconds() > 0.10) {
		x_initial = (x_initial + (size_frame * counter_frame));
		counter_frame++;
		if (counter_frame > amount_frames) {
			x_initial = (x_initial - (amount_frames * size_frame));
			counter_frame = 0;
		}
		rect_player = new IntRect(x_initial, y_initial, size_frame, size_frame);
		sp_player->setTextureRect(*rect_player);
		clock_player->restart();
	}
}
float Player::get_time() {//DEVUELVE EL TIEMPO EN FLOAT CON LOS DESCUENTOS POR PENALIZACION HECHOS.
	*time_player = clock_player->getElapsedTime();
	return time_player->asSeconds();
}