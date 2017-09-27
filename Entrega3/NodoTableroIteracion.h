#pragma once
#include "Iteracion.h"
#include "Tablero.h"
#include "NodoTablero.h"

template <class T = Tablero>
class NodoTableroIteracion: public Iteracion<T>
{
public:
	NodoTableroIteracion(const Puntero<NodoTablero> &nodo);
	NodoTableroIteracion(const NodoTablero *nodo){};
	~NodoTableroIteracion(){};

	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

private:
	Puntero<NodoTablero> inicio, actual, alreves;

};

