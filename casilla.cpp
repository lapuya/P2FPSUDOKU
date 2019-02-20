// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "casilla.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int charAEntero(char c);
void colorFondo(int color);

void iniciaCasilla(tCasilla & casilla)
{
	casilla.estado_casilla = c_vacia;
	cjto_lleno(casilla.conjunto);
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija = false)
{
	int numEquivalente = charAEntero(c);

	if (fija && c != ' ') {
		casilla.estado_casilla = c_fija;
		casilla.numero = numEquivalente;
	}
	else if (!fija && c != ' ') {
		casilla.estado_casilla = c_rellena;
		casilla.numero = numEquivalente;
	}
	else {
		casilla.estado_casilla = c_vacia;
		casilla.numero = 0;
	}
}

int charAEntero(char c) {

	int numero;

	if (c == '0')
		numero = 0;
	else if (c == '1')
		numero = 1;
	else if (c == '2')
		numero = 2;
	else if (c == '3')
		numero = 3;
	else if (c == '4')
		numero = 4;
	else if (c == '5')
		numero = 5;
	else if (c == '6')
		numero = 6;
	else if (c == '7')
		numero = 7;
	else if (c == '8')
		numero = 8;
	else
		numero = 9;

	return numero;
}

void dibujaCasilla(const tCasilla & casilla)
{
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

bool esSimple(const tCasilla & casilla, int & numero)
{
	return esUnitario(casilla.conjunto, numero);
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
