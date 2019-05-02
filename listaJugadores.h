// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once
#include "jugador.h"

typedef tJugadorPtr * tArrayJugadores;

typedef struct {
	tArrayJugadores array_jugadores;
	int cont;
	int capacidad;
}tListaJugadores;

void crearListaVacia(tListaJugadores &lista);
bool cargar(tListaJugadores &lista);
void mostrar(const tListaJugadores &lista);
bool guardar(const tListaJugadores &lista);
void puntuarJugador(tListaJugadores &lista, int puntos);
bool buscar(const tListaJugadores &lista, string id, int &pos);
tListaJugadores ordenarPorRanking(const tListaJugadores &lista);
void ampliar(tListaJugadores & lista);
void borrarListaJugadores(tListaJugadores & lista);
