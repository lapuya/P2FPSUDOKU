// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once
#include "conjunto.h"

typedef enum {c_vacia, c_fija, c_rellena} tEstadoCasilla;

typedef struct
{
	tEstadoCasilla estado_casilla;
	int numero;
	tConjunto conjunto;
}tCasilla;

void iniciaCasilla(tCasilla & casilla);
void rellenaCasilla(tCasilla & casilla, char c, bool fija = false);
void dibujaCasilla(const tCasilla & casilla);
bool esSimple(const tCasilla & casilla, int & numero);
