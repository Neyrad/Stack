#define DEBUG 1

#ifndef _STACK_H_
#define _STACK_H_

#define private private

#define MAX_STACK_NAME 50

#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <cstring>

template<class T>
class Stack
{
private:
    int               Canary1;
    char name[MAX_STACK_NAME];
    size_t           capacity;
    size_t               size;
    T*                  _data;
    T*                   data;
    size_t               hash;
    int               Canary2;

public:
    void Dump();
    void SetName(const char* _name);
    int OK();

    void Push(T& x);
    int Pop(T* x);

    size_t CalcHash();

    Stack();
    Stack(size_t _capacity, const char* _name);
    Stack(const char* _name);
    Stack(size_t _capacity);
    Stack(const Stack& other);
    ~Stack();

	void operator=(const Stack<T>& other);


    template<class K>
    friend std::ostream& operator<<(std::ostream& stream, Stack<K>& other);

    void CanaryTest();
};

const int POISON               =         42;
const int DEFAULT_CAPACITY     =          4;
const int STACK_CANARY         = 0xDEADBEEF;
const int DATA_CANARY          =   0xC0FFEE;

const int STACK_NULL           =          1;
const int DATA_NULL            =          2;
const int _DATA_NULL           =          3;
const int SIZE_BIGGER_CAPACITY =          4;
const int ZERO_CAPACITY        =          5;
const int BAD_STACK_CANARY     =          6;
const int BAD_DATA_CANARY      =          7;
const int BAD_HASH             =          8;
const int OK_RETURNED_NOTHING  =         -1;

const int  POP_ERROR            =       111;


#include "StackDump.hpp"
#include "CoutDump.hpp"
#include "Push.hpp"
#include "Pop.hpp"
#include "OK.hpp"
#include "Destructor.hpp"
#include "DefaultConstructor.hpp"
#include "CustomConstructor.hpp"
#include "CustomNameConstructor.hpp"
#include "CustomCapacityConstructor.hpp"
#include "CopyConstructor.hpp"
#include "CalcHash.hpp"
#include "SetName.hpp"
#include "AssignmentOperator.hpp"

#endif
