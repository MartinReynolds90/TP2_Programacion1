#include "Timer.h"
#include "iostream"

using namespace std;

Timer::Timer(int tiempoJuego, float x, float y) { //recibe como parametros el TIEMPO INICIAL y su POSICION EN PANTALLA
	tiempo_inicial = tiempoJuego;
	clock_timer = new Clock();
	time_timer = new Time();
	*time_timer = clock_timer->getElapsedTime();

	font_timer.loadFromFile("assets/Square.ttf");
	text_timer.setFont(font_timer);
	string_timer = " " + to_string(tiempo_inicial - static_cast<int>(time_timer->asSeconds()));
	text_timer.setString(string_timer);
	text_timer.setPosition(x, y);
	text_timer.setFillColor(Color::White);


}
void Timer::actualizar_temp() {           //ACTUALIZA EL TIEMPO DEL TEMPORIZADOR EN SEGUNDOS
	*time_timer = clock_timer->getElapsedTime();
	string_timer = "Tiempo: " + to_string(tiempo_inicial - static_cast<int>(time_timer->asSeconds()));
	text_timer.setString(string_timer);
}


Text Timer::get_text() { //OBTIENE EL TEXTO PARA PODER DIBUJARLO
	return text_timer;
}

float Timer::get_time() {
	float t;
	*time_timer = clock_timer->getElapsedTime();
	t = time_timer->asSeconds();
	return t;
}
