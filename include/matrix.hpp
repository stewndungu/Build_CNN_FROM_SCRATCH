#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "vec.hpp"
#include <random>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
using Mat = std::vector<std::vector<double>>;

Mat multiply(const Mat& A, const Mat& B); 

Mat random(int rows,int cols);

Mat transpose (const Mat& A);

Vec multiply(const Mat& A, const Vec& x);

void print(const Mat& m);


Mat conv2d(const Mat& img, const Mat& kernel);
Mat load_pgm(const string& path);


#endif
