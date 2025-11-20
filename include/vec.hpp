#ifndef VEC_HPP
#define VEC_HPP
#include <vector>
using Vec = std::vector<double>;

Vec add(const Vec& a, const Vec& b); 

Vec subtract(const Vec& a, const Vec& b);

Vec scalar_mult(const Vec& a, double s);

void print(const Vec& v);

double dot(const Vec& a, const Vec& b);

#endif