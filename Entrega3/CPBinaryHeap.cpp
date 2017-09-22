#ifndef CP_BINARY_HEAP_CPP
#define CP_BINARY_HEAP_CPP

#include "CPBinaryHeap.h"
#include "Utils.h"

template <class T, class P>
CPBinaryHeap<T, P>::CPBinaryHeap(const Comparador<T>& compElementos, const Comparador<P>& compPrioridades,
	Puntero<FuncionHash<T>> fHashElementos) :
	compElementos(compElementos),
	compPrioridades(compPrioridades)
{
	this->fHash = fHashElementos;
	this->pQueue = Array<Tupla<T, P>>(51);
	this->tope = 0;
}

template <class T, class P>
void CPBinaryHeap<T, P>::InsertarConPrioridad(const T& e, const P& p)
{
	Tupla<T, P>tupla(e, p);

	// Primer paso, va al final
	heap[++tope] = tupla;
	Utils util;
	// Flotar tupla y 
	for (nat hole = tope; compPrioridades.EsMenor(heap[hole].Dato2, heap[hole / 2].Dato2); hole /= 2)
	{
		// hundir los menores
		util.Swap(heap, hole, hole / 2);
	}

}

template <class T, class P>
T CPBinaryHeap<T, P>::EliminarElementoMayorPrioridad()
{
	nat posMin = 0;
	Swap(heap, 1, tope);
	tope--;

	for (nat i = 1; compPrioridades.EsMayor(heap[i].Dato2, heap[i * 2].Dato2) && i < heap.Largo / 2; i *= 2 )
	{
		posMin = i * 2;

		// busco el hijo mas chico
		if (compPrioridades.EsMenor(heap[i * 2 + 1].Dato2, heap[i * 2].Dato2))
			posMin = i * 2 + 1;

		Swap(heap, i, posMin);
	}

	return heap[tope+1];
}

template <class T, class P>
const T& CPBinaryHeap<T, P>::ObtenerElementoMayorPrioridad() const
{
	return heap[1].Dato1;
}

template <class T, class P>
nat CPBinaryHeap<T, P>::IndexOf(const T& e)
{
	nat i = 0;
	for (; i < heap.Largo + 1 && compElementos.SonDistintos(e,heap[i].Dato1) ;i++)
	{
		
	}
	return i;
}

template <class T, class P>
Tupla<T, P> CPBinaryHeap<T, P>::ObtenerElementoYPrioridad(const T& e)
{
	nat i = IndexOf(e);
	return heap[i];
}

template <class T, class P>
nat CPBinaryHeap<T, P>::Largo() const
{
	return tope;
}

template <class T, class P>
bool CPBinaryHeap<T, P>::Pertenece(const T& e) const
{
	return IndexOf(e) != 0;
}

template <class T, class P>
void CPBinaryHeap<T, P>::CambiarPrioridad(const T& e, const P& p)
{
}

template <class T, class P>
void CPBinaryHeap<T, P>::EliminarElemento(T& e)
{
}

template <class T, class P>
bool CPBinaryHeap<T, P>::EstaVacia() const
{
	return tope != 0;
}

template <class T, class P>
bool CPBinaryHeap<T, P>::EstaLlena() const
{
	return heap.Largo = tope +1;
}

template <class T, class P>
void CPBinaryHeap<T, P>::Vaciar()
{
	tope = 0;
}

template <class T, class P>
Puntero<ColaPrioridadExtendida<T, P>> CPBinaryHeap<T, P>::Clon() const
{
	return nullptr;
}

template <class T, class P>
Iterador<T> CPBinaryHeap<T, P>::ObtenerIterador() const
{
	return nullptr;
}


#endif
