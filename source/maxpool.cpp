#include <iostream>
#include "maxpool.hpp"


using namespace std;

Maxpool::Maxpool(int pool_size,int stride)
{
   this->pool_size = pool_size;
   this->stride = stride;
}
Maxpool::vector<Mat> forward(const vector<Mat>& input)
{
   //get the input dimensions
   int num_channels = input.size();
   this->last_row_size = input[0].size()
   this->last_col_size = input[0][0].size();

   //calculate the dimensions for the output matrix
   int out_row= this->last_row_size / stride;
   int out_col = this->last_col_size / stride;

   //Resize maxcoords to match shape of the intialized output
   vector<Mat> output(num_channels, Mat(out_row. Vec(out_col,0.0)));
   this->maxcoords.assign(num_channels,vector<vector<pair<int,int>>>(out_row, vector<pair<int,int>>(out_col)));

   for(int channel = 0; channel < num_channels; channel++)
   {
      
      for(int row = 0; row < out_row; row++)
      {

         for(int col = 0; col < out_col; col++)
         {

            //get the correct area to look at by multiplying by the stride
            int start_row = row * stride;
            int start_col = col * stride;

            //initialize max_val to the lowest possible value
            double max_val = -numeric_limits<double>::infinity();
            int max_r = -1;
            int max_c = -1;

            //looping over the 2x2 pool window
            for(int poolrow = 0; poolrow < pool_size; poolrow++)
            {
               for(int poolcol = 0 ; poolcol < pool_size; poolcol++)
               {
                  int current_row = start_row + poolrow;
                  int current_col = start_col + poolcol;

                  if(input[channel][current_row][current_col] > max_val)
                  {
                     max_val = input[channel][current_row][current_col]
                     max_r = current_row;
                     max_c = current_col;
                  }
               }
            }

            output[channel][row][col] = max_val;
            maxcoords[channel][row][col] = {max_r,max_c}
         }
      }
   }

   return output;
}
Maxpool::vector<Mat> backward(const vector<Mat>& output_error)
{
   //get the output_Error dimensions for channel/row/col
   int num_channels = output_error.size();
   int out_row = output_error[0].size();
   int out_col = output_error[0][0].size();

   //intialize the input_gradient
   vector<Mat> input_gradient(num_channels,Mat(this->last_row_size, Vec(this->last_col_size,0.0)));

   for(int c = 0; c < num_channels; c++)
   {
      for(int r = 0; r < out_row; r++)
      {
         for(int col = 0; col< out_col;col++)
         {
            // get the address for the saved max value
            int orig_row = this->maxcoords[c][r][col].first;
            int orig_col = this->maxcoords[c][r][col].second;

            // put the output_error values in the input_gradient
            input_gradient[c][orig_row][orig_col] = output_error[c][r][col]
         }
      }
   }
   return input_gradient;
}


