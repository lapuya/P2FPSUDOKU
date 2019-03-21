// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "juego.h"
#include <iostream>
using namespace std;

void mostrarInformacionSudoku(const tSudoku & sudoku);
void mostrarSubmenuJugar();
int submenuJuego();
void introducirFilaCol(int & fila, int & col);

void iniciaJuego(tJuego & juego, const tSudoku & sudoku) {
	juego.tablero_relleno = false;
	juego.sudoku = sudoku;
	iniciaTablero(juego.tablero);
}

void mostrarJuego(const tJuego & juego) {
	mostrarInformacionSudoku(juego.sudoku);
	dibujarTablero(juego.tablero);
}

void mostrarInformacionSudoku(const tSudoku & sudoku) {
	cout << "Sudoku: " << sudoku.nombre_archivo << " Puntos: " << sudoku.puntos << endl;
}

bool cargaJuego(tJuego & juego, const tSudoku & sudoku) {
	bool actualizar = false;

	if (cargarTablero(sudoku.nombre_archivo, juego.tablero))
		actualizar = true;

	return actualizar;
}

int jugarUnSudoku(const tSudoku & sudoku) {
	int opcion, fila, col, c;
	tJuego juego;

	iniciaJuego(juego, sudoku);
	if (cargaJuego(juego, sudoku)) {
		mostrarJuego(juego);
		opcion = submenuJuego();
		while (opcion != 0 || !tableroLleno(juego.tablero)) {
			if (opcion == 1) {
				introducirFilaCol(fila, col);
				actualizarValoresPosiblesCasilla(juego.tablero, fila, col);
				mostrarPosibles(juego.tablero, fila, col);
				cout << endl;
				mostrarJuego(juego);
			}
			else if (opcion == 2) {
				cout << "Introduzca un numero: ";
				cin >> c;
				introducirFilaCol(fila, col);
				if (!ponerNum(juego.tablero, fila, col, c)) {
					cout << "No se ha podido poner el numero" << endl;
				}
				mostrarJuego(juego);
			}
			else if (opcion == 3) {
				introducirFilaCol(fila, col);
				if (!borrarNum(juego.tablero, fila, col)) {
					cout << "No se ha podido borrar el numero" << endl;
				}
				mostrarJuego(juego);
			}
			else if (opcion == 4) {
				if (!cargaJuego(juego, sudoku)) {
					cout << "No se ha podido reiniciar el tablero" << endl;
				}
				mostrarJuego(juego);
			}
			else if (opcion == 5) {
				rellenarSimples(juego.tablero);
				mostrarJuego(juego);
			}
			else {
				//sudoku.puntos = 0;
			}
			if (tableroLleno(juego.tablero)) {
				opcion = submenuJuego();
			}
		}
	}

	return sudoku.puntos;
}

void introducirFilaCol(int & fila, int & col) {
	cout << "Introduzca la fila: ";
	cin >> fila;
	cout << "Introduzca la columna: ";
	cin >> col;
}

void mostrarSubmenuJugar() {
	cout << "1. Ver posibles valores de una casilla vacia" << endl;
	cout << "2. Colocar valor en una casilla" << endl;
	cout << "3. Borrar valor de una casilla" << endl;
	cout << "4. Reiniciar tablero" << endl;
	cout << "5. Autocompletar celdas simples" << endl;
	cout << "0. Abortar solucion y volver al menu principal" << endl;
	cout << "Elige una opcion: ";
}

int submenuJuego() {
	int opcion;

	mostrarSubmenuJugar();
	cin >> opcion;
	while (opcion < 0 || opcion > 5)
	{
		cout << "Opcion incorrecta" << endl;
		mostrarSubmenuJugar();
		cin >> opcion;
	}

	return opcion;
}

void asignarNombrePuntos(tSudoku &sudoku, string nombre, int puntos) {
	sudoku.nombre_archivo = nombre;
	sudoku.puntos = puntos;
}
