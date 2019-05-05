// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once
#include <string>
using namespace std;

typedef struct {
	string identificador;
	int puntos;
}tJugador;

typedef tJugador * tJugadorPtr;

string toString(tJugador jugador);
void modificarJugador(tJugador &jugador, int puntos);
bool menor(const tJugador &j1, const tJugador &j2);
string devolverIdentificadorJugador(const tJugador &jugador);
void asignarIdentificadorPuntos(tJugador & jugador, string identificador, int puntos);
void escribirJugador(const tJugador & jugador, string & identificador, int & puntos);
