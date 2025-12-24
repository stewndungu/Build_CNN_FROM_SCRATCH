#include <iostream>
#include "include/matrix.hpp"
#include "include/nn.hpp"

using namespace std;

int main()
{
    Mat Sobel_X = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

Mat Sobel_Y = {
    {-1, -2, 1},
    { 0, 0, 0}.
    { 1, 2, 1}
}

// 2. Laplacian (Finds all edges/outlines)
Mat laplacian = {
    { 0,  1, 0},
    { 1, -4, 1},
    { 0,  1, 0}
};

Mat blur_kernel = {
    {1.0/9, 1.0/9, 1.0/9},
    {1.0/9, 1.0/9, 1.0/9},
    {1.0/9, 1.0/9, 1.0/9}
};

Mat sharpen = {
    { 0, -1,  0},
    {-1,  5, -1},
    { 0, -1,  0}
};

Mat test_img = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

// 2. Define a simple Blur kernel (averaging)


    Mat img = load_pgm("random.pgm");
    Mat edges = conv2d(img, Sobel_X);
    //print(edges);

    for(auto row : edges)
    {
        for(double pixel : row)
         {
            printf("%.2f ", pixel);
        }
    printf("\n");
}

    return 0;
}
