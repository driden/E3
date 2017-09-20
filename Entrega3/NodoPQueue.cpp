#ifndef NODOPQUEUE_H
#define NODOPQUEUE_H

#include "NodoPQueue.h"
//Clase que modela un Nodo de PQueue, con su Elemento T, Y su prioridad P
template <class T, class P>
NodoPQueue<T, P>::NodoPQueue(const T& elem, const P& prio)	
{
	elemento = elem;
	prioridad = prio;	
}

template <class T, class P>
const T& NodoPQueue<T, P>::GetElemento() const
{
	return elemento;
}

template <class T, class P>
const P& NodoPQueue<T, P>::GetPrioridad() const
{
	return prioridad;
}

template <class T, class P>
void NodoPQueue<T, P>::SetElemento(const T& elem)
{
	elemento = elem;
}


template <class T, class P>
void NodoPQueue<T, P>::SetPrioridad(const P& prio)
{
	prioridad = prio;
}


#endif
