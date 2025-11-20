#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/matrix.hpp"
//#include "../include/vec.hpp"

using namespace std;

Mat multiply(const Mat& A, const Mat& B)
{
    vector<vector<double>> answer;

    

    return answer;
}
void print(const Mat& m)
{
    for(int i=0;i< m.size();i++)
    {
        for(int j=0; j< m[i].size();j++)
        {
            cout<< m[i].at(j)<< " ";
        }

        cout<<"\n";
    }

}