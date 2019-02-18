#include "conjunto.h"
#include <iostream>
using namespace std;

void cjto_vacio(tConjunto & c)
{
	for (int i = 0; i < MAX; i++)
		c.elementos[i] = false;

	c.numElem = 0;
}

void cjto_lleno(tConjunto & c)
{
	for (int i = 0; i < MAX; i++)
		c.elementos[i] = true;

	c.numElem = MAX;
}

bool pertenece(const tConjunto & c, int e)
{
	int i = 0;
	bool encontrado = false;
	while (i < MAX && !encontrado)
	{
		if (i == e - 1 && c.elementos[i] == true)
			encontrado = true;
		i++;
	}
	return encontrado;
}

void annadeElemento(tConjunto & c, int e)
{
	int i = 0;
	while (i < MAX)
	{
		if (i == e - 1 && c.elementos[i] == false)
		{
			c.elementos[i] = true;
			c.numElem++;
		}
		i++;
	}
}

void borraElemento(tConjunto & c, int e)
{
	int i = 0;
	while (i < MAX)
	{
		if (i == e - 1)
			c.elementos[i] = false;
		i++;
	}
	c.numElem--;
}

int numElems(const tConjunto & c)
{
	return c.numElem;
}

bool esUnitario(const tConjunto &c, int & e)
{
	bool unitario = false;
	int aux = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (c.elementos[i] == true)
		{
			aux++;
			e = i + 1;
		}
	}
	if (aux == 1)
		unitario = true;
	return unitario;
	//return c.numElem == 1;
}

void mostrar(const tConjunto & c)
{
	for (int i = 0; i < MAX; i++)
		if (c.elementos[i] == true)
			cout << i + 1 << " ";
}