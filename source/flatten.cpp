#include "../include/flatten.hpp"

Vec Flatten::forward(const vector<Mat>& input) {
    // Save the dimensions so we can rebuild the box later
    this->num_channels = input.size();
    this->num_rows = input[0].size();
    this->num_cols = input[0][0].size();
    

    Vec flat_output;
   
    // read the entire matrix and push to a vector
    for(int c = 0;c<num_channels;c++)
    {
        for(int r = 0; r < num_rows;r++)
        {
            for(int col =0 ; col < num_cols;col++)
            {
                flat_output.push_back(input[c][r][col]);
            }
        }
    }



    return flat_output;
}

vector<Mat> Flatten::backward(const Vec& output_error) {
    // Create a blank 3D canvas using the dimensions we saved
    vector<Mat> input_gradient(num_channels, Mat(num_rows, Vec(num_cols, 0.0)));

    int flat_index = 0; // This tracks our position in the 1D error line

    // for each element in output_error, map it to the 3d matrix
    for (int c = 0; c < num_channels; c++) {
        for (int r = 0; r < num_rows; r++) {
            for (int col = 0; col < num_cols; col++) {
                
                // Grab the current error and put it in the 3D grid
                input_gradient[c][r][col] = output_error[flat_index];
                flat_index++; 
                
            }
        }
    }

    return input_gradient;
}