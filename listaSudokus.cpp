// Beatriz Ălvarez de Arriba y Laurence Apuya Pangilinan

#include "checkML.h"
#include "listaSudokus.h"
#include <iostream>
#include <fstream>
using namespace std;

bool buscarFichero(const tListaSudokus &lista, string nombreFich);
int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku);
void desplazarSudokus(tListaSudokus & lista, int pos);

void creaListaVacia(tListaSudokus & lista) {
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista) {
	bool abierto;
	ifstream entrada;
	string nombre;
	int puntos;

	entrada.open("listaSudokus.txt");
	abierto = entrada.is_open();
	if (abierto) {
		int i = 0;
		entrada >> nombre;
		while (!entrada.eof() && i < MAX_SUDOKUS) {
			entrada >> puntos;
			asignarNombrePuntos(lista.array_sudokus[i], nombre, puntos); // Cargamos los datos del fichero
			lista.cont++;
			i++;
			entrada >> nombre;
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo de la lista de sudokus o no existe." << endl;

	entrada.close();

	return abierto;
}

void mostrar(const tListaSudokus & lista) {
	for (int i = 0; i < lista.cont; i++)
		mostrarInformacionSudoku(lista.array_sudokus[i]);
}

void devolverPuntos(const tListaSudokus & lista, string nombre, int & puntos) {
	int i = 0;
	while (i < lista.cont && !nombrePuntos(lista.array_sudokus[i], nombre, puntos))
		i++;
}

bool guardar(const tListaSudokus &lista) {
	bool abierto;
	ofstream salida;
	string nombre;
	int puntos;

	salida.open("listaSudokus.txt");
	abierto = salida.is_open();
	if (abierto)
	{
		for (int i = 0; i < lista.cont; i++) {
			escribir(lista.array_sudokus[i], nombre, puntos); // Escribimos los datos en el fichero
			salida << nombre << " " << puntos << endl;
		}
	}
	else
		cout << "Hubo problemas al abrir el archivo o no existe." << endl;

	salida.close();

	return abierto;
}

bool registrarSudoku(tListaSudokus &lista) {
	bool posible_registrar = false;
	string nombreFich;
	int puntosFich, posInsertar;
	tSudoku sudoku;

	cout << "Introduce el nommbre del nuevo sudoku: ";
	cin >> nombreFich;
	cout << "Introduce sus puntos: ";
	cin >> puntosFich;
	// Comprobamos que el sudoku no existe
	if (!buscarFichero(lista, nombreFich)) {
		asignarNombrePuntos(sudoku, nombreFich, puntosFich);
		posInsertar = buscarPos(lista, sudoku);
		if (lista.cont < MAX_SUDOKUS) {
			desplazarSudokus(lista, posInsertar);
			asignarNombrePuntos(lista.array_sudokus[posInsertar], nombreFich, puntosFich);
			posible_registrar = true;
			lista.cont++;
		}
		else
			cout << "Lista llena, no se puede insertar un nuevo sudoku" << endl;
	}
	return posible_registrar;
}

bool buscarFichero(const tListaSudokus &lista, string nombreFich) {
	int i = 0;
	bool encontrado = false;

	while (i < lista.cont && !encontrado) {
		if (devolverNombre(lista.array_sudokus[i]) == nombreFich)
			encontrado = true;
		i++;
	}

	return encontrado;
}

int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku) {
	int puntos, puntosLista, ini = 0, fin = lista.cont - 1, mitad, pos;
	bool encontrado = false;
	string nombre, nombreLista;

	puntos = devolverPuntos(sudoku);
	nombre = devolverNombre(sudoku);
	// Buscamos la posicion en la que insertar el sudoku, mediante una busqueda binaria
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2;
		puntosLista = devolverPuntos(lista.array_sudokus[mitad]);
		nombreLista = devolverNombre(lista.array_sudokus[mitad]);
		if (puntos == puntosLista) {
			if (nombre < nombreLista)
				pos = mitad;
			else
				pos = mitad + 1;
			encontrado = true;
		}
		else if (puntos < puntosLista)
			fin = mitad - 1;
		else
			ini = mitad + 1;
	}

	if (!encontrado)
		pos = ini;

	return pos;
}

void desplazarSudokus(tListaSudokus & lista, int pos) {
	for (int i = lista.cont - 1; i >= pos; i--)
		lista.array_sudokus[i + 1] = lista.array_sudokus[i];
}
