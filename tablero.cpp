// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "tablero.h"
#include "casilla.h"
#include <fstream>
#include <iostream>
using namespace std;

bool comprobarFilaColumna(int fila, int col);
bool comprobarNumero(int c);

void iniciaTablero(tTablero tablero)
{
	for (int i = 0; i < MAX_FILAS; i++)
		for (int j = 0; j < MAX_COLUMNAS; j++)
			iniciaCasilla(tablero[i][j]);
}

bool cargarTablero(string nombreFichero, tTablero tablero)
{
	bool abierto, fija;
	ifstream entrada;
	string basura;
	char c;

	entrada.open(nombreFichero);
	abierto = entrada.is_open();
	if (abierto)
	{
		for (int i = 0; i < MAX_FILAS; i++)
		{
			for (int j = 0; j < MAX_COLUMNAS; j++)
			{
				entrada >> c;
				rellenaCasilla(tablero[i][j], c, fija = true);
			}
			getline(entrada, basura);
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	entrada.close();

	return abierto;
}

void dibujarTablero(const tTablero tablero)
{
	for (int i = 0; i < MAX_FILAS; i++)
	{
		for (int j = 0; j < MAX_COLUMNAS; j++)
			dibujaCasilla(tablero[i][j]);
		cout << endl;
	}
}

bool ponerNum(tTablero tablero, int fila, int col, int c)
{
	bool posible = false;

	if (comprobarFilaColumna(fila, col) && comprobarNumero(c) && comprobarCasillaVacia(tablero[fila][col])) {
		tablero[fila][col].numero = c;
		tablero[fila][col].estado_casilla = c_rellena;
		posible = true;
	}

	return posible;
}

bool comprobarFilaColumna(int fila, int col) {
	return fila >= 1 && fila <= 9 && col >= 1 && col <= 9;
}

bool comprobarNumero(int c) {
	return c >= 1 && c <= 9;
}

bool borrarNum(tTablero tablero, int fila, int col)
{
	bool posible = false;

	if (comprobarFilaColumna(fila, col) && comprobarCasillaRellena(tablero[fila][col])) {
		tablero[fila][col].numero = 0;
		tablero[fila][col].estado_casilla = c_vacia;
		posible = true;
	}

	return posible;
}

bool tableroLleno(const tTablero tablero)
{
	bool relleno = false;
	int i = 0;

	while (i < MAX_FILAS && !relleno){
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

void mostrarPosibles(const tTablero tablero, int fila, int col)
{
	if (comprobarFilaColumna(fila, col))
		mostrar(tablero[fila][col].conjunto);
	else
		cout << "Las coordenadas no estan dentro de Sudoku" << endl;
}

void rellenarSimples(tTablero tablero)
{

}
