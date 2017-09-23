
#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "CPBinaryHeap.h"

template <class T, class P>
Puntero<ColaPrioridadExtendida<T, P>> Sistema::CrearColaPrioridadExtendida(const Comparador<T>& compElementos, const Comparador<P>& compPrioridades, Puntero<FuncionHash<T>> fHashElementos) {
	// Implementar.
	Puntero<ColaPrioridadExtendida<T, P>> pCola = new CPBinaryHeap<T, P>(compElementos, compPrioridades, fHashElementos);
	return pCola;
}

#endif