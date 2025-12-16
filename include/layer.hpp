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
        vector<Neuron>& getNeurons();
        vector<double>& getOutput();
        string& getActivation();
        const std::vector<double>& getWeightedSums() const; //
        

        void summary();
    private:
        vector<Neuron> neurons;
        vector<double> output;
        string typeActivation;
        std::vector<double> weighted_sums; // <<< ADD THIS





};





#endif