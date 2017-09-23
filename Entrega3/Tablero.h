#ifndef TABLERO_H
#define TABLERO_H

#include "Matriz.h"
#include "Cadena.h"
#include "Iterador.h"
#include "Prioridad.h"
#include "Tupla.h"

typedef unsigned int nat;

class Tablero {
public : 
	Tablero() {};

	//Construye un tablero dada una matriz de NxN bloques y la prioridad p. 
	Tablero(Matriz<int> bloques, Puntero<Prioridad> p);
	
	//Retorna el calculo de prioridad en base a la prioridad recibida en el constructor.
	nat CalcularPrioridad();

	//Retorna la cantidad de movimientos actuales
	nat ObtenerCantidadDeMovimientos();
	
	//Decide si esta posicion es igual a otra.
	bool operator==(const Tablero& t ) const;

	// PRE: -
	// POS: Devuelve la posicion donde esta el vacio
	Tupla<nat, nat> PosicionVacio() const;

	//Retorna un iterador de las posiciones vecinas a esta. 
	Iterador<Tablero> Vecinos();
	
	//Retorna el tablero. El cero representa la posición libre.
	Matriz<int> ObtenerTablero() const; 

	//Retorna la representación del tablero como cadena.
	Cadena Imprimir() const;
private:
	//Atributos que considre necesarios para resolver el problema. 
	Matriz<int> tablero;
	Puntero<Prioridad> pPrioridad;	
	nat cantidadMovimientos;
};

#endif