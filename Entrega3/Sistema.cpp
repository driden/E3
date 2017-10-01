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
		for (nat y = 0; y < t.Largo; y++)
		{
			t[x][y] = contador++;
		}
	}
	t[t.Largo - 1][t.Ancho - 1] = 0;
	tableroFinal = Tablero(t, nullptr, 0);

	if (TieneSolucion())
	{
		pQueue = new CPBinaryHeap<Puntero<NodoLista<Tablero>>, nat>(Comparador<Puntero<NodoLista<Tablero>>>::Default, Comparador<nat>::Default, nullptr);
		nodo = new NodoLista<Tablero>{ tablero, nullptr };

		// El tablero tiene que saber quien fue el anterior.
		nat prioridadInicial = tablero.CalcularPrioridad();
		pQueue->InsertarConPrioridad(nodo, prioridadInicial);
		bool esSolucion = false;

		while (!pQueue->EstaVacia())
		{
			nodo = pQueue->ObtenerElementoMayorPrioridad();
			pQueue->EliminarElementoMayorPrioridad();

			esSolucion = nodo->_data == tableroFinal;
			if (esSolucion)
				break;

			Tablero actual = nodo->_data;
			Iterador<Tablero> vecinos = actual.Vecinos();
			foreach(Tablero vecino, vecinos)
			{
				if (!(vecino == actual))
				{
					Puntero<NodoLista<Tablero>> nodoLista = new NodoLista<Tablero>{ vecino, nullptr };
					nodoLista->_sig = nodo;

					nat prioridadF = vecino.CalcularPrioridad();
					nat movs = vecino.ObtenerCantidadDeMovimientos();
					nat prioridadvecino = prioridadF  + movs;
					
					pQueue->InsertarConPrioridad(nodoLista, prioridadvecino);
				}
			}
		}
	}
}

int CantidadInversionesDeUnNumero(Array<int> arr, nat n) {

	int inv_count = 0;
	for (nat i = 0; i < n - 1; i++)
		for (nat j = i + 1; j < n; j++)
			if (arr[i] && arr[j] && arr[i] > arr[j])
				inv_count++;

	return inv_count;
}

int CantidadInversionesTotal(Array<int> arr) {
	int total = CantidadInversionesDeUnNumero(arr, arr.Largo);

	return total;
}

bool BlancoEnFilaImpar(Matriz<int> m)
{
	bool blankOdd = false;

	nat largo = m.Largo;

	for (nat fila = largo - 1; fila >= 0; fila--)
	{
		for (nat col = 0; col < largo; col++)
		{
			//Si es 0
			if (!m[fila][col])
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
Array<int> AplanarTablero(const Tablero& t)
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
bool Sistema::TieneSolucion()
{
	Matriz<int> t = tablero.ObtenerTablero();
	nat ancho = t.Ancho;

	Array<int> arr = AplanarTablero(tablero);
	nat candidadInversiones = CantidadInversionesTotal(arr);	

	bool tieneSolucion = ancho % 2 != 0 && (candidadInversiones % 2 == 0);
	tieneSolucion |= ((ancho % 2 == 0) && (BlancoEnFilaImpar(t) == (candidadInversiones % 2 == 0)));

	return tieneSolucion;
}

int Sistema::Movimientos()
{
	Tablero t = nodo->_data;
	return t.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	Puntero<NodoLista<Tablero>> lista = nodo;
	nat largo = 0;
	while (lista != nullptr)
	{
		largo++;
		lista = lista->_sig;
	}

	lista = nodo;

	Array<Tablero> arr(largo);
	for (int i = largo - 1; i > -1; i--)
	{
		arr[i] = lista->_data;
		lista = lista->_sig;
	}

	return arr.ObtenerIterador();
}

#endif