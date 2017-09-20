#ifndef COLAITERACION_CPP
#define COLAITERACION_CPP

#include "ColaIteracion.h"

template <class T, class P>
ColaIteracion<T, P>::ColaIteracion(const Puntero<ListaOrd<NodoPQueue<T, P>>> &pqueue)
{
	pQueue = pqueue;
	colaIter = pQueue->ObtenerIterador();
}

template <class T, class P>
bool ColaIteracion<T, P>::HayElemento() const
{
	return colaIter.HayElemento();
}

template <class T, class P>
const T& ColaIteracion<T, P>::ElementoActual() const
{
	return colaIter.ElementoActual().GetElemento();	
}

template <class T, class P>
void ColaIteracion<T, P>::Avanzar()
{
	colaIter.Avanzar();
}

template <class T, class P>
void ColaIteracion<T, P>::Reiniciar()
{
	colaIter.Reiniciar();
}

template <class T, class P>
Puntero<Iteracion<T>> ColaIteracion<T, P>::Clonar() const
{
	return new ColaIteracion(pQueue->Clon());	
}

#endif
