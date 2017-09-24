#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"
#include "Utils.h"
#include <string>

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	tablero = bloques;
	pPrioridad = p;
	cantidadMovimientos = 0;
}

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p, nat cantidadDeMovimientos)
{
	tablero = Matriz<int>(bloques);
	pPrioridad = p;
	cantidadMovimientos = cantidadDeMovimientos;
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

Tupla<nat, nat> Tablero::PosicionVacio() const
{
	nat x, y;
	bool salir = false;
	for (nat i = 0; i < this->tablero.Largo && !salir; i++)
	{
		for (nat j = 0; j < tablero.Ancho && !salir; j++)
		{
			if (tablero[i][j] == 0)
			{
				x = i;
				y = j;
				salir = true;
			}
		}
	}
	return Tupla<nat, nat>(x, y);
}

bool Tablero::EstaEnRango(Tupla<nat,nat> pos)
{
	return pos.Dato1 >= 0 && pos.Dato1 < tablero.Largo && pos.Dato2 >= 0 && pos.Dato2 < tablero.Largo;
}

Array<Tupla<nat,nat>> Tablero::FiltrarVecinosEnRango(Array<Tupla<nat,nat>> vecinos)
{
	nat cantCumple = 0;
	Array<bool> arrCumplen(vecinos.Largo, false);

	for (nat i = 0; i < vecinos.Largo; i++)
	{
		if (EstaEnRango(vecinos[i]))
		{
			arrCumplen[i] = true;
			cantCumple++;
		}
	}

	Array<Tupla<nat, nat>> ret(cantCumple);
	nat c = 0;
	for (nat i = 0; i < arrCumplen.Largo; i++)
	{
		if (arrCumplen[i])
		{
			ret[c] = vecinos[i];
			c++;
		}

	}
	return ret;
}

Array<Tablero> Tablero::CrearListaDeTableros(Array<Tupla<nat,nat>> jugadasPosibles, Tupla<nat,nat> posVacio) 
{
	Array<Tablero> tableros(jugadasPosibles.Largo);

	for (nat i =0 ; i < jugadasPosibles.Largo;i++)
	{
		Matriz<int> copia = Copiar();
		//Swap vacio con jugada
		copia[posVacio.Dato1][posVacio.Dato2] = copia[jugadasPosibles[i].Dato1][jugadasPosibles[i].Dato2];
		copia[jugadasPosibles[i].Dato1][jugadasPosibles[i].Dato2] = 0;

		tableros[i] = Tablero( copia,pPrioridad,cantidadMovimientos);
	}

	return tableros;
}

Iterador<Tablero> Tablero::Vecinos()
{
	Tupla<nat, nat> posVacio = PosicionVacio();

	nat cantidadVecinos = 0;
	Array<Tupla<nat, nat>> vecinos(4);

	vecinos[0] = Tupla<nat, nat>(posVacio.Dato1, posVacio.Dato2 - 1);
	vecinos[1] = Tupla<nat, nat>(posVacio.Dato1 - 1, posVacio.Dato2);
	vecinos[2] = Tupla<nat, nat>(posVacio.Dato1 + 1, posVacio.Dato2);
	vecinos[3] = Tupla<nat, nat>(posVacio.Dato1, posVacio.Dato2 + 1);

	// filtrar posiciones invalidas en el tablero
	Array<Tupla<nat, nat>> vecinosFiltrados = FiltrarVecinosEnRango(vecinos);
	
	Array<Tablero> tableros = CrearListaDeTableros(vecinosFiltrados, posVacio);
	return tableros.ObtenerIterador();
}


Matriz<int> Tablero::ObtenerTablero() const
{
	return tablero;
}

Cadena Tablero::Imprimir() const
{
	nat largo = tablero.Largo;
	string s = "\n";
	for (nat i = 0; i < largo ; i++)
	{
		for (nat j =1 ; j <= largo ; j++)
		{
			s += std::to_string(tablero[i][j-1]);
			if (j % largo == 0)
				s += "\n";
			else
				s += " ";
			
		}
	}
	return Cadena(s.c_str());
}

Matriz<int> Tablero::Copiar() const
{
	Matriz<int> m(tablero.Largo);

	for (nat x = 0; x < m.Largo; x++)
		for (nat y = 0; y < m.Largo; y++)
			m[x][y] = tablero[x][y];

	return m;
}

void Tablero::Mover(const nat& mov)
{
	cantidadMovimientos += mov;
}


#endif
