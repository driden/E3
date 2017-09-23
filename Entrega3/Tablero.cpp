#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"
#include "Utils.h"

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	tablero = bloques;
	pPrioridad = p;
	cantidadMovimientos = 0;
}

nat Tablero::CalcularPrioridad()
{
	// Implementar a partir de la prioridad recibida en el constructor.
	return pPrioridad->CalcularPrioridad(*this);
}

nat Tablero::ObtenerCantidadDeMovimientos() { return cantidadMovimientos; }

bool Tablero::operator==(const Tablero& t) const
{
	Matriz<int> otroTablero = t.ObtenerTablero();

	Iterador<Array<int>> iterOtroTablero = otroTablero.ObtenerIterador();
	Iterador<Array<int>> iterTablero = tablero.ObtenerIterador();
	Utils utils = Utils();
	bool iguales = true;
	while (iterTablero.HayElemento())
	{
		while (iterOtroTablero.HayElemento())
		{
			iguales &= utils.CompararArrays(iterTablero.ElementoActual(), iterOtroTablero.ElementoActual());
			iterOtroTablero.Avanzar();
		}
		iterTablero.Avanzar();
	}
	if (iguales)
	{
		iguales = !(iterTablero.HayElemento() || iterOtroTablero.HayElemento());
	}
	return iguales;
}

Tupla<nat,nat> Tablero::PosicionVacio() const
{
	nat x, y;
	bool salir = false;
	for (nat i =0 ; i < this->tablero.Largo && !salir; i++)
	{
		for (nat j = 0 ; j < tablero.Ancho && !salir; j++)
		{
			if (tablero[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}
	return Tupla<nat, nat>(x, y);
}

Iterador<Tablero> Tablero::Vecinos()
{
	// Implementar.
	return NULL;
}


Matriz<int> Tablero::ObtenerTablero() const
{
	return tablero;
}

Cadena Tablero::Imprimir() const
{
	// Implementar.
	return "";
}


#endif