#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP
#include "vec.hpp"
double sigmoid(double x);

double derivativeSigmoid(double x);

double ReLu(double x);

double derivativeRelu (double x);

double tanh_act(double x);
double derivatieTanh_act(double x);

double softplus(double x);

double mse(const Vec& output, const Vec& target);

#endif