template<class T>
void Stack<T>::operator=(const Stack<T>& other)
{
#if DEBUG == 1
    std::cout << "Assignment operator was called for <" << other.name << ">" << std::endl;
#endif

    if (_data) free(_data);
    Canary1  = other.Canary1; Canary2  = other.Canary2;
    capacity = other.capacity;
    size     = other.size;
    _data    = NULL; data    = NULL;
    hash     = other.hash;


    int i = 0;
    for(i = 0; (name[i] = other.name[i]) && i < MAX_STACK_NAME - 8; ++i)
        ;
    name[i++] = ' '; name[i++] = '('; name[i++] = 'c'; name[i++] = 'o' ;
    name[i++] = 'p'; name[i++] = 'y'; name[i++] = ')'; name[i]   = '\0';

    _data = (T*) calloc(capacity * sizeof(_data[0])      
                        + 2 * sizeof(DATA_CANARY), 1);

    *((int*)_data) = *((int*)other._data);                     // = DATA_CANARY (left)

    data = (T*)((int*)_data + 1);

    for (size_t i = 0; i < size; ++i)
        data[i] = other.data[i];
	for (size_t i = size; i < capacity; ++i)
        *((char*)(data + i)) = POISON;


    *((int*)&data[capacity]) = *((int*)&other.data[capacity]); // = DATA_CANARY (right)

#if DEBUG == 1
    assert(!OK());
#endif    
}
