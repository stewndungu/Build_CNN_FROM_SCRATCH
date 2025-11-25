#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/layer.hpp"
#include "../include/vec.hpp"
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"



Layer::Layer(int input_size, int num_neurons)
{
   this->neurons.resize(num_neurons);
   for(int i =0; i< this->neurons.size();i++)
   {
    
       auto neu = new Neuron(input_size);

    }

        
}

Vec forward(const Vec& x)
{
    // we are getting a vector then most likely use weights which are a matrix
    //  then do matrix * vector to get a vector
    // then use a sigmoid or relu to get a vector answer
}