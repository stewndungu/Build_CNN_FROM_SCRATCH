#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/neuron.hpp"
#include "../include/activation.hpp"

using namespace std;

class Neuron 
{
    public:

        double bias =0;

        double activate(vector<double>& x) const
        {
            for(int i=0;i<x.size();i++)
            {
                x.at(i) = sigmoid(x.at(i));
            }
        }

};