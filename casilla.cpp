// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "casilla.h"
#include <iostream>
using namespace std;

int charAEntero(char c);

void iniciaCasilla(tCasilla & casilla)
{
	casilla.estado_casilla = vacia;
	cjto_lleno(casilla.conjunto);
	// Conjunto de valores posibles para la casilla
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija = false)
{
	int numEquivalente = charAEntero(c);

	if(fija && c != ' '){
		casilla.estado_casilla = c_fija;
		casilla.numero = numEquivalente;
	} else if (!fija && c != ' '){
		casilla.estado_casilla = c_rellena;
		casilla.numro = numEquivalente;
	} else
		casilla.estado_casilla = c_vacia;
}


int charAEntero(char c){

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
	if(casilla.estado_casilla == c_fija){
		colorFondo(1);
		cout << casilla.numero;
	} else if (casilla.estado_casilla == c_rellena){
		colorFondo(4);
		cout << casilla.numero;
	} else {
		cout << " ";
	}

}

bool esSimple(const tCasilla & casilla, int & numero)
{
	return esUnitario(casilla, numero);
}

void colorFondo(int color){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}
