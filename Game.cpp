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
	sp_puerta = new Sprite;
	tx_puerta = new Texture;

	tx_background->loadFromFile("assets/fondo_plataformas.png");
	sp_background->setTexture(*tx_background);
	tx_puerta->loadFromFile("assets/puerta.png");
	sp_puerta->setTexture(*tx_puerta);
	sp_puerta->setPosition(400, 25);

	timer = new Timer(30,600.0,40.0);
	player = new Player("assets/Juego2D_2.png",Vector2i(0,64), Vector2i(32, 32), Vector2f(450, 492));
	vel = 2;

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



	tortuga_cero = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[0], 347), arr_pos_x[0], arr_pos_x[4]);
	tortuga_uno = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[1],347 ),arr_pos_x[1], arr_pos_x[5]);
	tortuga_dos = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[2],347 ), arr_pos_x[2], arr_pos_x[6]);
	tortuga_tres = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[3],347 ), arr_pos_x[3], arr_pos_x[7]);

	tortuga_cuatro = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 266), arr_pos_x[3], arr_pos_x[7]);;
	tortuga_cinco = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 266), arr_pos_x[2], arr_pos_x[6]);
	tortuga_seis = new Enemy("assets/shell_azul.png",  Vector2f(arr_pos_x[5], 266), arr_pos_x[1], arr_pos_x[5]);
	tortuga_siete = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 266), arr_pos_x[0], arr_pos_x[4]);

	tortuga_ocho = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 418), arr_pos_x[0], arr_pos_x[4]);;
	tortuga_nueve = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 418), arr_pos_x[1], arr_pos_x[5]);
	tortuga_diez = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[5], 418), arr_pos_x[2], arr_pos_x[6]);
	tortuga_once = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 418), arr_pos_x[3], arr_pos_x[7]);

	tortuga_doce = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[0], 193), arr_pos_x[3], arr_pos_x[7]);;
	tortuga_trece = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[1], 193), arr_pos_x[2], arr_pos_x[6]);
	tortuga_catorce = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[2], 193), arr_pos_x[1], arr_pos_x[5]);
	tortuga_quince = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[3], 193), arr_pos_x[0], arr_pos_x[4]);

	tortuga_dieciseis = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 120), arr_pos_x[0], arr_pos_x[4]);;
	tortuga_diecisiete= new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 120), arr_pos_x[1], arr_pos_x[5]);
	tortuga_dieciocho = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[5], 120), arr_pos_x[2], arr_pos_x[6]);
	tortuga_diecinueve = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 120), arr_pos_x[3], arr_pos_x[7]);


	tortugas[0] = tortuga_cero;
	tortugas[1] = tortuga_uno;
	tortugas[2] = tortuga_dos;
	tortugas[3] = tortuga_tres;
	tortugas[4] = tortuga_cuatro;
	tortugas[5] = tortuga_cinco;
	tortugas[6] = tortuga_seis;
	tortugas[7] = tortuga_siete;
	tortugas[8] = tortuga_ocho;
	tortugas[9] = tortuga_nueve;
	tortugas[10] = tortuga_diez;
	tortugas[11] = tortuga_once;
	tortugas[12] = tortuga_doce;
	tortugas[13] = tortuga_trece;
	tortugas[14] = tortuga_catorce;
	tortugas[15] = tortuga_quince;
	tortugas[16] = tortuga_dieciseis;
	tortugas[17] = tortuga_diecisiete;
	tortugas[18] = tortuga_dieciocho;
	tortugas[19] = tortuga_diecinueve;


	colision = false;
	rect_player = new FloatRect;
	

	/*salto = false;
	platforms_pos[0]= 492;
	platforms_pos[1] = 418;
	platforms_pos[2] = 345;
	platforms_pos[3] = 266;
	platforms_pos[4] = 193;
	platforms_pos[5] = 120;
	platforms_pos[6] = 43;*/
	plataforma_actual = 492;
	plataforma_destino = 418;


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

	pila_cinco = new Pila;
	cabeza_cinco = new Nodo;
	borrar_cinco = new Nodo;

	pila_seis = new Pila;
	cabeza_seis = new Nodo;
	borrar_seis = new Nodo;
    
	cola_uno = new Cola;
	frente_uno = new Nodo;
	fin_uno = new Nodo;

	cola_dos = new Cola;
	frente_dos = new Nodo;
	fin_dos = new Nodo;
	

	vuelven = false;
	//vuelven_dos = false;
	pila->agregar(*&cabeza, *tortuga_cero);
	pila->agregar(*&cabeza, *tortuga_uno);
	pila->agregar(*&cabeza, *tortuga_dos);
	pila->agregar(*&cabeza, *tortuga_tres);

	pila_tres->agregar(*&cabeza_tres, *tortuga_cuatro);
	pila_tres->agregar(*&cabeza_tres, *tortuga_cinco);
	pila_tres->agregar(*&cabeza_tres, *tortuga_seis);
	pila_tres->agregar(*&cabeza_tres, *tortuga_siete);

	pila_cinco->agregar(*&cabeza_cinco, *tortuga_ocho);
	pila_cinco->agregar(*&cabeza_cinco, *tortuga_nueve);
	pila_cinco->agregar(*&cabeza_cinco, *tortuga_diez);
	pila_cinco->agregar(*&cabeza_cinco, *tortuga_once);

	cola_uno->agregar(*&frente_uno, *&fin_uno, *tortuga_doce);
	cola_uno->agregar(*&frente_uno, *&fin_uno, *tortuga_trece);
	cola_uno->agregar(*&frente_uno, *&fin_uno, *tortuga_catorce);
	cola_uno->agregar(*&frente_uno, *&fin_uno, *tortuga_quince);

	cola_dos->agregar(*&frente_dos, *&fin_dos, *tortuga_dieciseis);
	cola_dos->agregar(*&frente_dos, *&fin_dos, *tortuga_diecisiete);
	cola_dos->agregar(*&frente_dos, *&fin_dos, *tortuga_dieciocho);
	cola_dos->agregar(*&frente_dos, *&fin_dos, *tortuga_diecinueve);



	game_loop();
}


void Game::game_loop() {
	while (w->isOpen()) {
		timer->actualizar_temp();
		*time_game = clock_game->getElapsedTime();
		*rect_player = player->get_sprite().getGlobalBounds();
		if (player->get_position().y < plataforma_destino) {//que caiga el personaje si no estoy presionando ninguna tecla
			player->set_position(Vector2f(player->get_position().x, player->get_position().y + 1));
		}
		if (player->get_position().y == plataforma_destino - 5) {//si ya llegó a la plataforma destino, entonces que actualice la plataforma destino a la siguiente
			plataforma_actual = plataforma_actual - 74;
			plataforma_destino = plataforma_destino - 74;
		}
		if (rect_player->intersects(sp_puerta->getGlobalBounds())) {
			cout << "Victoria========================================" << endl;
		}
		//////////////COLISION CON TORTUGAS////////////////////////////////
		for (int i = 0; i < 20; i++) {
			FloatRect rect_tortugas = tortugas[i]->get_sprite().getGlobalBounds();
			if (rect_player->intersects(rect_tortugas)) {
				colision = true;
				player->set_position(Vector2f(400, 492));
				plataforma_actual = 492;
				plataforma_destino = 418;
			}
			else {
				colision = false;
			}
		}

		
		if (vuelven == true) {
			if (cabeza_dos != NULL) {
				if (cabeza_dos->dato.get_position().x >= cabeza_dos->dato.get_min_x()) {
					cabeza_dos->dato.caminar(-vel);
					cabeza_cuatro->dato.caminar(vel);
					cabeza_seis->dato.caminar(vel);
				}
				else {
					pila->agregar(*&cabeza, cabeza_dos->dato);
					pila_dos->borrar(*&cabeza_dos, *&borrar_dos);
					pila_tres->agregar(*&cabeza_tres, cabeza_cuatro->dato);
					pila_cuatro->borrar(*&cabeza_cuatro, *&borrar_cuatro);
					pila_cinco->agregar(*&cabeza_cinco, cabeza_seis->dato);
					pila_seis->borrar(*&cabeza_seis, *&borrar_seis);
				}
			}
			else {
				vuelven = false;
			}

		}
		else if (vuelven == false) {
			if (cabeza != NULL) {
				if (cabeza->dato.get_position().x <= cabeza->dato.get_max_x()) {
					cabeza->dato.caminar(vel);
					cabeza_tres->dato.caminar(-vel);
					cabeza_cinco->dato.caminar(-vel);
				}
				else {
					pila_dos->agregar(*&cabeza_dos, cabeza->dato);//guardo en pila dos lo qeu hay en pila
					pila->borrar(*&cabeza, *&borrar);//borro lo que hay en pila
					pila_cuatro->agregar(*&cabeza_cuatro, cabeza_tres->dato);//guardo en pila cuatro lo que hay en pila tres
					pila_tres->borrar(*&cabeza_tres, *&borrar_tres);//borro lo que hay en pila tres
					pila_seis->agregar(*&cabeza_seis, cabeza_cinco->dato);//guardo en pila seis lo que hay en pila cinco
					pila_cinco->borrar(*&cabeza_cinco, *&borrar_cinco);//borro lo que hay en pila cinco
				}
			}
			else {
				vuelven = true;
			}
		}
			
		process_event();
		draw_game();
	}
}


void Game::draw_game() {
	w->clear(Color(255, 255, 255, 255));
	w->draw(*sp_background);
	w->draw(*sp_puerta);
	for (int i = 0; i < 20; i++) {
		w->draw(tortugas[i]->get_sprite());
	}
	w->draw(player->get_sprite());
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
			if ( player->get_position().y  >= plataforma_destino) {
				player->set_position(Vector2f(player->get_position().x, player->get_position().y - 35));
				//cout << "pos pj..............................................." << player->get_position().y<<endl;
			}
		}


			//CICLO DE SUBIDA DEL SALTO ///////////////////////////////////////////////////////////////////////////////////
			/*for (int i = 0; i <= 12; i++) {//FOR DE SUBIDA
				timer->actualizar_temp();
				//*time_game = clock_game->getElapsedTime();
				//*time_player = clock_player->getElapsedTime();
				if (player->get_time() >= 0.5) {  //ESPERA MEDIO SEGUNDO 
					player->set_position(Vector2f(player->get_position().x, player->get_position().y - 2 * 4));//SE DESPLAZA HACIA ARRIBA (VELOCIDAD * -4)
					clock_player->restart();
					draw_game();
				}
				//draw_game();
				//game_loop();
			}
			//CICLO DE CAIDA DEL SALTO//////////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i < 7; i++) {   //FOR QUE RECORRE LAS POSICIONES DE LAS PLATAFORMAS
				timer->actualizar_temp();
				//*time_game = clock_game->getElapsedTime();
				//*time_player = clock_player->getElapsedTime();
				pos_leap.x = player->get_position().x;         //EL CENTRO DEL PLAYER 
				pos_leap.y = player->get_position().y + 25;
				if (pos_leap.y <= platforms_pos[i]) {
					platform_current = platforms_pos[i];
					cout << "posicion saltando " << pos_leap.y;
					cout << "// plataforma actual " << platform_current << endl;
					clock_player->restart();
					draw_game();
				}
				//draw_game();
				//game_loop();
			}
			for (int i = 0; i <= 12; i++) {
				timer->actualizar_temp();
				//*time_game = clock_game->getElapsedTime();
				//*time_player = clock_player->getElapsedTime();
				if (player->get_time() >= 0.5 && player->get_position().y + 5 < platform_current) {         //CADA 0.5 SEGUNDO, SI ESTA POR ENCIMA DEL NIVEL DEL SUELO(445 EN EL EJE Y), SIGUE CAYENDO
					player->set_position(Vector2f(player->get_position().x, player->get_position().y + 2 * 4));//SE DESPLAZA HACIA ABAJO(CAE)(VELOCIDAD * 4)
					cout << "addadadadadad"<< player->get_position().y + 32<<endl;
					clock_player->restart();
					draw_game();
				}
				//draw_game();
				//game_loop();
			}*/
		

		
	}
}

