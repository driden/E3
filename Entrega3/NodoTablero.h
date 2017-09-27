#pragma once

#include "Tablero.h"
#include "Puntero.h"
#include "Iterador.h"

class NodoTablero : public Iterable<Tablero>
{
	public:	

	NodoTablero(Tablero t) { tablero = t; padre = nullptr; largo = -1; }

	const Tablero& ElementAt(nat index);
	const nat Largo();
	void Revert();
	Puntero<NodoTablero> RevertAux(Puntero<NodoTablero> lista);
	Iterador<Tablero> ObtenerIterador() const override;

	private:
		Puntero<NodoTablero> reverse, it, padre;
		int largo;
		Tablero tablero;		
};

