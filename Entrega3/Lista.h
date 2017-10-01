#pragma once
#include "Iterable.h"
#include "NodoLista.h"

typedef unsigned int nat;
template <class T>
class Lista : Iterable<T>
{
public:
	Iterador<T> ObtenerIterador() const override;

	void Insertar(const T& e, const Puntero<Lista<T>>& padre);

	const T& Obtener(const nat n) const;

	const T& Ultimo() const;
	
	Lista();
	~Lista(){}
	Puntero<NodoLista<T>> principio;
private:
	
	nat largo;
};

#include "Lista.cpp"
