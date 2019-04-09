// Beatriz Ălvarez de Arriba y Laurence Apuya Pangilinan

#include <iostream>
#include <string>
#include "juego.h"
#include "listaSudokus.h"
#include "listaJugadores.h"
using namespace std;

void mostrarMenu();
int menu();

int main() {
	int opcion, puntosFichero, puntos;
	string nombreSudoku;
	tListaSudokus listaSudokus;
	tJuego juego;
	tListaJugadores listaJugadores;

	creaListaVacia(listaSudokus);
	crearListaVacia(listaJugadores);
	if (cargar(listaSudokus) && cargar(listaJugadores)) {
		opcion = menu();
		while (opcion != 0) {
			if (opcion == 1) {
				mostrar(listaSudokus);
				cout << "Elige el nombre del archivo que quieras jugar: ";
				cin >> nombreSudoku;
				devolverPuntos(listaSudokus, nombreSudoku, puntosFichero);
				asignarNombrePuntos(juego.sudoku, nombreSudoku, puntosFichero);
				puntos = jugarUnSudoku(juego.sudoku);
			}
			else if (opcion == 2) {
				mostrar(listaJugadores);
			}
			else if (opcion == 3) {
				ordenarPorRanking(listaJugadores);
				mostrar(listaJugadores);
			}
			else {
				registrarSudoku(listaSudokus);
			}
			opcion = menu();
		}
	}
	system("pause");
	return 0;
}

void mostrarMenu() {
	cout << "1. Jugar" << endl;
	cout << "2. Ver jugadores ordenados por identificador" << endl;
	cout << "3. Ver jugadores ordenados por puntos" << endl;
	cout << "4. Incorporar sudoku" << endl;
	cout << "0. Salir" << endl;
	cout << "Elige una opcion: ";
}

int menu() {
	int opcion;

	mostrarMenu();
	cin >> opcion;
	while (opcion < 0 || opcion > 4)
	{
		cout << "Opcion incorrecta" << endl;
		mostrarMenu();
		cin >> opcion;
	}

	return opcion;
}
