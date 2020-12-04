#include "Stack.h"

size_t Stack::CalcHash()
{
	size_t newHash = 0;
	for (size_t i = 0; i < size; ++i)
		newHash += (i + 1) * data[i];
	return newHash;
}
