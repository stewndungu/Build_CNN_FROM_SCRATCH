#ifndef LAYER_HPP
#define LAYER_HPP
#include "vec.hpp"
#include "neuron.hpp"
#include <vector>
#include <string>
using namespace std;


class Layer
{
    public:

        Layer (int input_size, int num_neurons,const string word);
        vector<double> forward(const vector<double>& x);

        void summary();
    private:
        vector<Neuron> neurons;
        string typeActivation;





};





#endif