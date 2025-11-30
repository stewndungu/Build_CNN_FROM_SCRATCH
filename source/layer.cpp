#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/layer.hpp"
#include "../include/vec.hpp"
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"


using namespace std;
Layer::Layer(int input_size, int num_neurons,const string word ="sigmoid")
{
    //the input_size becomes the number of weights needed for a neuron
   this->neurons.reserve(num_neurons);
   for(int i =0; i< num_neurons ;i++)
   {

       this->neurons.push_back(Neuron(input_size,word)) ;
     

    }

    

        
}

vector<double> Layer::forward(const vector<double>& x)
{
    vector<double>answer;
    answer.reserve(this->neurons.size());

    for(const auto& neuron :this->neurons)
    {
        answer.push_back(neuron.forward(x));
    }

    
    // we are getting a vector then most likely use weights which are a matrix
    //  then do matrix * vector to get a vector
    // then use a sigmoid or relu to get a vector answer

    return answer;
}

void Layer::summary()
{
    cout<<"Neurons in Layer: \n";
    int i=0;
    for(const auto& cells : this->neurons)
    {
        cout<<"Neurons"<<i<<": ";
         cells.print();
         i++;
    }
}