#include <stdio.h>
#include "../include/vec.hpp"
using namespace std;
#include <vector>
#include <iostream>
#include <random>

Vec add(const Vec& a, const Vec& b)
{
   
    if(a.size() != b.size())
    {
        throw std::runtime_error("Vector dimension mismatch");
    }
    vector<double> answer;
    for(int i=0; i<a.size();i++)
    {
        answer.push_back(a.at(i) + b.at(i));
    }


    
    return answer;
}


Vec subtract(const Vec& a, const Vec& b)
{
    
    if(a.size() != b.size())
    {
        throw std::runtime_error("Vector dimension mismatch");
    }
    vector<double> answer;
     for(int i=0; i<a.size();i++)
    {
        answer.push_back(a.at(i) - b.at(i));
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

std::mt19937& get_generator()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}
Vec random(int size)
{
    std::mt19937& gen = get_generator();
    uniform_real_distribution<double> dis(-1.0, 1.0);
    
    vector<double> answer;
    for(int i=0;i<size;i++)
    {
        answer.push_back(dis(gen));
    }

    return answer;


}

double random_number()
{
    std::mt19937& gen = get_generator();
    uniform_real_distribution<double> dis(-1.0, 1.0);
    
    
    return dis(gen);
    
}
double dot(const Vec& a, const Vec& b)
{
    
    if(a.size() != b.size())
    {
        throw std::runtime_error("Vector dimension mismatch");
    }
    
    double answer = 0.0;
    for(int i=0; i<a.size();i++)
    {
        answer +=(a.at(i) * b.at(i));
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
