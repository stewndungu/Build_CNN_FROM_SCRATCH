#include <stdio.h>
#include "../include/vec.hpp"
using namespace std;
#include <vector>
#include <iostream>

Vec add(const Vec& a, const Vec& b)
{
   int i=0;
    int j=0;

    vector<double> answer;
    while(i< a.size() && j< b.size())
    {
        answer.push_back(a.at(i) + b.at(j));
        i++;
        j++;
    }
    if( i > j)
    {
        while(i < a.size()-1)
        {
            answer.push_back(a.at(i));
            i++;
        }    
    }
    else if( j > i)
    {
        while(j < b.size()-1)
        {
            answer.push_back(b.at(j));
            j++;
        }
    }


    
    return answer;
}


Vec subtract(const Vec& a, const Vec& b)
{
     int i=0;
    int j=0;
    
    vector<double> answer;
    while(i< a.size() && j< b.size())
    {
        answer.push_back(a.at(i) - b.at(j));
        i++;
        j++;
    }
    if( i > j)
    {
        while(i < a.size()-1)
        {
            answer.push_back(a.at(i));
            i++;
        }    
    }
    else if( j > i)
    {
        while(j < b.size()-1)
        {
            answer.push_back(b.at(j));
            j++;
        }
    }


    
    return answer;
}

Vec scalar_mult(const Vec& a, double s)
{
    vector<double> answer;
    for(int i=0;i< a.size(); i++)
    {
       answer.push_back( a.at(i) * s);

    }

    return answer;
}

double dot(const Vec& a, const Vec& b)
{
    
    int i=0;
    int j=0;
    
    double answer = 0.0;
    while(i< a.size() && j< b.size())
    {
       answer += ( a.at(i) * b.at(j));
        i++;
        j++;
    }
    if( i > j)
    {
        while(i < a.size()-1)
        {
            answer += a.at(i);
        }    
    }
    else if( j > i)
    {
        while(j < b.size()-1)
        {
           answer += b.at(j);
            j++;
        }
    }

    return answer;
    
}

void print(const Vec& v)
{
    for(int i=0; i< v.size();i++)
    {
        cout<< v.at(i)<< " ";
    }
    cout<< "\n";
}
