#include "CadenaFuncionHash.h"
#include "NodoTablero.h"
#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"

Sistema::Sistema()
{
}

void Sistema::EstablecerTableroInicial(Tablero inicial)
{
	tablero = inicial;
	Matriz<int> t(inicial.ObtenerTablero().Largo);
	nat contador = 1;
	for (nat x = 0; x < t.Largo; x++)
	{
		for (nat y = 0 ; y < t.Largo ; y++)
		{
			t[x][y] = contador++;
		}
	}
	t[t.Largo - 1][t.Ancho - 1] = 0;
	tableroFinal = Tablero(t, nullptr, 0);
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
	Puntero<ColaPrioridadExtendida<Puntero<NodoTablero>, nat>> pQueue = new CPBinaryHeap<Puntero<NodoTablero>,nat>(Comparador<Puntero<NodoTablero>>::Default, Comparador<nat>::Default,nullptr);
	
	//Esto puede fallar por el fwk
	Puntero<NodoTablero> actual = new NodoTablero(tablero);
		
	// El tablero tiene que saber quien fue el anterior.
	pQueue->InsertarConPrioridad(actual, tablero.CalcularPrioridad());
	bool esSolucion = false;
	while (!pQueue->EstaVacia())
	{
		actual = pQueue->ObtenerElementoMayorPrioridad();		
		pQueue->EliminarElementoMayorPrioridad();

		esSolucion = actual->tablero == tableroFinal;		
		if (esSolucion) break;

		Iterador<Tablero> vecinos = actual->tablero.Vecinos();
		foreach(Tablero vecino, vecinos)
		{
			Puntero<NodoTablero> nodo = new NodoTablero(vecino);
			nodo->padre = actual;
			
			if (!(nodo->tablero == nodo->padre->tablero))
			{
				nat prioridadvecino = vecino.CalcularPrioridad() + actual->tablero.ObtenerCantidadDeMovimientos();
				pQueue->InsertarConPrioridad(nodo, prioridadvecino);
			}
		}		
	}
	Iterador<Tablero> jugadas = actual->ObtenerIterador();

	foreach(Tablero t, jugadas)
	{
		std::cout << t.Imprimir() << "--> ";
	}
	return actual->ObtenerIterador();
}


#endif