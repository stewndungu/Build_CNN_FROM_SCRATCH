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
        vector<Mat> forward(const vector<Mat>& input);
        vector<Mat> backward(const vector<Mat>& output_error, double learning_rate);
    

    private:
        Weights weights;
        Vec bias;
        string activationType;

        vector<Mat> last_input;
        vector<Mat> last_output;
};


#endif