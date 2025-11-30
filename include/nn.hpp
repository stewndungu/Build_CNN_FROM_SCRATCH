#ifndef NN.HPP
#define NN.HPP
#include "layer.hpp"
#include "vec.hpp"
class NeuralNetwork
{
    public:

        NeuralNetwork(const vector<int>& layers_size, string word);
        Vec forward(const Vec& x);
        void backward(const Vec& x, const Vec& target, double lr);


    private:
        vector<Layer>Layers;
};


#endif