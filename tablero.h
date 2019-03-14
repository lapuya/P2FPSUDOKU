// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once

#include "casilla.h"
#include <string>
using namespace std;

const int MAX_FILAS = 9;
const int MAX_COLUMNAS = 9;

typedef tCasilla tTablero[MAX_FILAS][MAX_COLUMNAS];

void iniciaTablero(tTablero tablero);
bool cargarTablero(string nombreFichero, tTablero tablero);
void dibujarTablero(const tTablero tablero);
bool ponerNum(tTablero tablero, int fila, int col, int c);
bool borrarNum(tTablero tablero, int fila, int col);
bool tableroLleno(const tTablero tablero);
void mostrarPosibles(const tTablero tablero, int fila, int col);
void rellenarSimples(tTablero tablero);
void actualizarValoresPosiblesCasilla(tTablero tablero, int fila, int col);
