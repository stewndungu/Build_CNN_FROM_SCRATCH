#include "../include/nn.hpp"
#include "../include/vec.hpp"
#include <iostream>
#include "../include/layer.hpp"
#include <string>



NeuralNetwork::NeuralNetwork(const vector<int>& layer_sizes, string word)
{
    for (size_t i = 1; i < layer_sizes.size(); ++i) 
    {
        
        int input_size_for_layer = layer_sizes[i - 1]; 

      
        int num_neurons_in_layer = layer_sizes[i];      

        this->Layers.push_back(Layer(input_size_for_layer, num_neurons_in_layer,word));
    }
}
/*
Vec NeuralNetwork::forward(const Vec& x)
{

}
void NeuralNetwork::backward(const Vec& x, const Vec& target, double lr){

}

*/
