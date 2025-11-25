#ifndef LAYER_HPP
#define LAYER_HPP
#include "vec.hpp"
#include "neuron.hpp"
#include <vector>

using namespace std;


class Layer
{
    public:

        Layer (int input_size, int num_neurons);
        Vec forward(const Vec& x);
    private:
        vector<Neuron> neurons;




};





#endif