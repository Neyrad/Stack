//#define DEBUG

#include "Stack.h"

int main()
{
    static int trash = 777;

    Stack stk(6);
    stk.Dump();

    stk.Push(100);
    stk.Dump();

    stk.Pop(trash);
    stk.Dump();

    stk.Push(200);
    stk.Dump();

    stk.Push(300);
    stk.Dump();

    std::cin >> trash;
}
