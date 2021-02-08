template<class K>
std::ostream& operator<<(std::ostream& stream, Stack<K>& other)
{
    int err = OK_RETURNED_NOTHING;

    stream << std::endl;
    stream << "Stack <" << other.name << "> (";

    if (err = other.OK()) 
    {
        stream << "Error #" << err << ": ";
        switch (err)
        {
        case  STACK_NULL: 
            stream <<                     "Stack == NULL";
            break;
        case  DATA_NULL:
            stream <<                      "data == NULL";
            break;
        case  _DATA_NULL:
            stream <<                     "_data == NULL";
            break;
        case  SIZE_BIGGER_CAPACITY:
            stream <<                   "size > capacity";
            break;
        case OK_RETURNED_NOTHING:
            stream << "Couldn't get return value of OK()";
            break;
        case ZERO_CAPACITY:
            stream <<                     "capacity == 0";
            break;
        case BAD_STACK_CANARY:
            stream <<       "The Stack Canary is damaged";
            break;
        case BAD_DATA_CANARY:
            stream <<        "The data Canary is damaged";
            break;
        case BAD_HASH:
            stream <<                     "Hash is wrong";
            break;
        default: 
            stream <<                     "Unknown error";
            break;
        }
    }
    else 
	    stream << "OK";

    stream << ")";

    if (&other)
    {
        stream << " [" << &other << "]"              << std::endl;
        stream << "{"                                << std::endl;
        stream << "    capacity: " << other.capacity << std::endl;
        stream << "    size:     " << other.size     << std::endl;
        stream << "    hash:     " << other.hash     << std::endl;

        if (other.data)
        {
            stream << "    data[" << (void*)other.data << "]"   << std::endl;
            stream << "    {"                                   << std::endl;

            for (size_t i = 0; i < other.capacity; ++i)
                if (i < other.size)
                {
                    stream << "       *[" << i << "]: " 
                           <<    other.data[i] << std::endl;
                }
                else
                {
                    if (*((char*)(other.data + i)) == POISON)
                        stream << "        [" << i << "]: "
                               << (int)(*((char*)(other.data + i))) 
                               << " (poison)" <<    std::endl;
                    else
                        stream << "        [" << i << "]: " 
                               <<     other.data[i] << std::endl;
                }

            stream << "    }" << std::endl;
        }

        stream << "}" << std::endl;
    }
    else
        stream << std::endl;

    stream << std::endl;

#if DEBUG == 1
    assert(!other.OK());
#endif
    
    return stream;
}
