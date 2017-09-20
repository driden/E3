#ifndef PRIORIDAD_A_H
#define PRIORIDAD_A_H

#include "Tablero.h"
#include "Prioridad.h"

typedef unsigned int nat;

class PrioridadA : public Prioridad {
public:
	PrioridadA() {}
	~PrioridadA() {}
	Array<int> AplanarTablero(const Tablero& t) const;
	nat SumarArray(const Array<int> arr) const;
	//Retorna el numero de bloques fuera de lugar. 
	nat CalcularPrioridad(const Tablero& t) const;
};

#endif