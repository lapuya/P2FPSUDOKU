// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "casilla.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int charAEntero(char c);
void colorFondo(int color);

void iniciaCasilla(tCasilla & casilla) {
	casilla.estado_casilla = c_vacia; // Iniciamos el estado de la casilla a vacia
	cjto_vacio(casilla.conjunto); // Iniciamos el conjunto a todos los elementos que puede tener una casilla inicialmente
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija = false) {
	int numEquivalente = charAEntero(c); // Calculamos el numero al que equivale el caracter que nos dan
	// Casilla fija
	if (fija && c != ' ') {
		casilla.estado_casilla = c_fija;
		casilla.numero = numEquivalente;
		annadeElemento(casilla.conjunto, casilla.numero);
	} // Casilla rellena
	else if (!fija && c != ' ') {
		casilla.estado_casilla = c_rellena;
		casilla.numero = numEquivalente;
	} // Casilla vacia
	else {
		casilla.estado_casilla = c_vacia;
		casilla.numero = 0;
	}
}

int charAEntero(char c) {
	int numero;
	// Dado un caracter devolvemos el numero equivalente
	if (c == '0' || c == 0)
		numero = 0;
	else if (c == '1' || c == 1)
		numero = 1;
	else if (c == '2' || c == 2)
		numero = 2;
	else if (c == '3' || c == 3)
		numero = 3;
	else if (c == '4' || c == 4)
		numero = 4;
	else if (c == '5' || c == 5)
		numero = 5;
	else if (c == '6' || c == 6)
		numero = 6;
	else if (c == '7' || c == 7)
		numero = 7;
	else if (c == '8' || c == 8)
		numero = 8;
	else
		numero = 9;

	return numero;
}

void dibujaCasilla(const tCasilla & casilla) {
	// Dibujamos en la pantalla cada casilla, con su numero y color correspondiente
	if (casilla.estado_casilla == c_fija) {
		colorFondo(1);
		cout << casilla.numero;
	}
	else if (casilla.estado_casilla == c_rellena) {
		colorFondo(4);
		cout << casilla.numero;
	}
	else {
		cout << " ";
	}
	colorFondo(0);
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool simple = false;
	// Una casilla sera simple si esta vacia y tiene un unico valor posible
	if (comprobarCasillaVacia(casilla) && esUnitario(casilla.conjunto, numero)) {
		simple = true;
	}

	return simple;
}

bool comprobarCasillaVacia(const tCasilla & casilla) {
	// Comprobamos si el estado de la casilla es vacia
	return casilla.estado_casilla == c_vacia;
}

bool comprobarCasillaRellena(const tCasilla & casilla) {
	// Comprobamos si el estado de la casilla es rellena
	return casilla.estado_casilla == c_rellena;
}

void colorFondo(int color) {
	// Cambiar el color de fondo
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void mostrarValores(const tCasilla & casilla) {
	// Mostramos los posibles valores que puede tener una casilla
	mostrarValoresPosibles(casilla.conjunto);
}

void actualizarValor(tCasilla & casilla, tCasilla & casilla2) {
	int numero = casilla2.numero;
	annadeElemento(casilla.conjunto, numero);
}

bool comprobarValido(tCasilla &casilla, int c) {
	return pertenece(casilla.conjunto, c);
}

void quitarNumero(tCasilla &casilla) {
	// Borramos un elemento de conjunto
	borraElemento(casilla.conjunto, casilla.numero);
	casilla.estado_casilla = c_vacia;
	casilla.numero = 0;
}
