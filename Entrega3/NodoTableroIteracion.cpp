#include "NodoTableroIteracion.h"


Puntero<NodoTablero> Reverse (const Puntero<NodoTablero>& lista)
{
	if (lista != nullptr)
	{
		Puntero<NodoTablero> nodo = new NodoTablero(lista->tablero);
		nodo->padre = Reverse(lista->padre);

		return nodo;
	}
	return nullptr;
}

NodoTableroIteracion<Tablero>::NodoTableroIteracion(const Puntero<NodoTablero>& lista)
{
	inicio = Reverse(lista);
	actual = inicio;
}



bool NodoTableroIteracion<Tablero>::HayElemento() const
{
	return actual != nullptr;
}

const Tablero& NodoTableroIteracion<Tablero>::ElementoActual() const
{
	return actual->tablero;
}

void NodoTableroIteracion<Tablero>::Avanzar()
{
	actual = actual->padre;
}

void NodoTableroIteracion<Tablero>::Reiniciar()
{
	actual = inicio;
}

