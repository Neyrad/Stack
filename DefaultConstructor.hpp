template<class T>
Stack<T>::Stack()
    : Canary1(STACK_CANARY), name("Unknown"), capacity(DEFAULT_CAPACITY), size(0),
      _data(NULL), data(NULL), hash(CalcHash()), Canary2(STACK_CANARY)
{
#if DEBUG == 1
    std::cout << "Default constructor was called" << std::endl;
#endif
    _data = (T*) calloc(capacity * sizeof(_data[0]) + 2 * sizeof(DATA_CANARY), 1);

    *((int*)_data) = DATA_CANARY;

    data = (T*)((int*)_data + 1); 

    for (size_t i = 0; i < capacity; ++i)
        *((char*)(data + i)) = POISON;

    *((int*)&data[capacity]) = DATA_CANARY;

#if DEBUG == 1
    assert(!OK());
#endif
}
