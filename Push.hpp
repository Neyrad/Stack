template<class T>
void Stack<T>::Push(T& x)
{
#if DEBUG == 1
    assert(!OK());
#endif
    if (size == capacity)
    {
        capacity *= 2;

        _data = (T*) realloc(_data, capacity * sizeof(data[0])
                                    + 2 * sizeof(DATA_CANARY));

        data = (T*)((int*)_data + 1);

        for (size_t i = capacity / 2; i < capacity; ++i)
            *((char*)(data + i)) = POISON;

        *((int*)&data[capacity]) = DATA_CANARY;
    }
    data[size++] = x;

    hash = CalcHash();
#if DEBUG == 1
    assert(!OK());
#endif
}
