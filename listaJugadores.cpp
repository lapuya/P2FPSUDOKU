// Beatriz Álvarez de Arriba y Laurence Apuya Pangilinan

#include "checkML.h"
#include "listaJugadores.h"
#include <fstream>
#include <iostream>
using namespace std;

void desplazarJugadores(tListaJugadores & lista, int pos);
bool buscar(const tListaJugadores &lista, string id, int &pos, int ini, int fin);
void ampliar(tListaJugadores & lista);
void copiarLista(const tListaJugadores & lista, tListaJugadores & copiaLista);

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
		entrada >> identificador;
		while (!entrada.eof()) {
			if (lista.cont == lista.capacidad) {
				ampliar(lista); // Si es necesario ampliamos
			}
			entrada >> puntos;
			lista.array_jugadores[lista.cont] = new tJugador;
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

void ampliar(tListaJugadores & lista) {
	tArrayJugadores array_aux = lista.array_jugadores;
	lista.capacidad = lista.capacidad * 2; // Aumentamos la capacidad
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
	if (buscar(lista, identificador, pos, 0, lista.cont-1)) {
		// Si el jugador ya existe
		modificarJugador(*lista.array_jugadores[pos], puntos);
	}
	else {
		// Si el jugador no existe
		if (lista.cont == lista.capacidad) {
			ampliar(lista);
		}
		desplazarJugadores(lista, pos);
		asignarIdentificadorPuntos(*lista.array_jugadores[pos], identificador, puntos);
		lista.cont++;
	}
}

bool buscar(const tListaJugadores & lista, string id, int & pos, int ini, int fin) {
	bool encontrado = false;
	if (ini <= fin) {
		int mitad = (ini + fin) / 2;
		if (id < devolverIdentificadorJugador(*lista.array_jugadores[mitad])) {
			encontrado = buscar(lista, id, pos, ini, mitad - 1);
		}
		else if (devolverIdentificadorJugador(*lista.array_jugadores[mitad]) < id) {
			encontrado = buscar(lista, id, pos, mitad + 1, fin);
		}
		else {
			// Encontrado
			pos = mitad;
			encontrado = true;
		}
	}
	else {
		pos = ini;
		encontrado = false;
	}
	return encontrado;
}

void desplazarJugadores(tListaJugadores & lista, int pos) {
	// Movemos los jugadores, para insertar uno nuevo
	for (int i = lista.cont - 1; i >= pos; i--) {
		lista.array_jugadores[i + 1] = new tJugador;
		*lista.array_jugadores[i + 1] = *lista.array_jugadores[i];
	}
}

tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores lista_ordenada;
	int i = 0;
	string identificador1, identificador2;
	int puntos1, puntos2;

	crearListaVacia(lista_ordenada);
	copiarLista(lista, lista_ordenada);
	// Ordenacion
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

void copiarLista(const tListaJugadores & lista, tListaJugadores & copiaLista) {
	tJugador jugador;
	copiaLista.capacidad = lista.capacidad;
	copiaLista.cont = lista.cont;
	copiaLista.array_jugadores = new tJugadorPtr[copiaLista.capacidad];
	for (int i = 0; i < copiaLista.cont; i++) {
		jugador = *lista.array_jugadores[i];
		copiaLista.array_jugadores[i] = new tJugador;
		*copiaLista.array_jugadores[i] = jugador;
	}
}

void borrarListaJugadores(tListaJugadores & lista) {
	// Liberamos memoria
	for (int i = 0; i < lista.cont; i++) {
		delete lista.array_jugadores[i];
	}
}
