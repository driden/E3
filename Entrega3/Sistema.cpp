#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"
#include "CadenaFuncionHash.h"
#include "NodoLista.h"
#include "Lista.h"


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
	Puntero<ColaPrioridadExtendida<Puntero<Lista<Tablero>>, nat>> pQueue = new CPBinaryHeap<Puntero<Lista<Tablero>>,nat>(Comparador<Puntero<Lista<Tablero>>>::Default, Comparador<nat>::Default,nullptr);
	Puntero<Lista<Tablero>> lista = new Lista<Tablero>();
	lista->Insertar(tablero);

	// El tablero tiene que saber quien fue el anterior.
	pQueue->InsertarConPrioridad(lista, tablero.CalcularPrioridad());
	bool esSolucion = false;
	while (!pQueue->EstaVacia())
	{
		lista = pQueue->ObtenerElementoMayorPrioridad();
		pQueue->EliminarElementoMayorPrioridad();

		esSolucion = lista->Ultimo() == tableroFinal;
		if (esSolucion) break;

		Tablero actual = lista->Ultimo();
		Iterador<Tablero> vecinos = actual.Vecinos();
		foreach(Tablero vecino, vecinos)
		{			
			lista->Insertar(vecino);
			Tablero ultimo = lista->Ultimo();
			if (!( ultimo == actual))
			{
				nat prioridadvecino = vecino.CalcularPrioridad() + ultimo.ObtenerCantidadDeMovimientos();
				pQueue->InsertarConPrioridad(lista, prioridadvecino);
			}
		}		
	}


	return lista->ObtenerIterador();
}


#endif