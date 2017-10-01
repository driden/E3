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
		pQueue = new CPBinaryHeap<Puntero<Lista<Tablero>>, nat>(Comparador<Puntero<Lista<Tablero>>>::Default, Comparador<nat>::Default, nullptr);
		lista = new Lista<Tablero>();
		lista->Insertar(tablero);

		// El tablero tiene que saber quien fue el anterior.
		nat prioridadInicial = tablero.CalcularPrioridad();
		pQueue->InsertarConPrioridad(lista, prioridadInicial);
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
					nat prioridadF = vecino.CalcularPrioridad();
					nat movs = ultimo.ObtenerCantidadDeMovimientos();
					nat prioridadvecino = prioridadF  + movs;
					pQueue->InsertarConPrioridad(lt, prioridadvecino);
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
	Tablero t = lista->Ultimo();
	return t.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	return lista->ObtenerIterador();
}


#endif