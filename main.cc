#include "lab3.h"

#include <iostream>
using namespace std;
int main()
{
    TwoStackFixed <int>test1(20, 11);
    test1.push_Stack1(5);
    test1.push_Stack1(2);
    test1.push_Stack2(6);
    test1.display();
    return 0;
}
