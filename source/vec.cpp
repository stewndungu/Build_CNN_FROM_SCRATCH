#include <stdio.h>
#include "../include/vec.hpp"
using namespace std;
#include <vector>
#include <iostream>
/*
Vec add(const Vec& a, const Vec& b)
{
    int i=0;
    vector<double> answer;
    while(i< a.size()-1 && i< b.size()-1)
    {
        
        
    }
    
    return answer;
}
*/



void print(const Vec& v)
{
    for(int i=0; i< v.size();i++)
    {
        cout<< v.at(i)<< " ";
    }
    cout<< "\n";
}
