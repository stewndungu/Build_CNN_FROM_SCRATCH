#include <iostream>
#include "maxpool.hpp"


using namespace std;

Maxpool::vector<Mat> forward(const vector<Mat>& input)
{
   //get the input dimensions
   int num_channels = input.size();
   this->last_input_row = input[0].size()
   this->last_input_col = input[0][0].size();

   //calculate the dimensions for the output matrix
   int out_row= this->last_input_row / str
}
Maxpool::vector<Mat> backward(const vector<Mat>& output_error)
{

}


