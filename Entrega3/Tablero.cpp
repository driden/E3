#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	// Implementar.
}
	
nat Tablero::CalcularPrioridad()
{
	// Implementar a partir de la prioridad recibida en el constructor.
	return 0;
}
		
bool Tablero::operator==(const Tablero& t ) const
{
	// Implementar.
	return false;
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