#ifndef PRIORIDAD_A_CPP
#define PRIORIDAD_A_CPP

#include "PrioridadA.h"

Array<int> PrioridadA::AplanarTablero(const Tablero& t) const
{
	nat largo = t.ObtenerTablero().Largo;
	
	Array<int>arrayTablero(largo*largo, 0);

	Matriz<int> matriz = t.ObtenerTablero();
	Iterador<Array<int>> itMatriz = matriz.ObtenerIterador();
	
	nat desde = 0;
	while (itMatriz.HayElemento())
	{
		Array<int> linea = itMatriz.ElementoActual();
		itMatriz.Avanzar();


		Array<int>::Copiar(itMatriz.ElementoActual(), arrayTablero, desde);
		desde += linea.Largo + 1;
	}
	return arrayTablero;
}

nat PrioridadA::SumarArray(const Array<int> arr) const
{
	int total = 0;
	
	foreach(nat num, arr.ObtenerIterador())
	{
		total += num;
	}
	return total;
}

nat PrioridadA::CalcularPrioridad(const Tablero& t) const 
{
	Array<int>arrayPrioridades = AplanarTablero(t);

	for (nat i = 0; i < arrayPrioridades.Largo; i++)
	{
		if (arrayPrioridades[i] != i + 1)
			arrayPrioridades[i] = 1;
		else
			arrayPrioridades[i] = 0;
	}

	return SumarArray(arrayPrioridades);
}
#endif