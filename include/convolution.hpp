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


    private:
        Weights weights;
        Vec bias;
        string activationType;
};


#endif