#ifndef _HEADER_H_
#define _HEADER_H

#include <stdlib.h>
#include <iostream>
#include <assert.h>

class Stack
{
private:
	int 	Canary1;
	size_t capacity;
	size_t     size;
	int*      _data;
	int*       data;
	size_t     hash;
	int 	Canary2;

public:
	void Dump();
	int OK();

	void Push(int x);
	int Pop(int& x);

	size_t CalcHash();

	Stack();
	Stack(size_t _capacity);
	~Stack();
};

const int POISON 		   	   =       -666;
const int DEFAULT_CAPACITY 	   = 	      4;
const int STACK_CANARY		   = 0xDEADBEEF;
const int DATA_CANARY		   =   0xC0FFEE;

const int STACK_NULL	       =  		  1;
const int DATA_NULL		   	   =          2;
const int SIZE_BIGGER_CAPACITY =          3;
const int ZERO_CAPACITY        =          4;
const int BAD_STACK_CANARY	   =          5;
const int BAD_DATA_CANARY	   =          6;
const int BAD_HASH			   =          7;
const int OK_RETURNED_NOTHING  =         -1;

const int POP_ERROR			   =        111;

#endif
