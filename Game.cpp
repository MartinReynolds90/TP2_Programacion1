#include "Game.h"

Game::Game() {
}

Game::Game(int ancho_vent,int alto_vent, String nombre_vent) {
	srand(time(NULL));
	w = new RenderWindow(VideoMode(ancho_vent, alto_vent),nombre_vent);
	w->setFramerateLimit(fps);
	e = new Event;
	clock_game = new Clock();
	time_game = new Time();
	*time_game = clock_game->getElapsedTime();

	tx_background = new Texture;
	sp_background = new Sprite;
	tx_background->loadFromFile("assets/fondo_plataformas.png");
	sp_background->setTexture(*tx_background);


	timer = new Timer(30,600.0,40.0);
	player = new Player("assets/Juego2D_2.png",Vector2i(0,64), Vector2i(32, 32), Vector2f(450, 492));
	enemy = new Enemy("assets/Juego2D_2.png", Vector2i(0,32), Vector2i(32, 32), Vector2f(450, 43));

	platform_current = 0;
	platforms_pos[0]= 492;
	platforms_pos[1] = 417;
	platforms_pos[2] = 343;
	platforms_pos[3] = 266;
	platforms_pos[4] = 193;
	platforms_pos[5] = 120;
	platforms_pos[6] = 43;

	game_loop();
}


void Game::game_loop() {
	while (w->isOpen()) {
		*time_game = clock_game->getElapsedTime();
		timer->actualizar_temp();
		process_event();
		draw_game();
	}
}

void Game::draw_game() {
	w->clear(Color(255, 255, 255, 255));
	w->draw(*sp_background);
	w->draw(player->get_sprite());
	w->draw(enemy->get_sprite());
	w->draw(timer->get_text());
	w->display();
}

void Game::process_event() {
	while (w->pollEvent(*e)) {
		if (e->type == Event::Closed) {
			w->close();
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			player->set_position(Vector2f(player->get_position().x - 5, player->get_position().y));
			player->animation_player(0,128,32,3);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			player->set_position(Vector2f(player->get_position().x + 5, player->get_position().y));
			player->animation_player(0,96,32,3);
			//cout << "pos pj en x,y  " << player->get_position().x<<", "<<player->get_position().y << endl;
		}
        
		if (Keyboard::isKeyPressed(Keyboard::Space)) {//SI SE PRESIONA ESPACIO
			w->setKeyRepeatEnabled(false);            //BLOQUEO PARA QUE NO VUELVA A TOMAR LA ACCION HASTA TERMINAR EL CICLO
			//CICLO DE SUBIDA DEL SALTO ///////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i <= 12; i++) {//FOR DE SUBIDA
				timer->actualizar_temp();
				if (time_game->asSeconds() >= 0.5) {  //ESPERA MEDIO SEGUNDO 
					player->set_position(Vector2f(player->get_position().x, player->get_position().y - 2 * 4));//SE DESPLAZA HACIA ARRIBA (VELOCIDAD * -4)
					clock_game->restart();
					draw_game();
				}
			}
			//CICLO DE CAIDA DEL SALTO//////////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i < 7; i++) {   //FOR QUE RECORRE LAS POSICIONES DE LAS PLATAFORMAS
				pos_leap.x = player->get_position().x;         //EL CENTRO DEL PLAYER 
				pos_leap.y = player->get_position().y + 25;
				if (pos_leap.y <= platforms_pos[i]) {
					platform_current = platforms_pos[i];

					cout << "posicion saltando " << pos_leap.y;
					cout << "// plataforma actual " << platform_current << endl;
				}
			}
			for (int i = 0; i <= 12; i++) {
				//colision_arriba = false; //CUANDO EMPIEZA A CAER DESACTIVA LA COLISION CON EL BLOQUE
				timer->actualizar_temp();
				
				if (time_game->asSeconds() >= 0.5 && player->get_position().y +5 < platform_current) {       //CADA 0.5 SEGUNDO, SI ESTA POR ENCIMA DEL NIVEL DEL SUELO(445 EN EL EJE Y), SIGUE CAYENDO
					player->set_position(Vector2f(player->get_position().x, player->get_position().y + 2 * 4));//SE DESPLAZA HACIA ABAJO(CAE)(VELOCIDAD * 4)
					cout << "addadadadadad"<< player->get_position().y + 32<<endl;
					clock_game->restart();
					draw_game();
				}
			}
		}
		w->setKeyRepeatEnabled(true);
	}
}

