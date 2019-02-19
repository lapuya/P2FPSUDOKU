// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "casilla.h"
#include <iostream>
using namespace std;

void iniciaCasilla(tCasilla & casilla)
{
	casilla.estado_casilla = vacia;
	
	// Conjunto de valores posibles para la casilla
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija = false)
{
	if (c == ' ')
		casilla.estado_casilla = vacia;
	else if (c == '1')
	{
		casilla.numero = 1;
		// Decir si la casilla es fija o rellena
	}
}

void dibujaCasilla(const tCasilla & casilla)
{

}

bool esSimple(const tCasilla & casilla, int & numero)
{
	bool casilla_vacia = false;


}
