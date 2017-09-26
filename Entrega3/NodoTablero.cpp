#ifndef NODO_TABLERO_CPP
#define NODO_TABLERO_CPP

#include "NodoTablero.h"
#include "NodoTableroIteracion.h"

Iterador<Tablero> NodoTablero::ObtenerIterador() const
{
	return new NodoTableroIteracion<Tablero>(*this);
}


#endif