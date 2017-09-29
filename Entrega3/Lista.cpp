
#ifndef LISTA_TABLERO_CPP
#define LISTA_TABLERO_CPP

#include "Lista.h"
#include "ListaIteracion.h"

template <class T>
Iterador<T> Lista<T>::ObtenerIterador() const
{
//	return new ListaIteracion<Tablero>(*this);
	const Puntero<NodoLista<Tablero>> lista = principio;
	
	Iteracion<T>* it = new  ListaIteracion<T>(lista);
	return Puntero<Iteracion<T>>(it);
}

template <class T>
void Lista<T>::Insertar(const T& e)
{
	Puntero<NodoLista<T>> nodo = new NodoLista<T>{ e, nullptr };
	
	if (principio == nullptr)
	{
		principio = nodo;
		fin = principio;
	}else
	{
		fin->_sig = nodo;
	}

	largo++;

}
template <class T>
const T& Lista<T>::Obtener(const nat n) const
{
	nat it = 0;
	Puntero<NodoLista<T>> iterador = principio;
	while (it < n)
	{
		iterador = iterador->_sig;
		it++;
	}

	return iterador->_data;
}

template <class T>
const T& Lista<T>::Ultimo() const
{
	return fin->_data;
}

template <class T>
Lista<T>::Lista()
{
	principio = nullptr;
	fin = principio;
	largo = 0;
}

#endif
