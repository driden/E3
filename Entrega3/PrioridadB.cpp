#ifndef PRIORIDAD_B_CPP
#define PRIORIDAD_B_CPP

#include "PrioridadB.h"

nat Abs(const int num)
{
	return num < 0 ? num*-1 : num;
}

nat PrioridadB::CalcularMovimientos(nat filaActual, nat columnaActual, nat filaEsperada, nat columnaEsperada) const
{
	const int movHorizontales = Abs(filaActual - filaEsperada);
	const int movVerticales = Abs(columnaActual - columnaEsperada);

	return movHorizontales + movVerticales;
}

nat PrioridadB::CalcularPrioridad(const Tablero& t) const
{

	nat movimientosNecesarios = 0;

	const nat largo = t.ObtenerTablero().Largo;

	for (nat fila = 0; fila < largo; fila++)
	{
		for (nat columna = 0; columna < largo; columna++)
		{
			nat obtenido = t.ObtenerTablero()[fila][columna];
			if (obtenido == 0) continue;
			nat num = obtenido -1 ;
			nat filaEsperada = (num / largo) ;
			nat columnaEsperada = (num % largo);

			nat movs = CalcularMovimientos(fila, columna, filaEsperada, columnaEsperada);
			movimientosNecesarios += movs;
		}
	}
	return movimientosNecesarios;
}


#endif