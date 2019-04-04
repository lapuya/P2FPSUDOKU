// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once
#include "jugador.h"
const int MAX_JUGADORES = 10;

typedef tJugador tArrayJugadores[MAX_JUGADORES];

typedef struct {
	tArrayJugadores array_jugadores;
	int cont;
}tListaJugadores;

void crearListaVacia(tListaJugadores &lista);
bool cargar(tListaJugadores &lista);
void mostrar(const tListaJugadores &lista);
bool guardar(const tListaJugadores &lista);
void puntuarJugador(tListaJugadores &lista, int puntos);
bool buscar(const tListaJugadores &lista, string id, int &pos);
tListaJugadores ordenarPorRanking(const tListaJugadores &lista);
