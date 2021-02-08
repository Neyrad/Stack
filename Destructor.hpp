template<class T>
Stack<T>::~Stack()
{
#if DEBUG == 1
    std::cout << "Destructor was called for <"<< this->name << ">" << std::endl;

/*	std::cout << "this: " << this << std::endl;

	for(size_t i = 0; i < size; ++i)
	    std::cout << this->data[i] << std::endl;

    std::cout << "OK() = " << OK() << std::endl;
*/
    assert(!OK());
#endif
    if (_data) free (_data);
}
