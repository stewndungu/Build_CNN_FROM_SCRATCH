#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include "vec.hpp"

using Mat = std::vector<std::vector<double>>;

Mat multiply(const Mat& A, const Mat& B); 

Mat random(int rows,int cols);

Vec multiply(const Mat& A, const Vec& x);

void print(const Mat& m);


#endif