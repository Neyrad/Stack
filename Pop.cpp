#include "Stack.h"

int Stack::Pop(int& x)
{
#ifdef DEBUG
	assert(!OK());
#endif
	if (size < 1) return POP_ERROR;
	x = data[size - 1];
	data[size - 1] = POISON;
	--size;

	hash = CalcHash();
#ifdef DEBUG
	assert(!OK());
#endif
	return 0;
}
