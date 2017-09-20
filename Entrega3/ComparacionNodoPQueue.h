#ifndef COMPARADORNODOPQUEUE_H
#define COMPARADORNODOPQUEUE_H
#include "Comparacion.h"
#include "NodoPQueue.h"
#include "Comparador.h"

// Clase que compara dos nodos de cola prioridad
template <class T, class P>
class ComparadorNodoPQueue : public Comparacion<NodoPQueue<T, P>>
{
private:
	Comparador<P> comparador;
public:
	~ComparadorNodoPQueue(){}
	// PRE: -
	// POS: Crea un nuevo nodo con un comparador de prioridad, si no se provee toma el default de P
	ComparadorNodoPQueue(Comparador<P> compPrioridad = Comparador<P>::Default);

	// PRE: -
	// PRE: Compara dos instancias de NodoPQueue
	CompRetorno Comparar(const NodoPQueue<T, P>& t1, const NodoPQueue<T, P>& t2) const override;
};

#include "ComparacionNodoPQueue.cpp"
#endif