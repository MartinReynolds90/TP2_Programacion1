#include "Game.h"



Game::Game() {
}

Game::Game(int ancho_vent,int alto_vent, String nombre_vent) {
	srand(time(NULL));
	w = new RenderWindow(VideoMode(ancho_vent, alto_vent),nombre_vent);
	w->setFramerateLimit(fps);
	e = new Event;

	clock_player = new Clock();//sirve para la funcion animar del personaje
	time_player = new Time();

	tx_background = new Texture;
	sp_background = new Sprite;
	sp_puerta = new Sprite;
	tx_puerta = new Texture;

	tx_background->loadFromFile("assets/fondo_plataformas.png");//fondo
	sp_background->setTexture(*tx_background);
	tx_puerta->loadFromFile("assets/puerta.png");
	sp_puerta->setTexture(*tx_puerta);
	sp_puerta->setPosition(400, 25);

	timer = new Timer(30,600.0,40.0);//creo el temporizador
	player = new Player("assets/Juego2D_2.png",Vector2i(0,64), Vector2i(32, 32), Vector2f(450, 492));//creo el personaje
	speed_player = 5;  
	

	arr_pos_x[0] = 11;//arreglo de posiciones que tomaran las tortugas en su estadio inicial
	arr_pos_x[1] = 42;//TAMBIEN SE USAN PARA ESTABLECER LOS LIMITES DE DESPLAZAMIENTO DE LAS TORTUGAS 
	arr_pos_x[2] = 74;//DANDOLE UN X MINIMO Y UN X MAXIMO
	arr_pos_x[3] = 106;
	arr_pos_x[4] = 664;
	arr_pos_x[5] = 696;
	arr_pos_x[6] = 728;
	arr_pos_x[7] = 760;


	//LOS PARAMETROS QUE RECIBE EL CONSTRUCTOR DE LAS TORTUGAS SON: EL ARCHIVO DEL CUAL SACA EL SPRITE,UN VECTOR2F CON LA POSICION INICIAL EN PANTALLA Y DOS ENTEROS QUE ESTABLECEN LOS LIMITES EN X A LOS QUE PUEDE LEGAR CADA TORTUGA
	tortuga_cero = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[0], 347), arr_pos_x[0], arr_pos_x[4]);
	tortuga_uno = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[1],347 ),arr_pos_x[1], arr_pos_x[5]);
	tortuga_dos = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[2],347 ), arr_pos_x[2], arr_pos_x[6]);
	tortuga_tres = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[3],347 ), arr_pos_x[3], arr_pos_x[7]);

	tortuga_cuatro = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 266), arr_pos_x[3], arr_pos_x[7]);
	tortuga_cinco = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 266), arr_pos_x[2], arr_pos_x[6]);
	tortuga_seis = new Enemy("assets/shell_azul.png",  Vector2f(arr_pos_x[5], 266), arr_pos_x[1], arr_pos_x[5]);
	tortuga_siete = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 266), arr_pos_x[0], arr_pos_x[4]);

	tortuga_ocho = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 418), arr_pos_x[0], arr_pos_x[4]);
	tortuga_nueve = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6], 418), arr_pos_x[1], arr_pos_x[5]);
	tortuga_diez = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[5], 418), arr_pos_x[2], arr_pos_x[6]);
	tortuga_once = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4], 418), arr_pos_x[3], arr_pos_x[7]);

	tortuga_doce = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[0], 193), arr_pos_x[0], arr_pos_x[4]);
	tortuga_trece = new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[1], 193), arr_pos_x[1], arr_pos_x[5]);
	tortuga_catorce = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[2], 193), arr_pos_x[2], arr_pos_x[6]);
	tortuga_quince = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[3], 193), arr_pos_x[3], arr_pos_x[7]);

	tortuga_dieciseis = new Enemy("assets/shell_rojo.png", Vector2f(arr_pos_x[7], 120), arr_pos_x[3], arr_pos_x[7]);
	tortuga_diecisiete= new Enemy("assets/shell_amarillo.png", Vector2f(arr_pos_x[6] , 120), arr_pos_x[2], arr_pos_x[6]);
	tortuga_dieciocho = new Enemy("assets/shell_azul.png", Vector2f(arr_pos_x[5] , 120), arr_pos_x[1], arr_pos_x[5]);
	tortuga_diecinueve = new Enemy("assets/shell_verde.png", Vector2f(arr_pos_x[4] , 120), arr_pos_x[0], arr_pos_x[4]);


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

	vel = 2;
	colision = false;
	rect_player = new FloatRect;
	
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
	

	vuelven = false;// cambia a true cuando la ultima tortuga de la lista llega a el limite de la pantalla que le estableci

	/////////////////////CARGO LAS TORTUGAS A LAS CORRESPONDIENTES PILAS Y COLAS///////////////////////////////
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
		timer->actualizar_temp();//ACTUALIZA EL TEMPORIZADOR
		*rect_player = player->get_sprite().getGlobalBounds();//actualiza el globalBound del personaje en todo momento
		if (player->get_position().y < plataforma_destino) {//que caiga el personaje si no estoy presionando ninguna tecla
			player->set_position(Vector2f(player->get_position().x, player->get_position().y + 1));
		}
		if (player->get_position().y == plataforma_destino - 2) {//si ya llegó a la plataforma destino, entonces que actualice la plataforma destino a la siguiente
			plataforma_actual = plataforma_actual - 74;
			plataforma_destino = plataforma_destino - 74;
		}
		if (rect_player->intersects(sp_puerta->getGlobalBounds())) {//SI COLISIONA CON LA PUERTA GANA
			cout << "//////////////////////////// GANASTE //////////////////////////////" << endl;
		}
		if ((30- timer->get_time()) <= 0.0) {//SI PASARON LOS 30 SEG LE SETEO VELOCIDAD CERO AL JUGADOR
			speed_player = 0;
			cout << "============================ PERDISTE ============================" << endl;
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

		
		if (vuelven == true) {//ACA ENTRA CUANDO LAS 4 TORTUGAS LLEGARON AL OTRO EXTREMO DE LA PANTALLA, Y HACE QUE VUELVAN. LA VARIABLE vel CAMBIA SU SIGNO Y SE PASA COMO VELOCIDAD DE LAS TORTUGAS  
			//////////////////////////////PILA///////////////////////////////////////////////////////////

			if (cabeza_dos != NULL) {//ESTA PILA SIRVE COMO GUIA PARA LAS OTRAS Y SE ACTIVA CUANDO SE VACIA LA CABEZA SECUNDARIA(cabeza)
				if (cabeza_dos->dato.get_position().x >= cabeza_dos->dato.get_min_x()) {//MIENTRAS NO SE SALGA DEL LIMITE IZQUIERDO QUE LE PUSE A LA TORTUGA EN EL CONSTRUCTOR
			 		cabeza_dos->dato.caminar(-vel);    //LLAMO A LA FUNCION CAMINAR DE LAS TORTUGAS DE LAS TRES PILAS, AL LLEGAR A SU LIMITE ESTABLECIDO, SE BORRA LA CABEZA Y LA QUE SIGUE TOMA EL LUGAR
					cabeza_cuatro->dato.caminar(vel);  //CADA NODO DE ESTAS TRES PILAS SE BORRA DE LA CIMA Y SE AGREGA A OTRA PILA QUE SE USARA PARA EL RETORNO DE LAS TORTUGAS
					cabeza_seis->dato.caminar(vel);    //ESTAS SON LAS TRES PILAS QUE HACEN EL PRIMER RECORRIDO, HASTA ATRAVESAR LA PANTALLA POR PRIMERA VEZ
				}
				else {//si llega al extremo opuesto borro el nodo de la pila y lo agrego en la segunda pila
					pila->agregar(*&cabeza, cabeza_dos->dato);     
					pila_dos->borrar(*&cabeza_dos, *&borrar_dos);
					pila_tres->agregar(*&cabeza_tres, cabeza_cuatro->dato);
					pila_cuatro->borrar(*&cabeza_cuatro, *&borrar_cuatro);
					pila_cinco->agregar(*&cabeza_cinco, cabeza_seis->dato);
					pila_seis->borrar(*&cabeza_seis, *&borrar_seis);
				}
			}
			else {//DESPUES DE QUE TODAS LAS TORTUGAS DE LAS TRES PILAS (pila_dos, pila_cuatro, pila_seis)LLEGARON AL EXTREMO OPUESTO DE LA PANTALLA Y SE CARGARON EN 3 PILAS SECUNDARIAS 
				vuelven = false;// VUELVEN CAMBIA SU VALOR A FALSE Y LAS PILAS SECUNDARIAS SE ACTIVAN (pila,pila_tres,pila_cinco)
			}

		}
		else if (vuelven == false) {
			if (!cola_uno->cola_vacia()) {//MOVIMIENTO DE LOS ELEMENTOS DE LAS COLAS
				Enemy borrado = cola_uno->borrar();
				cout << borrado.get_position().x;
				if (borrado.get_position().x >= borrado.get_min_x()) {
					borrado.caminar(vel);
					cout << "POSICION EN X DEL DATO, DEL NODO FRENTE  "<<borrado.get_position().x << endl;
				}
				else {//si llega al extremo opuesto, la borro del frente y la agrego en el fin
					cola_uno->agregar(*&frente_uno, *&fin_uno, borrado);
				}

			}

			///////////////////////////////pilas volviendo////////////////////////////////

			if (cabeza != NULL) {//ESTA PILA SE RECORRE CUANDO LA PRIMERA(cabeza_dos) SE VACIA
				if (cabeza->dato.get_position().x <= cabeza->dato.get_max_x()) {//MIENTRAS NO SE SALGA DEL LIMITE DERECHO QUE SE LE DIO A CADA TORTUGA EN EL CONSTRUCTOR
					cabeza->dato.caminar(vel);                          //CAMINAN HASTA LLEGAR A SU LIMITE DERECHO
					cabeza_tres->dato.caminar(-vel);                    
					cabeza_cinco->dato.caminar(-vel);

				}
				else {//AL LLEGAR AL LIMITE DERECHO ENTRA EN ESTE ELSE Y SE BORRA LA CABEZA, PERO ANTES SE LA AGREGA A UNA PILA SECUNDARIA, ASI SE ALTERNAN 2 GRUPOS DE 3 PILAS. 
					pila_dos->agregar(*&cabeza_dos, cabeza->dato);//guardo en pila DOS lo qeu hay en pila
					pila->borrar(*&cabeza, *&borrar);//borro lo que hay en pila
					pila_cuatro->agregar(*&cabeza_cuatro, cabeza_tres->dato);//guardo en pila CUATRO lo que hay en pila TRES
					pila_tres->borrar(*&cabeza_tres, *&borrar_tres);//borro lo que hay en pila TRES
					pila_seis->agregar(*&cabeza_seis, cabeza_cinco->dato);//guardo en pila SEIS lo que hay en pila CINCO
					pila_cinco->borrar(*&cabeza_cinco, *&borrar_cinco);//borro lo que hay en pila CINCO
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
			player->set_position(Vector2f(player->get_position().x - speed_player, player->get_position().y));
			player->animation_player(0,128,32,3);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			player->set_position(Vector2f(player->get_position().x + speed_player, player->get_position().y));
			player->animation_player(0,96,32,3);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {//SI SE PRESIONA ESPACIO
			if ( player->get_position().y  >= plataforma_destino) {
				player->set_position(Vector2f(player->get_position().x, player->get_position().y - speed_player*7));
			}
		}
	}
}

