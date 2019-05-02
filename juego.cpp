// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "checkML.h"
#include "juego.h"
#include "listaJugadores.h"
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
	int opcion, fila, col, c, puntos = 0;
	tJuego juego;

	iniciaJuego(juego, sudoku);
	if (cargaJuego(juego, sudoku)) {
		mostrarJuego(juego);
		opcion = submenuJuego();
		while (opcion != 0 && !tableroLleno(juego.tablero)) {
			// Actualizamos el tablero
			actualizarTablero(juego.tablero);
			// Ejecutamos las acciones
			if (opcion == 1) {
				introducirFilaCol(fila, col);
				if (!estaVacia(juego.tablero[fila - 1][col - 1]))	// Para que solo muestre cuando la casilla este vacia
					cout << "Esta casilla ya esta rellena" << endl;
				else
					mostrarPosibles(juego.tablero, fila - 1, col - 1);
				cout << endl;
				mostrarJuego(juego);
			}
			else if (opcion == 2) {
				cout << "Introduzca un numero: ";
				cin >> c;
				introducirFilaCol(fila, col);
				if (!ponerNum(juego.tablero, fila - 1, col - 1, c)) {
					cout << "No se ha podido poner el numero" << endl;

				}
				mostrarJuego(juego);
			}
			else if (opcion == 3) {
				introducirFilaCol(fila, col);
				if (!borrarNum(juego.tablero, fila - 1, col - 1)) {
					cout << "No se ha podido borrar el numero" << endl;
				}
				mostrarJuego(juego);
			}
			else if (opcion == 4) {
				iniciaJuego(juego, sudoku);
				if (!cargaJuego(juego, sudoku)) {
					cout << "No se ha podido reiniciar el tablero" << endl;
				}
				mostrarJuego(juego);
			}
			else if (opcion == 5) {
				rellenarSimples(juego.tablero);
				mostrarJuego(juego);
			}
			if (!tableroLleno(juego.tablero)) {
				opcion = submenuJuego();
			}

		}
	}

	if (tableroLleno(juego.tablero)) {
		puntos = sudoku.puntos;
	}

	return puntos;
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
	//Asignamos al sudoku el nombre y los puntos corespondientes
	sudoku.nombre_archivo = nombre;
	sudoku.puntos = puntos;
}

bool nombrePuntos(const tSudoku & sudoku, string nombre, int & puntos) {
	//Función para encontrar y asignar el suoku y los puntos
	bool encontrado = false;

	if (sudoku.nombre_archivo == nombre) {
		puntos = sudoku.puntos;
		encontrado = true;
	}
	return encontrado;
}

void escribir(const tSudoku &sudoku, string & nombre, int & puntos) {
	//funcion que extrae el nombre y los puntos del sudoku para escribirlo en el fichero
	nombre = sudoku.nombre_archivo;
	puntos = sudoku.puntos;
}

string devolverNombre(const tSudoku &sudoku) {
	return sudoku.nombre_archivo;
}

int devolverPuntos(const tSudoku &sudoku) {
	return sudoku.puntos;
}
