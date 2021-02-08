template<class T>
void Stack<T>::SetName(const char* _name)
{
    int i = 0;
    for(i = 0; (this->name[i] = _name[i]) && i < MAX_STACK_NAME; ++i)
        ;
    this->name[i] = '\0';
}
