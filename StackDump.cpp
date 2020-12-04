#include "Stack.h"

void Stack::Dump()
{
	static int err = OK_RETURNED_NOTHING;

	std::cout <<								 std::endl;
	std::cout << "Stack (";

	if (err = OK()) 
	{
		std::cout << "Error #" << err << ": ";
		switch (err)
		{
		case  STACK_NULL: 
			std::cout <<  	  	   			 "Stack == NULL";
			break;
		case  DATA_NULL:
			std::cout <<   		    		  "data == NULL";
			break;
		case  SIZE_BIGGER_CAPACITY:
			std::cout <<				   "size > capacity";
			break;
		case OK_RETURNED_NOTHING:
			std::cout << "Couldn't get return value of OK()";
			break;
		case ZERO_CAPACITY:
			std::cout << 					  "capacity = 0";
			break;
		case BAD_STACK_CANARY:
			std::cout << 	   "The Stack Canary is damaged";
			break;
		case BAD_DATA_CANARY:
			std::cout << 	    "The data Canary is damaged";
			break;
		case BAD_HASH:
			std::cout << 	    			 "Hash is wrong";
			break;
		default: 
			std::cout << 			     	 "Unknown error";
			break;
		}
	}
	else 
		std::cout << "OK";

	std::cout << ")";

	if (this)
	{
		std::cout << " [" << this << "]"          << std::endl;
		std::cout << "{"	    		          << std::endl;
		std::cout << "    capacity: " << capacity << std::endl;
		std::cout << "    size:     " << size     << std::endl;
		std::cout << "    hash:     " << hash     << std::endl;

		if (data)
		{
			std::cout << "    data[" << data << "]"   << std::endl;
			std::cout << "    {"                      << std::endl;

			for (size_t i = 0; i < capacity; ++i)
				if (i < size)
				{
					std::cout << "       *[" << i << "]: " << data[i];
					if (data[i] == POISON) std::cout << " (poison)" << std::endl;
					else		 		   std::cout <<				   std::endl;
				}
				else
				{
					std::cout << "        [" << i << "]: " << data[i];
					if (data[i] == POISON) std::cout << " (poison)" << std::endl;
					else		 		   std::cout <<				   std::endl;
				}

			std::cout << "    }"                      << std::endl;
		}

		std::cout << "}"			        	  << std::endl;
	}
	else
		std::cout << std::endl;

	std::cout << std::endl;
}
