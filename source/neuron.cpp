#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/neuron.hpp"
#include "../include/activation.hpp"
#include "../include/vec.hpp"
#include <stdexcept>

using namespace std;

Neuron::Neuron(int size)
 {
      this->weights= random(size) ;
      this->bias = random_number(); 

 }
 

double Neuron::forward(vector<double>& x) const
{
    
    if (x.size() != this->weights.size()) {
        throw std::invalid_argument("Input size does not match Neuron weights size.");
    }

    double answer = dot(x,this->weights);

    return sigmoid(answer+bias);
 }
    

