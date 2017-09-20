#pragma once
#include "Iteracion.h"
#include "ColaPrioridadLista.h"
#include "NodoPQueue.h"

template <class T,class P>
class ColaIteracion : public Iteracion<T>
{
private:
	Puntero<ListaOrd<NodoPQueue<T, P>>> pQueue;
	Iterador<NodoPQueue<T, P>> colaIter;
public:
	~ColaIteracion(){}
	// PRE: 
	// POS: Genera una nueva instancia de ColaIteracion recibiendo una lista ordenada de NodoPQueue
	ColaIteracion(const Puntero<ListaOrd<NodoPQueue<T, P>>> &pqueue);

	// PRE: 
	// POS: Devuelve true sii Hay elementos en el iterador
	bool HayElemento() const override;
	// PRE: HayElemento()
	// POS: Devuelve el elemento actual del iterador
	const T& ElementoActual() const override;
	// PRE: 
	// POS: Avanza el iterador en 1
	void Avanzar() override;
	// PRE: 
	// POS: Reinicia el iterador al estado que tenia al crearse
	void Reiniciar() override;

	// PRE: 
	// POS: Clona el iterador, sin compartir memoria entre instancias
	Puntero<Iteracion<T>> Clonar() const override;
};
#include "ColaIteracion.cpp"
