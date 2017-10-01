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


		Array<int>::Copiar(linea, arrayTablero, desde);
		desde += linea.Largo;
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
	/*Array<int>arrayPrioridades = AplanarTablero(t);

	for (nat i = 0; i < arrayPrioridades.Largo; i++)
	{
		if (arrayPrioridades[i] != i + 1)
			arrayPrioridades[i] = 1;
		else
			arrayPrioridades[i] = 0;
	}

	return SumarArray(arrayPrioridades);*/

	Matriz<int> m = t.ObtenerTablero();
	Matriz<int> mCorrecta(m.Largo);
	nat contador = 1;
	for (nat i = 0; i < mCorrecta.Largo; i++)
		for (nat k = 0; k < mCorrecta.Ancho; k++)
			mCorrecta[i][k] = contador++;
	mCorrecta[m.Largo - 1][m.Largo - 1] = 0;

	nat total = 0, actual;
	for(nat f = 0 ; f < m.Largo;f++)
	{
		for(nat c = 0; c < m.Ancho; c++)
		{
			actual = m[f][c];
			if (actual == 0) continue;
			
			if (!(actual == mCorrecta[f][c]))
				total++;
		}
	}
	return total;
}
#endif