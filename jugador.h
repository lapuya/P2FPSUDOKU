// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once
#include <string>
using namespace std;

typedef struct {
	string identificador;
	int puntos;
}tJugador;

string toString(tJugador jugador);
void modificarJugador(tJugador &jugador, int puntos);
bool operator<(const tJugador &opIzq, const tJugador &opDer);
bool menor(const tJugador &j1, const tJugador &j2);
void mostrarJugador(const tJugador &jugador);
string devolverIdentificadorJugador(const tJugador &jugador);
void asignarIdentificadorPuntos(tJugador & jugador, string identificador, int puntos);
void escribirJugador(const tJugador & jugador, string & identificador, int & puntos);
