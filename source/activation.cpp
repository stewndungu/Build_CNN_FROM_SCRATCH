#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/activation.hpp"
#include <stdio.h>
#include <cmath>

using namespace std;

double sigmoid(double x)
{
    return (1.0)/(1.0 + exp(-x));
}

double derivativeSigmoid(double x)
{
    
    return x * (1.0 - x);
}

double ReLu(double x)
{
    return max(0.0, x);
}

double derivativeRelu (double x)
{
    return (x > 0.0) ? 1.0 : 0.0;
}

double tanh_act(double x)
{
    return tanh(x);
}

double derivatieTanh_act(double x)
{
    
    return (1.0 - (x*x));

}

double softplus(double x)
{
    return (log(1 + exp(x)));
}

double mse(const Vec& output, const Vec& target)
{
    double sum=0.0;
    
    if(output.size() != target.size())
    {
          throw std::runtime_error("Vector dimension mismatch");
    }

    for(int i=0;i<output.size();i++)
    {
        double ans= target.at(i) - output.at(i);
        sum+=(ans*ans);
    }

    return sum/static_cast<double>(output.size());
}


Vec mse_derivative(const Vec& output, const Vec& target)
{
   
    size_t N = output.size(); 
    Vec gradient(N);

    for (size_t i = 0; i < N; ++i)
    {
        gradient[i] = (2.0 / static_cast<double>(N)) * (output[i] - target[i]);
    }
    return gradient;
}