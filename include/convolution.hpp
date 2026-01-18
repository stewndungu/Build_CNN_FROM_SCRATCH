#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP
#include "matrix.hpp"
#include "activation.hpp"

using Weights = vector<vector<Mat>>;
using namespace std;
class convolution 
{
    public:
        convolution(int& num_of_Filters, int& num_of_channels, int& kernelSize, string activationType);
        Weights& getWeights();
        Vec& getBias();
        Mat forward(const vector<Mat>& input);
    

    private:
        Weights weights;
        Vec bias;
        string activationType;
};


#endif