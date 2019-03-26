// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include <iostream>
#include <string>
#include "listaSudokus.h"
#include "juego.h"
using namespace std;

void mostrarMenu();
int menu();
int designarPuntos(string nombre);

int main(){
	int opcion, puntosFichero, puntos;
	string nombreSudoku;
	tListaSudokus lista;
	tJuego juego;

	creaListaVacia(lista);
	if (cargar(lista)) {
		opcion = menu();
		while (opcion != 0) {
			mostrar(lista);
			cout << "Elige el nombre del archivo que quieras jugar: ";
			cin >> nombreSudoku;
			devolverPuntos(lista, nombreSudoku, puntosFichero);
			asignarNombrePuntos(juego.sudoku, nombreSudoku, puntosFichero);
			puntos = jugarUnSudoku(juego.sudoku);
			opcion = menu();
		}
	}
	system("pause");
	return 0;
}

void mostrarMenu(){
	cout << "1. Jugar" << endl;
	cout << "0. Salir" << endl;
	cout << "Elige una opcion: ";
}

int menu(){
	int opcion;

	mostrarMenu();
	cin >> opcion;
	while (opcion < 0 || opcion > 1)
	{
		cout << "Opcion incorrecta" << endl;
		mostrarMenu();
		cin >> opcion;
	}

	return opcion;
}
