#pragma once

#include "Tablero.h"
#include "Puntero.h"
#include "Iterable.h"

class NodoTablero : public Iterable<Tablero>
{
	public:
	Tablero tablero;
	Puntero<NodoTablero> padre;
	NodoTablero(Tablero t) { tablero = t; padre = nullptr; }

	Iterador<Tablero> ObtenerIterador() const override;
	
};

