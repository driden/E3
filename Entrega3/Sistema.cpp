#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"
#include "CadenaFuncionHash.h"

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

	if (TieneSolucion()) 
	{
		pQueue = new CPBinaryHeap<Puntero<Lista<Tablero>>, nat>(Comparador<Puntero<Lista<Tablero>>>::Default, Comparador<nat>::Default, nullptr);
		lista = new Lista<Tablero>();
		lista->Insertar(tablero);

		// El tablero tiene que saber quien fue el anterior.
		pQueue->InsertarConPrioridad(lista, tablero.CalcularPrioridad());
		bool esSolucion = false;
		while (!pQueue->EstaVacia())
		{
			lista = pQueue->ObtenerElementoMayorPrioridad();
			pQueue->EliminarElementoMayorPrioridad();

			esSolucion = lista->Ultimo() == tableroFinal;
			if (esSolucion) 
				break;

			Tablero actual = lista->Ultimo();
			Iterador<Tablero> vecinos = actual.Vecinos();
			foreach(Tablero vecino, vecinos)
			{
				Puntero<Lista<Tablero>> lt = new Lista<Tablero>(lista);
				lt->Insertar(vecino);
				
				Tablero ultimo = lt->Ultimo();
				if (!(ultimo == actual))
				{
					nat prioridadvecino = vecino.CalcularPrioridad() + ultimo.ObtenerCantidadDeMovimientos();
					pQueue->InsertarConPrioridad(lt, prioridadvecino);
				}
			}
		}
	}
}

int CantidadInversionesDeUnNumero(Matriz<int> t, int num, int pos) {

	if (num == 0) return 0;
	
	int inversiones = 0;
	const int largo = t.Largo;
	
	int filaDesde = pos / largo;
	int colDesde = pos % largo;

	for (int i = filaDesde; i < largo; i++) {
		for (int j = colDesde; j < largo; j++) {
			if (t[i][j] < num && t[i][j] != 0) {
				inversiones++;
			}
		}
	}
	return inversiones;
}

int CantidadInversionesTotal(Matriz<int> t) {
	int inversionesTotales = 0;

	const int largo = t.Largo;
	nat contador = 0;
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++)
		{
			inversionesTotales += CantidadInversionesDeUnNumero(t, t[i][j],contador);
			contador++;
		}
	}
	return inversionesTotales;
}

bool BlancoEnFilaImpar(Matriz<int> m)
{
	bool blankOdd= false;

	nat largo = m.Largo;

	for(nat fila = largo -1 ; fila >= 0 ; fila--)
	{
		for (nat col = 0; col < largo;col++)
		{
			//Si es 0
			if(!m[fila][col])
			{
				nat fromBottom = largo - fila;
				if (fromBottom % 2 == 0)
					return true;
				
				return false;
			}
		}
	}

	return blankOdd;

}

bool Sistema::TieneSolucion()
{
	Matriz<int> t = tablero.ObtenerTablero();
	nat ancho = t.Ancho;

	nat candidadInversiones = CantidadInversionesTotal(t);

	bool tieneSolucion = ancho % 2 != 0 && (candidadInversiones % 2 == 0);
	tieneSolucion |= ((ancho % 2 == 0) && (BlancoEnFilaImpar(t) == (candidadInversiones % 2 == 0)));

	return tieneSolucion;
}
	
int Sistema::Movimientos()
{
	Tablero t = lista->Ultimo();
	return t.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	return lista->ObtenerIterador();
}


#endif