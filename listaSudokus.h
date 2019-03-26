// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once

#include "juego.h"

const int MAX_SUDOKUS = 20;

typedef tSudoku tArraySudokus[MAX_SUDOKUS];

typedef struct
{
	tArraySudokus array_sudokus;
	int cont;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);
void devolverPuntos(const tListaSudokus & lista, string nombre, int & puntos);
