#ifndef NODO_TABLERO_CPP
#define NODO_TABLERO_CPP

#include "NodoTablero.h"
#include "NodoTableroIteracion.h"

Iterador<Tablero> NodoTablero::ObtenerIterador() const
{
	Iterador<Tablero> it = new NodoTableroIteracion<Tablero>(this);
	return it;
}


#endif