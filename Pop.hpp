template<class T>
int Stack<T>::Pop(T* x)
{
#if DEBUG == 1
    assert(!OK());
#endif
    if (size < 1) return POP_ERROR;
    *x = data[size - 1];
    *((char*)(data + size - 1)) = POISON;
    --size;

    hash = CalcHash();
#if DEBUG == 1
    assert(!OK());
#endif
    return 0;
}
