// Beatriz Ălvarez de Arriba y Laurence Apuya Pangilinan

#include "listaJugadores.h"
#include <fstream>
#include <iostream>
using namespace std;

void crearListaVacia(tListaJugadores & lista) {
	lista.cont = 0;
}

bool cargar(tListaJugadores & lista) {
	bool abierto;
	ifstream entrada;
	string identificador;
	int puntos;

	entrada.open("listaJugadores.txt");
	abierto = entrada.is_open();
	if (abierto)
	{
		int i = 0;
		entrada >> identificador;
		while (!entrada.eof() && i < MAX_JUGADORES) {
			entrada >> puntos;
			asignarIdentificadorPuntos(lista.array_jugadores[i] , identificador, puntos);
			lista.cont++;
			i++;
			entrada >> identificador;
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo de la lista de jugadores o no existe." << endl;

	entrada.close();

	return abierto;
}

void mostrar(const tListaJugadores & lista) {
	for (int i = 0; i < lista.cont; i++) {
		mostrarJugador(lista.array_jugadores[i]);
	}
}

bool guardar(const tListaJugadores & lista) {
	bool abierto;
	ofstream salida;
	string identificador;
	int puntos;

	salida.open("listaJugadores.txt");
	abierto = salida.is_open();
	if (abierto){
		for (int i = 0; i < lista.cont; i++) {
			escribirJugador(lista.array_jugadores[i], identificador, puntos); // ESCRIBIR DE MANERA ORDENADA
			salida << identificador << " " << puntos << endl;
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	salida.close();

	return abierto;
}

void puntuarJugador(tListaJugadores & lista, int puntos) {
	string identificador;
	int pos;

	cout << "Introduce el identificador: ";
	cin >> identificador;
	if (buscar(lista, identificador, pos)) {
		modificarJugador(lista.array_jugadores[pos], puntos);
	}
	else if (lista.cont < MAX_JUGADORES && !buscar(lista, identificador, pos)) {
		asignarIdentificadorPuntos(lista.array_jugadores[pos], identificador, puntos);
	}
}

bool buscar(const tListaJugadores & lista, string id, int & pos) {
	bool existe = false;
	pos = 0;
	while (pos < lista.cont && !existe) {
		if (id == devolverIdentificadorJugador(lista.array_jugadores[pos])) {
			existe = true;
		}
		else {
			pos++;
		}
	}
	return existe;
}

tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores lista_ordenada = lista;
	int i = 0;

	while (i < lista_ordenada.cont-1 && menor(lista_ordenada.array_jugadores[i], lista_ordenada.array_jugadores[i + 1])) {
		i++;
	}

	return lista_ordenada;
}
