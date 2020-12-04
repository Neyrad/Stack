#include "Stack.h"

void Stack::Push(int x)
{
#ifdef DEBUG
    assert(!OK());
#endif
    if (size == capacity)
    {
        capacity *= 2;

        data = (int*) realloc(data, capacity * sizeof(data[0]));

        for (size_t i = capacity / 2; i < capacity; ++i)
            data[i] = POISON;
    }
    data[size++] = x;

    hash = CalcHash();
#ifdef DEBUG
    assert(!OK());
#endif
}
