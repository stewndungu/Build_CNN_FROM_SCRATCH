#ifndef NEURON_HPP
#define NEURON_HPP


class Neuron 
{
    public:
        
        Neuron(int size);

        double forward(vector<double>& x) const;

    private:
        double bias;
        vector<double> weights;
};

#endif