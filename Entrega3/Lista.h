#pragma once
#include "Iterable.h"
#include "NodoLista.h"

typedef unsigned int nat;
template <class T>
class Lista : Iterable<T>
{
public:
	Iterador<T> ObtenerIterador() const override;

	void Insertar(const T& e);

	const T& Obtener(const nat n) const;

	const T& Ultimo() const;
	const T& Ultimo();

	void Append(Puntero<Lista<T>> listaAppend);
	
	Lista();
	Lista(Puntero<Lista<T>> listaAppend);
	~Lista(){}

private:
	Puntero<NodoLista<T>> principio, fin;
	nat largo;
};

#include "Lista.cpp"
