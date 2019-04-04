// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "conjunto.h"
#include <iostream>
using namespace std;

void cjto_vacio(tConjunto & c){
	// Iniciamos el conjunto vacio
	for (int i = 0; i < MAX; i++)
		c.elementos[i] = false;

	c.numElem = 0;
}

void cjto_lleno(tConjunto & c){
	// Iniciamos el conjunto con todos los valores
	for (int i = 0; i < MAX; i++)
		c.elementos[i] = true;

	c.numElem = MAX;
}

bool pertenece(const tConjunto & c, int e){
	int i = 0;
	bool encontrado = false;
	// Buscamos si el elemento pertenece al conjunto
	while (i < MAX && !encontrado){
		if (i == e - 1 && c.elementos[i] == true)
			encontrado = true;
		i++;
	}

	return encontrado;
}

void annadeElemento(tConjunto & c, int e){
	// Añadimos el elemento al conjunto
	int i = 0;
	while (i < MAX){
		if (i == e - 1 && c.elementos[i] == false){
			c.elementos[i] = true;
			c.numElem++;
		}
		i++;
	}
}

void borraElemento(tConjunto & c, int e){
	// Quitamos el elemento del conjunto
	int i = 0;
	while (i < MAX){
		if (i == e - 1)
			c.elementos[i] = false;
		i++;
	}
	c.numElem--;
}

int numElems(const tConjunto & c){
	// Devolvemos el numero de elementos que hay en el conjunto
	return c.numElem;
}

bool esUnitario(const tConjunto &c, int & e){
	bool unitario = false;
	int aux = 0, i = 0;
	// Buscamos cuantos elementos tiene el conjunto
	while (i < MAX && aux <= 1){
		if (c.elementos[i] == true){
			aux++;
			e = i + 1;
		}
		i++;
	}
	// Si solo tiene un elemento entonces es unitario
	if (aux == 1)
		unitario = true;
	return unitario;
}

void mostrar(const tConjunto & c){
	// Mostramos los elementos que tiene el conjunto
	for (int i = 0; i < MAX; i++)
		if (c.elementos[i] == true)
			cout << i + 1 << " ";
}

void mostrarValoresPosibles(const tConjunto & c){
	// Mostramos los elementos que no estan en el conjunto, porque luego seran los posibles valores a insertar en cada casilla
	for (int i = 0; i < MAX; i++)
		if (c.elementos[i] == false)
			cout << i + 1 << " ";
}
