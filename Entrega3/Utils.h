#pragma once
#include "Array.h"
#include "Tupla.h"

class Utils
{
public:
	Utils(){}
	~Utils(){}
	bool CompararArrays(const Array<int>& arr1, const Array<int>& arr2) const;
	template <class T>
	void Swap(Array<T> &arr, nat pos1, nat pos2);

	template <class T,class P>
	void Swap(Array<Tupla<T,P>> &arr, nat pos1, nat pos2);
	
	template <class T>
	Array<T> Filter(const Array<T> &arr, bool(*cumple)(T));
};


