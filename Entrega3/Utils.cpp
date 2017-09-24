#ifndef UTILS_CPP
#define UTILS_CPP

#include "Utils.h"
bool Utils::CompararArrays(const Array<int> &arr1, const Array<int> &arr2) const
{
	bool sonIguales = false;
	if (arr1.Largo == arr2.Largo)
	{
		bool salir = false;
		for (nat x = 0; x < arr1.Largo && !salir; x++)
		{
			for (nat y = 0; y < arr2.Largo; y++)
			{
				if (arr1[x] != arr2[y])
				{
					salir = true;
					break;
				}
			}
		}

		if (salir) sonIguales = false;
		else sonIguales = true;
	}

	return sonIguales;
}
template <class T>
void Utils::Swap(Array<T> &arr, nat pos1, nat pos2)
{
	T aux = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = aux;
}

template <class T, class P>
void Utils::Swap(Array<Tupla<T,P>> &arr, nat pos1, nat pos2)
{
	Tupla<T,P> aux = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = aux;
}

template <class T>
Array<T> Utils::Filter(const Array<T>& arr, bool(*cumple)(T))
{
	nat cantCumple = 0;
	Array<bool> arrCumplen(arr.Largo, false);

	for (nat i = 0; i < arr.Largo; i++)
	{
		if (cumple(arr[i]))
		{
			arrCumplen[i] = true;
			cantCumple++;
		}			
	}

	Array<T> ret(cantCumple);
	nat c = 0;
	for(nat i =0; i < arrCumplen.Largo;i++)
	{
		if(arrCumplen[i])
		{
			ret[c] = arr[i];
			c++;
		}

	}
	return ret;
}
#endif
