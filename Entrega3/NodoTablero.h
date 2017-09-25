#pragma once

#include "Tablero.h"
#include "Puntero.h"

class NodoTablero
{
	public:
	Tablero tablero;
	Puntero<NodoTablero> padre;
	NodoTablero(Tablero t) { tablero = t; padre = nullptr; }
	
};