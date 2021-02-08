template<class T>
int Stack<T>::OK()
{
    if (!this)           return           STACK_NULL;
    if (!data)           return            DATA_NULL;
    if (!_data)          return           _DATA_NULL;
    if (size > capacity) return SIZE_BIGGER_CAPACITY;
    if (!capacity)       return        ZERO_CAPACITY;

    if (Canary1 != STACK_CANARY || Canary2 != STACK_CANARY)
                         return     BAD_STACK_CANARY;
	
    if (*((int*)_data)           != DATA_CANARY ||
        *((int*)&data[capacity]) != DATA_CANARY)
                         return      BAD_DATA_CANARY;

    if (hash != CalcHash())
                         return             BAD_HASH;

    return 0;
}
