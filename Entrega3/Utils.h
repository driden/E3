#pragma once
#include "Array.h"

class Utils
{
public:
	Utils(){}
	~Utils(){}
	bool CompararArrays(const Array<int>& arr1, const Array<int>& arr2) const;
	template <class T>
	void Swap(Array<T> &arr, nat pos1, nat pos2);
};


