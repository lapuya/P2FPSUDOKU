// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "tablero.h"
#include "casilla.h"
#include <fstream>
#include <iostream>
using namespace std;

bool comprobarFilaColumna(int fila, int col);
bool comprobarNumero(int c);
void actualizarValoresColumnas(tTablero  tablero, int fila, int col);
void actualizarValoresFilas(tTablero tablero, int fila, int col);
void actualizarValoresRegion(tTablero tablero, int fila, int col);
void actualizarRegion(int x, int y, tTablero tablero, int fila, int col);

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < MAX_FILAS; i++)
		for (int j = 0; j < MAX_COLUMNAS; j++)
			iniciaCasilla(tablero[i][j]);
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	bool abierto, fija;
	ifstream entrada;
	string linea;
	char c;

	entrada.open(nombreFichero);
	abierto = entrada.is_open();
	if (abierto)
	{
		for (int i = 0; i < MAX_FILAS; i++)
		{
			getline(entrada, linea);
			for (int j = 0; j < MAX_COLUMNAS; j++)
			{
				c = linea[j];
				rellenaCasilla(tablero[i][j], c, fija = true);
			}
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	entrada.close();

	return abierto;
}

void dibujarTablero(const tTablero tablero) {
	for (int i = 0; i < MAX_FILAS; i++)
	{
		for (int j = 0; j < MAX_COLUMNAS; j++)
			dibujaCasilla(tablero[i][j]);
		cout << endl;
	}
}

bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool posible = false, fija;

	if (comprobarFilaColumna(fila, col) && comprobarNumero(c) && comprobarCasillaVacia(tablero[fila][col])) {
		rellenaCasilla(tablero[fila][col], c, fija = false);
		posible = true;
	}



	return posible;
}

bool comprobarFilaColumna(int fila, int col) {
	return fila >= 0 && fila < MAX_FILAS && col >= 0 && col < MAX_COLUMNAS;
}

bool comprobarNumero(int c) {
	return c >= 1 && c <= 9;
}

bool borrarNum(tTablero tablero, int fila, int col) {
	bool posible = false;

	if (comprobarFilaColumna(fila, col) && comprobarCasillaRellena(tablero[fila][col])) {
		iniciaCasilla(tablero[fila][col]);
		posible = true;
	}

	return posible;
}

bool tableroLleno(const tTablero tablero) {
	bool relleno = false;
	int i = 0;

	while (i < MAX_FILAS && !relleno) {
		int j = 0;
		while (j < MAX_COLUMNAS && !relleno) {
			if (comprobarCasillaVacia(tablero[i][j]))
				relleno = true;
			else
				j++;
		}
		if (!relleno)
			i++;
	}

	return relleno;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	if (comprobarFilaColumna(fila, col)) {
		mostrarValores(tablero[fila][col]);
	}
	else {
		cout << "Las coordenadas no estan dentro de Sudoku" << endl;
	}
}

void actualizarValoresPosiblesCasilla(tTablero tablero, int fila, int col) {
	actualizarValoresColumnas(tablero, fila, col);
	actualizarValoresFilas(tablero, fila, col);
	actualizarValoresRegion(tablero, fila, col);
}

void rellenarSimples(tTablero tablero) {
	int n;
	bool fija;

	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			if (esSimple(tablero[i][j], n)) {
				rellenaCasilla(tablero[i][j], n, fija = false);
			}
		}
	}
}

void actualizarValoresColumnas(tTablero tablero, int fila, int col) {

	for (int j = 0; j < MAX_COLUMNAS; j++) {
		actualizarValor(tablero[fila][col], tablero[fila][j]);
	}
}

void actualizarValoresFilas(tTablero tablero, int fila, int col) {
	for (int i = 0; i < MAX_FILAS; i++) {
		actualizarValor(tablero[fila][col], tablero[i][col]);
	}
}

void actualizarValoresRegion(tTablero tablero, int fila, int col) {
	if (col < 3 && fila < 3)
		actualizarRegion(0, 0, tablero, fila, col);
	else if (col < 6 && fila < 3)
		actualizarRegion(0, 3, tablero, fila, col);
	else if (col < 9 && fila < 3)
		actualizarRegion(0, 6, tablero, fila, col);
	else if (col < 3 && fila < 6)
		actualizarRegion(3, 0, tablero, fila, col);
	else if (col < 6 && fila < 6)
		actualizarRegion(3, 3, tablero, fila, col);
	else if (col < 9 && fila < 6)
		actualizarRegion(3, 6, tablero, fila, col);
	else if (col < 3 && fila < 9)
		actualizarRegion(6, 0, tablero, fila, col);
	else if (col < 6 && fila < 9)
		actualizarRegion(6, 3, tablero, fila, col);
	else
		actualizarRegion(6, 6, tablero, fila, col);

}
void actualizarRegion(int x, int y, tTablero  tablero, int fila, int col) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			actualizarValor(tablero[fila][col], tablero[i][j]);
}
