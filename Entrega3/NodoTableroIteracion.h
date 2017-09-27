#pragma once
#include "Iteracion.h"
#include "Tablero.h"
#include "NodoTablero.h"

template <class T = Tablero>
class NodoTableroIteracion: public Iteracion<T>
{
public:
	NodoTableroIteracion(const NodoTablero &nodo);
	~NodoTableroIteracion(){};

	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

private:
	NodoTablero inicio, actual;
	nat largo;
	int tope;	
};

