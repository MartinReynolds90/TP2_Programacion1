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
	clock_player = new Clock();
	time_player = new Time();

	tx_background = new Texture;
	sp_background = new Sprite;
	tx_background->loadFromFile("assets/fondo_plataformas.png");
	sp_background->setTexture(*tx_background);


	timer = new Timer(30,600.0,40.0);
	player = new Player("assets/Juego2D_2.png",Vector2i(0,64), Vector2i(32, 32), Vector2f(450, 492));
	vel = 5;

	//l_derecho = 790;
	//l_izquierdo = 10;

	arr_pos_x[0] = 11;
	arr_pos_x[1] = 42;
	arr_pos_x[2] = 74;
	arr_pos_x[3] = 106;
	arr_pos_x[4] = 664;
	arr_pos_x[5] = 696;
	arr_pos_x[6] = 728;
	arr_pos_x[7] = 760;



	enemy = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[0], 347), arr_pos_x[0], arr_pos_x[4]);
	enemi_uno = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[1],347 ),arr_pos_x[1], arr_pos_x[5]);
	enemi_dos = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[2],347 ), arr_pos_x[2], arr_pos_x[6]);
	enemi_tres = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[3],347 ), arr_pos_x[3], arr_pos_x[7]);

	enemi_cuatro = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 266), arr_pos_x[0], arr_pos_x[4]);;
	enemi_cinco = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 266), arr_pos_x[1], arr_pos_x[5]);
	enemi_seis = new Enemy("assets/shell_azul.png",  Vector2f(arr_pos_x[5], 266), arr_pos_x[2], arr_pos_x[6]);
	enemi_siete = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 266), arr_pos_x[3], arr_pos_x[7]);

	platform_current = 0;
	platforms_pos[0]= 492;
	platforms_pos[1] = 418;
	platforms_pos[2] = 345;
	platforms_pos[3] = 266;
	platforms_pos[4] = 193;
	platforms_pos[5] = 120;
	platforms_pos[6] = 43;


	pila = new Pila;
	cabeza = new Nodo;
	borrar = new Nodo;

	pila_dos = new Pila;
	cabeza_dos = new Nodo;
	borrar_dos = new Nodo;

	pila_tres = new Pila;
	cabeza_tres = new Nodo;
	borrar_tres = new Nodo;

	pila_cuatro = new Pila;
	cabeza_cuatro = new Nodo;
	borrar_cuatro = new Nodo;
	//temporal = new Enemy;
	

	vuelven = false;
	//vuelven_dos = false;
	pila->agregar(*&cabeza, *enemy);
	pila->agregar(*&cabeza, *enemi_uno);
	pila->agregar(*&cabeza, *enemi_dos);
	pila->agregar(*&cabeza, *enemi_tres);

	pila_tres->agregar(*&cabeza_tres, *enemi_cuatro);
	pila_tres->agregar(*&cabeza_tres, *enemi_cinco);
	pila_tres->agregar(*&cabeza_tres, *enemi_seis);
	pila_tres->agregar(*&cabeza_tres, *enemi_siete);

	game_loop();
}


void Game::game_loop() {
	while (w->isOpen()) {
		timer->actualizar_temp();
		*time_game = clock_game->getElapsedTime();

		
			switch (vuelven) {
			case true:
				if (cabeza_dos != NULL) {
					if (cabeza_dos->dato.get_position().x >= cabeza_dos->dato.get_min_x()) {
						cabeza_dos->dato.caminar(-vel);
					}
					else {
						pila->agregar(*&cabeza, cabeza_dos->dato);
						pila_dos->borrar(*&cabeza_dos, *&borrar_dos);
					}
					///////////////////////////////////////////////////////////////////
					/*if (cabeza_cuatro->dato.get_position().x <= cabeza_cuatro->dato.get_max_x()) {
						cabeza_cuatro->dato.caminar(vel);
					}
					else {
						pila_tres->agregar(*&cabeza_tres, cabeza_cuatro->dato);
						pila_cuatro->borrar(*&cabeza_cuatro, *&borrar_cuatro);
					}*/
				}
				else {
					vuelven = false;
				}
              
				break;
			
			case false: 
				if (cabeza != NULL) {
					if (cabeza->dato.get_position().x <= cabeza->dato.get_max_x()) {
						cabeza->dato.caminar(vel);
					}
					else {
						pila_dos->agregar(*&cabeza_dos, cabeza->dato);//guardo en pila dos lo qeu hay en pila
						pila->borrar(*&cabeza, *&borrar);//borro lo que hay en pila
					}
					////////////////////////////////////////////////////////////////////////
					/*if (cabeza_tres->dato.get_position().x >= cabeza_tres->dato.get_min_x()) {
						cabeza_tres->dato.caminar(-vel);
					}
					else {
						pila_cuatro->agregar(*&cabeza_cuatro, cabeza_tres->dato);//guardo en pila cuatro lo que hay en pila tres
						pila_tres->borrar(*&cabeza_tres, *&borrar_tres);//borro lo que hay en pila tres
					}*/
				}
				else {
					vuelven = true;
				}

				break;
			}
		process_event();
		draw_game();
	}
}


void Game::draw_game() {
	w->clear(Color(255, 255, 255, 255));
	w->draw(*sp_background);
	w->draw(player->get_sprite());
	w->draw(enemy->get_sprite());
	w->draw(enemi_uno->get_sprite());
	w->draw(enemi_dos->get_sprite());
	w->draw(enemi_tres->get_sprite());

	/*w->draw(enemi_cuatro->get_sprite());
	w->draw(enemi_cinco->get_sprite());
	w->draw(enemi_seis->get_sprite());
	w->draw(enemi_siete->get_sprite());*/
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
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {//SI SE PRESIONA ESPACIO
			w->setKeyRepeatEnabled(false);            //BLOQUEO PARA QUE NO VUELVA A TOMAR LA ACCION HASTA TERMINAR EL CICLO
			//CICLO DE SUBIDA DEL SALTO ///////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i <= 12; i++) {//FOR DE SUBIDA
				timer->actualizar_temp();
				if (player->get_time() >= 0.5) {  //ESPERA MEDIO SEGUNDO 
					player->set_position(Vector2f(player->get_position().x, player->get_position().y - 2 * 4));//SE DESPLAZA HACIA ARRIBA (VELOCIDAD * -4)
					clock_player->restart();
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
				if (player->get_time() >= 0.5 && player->get_position().y + 5 < platform_current) {         //CADA 0.5 SEGUNDO, SI ESTA POR ENCIMA DEL NIVEL DEL SUELO(445 EN EL EJE Y), SIGUE CAYENDO
					player->set_position(Vector2f(player->get_position().x, player->get_position().y + 2 * 4));//SE DESPLAZA HACIA ABAJO(CAE)(VELOCIDAD * 4)
					cout << "addadadadadad"<< player->get_position().y + 32<<endl;
					clock_player->restart();
					draw_game();
				}
			}
		}
		w->setKeyRepeatEnabled(true);
	}
}

