#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/matrix.hpp"
#include <random>

using namespace std;

Mat multiply(const Mat& A, const Mat& B)
{
    int rowsA = A.size(), colsA = A[0].size(), rowsB = B.size(), colsB = B[0].size();

    // dimension check
    if(colsA != rowsB)
    {
        throw std::runtime_error("Matrix dimension mismatch");
    }
    Mat result(rowsA, vector<double>(colsB, 0.0));

    for(int i = 0; i < rowsA; i++)           // rows of A
    {
        for(int j = 0; j < colsB; j++)       // columns of B
        {
            double sum = 0.0;

            for(int k = 0; k < colsA; k++)   // shared dimension
            {
                sum += A[i].at(k) * B[k].at(j);    // key operation
            }

            result[i][j]=sum;
        }
    }

    return result;
}

//vector and matrix must have the same row size
Vec multiply(const Mat& A, const Vec& x)
{
    vector<double> answer;
    
    if(A[0].size() != x.size())
    {
        throw std::runtime_error("Matrix & Vector dimension mismatch");
    }
    for(int i=0; i< A.size();i++)
    {
        double sum=0.0;
        for(int j=0;j<A[i].size();j++)
        {
            sum+= (x.at(j) * A[i].at(j));
        }
        answer.push_back(sum);
    }
    return answer;
}

Mat random(int rows,int cols)
{
      random_device rd;
    std::mt19937 gen(rd()); 
      std::uniform_real_distribution<> dis(-1.0, 1.0);

      Mat result(rows,vector<double>(cols,0.0));
      for(int i=0;i<rows;i++)
      {
        for(int j=0;j<cols;j++)
        {
            result[i][j]= dis(gen);
        }
      }

      return result;


}

Mat transpose (const Mat& A)
{
    Mat answer(A[0].size(),vector<double>(A.size(),0.0));

    for(int i=0;i<A.size();i++)
    {
        for(int j=0; j<A[i].size();j++)
        {
            answer[j][i] = A[i][j];
        }
    }
    
    return answer;
}

void print(const Mat& m)
{
    for(int i=0;i< m.size();i++)
    {
        cout<<"{";
        for(int j=0; j< m[i].size();j++)
        {
            cout<< m[i].at(j)<< " ";
        }

        cout<<"}"<<"\n";
    }

    

}