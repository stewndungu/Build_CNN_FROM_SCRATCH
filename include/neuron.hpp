#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <string>

using namespace std;

class Neuron 
{
    public:
        
        Neuron(int size,string word);

        double forward(const vector<double>& x) const;

        void print() const;

        vector<double>& getWeights();
        double& getBias();
        void setBias(double number);;
        void setWeights(int index, double value);

    private:
        double bias;
        vector<double> weights;
        string typeActivation;
};

#endif