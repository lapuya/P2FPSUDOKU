// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "juego.h"
#include <iostream>
using namespace std;

void mostrarInformacionSudoku(const tSudoku & sudoku);
void mostrarSubmenuJugar();
int submenuJuego();

void iniciaJuego(tJuego & juego, const tSudoku & sudoku){
	juego.tablero_relleno = false;
	juego.sudoku = sudoku;
	iniciaTablero(juego.tablero);
}

void mostrarJuego(const tJuego & juego){
	mostrarInformacionSudoku(juego.sudoku);
	dibujarTablero(juego.tablero);
}

void mostrarInformacionSudoku(const tSudoku & sudoku) {
	cout << "Puntos: " << sudoku.puntos << endl;
	cout << "Sudoku elegido: " << sudoku.nombre_archivo << endl;
}

bool cargaJuego(tJuego & juego, const tSudoku & sudoku){
	bool actualizar = false;

	if (cargarTablero(sudoku.nombre_archivo, juego.tablero))
		actualizar = true;

	return actualizar;
}

int jugarUnSudoku(const tSudoku & sudoku){
	int opcion, fila, col, c;
	tJuego juego;
	bool resuelto = false;

	iniciaJuego(juego, sudoku);
	if (cargaJuego(juego, sudoku)) {
		opcion = submenuJuego();
		while (opcion != 0 || !resuelto) {

			if (opcion == 1) {
				introducirFilaCol(fila, col);
				mostrarPosibles(juego.tablero, fila, col);
			}
			else if (opcion == 2) {
				introducirFilaCol(fila, col);
				if (!ponerNum(juego.tablero, fila, col, c)) {
					cout << "No se ha podido poner el numero" << endl;
				}
			}
			else if (opcion == 3) {
				borrarNum(juego.tablero, fila, col);
			}
			else if (opcion == 4) {

			}
			else if (opcion == 5) {
				rellenarSimples(juego.tablero);
			}
			else {
				// Puntos igual a 0
			}
			opcion = submenuJuego();
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

void mostrarSubmenuJugar(){
	cout << "1. Ver posibles valores de una casilla vacia" << endl;
	cout << "2. Colocar valor en una casilla" << endl;
	cout << "3. Borrar valor de una casilla" << endl;
	cout << "4. Reiniciar tablero" << endl;
	cout << "5. Autocompletar celdas simples" << endl;
	cout << "0. Abortar solucion y volver al menu principal" << endl;
	cout << "Elige una opcion: ";
}

int submenuJuego(){
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
