#ifndef SISTEMA_H
#define SISTEMA_H

#include "Iterador.h"
#include "Tablero.h"
#include "Prioridad.h"
#include "PrioridadA.h"
#include "PrioridadB.h"
#include "Tupla.h"
#include "ColaPrioridadExtendida.h"
#include "FuncionHash.h"

class Sistema
{
public:
	Sistema();

	void EstablecerTableroInicial(Tablero inicial);

	//Decide si el tablero inicial tiene solución. 
	bool TieneSolucion();
	
	//Retorna la cantidad mínima de movimientos necesarios para resolver el rompecabezas. Si no hay solución posible retorna −1. 
	int Movimientos();

	//Retorna un iterador de tableros con los movimientos necesarios para resolver el rompecabezas con movimientos mínimos.
	//Si no hay solución devuelve un iterador vacío. 
	Iterador<Tablero> Solucionar();

	template <class T, class P>
	Puntero<ColaPrioridadExtendida<T, P>> CrearColaPrioridadExtendida(const Comparador<T>& compElementos, const Comparador<P>& compPrioridades, Puntero<FuncionHash<T>> fHashElementos);


private:
	//Atributos necesarios para cumplir con las operaciones.
};

#include "SistemaTemplates.cpp"

#endif
