#pragma once

#include "Tablero.h"
#include "Puntero.h"
#include "Iterador.h"

class NodoTablero : public Iterable<NodoTablero>
{
	public:	
		
		NodoTablero(Tablero t) { tablero = t; padre = nullptr; largo = -1; revert = false; }

	const Puntero<NodoTablero>& ElementAt(nat index) const;
	nat Largo();
	//void Revert();
	Puntero<NodoTablero> RevertAux(Puntero<NodoTablero> lista);
	Iterador<NodoTablero> ObtenerIterador() const override;
	Tablero tablero;
	Puntero<NodoTablero> padre;
	private:
		Puntero<NodoTablero> reverse, it, pNodo;
		int largo;
		bool revert;
};

