#ifndef FLATTEN_HPP
#define FLATTEN_HPP

#include "matrix.hpp" // Assuming this holds your vector<Mat> and Vec typedefs
#include <vector>

using namespace std;

class Flatten {
public:
    // Takes in the 3D box, returns a 1D line
    Vec forward(const vector<Mat>& input);
    
    // Takes in the 1D error line, returns a 3D error box
    vector<Mat> backward(const Vec& output_error);

private:
    // Memory of the original shape for the backward pass
    int num_channels;
    int num_rows;
    int num_cols;
};

#endif