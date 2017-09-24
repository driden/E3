#include "CadenaFuncionHash.h"
#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"

Sistema::Sistema()
{
}

void Sistema::EstablecerTableroInicial(Tablero inicial)
{
	tablero = inicial;
}

bool Sistema::TieneSolucion()
{
	//Implementar.
	return false;
}
	
int Sistema::Movimientos()
{
	//Implemetar.
	return tablero.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	Puntero<ColaPrioridadExtendida<Tablero, nat>> pQueue = new CPBinaryHeap<Tablero,nat>(Comparador<Tablero>::Default, Comparador<nat>::Default,nullptr);
	
	nat menorPrioridad = tablero.CalcularPrioridad();
	
	pQueue->InsertarConPrioridad(tablero, menorPrioridad);
	Tablero menor;
		
	Array<Tablero> movimientos(15);
	nat i = 0;
	while (!pQueue->EstaVacia())
	{
		Tablero actual = pQueue->ObtenerElementoMayorPrioridad();
		pQueue->EliminarElementoMayorPrioridad();

		Iterador<Tablero> vecinos = tablero.Vecinos();

		foreach(Tablero vecino,vecinos)
		{
			if (menorPrioridad > vecino.CalcularPrioridad() + vecino.ObtenerCantidadDeMovimientos())
			{
				menorPrioridad = vecino.CalcularPrioridad() + vecino.ObtenerCantidadDeMovimientos();
				menor = vecino;
			}
		}
		menor.Mover(1);
		movimientos[i++] = menor;
		pQueue->InsertarConPrioridad(menor, menorPrioridad);
	}
	
	
	return movimientos.ObtenerIterador();
}


#endif