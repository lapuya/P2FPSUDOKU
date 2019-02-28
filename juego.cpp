// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "juego.h"
#include <iostream>
using namespace std;

void mostrarSubmenuJugar();
int submenuJuego();

void iniciaJuego(tJuego & juego, const tSudoku & sudoku){
	// Sudoku
	juego.tablero_completo = false;
	iniciaTablero(juego.tablero);
}

void mostrarJuego(const tJuego & juego){
	// Informacion sudoku
	dibujarTablero(juego.tablero);
}

bool cargaJuego(tJuego & juego, const tSudoku & sudoku){
	bool actualizar = false;

	if (cargarTablero(sudoku.nombre_archivo, juego.tablero))
		actualizar = true;

	return actualizar;
}

int jugarUnSudoku(const tSudoku & sudoku){
	int opcion;
	tJuego juego;

	opcion = submenuJuego();
	if (opcion == 1) {
		mostrarPosibles(juego.tablero, fila, col);
	}
	else if (opcion == 2) {
		ponerNum(juego.tablero, fila, col, c);
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

	return sudoku.puntos;
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
