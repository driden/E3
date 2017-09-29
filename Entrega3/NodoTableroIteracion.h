#pragma once
#include "Iteracion.h"
#include "Tablero.h"
#include "NodoTablero.h"

class NodoTableroIteracion: public Iteracion<NodoTablero>
{
public:
	NodoTableroIteracion( Puntero<NodoTablero> nodo);
	~NodoTableroIteracion(){}

	bool HayElemento() const override;
	const NodoTablero& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

private:	
	Puntero<NodoTablero> inicio;
	nat largo;
	nat tope;	
	
};

