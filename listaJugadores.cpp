// Beatriz Ălvarez de Arriba y Laurence Apuya Pangilinan

#include "checkML.h"
#include "listaJugadores.h"
#include <fstream>
#include <iostream>
using namespace std;

void desplazarJugadores(tListaJugadores & lista, int pos);

void crearListaVacia(tListaJugadores & lista) {
	lista.cont = 0;
	lista.capacidad = 5;
	lista.array_jugadores = NULL;
	lista.array_jugadores = new tJugadorPtr[lista.capacidad];
	if (lista.array_jugadores == NULL) {
		cout << "No hay memoria" << endl;
	}
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
		crearListaVacia(lista);
		entrada >> identificador;
		while (!entrada.eof()) {
			if (lista.cont == lista.capacidad) {
				ampliar(lista);
			}
			entrada >> puntos;
			asignarIdentificadorPuntos(*lista.array_jugadores[lista.cont], identificador, puntos);
			lista.cont++;
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
		cout << toString(*lista.array_jugadores[i]) << endl;
	}
}

bool guardar(const tListaJugadores & lista) {
	bool abierto;
	ofstream salida;
	string identificador;
	int puntos;

	salida.open("listaJugadores.txt");
	abierto = salida.is_open();
	if (abierto) {
		for (int i = 0; i < lista.cont; i++) {
			escribirJugador(*lista.array_jugadores[i], identificador, puntos);
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
		modificarJugador(*lista.array_jugadores[pos], puntos);
	}
	else if (lista.cont < lista.capacidad && !buscar(lista, identificador, pos)) {
		if (lista.cont == lista.capacidad) {
			ampliar(lista);
		}
		lista.cont++;
		desplazarJugadores(lista, pos);
		asignarIdentificadorPuntos(*lista.array_jugadores[pos], identificador, puntos);
	}
}

void desplazarJugadores(tListaJugadores & lista, int pos) {
	for (int i = lista.cont - 1; i >= pos; i--) {
		lista.array_jugadores[i + 1] = lista.array_jugadores[i];
	}
}

bool buscar(const tListaJugadores & lista, string id, int & pos) {
	int ini = 0, fin = lista.cont - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2;
		if (id == devolverIdentificadorJugador(*lista.array_jugadores[mitad])) {
			encontrado = true;
			pos = mitad;
		}
		else if (id < devolverIdentificadorJugador(*lista.array_jugadores[mitad])) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	if (!encontrado) {
		pos = ini;
	}

	return encontrado;
}

tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores lista_ordenada = lista;
	int i = 0;
	string identificador1, identificador2;
	int puntos1, puntos2;

	while (i < lista_ordenada.cont - 1) {
		if (menor(*lista_ordenada.array_jugadores[i + 1], *lista_ordenada.array_jugadores[i])) {
			i++;
		}
		else {
			for (int j = 0; j < lista_ordenada.cont - 1; j++) {
				int mayor = j;
				for (int k = j + 1; k < lista_ordenada.cont; k++) {
					escribirJugador(*lista_ordenada.array_jugadores[k], identificador1, puntos1);
					escribirJugador(*lista_ordenada.array_jugadores[mayor], identificador2, puntos2);
					if (puntos1 > puntos2) {
						mayor = k;
					}
					else if (puntos1 == puntos2 && identificador1 < identificador2) {
						mayor = k;
					}
				}
				if (mayor > j) {
					escribirJugador(*lista_ordenada.array_jugadores[j], identificador1, puntos1);
					escribirJugador(*lista_ordenada.array_jugadores[mayor], identificador2, puntos2);
					asignarIdentificadorPuntos(*lista_ordenada.array_jugadores[j], identificador2, puntos2);
					asignarIdentificadorPuntos(*lista_ordenada.array_jugadores[mayor], identificador1, puntos1);
				}
			}
		}
	}

	return lista_ordenada;
}

void ampliar(tListaJugadores & lista) {
	tArrayJugadores array_aux = lista.array_jugadores;
	lista.capacidad = lista.capacidad * 2;
	lista.array_jugadores = new tJugadorPtr[lista.capacidad];
	for (int i = 0; i < lista.cont; i++) {
		lista.array_jugadores[i] = array_aux[i];
	}
	for (int j = 0; j < lista.cont; j++) {
		delete array_aux[j];
	}
	if (lista.array_jugadores == NULL) {
		cout << "No hay memoria" << endl;
	}
}

void borrarListaJugadores(tListaJugadores & lista) {
	for (int i = 0; i < lista.cont; i++) {
		delete lista.array_jugadores[i];
	}
}
