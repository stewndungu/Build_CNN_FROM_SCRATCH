#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/neuron.hpp"
#include "../include/activation.hpp"
#include "../include/vec.hpp"

#include <stdexcept>

using namespace std;

Neuron::Neuron(int size,string word)
 {
      this->weights= random(size) ;
      this->bias = random_number(); 
      this->typeActivation = word;
     

 }
 
vector<double>& Neuron::getWeights()
{
     return this->weights;
}
double& Neuron::getBias()
{
     return this->bias;
}
void Neuron::setBias(double number)
{
      this->bias = number;
}
void Neuron::setWeights(int index, double value)
{
     this->weights[index] = value;
}
double Neuron::forward(const vector<double>& x) const
{
    
    if (x.size() != this->weights.size()) {
        throw std::invalid_argument("Input size does not match Neuron weights size.");
    }

    double answer = dot(x,this->weights);

    if(this->typeActivation == "softplus")
    {
         
         return softplus(answer+bias);
    }

    if(this->typeActivation == "ReLu")
    {
         return ReLu(answer+bias);
    }
    if(this->typeActivation == "tanh_act")
    {
         return tanh_act(answer+bias);
    }
    
    return sigmoid(answer+bias);
 }

void Neuron::print() const
{
    cout<< "Bias: "<< this->bias << "\n";
    cout<< "Activation type: "<< this->typeActivation<<"\n";
    cout<< "Weights size: "<< this->weights.size()<<"\n";
    cout<< "Weights: ";
    for(const auto& many : this->weights)
    {
        cout<< many << " " ;
    }
    cout<<"\n";
   
}
    

