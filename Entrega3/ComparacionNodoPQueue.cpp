#ifndef COMPARADORNODOPQUEUE_CPP
#define COMPARADORNODOPQUEUE_CPP

#include "ComparacionNodoPQueue.h"

template <class T, class P>
ComparadorNodoPQueue<T,P>::ComparadorNodoPQueue(Comparador<P> compPrioridad)
{
	comparador = compPrioridad;
}

template <class T, class P>
CompRetorno ComparadorNodoPQueue<T,P>::Comparar(const NodoPQueue<T,P>& t1, const NodoPQueue<T,P>& t2) const
{
	if (comparador.EsMayor(t1.GetPrioridad(),t2.GetPrioridad()))
		return MAYOR;
	if (comparador.EsMenor(t1.GetPrioridad() , t2.GetPrioridad()))
		return MENOR;
	if (comparador.SonIguales(t1.GetPrioridad() , t2.GetPrioridad()))
		return IGUALES;
	return DISTINTOS;
}


#endif