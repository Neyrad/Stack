#include "Stack.h"

Stack::Stack()
    : Canary1(STACK_CANARY), capacity(DEFAULT_CAPACITY), size(0),
      _data(NULL), data(NULL), hash(CalcHash()), Canary2(STACK_CANARY)
{
    std::cout << "Default constructor was called" << std::endl;

    _data = (int*) calloc(capacity * sizeof(_data[0]) + 2 * sizeof(DATA_CANARY), 1);

    *_data = DATA_CANARY;

    data = (int*)((int*)_data + 1); 

    for (size_t i = 0; i < capacity; ++i)
        data[i] = POISON;

    *((int*)&data[capacity]) = DATA_CANARY;

#ifdef DEBUG
    assert(!OK());
#endif
}
