#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/layer.hpp"
#include "../include/vec.hpp"
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"



Layer::Layer(int input_size, int num_neurons)
{
    Mat result(num_neurons,vector<double>(input_size,0.0));

    for(int i=0; i< num_neurons;i++)
    {
        for(int j=0; j< input_size;j++)
        {
            result[i][j]= Ne
        }
    }
}

Vec forward(const Vec& x)
{
    // we are getting a vector then most likely use weights which are a matrix
    //  then do matrix * vector to get a vector
    // then use a sigmoid or relu to get a vector answer
}