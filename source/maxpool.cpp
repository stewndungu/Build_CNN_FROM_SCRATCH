#include <iostream>
#include "maxpool.hpp"


using namespace std;

Maxpool::vector<Mat> forward(const vector<Mat>& input)
{
    for(int i=0;i<input.size();i++)
    {
        for(int row =0; row<input[i].size();row + stride)
        {
            for(int column = 0 ;column< input[i][row].size();column + stride)
            {
                int max =0;
                int max_row=0;
                int max_column=0;

                for(int maxrow = row; maxrow < row + pool_size; maxrow++)
                { 
                    for(int maxcol = column; maxcol < column + pool_size;maxcol++)
                    {
                        if(input[i][maxrow][maxcol] > max)
                        {
                            max = input[i][maxrow][maxcol];
                            max_row= maxrow;
                            max_col=maxcol;
                        }
                    }
                }
                

                // I am question why we have a 3D vector of a pair for max_coords. It seems abit odd. Why not a hash map? Or just a regular 3D matrix ?
                maxcoords.push_back();
            }
        }
    }
}
Maxpool::vector<Mat> backward(const vector<Mat>& output_error)
{

}


