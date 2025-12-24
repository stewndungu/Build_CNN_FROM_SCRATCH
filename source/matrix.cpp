#include <iostream>
#include <stdio.h>
#include "../include/matrix.hpp"


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

Mat conv2d(const Mat& img, const Mat& kernel)
 {
    int img_h = img.size();
    int img_w = img[0].size();
    int k_size = kernel.size(); 
    int offset = k_size / 2;    // for a 3x3 kernel, offset is 1

  
    Mat output(img_h, Vec(img_w, 0.0));

    #pragma omp parallel for
    for (int i = offset; i < img_h - offset; i++) {
        for (int j = offset; j < img_w - offset; j++) {
            
            double sum = 0.0;
           
            for (int ki = 0; ki < k_size; ki++) {
                for (int kj = 0; kj < k_size; kj++) {
                    
                    sum += kernel[ki][kj] * img[i - offset + ki][j - offset + kj];
                }
            }
            output[i][j] = sum;
        }
    }
    return output;
}
Mat load_pgm(const string& path)
{
    
    int width = 0;
    int height = 0;
    int grayvalue = 0;
    string type;
    Mat fileinfo;
    ifstream file(path);

    if(!file.is_open())
    {
        cout<< "Error: Trouble opening the file\n";
        return {};
    }

    file>> type;
    if (type != "P2") {
        cout << "Error: This function only supports ASCII PGM (P2). Your file is: " << type << "\n";
        return {};
    }

    string line;
    while(file >> ws && file.peek() == '#')
    {
        getline(file,line);
    }


    file >> width >> height;
    file >> grayvalue;

    fileinfo.resize(height, Vec(width));

    for(int i=0; i< height;i++)
    {
        for(int j=0; j< width;j++)
        {
            int data;
            file >> data;
            fileinfo[i][j] = static_cast<double>(data) / grayvalue;
        }
    }
    
    
    file.close();
    return fileinfo;
}

