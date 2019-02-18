// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once

#include "tablero.h"
#include <string>
using namespace std;

typedef struct
{
	int puntos;
	string nombre_archivo;
}tSudoku;

typedef struct
{
	tSudoku sudoku;
	tTablero tablero;
	bool tablero_completo;
}tJuego;

void iniciaJuego(tJuego & juego, const tSudoku & sudoku);
void mostrarJuego(const tJuego & juego);
bool cargaJuego(tJuego & juego, const tSudoku & sudoku);
int jugarUnSudoku(const tSudoku & sudoku);
