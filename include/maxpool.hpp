#ifdef MAXPOOL_HPP
#define MAXPOOL_HPP
#include "matrix.hpp"
#include <utility>
using namespace std;

class Maxpool
{
    public:
        Maxpool(int pool_size,int stride);

        vector<Mat> forward(const vector<Mat>& input);
        vector<Mat> backward(const vector<Mat>& output_error);



    private:
        //the parameters for the window
        int pool_size;
        int stride;

        int last_row_size;
        int last_col_size;

        // A 3D vector holding pairs of (Row, Col)
        vector<vector<vector<pair<int,int>>>>maxcoords;
}


#endif