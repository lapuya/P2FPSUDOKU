// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "jugador.h"
#include <iostream>

string toString(tJugador jugador) {
	int puntos;

	puntos = jugador.puntos;
	string aCadena = to_string(puntos);

	return jugador.identificador + aCadena;
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.puntos += puntos;
}

bool operator<(const tJugador & opIzq, const tJugador & opDer) {
	return opIzq.identificador < opDer.identificador;
}

bool menor(const tJugador & j1, const tJugador & j2) {
	bool menor = false;

	if (j1.puntos == j2.puntos && j2.identificador < j1.identificador) {
		menor = true;
	}
	else if (j1.puntos < j2.puntos) {
		menor = true;
	}

	return menor;
}

void mostrarJugador(const tJugador & jugador) {
	cout << "Jugador: " << jugador.identificador << endl;
	cout << "Puntos: " << jugador.puntos << endl;
}

string devolverIdentificadorJugador(const tJugador &jugador) {
	return jugador.identificador;
}

void asignarIdentificadorPuntos(tJugador & jugador, string identificador, int puntos) {
	jugador.identificador = identificador;
	jugador.puntos = puntos;
}

void escribirJugador(const tJugador & jugador, string & identificador, int & puntos) {
	identificador = jugador.identificador;
	puntos = jugador.puntos;
}
