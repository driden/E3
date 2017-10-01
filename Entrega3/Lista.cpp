
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
	Iterador<T> alreves = Puntero<Iteracion<T>>(it);

	nat largo = 0;
	while (alreves.HayElemento())
	{
		largo++;
		alreves.Avanzar();
	}

	alreves.Reiniciar();

	Array<T> arr(largo);
	for (nat i = largo - 1; i > 0; i--)
	{
		arr[i] = alreves.ElementoActual();
		alreves.Avanzar();
	}

	return arr.ObtenerIterador();
}

template <class T>
void Lista<T>::Insertar(const T& e, const Puntero<Lista<T>>& padre)
{
	Puntero<NodoLista<T>> nodo = new NodoLista<T>{ e, nullptr };

	if (padre != nullptr)
		principio = padre->principio;
	
	nodo->_sig = principio;

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

	return principio->_data;
}


template <class T>
Lista<T>::Lista()
{
	principio = nullptr;
	largo = 0;
}





#endif
