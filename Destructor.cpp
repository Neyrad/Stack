#include "Stack.h"

Stack::~Stack()
{
    std::cout << "Destructor was called" << std::endl;
#ifdef DEBUG
    assert(!OK());
#endif
    if (_data) free (_data);
}
