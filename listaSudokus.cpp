// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "listaSudokus.h"
#include <iostream>
#include <fstream>
using namespace std;

void creaListaVacia(tListaSudokus & lista) {
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista) {
	bool abierto;
	ifstream entrada;
	string nombre;
	int puntos;

	entrada.open("listaSudokus.txt");
	abierto = entrada.is_open();
	if (abierto)
	{
		int i = 0;
		entrada >> nombre;
		while (!entrada.eof() && i < MAX_SUDOKUS) {
			entrada >> puntos;
			asignarNombrePuntos(lista.array_sudokus[i], nombre, puntos);
			lista.cont++;
			i++;
			entrada >> nombre;
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	entrada.close();

	return abierto;
}

void mostrar(const tListaSudokus & lista) {
	for (int i = 0; i < lista.cont; i++)
		mostrarInformacionSudoku(lista.array_sudokus[i]);
}
