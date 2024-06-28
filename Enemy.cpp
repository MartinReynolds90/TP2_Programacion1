#include "Enemy.h"

Enemy::Enemy() {
	tx_enemy = new Texture;
	sp_enemy = new Sprite;
	tx_enemy->loadFromFile("assets/shell_rojo.png");
	sp_enemy->setTexture(*tx_enemy);
	rect_enemy = new IntRect(0, 0, 32, 32);
	sp_enemy->setTextureRect(*rect_enemy);
	sp_enemy->setPosition(50,50);



}
Enemy::Enemy(String asset, Vector2f pos_enemy,int x_izquierda,int x_derecha) {

	tx_enemy = new Texture;
	sp_enemy = new Sprite;
	tx_enemy->loadFromFile(asset);
	sp_enemy->setTexture(*tx_enemy);
	rect_enemy = new IntRect(0, 0, 32, 32);
	sp_enemy->setTextureRect(*rect_enemy);
	sp_enemy->setPosition(pos_enemy);

	min = x_izquierda;
	max = x_derecha;
	//sp_enemy->setScale(sp_enemy->getScale().x * 2, sp_enemy->getScale().y * 2);
}

Sprite Enemy::get_sprite() {
	return *sp_enemy;
}
Vector2f Enemy::get_position() {
	return sp_enemy->getPosition();
}

void Enemy::set_position(Vector2f new_pos) {
	sp_enemy->setPosition(new_pos);
}
void Enemy::caminar(int magnitud ) {
	sp_enemy->setPosition(Vector2f(sp_enemy->getPosition().x + magnitud, sp_enemy->getPosition().y));
}
int Enemy::get_min_x() {
	return min;
	  
}
int Enemy::get_max_x() {
	return max;
}