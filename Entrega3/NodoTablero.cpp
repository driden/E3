#ifndef NODO_TABLERO_CPP
#define NODO_TABLERO_CPP

#include "NodoTablero.h"
#include "NodoTableroIteracion.h"

const NodoTablero& NodoTablero::ElementAt(nat index) const
{
	assert(static_cast<int>(index) < largo);
	Puntero<NodoTablero> itt = padre;
	nat contador = 0;
	while (itt != nullptr  && contador++!= index)
	{
		itt = itt->padre;
		
	}
	return itt;
}
 nat NodoTablero::Largo()
{
	if (largo == -1)
	{
		it = padre;		
		while (this->it != nullptr)
		{
			it = it->padre;
			largo++;
		}
	}
	return largo;
}

//void NodoTablero::Revert()
//{
//	reverse = padre;
//	it = padre;
//	reverse = RevertAux(it);
//	revert = true;
//}

Puntero<NodoTablero> NodoTablero::RevertAux(Puntero<NodoTablero> lista)
{
	if (lista == nullptr) return nullptr;
	it->padre = RevertAux(lista->padre);
	return lista;
}


Iterador<NodoTablero> NodoTablero::ObtenerIterador() const
{
	Iteracion<NodoTablero>* it = new NodoTableroIteracion(this->reverse);
	return Puntero<Iteracion<NodoTablero>>(it);
}


#endif