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

double derivateSigmoid(double x)
{
    double s= sigmoid(x);
    return s * (1.0 - s);
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
    double s = tanh_act(x);
    return (1.0 - (s*s));

}

double softplus(double x)
{
    return (log(1 + exp(x)));
}