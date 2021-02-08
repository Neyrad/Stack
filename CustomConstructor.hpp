template<class T>
Stack<T>::Stack(size_t _capacity, const char* _name)
    : Canary1(STACK_CANARY), name("Poison"), capacity(_capacity), size(0),
      _data(NULL), data(NULL), hash(CalcHash()), Canary2(STACK_CANARY)
{
#if DEBUG == 1
    std::cout << "Custom constructor was called with "
                 "_capacity: " << _capacity << 
                 ", _name: <" << _name << ">" << std::endl;
#endif

    int i = 0;
    for(i = 0; (name[i] = _name[i]) && i < MAX_STACK_NAME; ++i)
        ;
    name[i] = '\0';

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
