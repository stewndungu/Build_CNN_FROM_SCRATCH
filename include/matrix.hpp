#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include "include/vec.hpp"

using Mat = std::vector<std::vector<double>>;


Mat multiply(const Mat& A, const Mat& B); 

Vec multiply(const Mat& A, const Vec& x);

void print(const Mat& m);


#endif