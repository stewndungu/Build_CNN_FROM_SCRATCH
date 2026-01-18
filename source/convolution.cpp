#include <iostream>
#include "convolution.hpp"

using namespace std;
 convolution::convolution (int& num_of_Filters, int& num_of_channels, int& kernelSize, string activationType)
{
    this->weights.resize(num_of_Filters, vector<vector<Vec>>(num_of_channels, vector<Vec>(kernelSize, Vec(kernelSize))));

    this->activationType = activationType;

    int in = num_of_channels * kernelSize * kernelSize;
    
    for(int filter= 0; filter < num_of_Filters; filter++)
    {
        for(int channel; channel < num_of_channels; channel++)
        {
            for(int row= 0; row < kernelSize ; row++)
            {
                for(int column = 0; column < kernelSize ; column++)
                {
                    if(activationType == "ReLu")
                    {
                         weights[filter][channel][row][column] = HeAdjusted(in,0.01);
                    }
                    else if(activationType == "sigmoid" || activationType == "tanh_act")
                    {
                         weights[filter][channel][row][column] = Xavier(in);
                    } 
                   
                }
            }
        }
    }


    this->bias.resize(num_of_Filters,0.0);
}

Weights& convolution::getWeights()
{
    return this->weights;
}

Vec& convolution::getBias()
{
    return this->bias;
}

Mat convolution::forward(const vector<Mat> input)
{

}