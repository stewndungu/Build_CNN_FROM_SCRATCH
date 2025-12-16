#ifndef VEC_HPP
#define VEC_HPP
#include <vector>
#include <random>

using Vec = std::vector<double>;

std::mt19937& get_generator();

Vec add(const Vec& a, const Vec& b); 

Vec subtract(const Vec& a, const Vec& b);

Vec scalar_mult(const Vec& a, double s);

Vec random(int size);

double random_number();

void print(const Vec& v);

double dot(const Vec& a, const Vec& b);

#endif