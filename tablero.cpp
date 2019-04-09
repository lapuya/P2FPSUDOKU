// Beatriz Ălvarez de Arriba y Laurence Apuya Pangilinan

#include "tablero.h"
#include "casilla.h"
#include <fstream>
#include <iostream>
using namespace std;

bool comprobarFilaColumna(int fila, int col);
bool comprobarNumero(int c);
void actualizarValoresPosiblesCasilla(tTablero tablero, int fila, int col);
void actualizarValoresColumnas(tTablero  tablero, int fila, int col);
void actualizarValoresFilas(tTablero tablero, int fila, int col);
void actualizarValoresRegion(tTablero tablero, int fila, int col);
void actualizarRegion(int x, int y, tTablero tablero, int fila, int col);
char enteroAChar(int n);

void iniciaTablero(tTablero tablero) {
	// Iniciamos cada casilla del tablero
	for (int i = 0; i < MAX_FILAS; i++)
		for (int j = 0; j < MAX_COLUMNAS; j++)
			iniciaCasilla(tablero[i][j]);
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	bool abierto, fija;
	ifstream entrada;
	string linea;
	char c;
	// Abrimos el fichero
	entrada.open(nombreFichero);
	abierto = entrada.is_open();
	if (abierto){
		for (int i = 0; i < MAX_FILAS; i++){
			getline(entrada, linea); // Leemos cada linea del fichero
			for (int j = 0; j < MAX_COLUMNAS; j++){
				c = linea[j]; // Cogemos cada elemento de la cadena que hemos leido
				rellenaCasilla(tablero[i][j], c, fija = true); // Vamos rellenando las casillas del tablero
			}
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;
	// Cerramos el fichero
	entrada.close();

	return abierto;
}

void dibujarTablero(const tTablero tablero) {
	// Dibujamos cada casilla del tablero
	for (int i = 0; i < MAX_FILAS; i++){
		for (int j = 0; j < MAX_COLUMNAS; j++)
			dibujaCasilla(tablero[i][j]);
		cout << endl;
	}
}

bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool posible = false, fija;
	char n;

	// Comprobamos si el numero se puede insertar (si ya pertenece al conjunto no se puede)
	if (comprobarValido(tablero[fila][col], c)) {
		cout << "El numero ya pertenece al conjunto" << endl;
	}
	else {
		// Comprobamos que este dentro de las dimensiones, si el numero esta dentro del rango y si la casilla es vacia
		if (comprobarFilaColumna(fila, col) && comprobarNumero(c) && comprobarCasillaVacia(tablero[fila][col])) {
			n = enteroAChar(c);
			rellenaCasilla(tablero[fila][col], n, fija = false);
			posible = true;
		}
	}

	return posible;
}

bool comprobarFilaColumna(int fila, int col) {
	return fila >= 0 && fila <= MAX_FILAS && col >= 0 && col <= MAX_COLUMNAS; // Comprobamos que no nos salimos de las dimensiones del tablero
}

bool comprobarNumero(int c) {
	return c >= 1 && c <= 9; // Comprobamos que el numero esta en el intervalo posible
}

bool borrarNum(tTablero tablero, int fila, int col) {
	bool posible = false;
	// Comprobamos que este dentro de las dimensiones y si la casilla es rellena
	if (comprobarFilaColumna(fila, col) && comprobarCasillaRellena(tablero[fila][col])) {
		// Quitamos el numero del conjunto
		quitarNumero(tablero[fila][col]);
		posible = true;
	}
	return posible;
}

bool tableroLleno(const tTablero tablero) { // MIRAR
	bool relleno = true;
	int i = 0;

	while (i < MAX_FILAS && relleno) {
		int j = 0;
		while (j < MAX_COLUMNAS && relleno) {
			if (comprobarCasillaVacia(tablero[i][j]))
				relleno = false;
			else
				j++;
		}
		if (relleno)
			i++;
	}
	return relleno;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	// Funcion que mostrara los valores posibles de una casilla. Se avisa si la coordenada introducida esta fuera
	if (comprobarFilaColumna(fila, col)) {
		mostrarValores(tablero[fila][col]);
	}
	else {
		cout << "Las coordenadas no estan dentro de Sudoku" << endl;
	}
}

void actualizarValoresPosiblesCasilla(tTablero tablero, int fila, int col) {
	actualizarValoresColumnas(tablero, fila, col);
	actualizarValoresFilas(tablero, fila, col);
	actualizarValoresRegion(tablero, fila, col);
}

void rellenarSimples(tTablero tablero) {
	int n;
	bool fija;
	char c;

	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			// Si es simple, la rellenamos
			if (esSimple(tablero[i][j], n)) {
				c = enteroAChar(n);
				rellenaCasilla(tablero[i][j], c, fija = false);
			}
		}
	}
}

char enteroAChar(int n) {
	char c;
	// Dado un numero devolvemos su caracter
	if (n == 1)
		c = '1';
	else if (n == 2)
		c = '2';
	else if (n == 3)
		c = '3';
	else if (n == 4)
		c = '4';
	else if (n == 5)
		c = '5';
	else if (n == 6)
		c = '6';
	else if (n == 7)
		c = '7';
	else if (n == 8)
		c = '8';
	else
		c = '9';

	return c;
}

void actualizarTablero(tTablero &tablero){
	for(int i = 0; i < MAX_FILAS; i++){
		for(int j = 0; j < MAX_COLUMNAS; j++){
			actualizarValoresPosiblesCasilla(tablero, i, j);
		}
	}
}

void actualizarValoresColumnas(tTablero tablero, int fila, int col) {
	// Nos vamos moviendo de casilla hacia la derecha
	for (int j = 0; j < MAX_COLUMNAS; j++) {
		actualizarValor(tablero[fila][col], tablero[fila][j]);
	}
}

void actualizarValoresFilas(tTablero tablero, int fila, int col) {
	// Nos vamos moviendo de casilla hacia abajo
	for (int i = 0; i < MAX_FILAS; i++) {
		actualizarValor(tablero[fila][col], tablero[i][col]);
	}
}

void actualizarValoresRegion(tTablero tablero, int fila, int col) {

	//las regiones van de izquierda a derecha, 3x3
	//los dos primeros valores de actualizarRegion representan el punto de inicio de la subregion
	if(fila <= 2 && col <= 2)
		actualizarRegion(0, 0, tablero, fila, col); //primera region
	else if(fila <= 2 && col <= 5)
		actualizarRegion(0, 3, tablero, fila, col); //segunda region
	else if(fila <= 2 && col <= 8)
		actualizarRegion(0, 6, tablero, fila, col); //tercera region
	else if(fila <= 5 && col <= 2)
		actualizarRegion(3, 0, tablero, fila, col); //cuarta region
	else if (fila <= 5 && col <= 5)
		actualizarRegion(3, 3, tablero, fila, col); //quinta region
	else if (fila <= 5 && col <= 8)
		actualizarRegion(3, 6, tablero, fila, col); //sexta region
	else if (fila <= 8 && col <= 2)
		actualizarRegion(6, 2, tablero, fila, col); //septima region
	else if (fila <= 8 && col <= 5)
		actualizarRegion(6, 3, tablero, fila, col); //octava region
	else
		actualizarRegion(6, 6, tablero, fila, col); //novena region

}

void actualizarRegion(int x, int y, tTablero  tablero, int fila, int col) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			actualizarValor(tablero[fila][col], tablero[i][j]);
}

bool estaVacia(const tCasilla casilla){
	return comprobarCasillaVacia(casilla);
}
