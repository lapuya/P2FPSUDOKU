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
	bool tablero_relleno;
}tJuego;

void iniciaJuego(tJuego & juego, const tSudoku & sudoku);
void mostrarJuego(const tJuego & juego);
bool cargaJuego(tJuego & juego, const tSudoku & sudoku);
int jugarUnSudoku(const tSudoku & sudoku);
void asignarNombrePuntos(tSudoku &sudoku, string nombre, int puntos);
void mostrarInformacionSudoku(const tSudoku & sudoku);
bool nombrePuntos(const tSudoku & sudoku, string nombre, int & puntos);
void escribir(const tSudoku &sudoku, string & nombre, int & puntos);
string devolverNombre(const tSudoku &sudoku);
int devolverPuntos(const tSudoku &sudoku);
