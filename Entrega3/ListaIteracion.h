#pragma once
#include "Iteracion.h"
#include "NodoLista.h"

template <class T>
class ListaIteracion: public Iteracion<T>
{
public:
	ListaIteracion(const Puntero<NodoLista<T>> &ppio);
	~ListaIteracion(){}


	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

	private:
		const Puntero<NodoLista<T>> principio;
		Puntero<NodoLista<T>> iterador;

};

#include "ListaIteracion.cpp"
