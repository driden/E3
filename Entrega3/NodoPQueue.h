#pragma once

//Clase que modela un Nodo de PQueue, con su Elemento T, Y su prioridad P
template <class T, class P>
class NodoPQueue
{
private:
	T elemento;
	P prioridad;
	
public:
	~NodoPQueue(){};
	// PRE: -
	// POS: Crea un nodo de la cola a pertir del elemento y su prioridad
	NodoPQueue(const T& elem, const P& prioridad);
	// PRE: -
	// POS: Constructor por defecto de la cola
	NodoPQueue(){}

	// PRE: -
	// POS: retorna una referencia al elemento de la cola
	const T& GetElemento() const;
	// PRE: -
	// POS: retorna una referncia a la prioridad del elemento
	const P& GetPrioridad() const;
	// PRE: -
	// POS: setea el elemento con la referencia a elem
	void SetElemento(const T &elem);
	// PRE:
	// POS: setea la prioridad del elemento con la prioridad pasada por referencia
	void SetPrioridad(const P &prio);
};

#include "NodoPQueue.cpp"

