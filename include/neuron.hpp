#ifndef NEURON_HPP
#define NEURON_HPP


class Neuron 
{
    public:
        double bias;
        vector<double> weights;

        double activate(vector<double>& x) const;

};

#endif