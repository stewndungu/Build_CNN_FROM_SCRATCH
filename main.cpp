#include <stdio.h>
#include <iostream>
#include "include/vec.hpp"
#include "include/matrix.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    Vec myVec;
    Vec myTec;
    myVec.push_back(1.23);
    myVec.push_back(2.5);
    myVec.push_back(1.23);

    myTec.push_back(123);
    myTec.push_back(1.23);
    myTec.push_back(1.23);

    

    vector<double>answer = scalar_mult(myVec,4);
    
    cout << dot(myVec,myTec) << "\n";

   
    print(answer);
    return 0;
}