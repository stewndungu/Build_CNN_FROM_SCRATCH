#ifndef NN_HPP
#define NN_HPP
#include "layer.hpp"
#include "vec.hpp"
class NeuralNetwork
{
    public:

        NeuralNetwork(const vector<int>& layers_sizes,string first_activation, string second_activation);
        Vec forward( Vec& x);
        void backward(const Vec& x, const Vec& target, double lr);


    private:
        vector<Layer>Layers;
};


#endif