#include <stdio.h>
#include <iostream>
#include "include/vec.hpp"
//#include "source/vec.cpp"
#include <vector>
#include <iostream>
int main()
{
    Vec myVec;
    myVec.push_back(1.23);

    print(myVec);
    return 0;
}