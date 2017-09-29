#ifndef LISTA_ITERACION_H
#define LISTA_ITERACION_H

#include "ListaIteracion.h"


template <class T>
ListaIteracion<T>::ListaIteracion(const Puntero<NodoLista<T>>& ppio)
	:principio(ppio)
{
	iterador = principio;
}

template <class T>
bool ListaIteracion<T>::HayElemento() const
{
	return iterador != nullptr;
}

template <class T>
const T& ListaIteracion<T>::ElementoActual() const
{
	return iterador->_data;
}

template <class T>
void ListaIteracion<T>::Avanzar()
{
	iterador = iterador->_sig;
}

template <class T>
void ListaIteracion<T>::Reiniciar()
{
	iterador = principio;
}

#endif
