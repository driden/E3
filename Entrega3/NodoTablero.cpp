#ifndef NODO_TABLERO_CPP
#define NODO_TABLERO_CPP

#include "NodoTablero.h"
#include "NodoTableroIteracion.h"

const Tablero& NodoTablero::ElementAt(nat index)
{
	assert(index < largo);
	it = padre;
	nat contador = 0;
	while (this->it != nullptr  && contador++!= index)
	{
		it = it->padre;
		
	}
	return it->tablero;
}

const nat NodoTablero::Largo() 
{
	if (largo == -1)
	{
		it = padre;		
		while (this->it != nullptr)
		{
			it = it->padre;
			largo++;
		}
	}
	return largo;
}

void NodoTablero::Revert()
{
	it = padre;
	padre = RevertAux(it);
}

Puntero<NodoTablero> NodoTablero::RevertAux(Puntero<NodoTablero> lista)
{
	if (lista == nullptr) return nullptr;
	it->padre = RevertAux(lista->padre);
	return lista;
}


Iterador<Tablero> NodoTablero::ObtenerIterador() const
{
	return new NodoTableroIteracion<Tablero>(*this);	
}


#endif