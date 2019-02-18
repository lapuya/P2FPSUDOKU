// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "listaSudokus.h"
#include <iostream>
#include <fstream>
using namespace std;

void creaListaVacia(tListaSudokus & lista)
{
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista)
{
	bool abierto;
	ifstream entrada;

	entrada.open("listaSudokus.txt");
	abierto = entrada.is_open();
	if (abierto)
	{
		for (int i = 0; i < MAX_FILAS; i++)
				entrada >> lista.array_sudokus[i];
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	entrada.close();

	return abierto;
}

void mostrar(const tListaSudokus & lista)
{
	for (int i = 0; i < MAX_FILAS; i++)
		lista.array_sudokus[i];
}
