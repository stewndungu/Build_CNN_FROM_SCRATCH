#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/layer.hpp"


using namespace std;
Layer::Layer(int input_size, int num_neurons,const string word ="sigmoid")
{
    //the input_size becomes the number of weights needed for a neuron
   this->typeActivation = word;
   this->acc_bias_gradients.resize(num_neurons, 0.0);
   this->acc_weight_gradients.resize(num_neurons);
   this->neurons.reserve(num_neurons);

   for(int j = 0; j < num_neurons;j++)
   {
    acc_weight_gradients[j].resize(input_size,0.0);
   }

   for(int i =0; i< num_neurons ;i++)
   {

       this->neurons.push_back(Neuron(input_size,word)) ;
     

    }

    

        
}
 vector<Neuron>& Layer::getNeurons()
{
  return this->neurons;
 }

vector<double>& Layer::getOutput()
{
    return this->output;
}

vector<double> Layer::forward(const vector<double>& x)
{
    vector<double>answer;
    
    answer.reserve(this->neurons.size());

    for(const auto& neuron :this->neurons)
    {
       
        answer.push_back(neuron.forward(x));
    }

    this->output = answer;
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

string& Layer::getActivation()
{
    return typeActivation;
}

vector<Vec>& Layer::get_acc_weight_gradients()
{
    return acc_weight_gradients;
}
Vec& Layer::get_acc_bias_gradients()
{
    return acc_bias_gradients;
}
