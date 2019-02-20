// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "tablero.h"
#include <fstream>
#include <iostream>
using namespace std;

void iniciaTablero(tTablero tablero)
{
	for (int i = 0; i < MAX_FILAS; i++)
		for (int j = 0; j < MAX_COLUMNAS; j++)
			iniciaCasilla(tablero[i][j]);
}

bool cargarTablero(string nombreFichero, tTablero tablero)
{
	bool abierto;
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
			cout << tablero[i][j].numero;
		cout << endl;
	}
}

bool ponerNum(tTablero tablero, int fila, int col, int c)
{

}

bool borrarNum(tTablero tablero, int fila, int col)
{

}

bool tableroLleno(const tTablero tablero)
{

}

void mostrarPosibles(const tTablero tablero, int fila, int col)
{

}

void rellenarSimples(tTablero tablero)
{

}
