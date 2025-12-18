#ifndef NN_HPP
#define NN_HPP
#include "layer.hpp"
class NeuralNetwork
{
    public:

        NeuralNetwork(const vector<int>& layers_sizes,string first_activation, string second_activation);
        Vec forward( Vec& x);
        void backward(const Vec& x, const Vec& target, double lr);
        void save(const std::string& filename) const;
        void load(const std::string& filename);


    private:
        vector<Layer>Layers;
};


#endif