
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
    friend ostream& operator<<(ostream& out, const Matrix& srcMatrix);
public:
    Matrix();
    // initialize Matrix class object with rowN=1, colN=1, and zero value
    Matrix(const int rN, const int cN);
    // initialize Matrix class object with row number rN, col number cN and zero values
    Matrix(const Matrix& srcMatrix);
    // initialize Matrix class object with another Matrix class object
    Matrix(const int rN, const int cN, const float* srcPtr);
    // initialize Matrix class object with row number rN, col number cN and a pointer to an array

    const float* getData()const;
    // create a temp pointer and copy  the array values  which data pointer points,
    // then returns temp.
    int getRowN()const; // returns rowN
    int getColN()const; // returns colN
    void print()const;  // prints the Matrix object in rowNxcolN form
    Matrix transpose(); // takes the transpose of the matrix

    Matrix operator+(const Matrix& rhsMatrix)const;
    //+ operator which allows m1+m2 and returns a temp Matrix object 
    Matrix operator-(const Matrix& rhsMatrix)const;
    //- operator which allows m1-m2 and returns a temp Matrix object 
    Matrix operator*(const Matrix& rhsMatrix)const;
    //* operator which allows  product of m1*m2 
    //(element-wise) and returns a temp Matrix object 
    float operator()(const int r, const int c)const;
    //() operator which allows returning m1(r,c), 
    //m1(0,0) is on the first row, first col 

    Matrix& operator=(const Matrix& rhsMatrix);
    //= operator which allows m1=m2 and returns this pointer of m1
    Matrix& operator+=(const Matrix& rhsMatrix);
    //+= operator which allows m1+=m2 and returns this pointer of m1
    Matrix& operator-=(const Matrix& rhsMatrix);
    //-= operator which allows m1-=m2 and returns this pointer of m1
    Matrix& operator*=(const Matrix& rhsMatrix);
    //*= operator which allows m1*=m2 (element-wise) and returns this pointer of m1

    int operator==(const Matrix& rhsMatrix)const;
    //== operator which returns 1 if (m1==m2)
    int operator!=(const Matrix& rhsMatrix)const;
    //== operator which returns 1 if (m1!=m2)

private:

    //() operator which allows returning m1(r,c), 
    //m1(0,0) is on the first row,first col 
    int rowN, colN;
    float* data;
    // e.g: if pointer data points an array of [ 1, 2, 3, 4, 5, 6] and the rowN=3 and coln=2
    // matrix is actually 
    // 1 2 3
    // 4 5 6
};

#endif
#pragma once
