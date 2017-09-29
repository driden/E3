#ifndef NODO_TABLERO_ITERACION_H
#define NODO_TABLERO_ITERACION_H

#include "NodoTableroIteracion.h"


NodoTableroIteracion::NodoTableroIteracion( Puntero<NodoTablero> nodo)
{
	this->inicio = nodo;
	this->tope = 0;
	this->largo = inicio->Largo();
}

bool NodoTableroIteracion::HayElemento() const
{
	return tope < largo - 1;
}

const NodoTablero& NodoTableroIteracion::ElementoActual() const
{
	nat t = 0;

	Puntero<NodoTablero> it = inicio;

	while(it != nullptr && t != tope)
	{
		it = it->padre;
	}

	return it->ElementAt(tope);
}

void NodoTableroIteracion::Avanzar()
{
	tope++;
}

void NodoTableroIteracion::Reiniciar()
{
	tope = 0;
}


#endif
