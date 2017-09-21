#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"
#include "Utils.h"

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	tablero = bloques;
	pPrioridad = p;
}

nat Tablero::CalcularPrioridad()
{
	// Implementar a partir de la prioridad recibida en el constructor.
	return pPrioridad->CalcularPrioridad(*this);
}

nat Tablero::ObtenerCantidadDeMovimientos(){return 0;}

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


Iterador<Tablero> Tablero::Vecinos()
{
	// Implementar.
	return NULL;
}


Matriz<int> Tablero::ObtenerTablero() const
{
	// Implementar.
	return Matriz<int>();
}

Cadena Tablero::Imprimir() const
{
	// Implementar.
	return "";
}


#endif