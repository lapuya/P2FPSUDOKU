// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#pragma once

const int MAX = 9;

typedef bool tElementos[MAX];

typedef struct {
	tElementos elementos;
	int numElem;
} tConjunto;

void cjto_vacio(tConjunto & c);
void cjto_lleno(tConjunto & c);
bool pertenece(const tConjunto & c, int e);
void annadeElemento(tConjunto & c, int e);
void borraElemento(tConjunto & c, int e);
int numElems(const tConjunto & c);
bool esUnitario(const tConjunto &c, int & e);
void mostrar(const tConjunto & c);
void mostrarValoresPosibles(const tConjunto &c);
