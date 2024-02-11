#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;

ostream& operator<<(ostream& out, const Matrix& srcMatrix) {
	// << operator which allows returns out and prints Matrix object 

	for (int i = 0; i < srcMatrix.rowN; i++) {
		for (int j = 0; j < srcMatrix.colN; j++) {
			out << srcMatrix.data[i * srcMatrix.colN + j] << " ";
		}
		out << endl;
	}
	out << endl;

	return out;
}

Matrix::Matrix() {
	// initialize Matrix class object with rowN=1, colN=1, and zero value
	rowN = 1;
	colN = 1;
	data = new float[rowN * colN];

	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			data[i * colN + j] = 0;
		}
	}
}

Matrix::Matrix(const int rN, const int cN):rowN(rN),colN(cN) {
	// initialize Matrix class object with row number rN, col number cN and zero values
	
	data = new float[rowN * colN];
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			data[i * colN + j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& srcMatrix) :rowN(srcMatrix.rowN), colN(srcMatrix.colN) {
	// initialize Matrix class object with another Matrix class object

	data = new float[rowN * colN];
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			data[i * colN + j] = srcMatrix.data[i*colN+j];
		}
	}
}

Matrix::Matrix(const int rN, const int cN, const float* srcPtr) :rowN(rN), colN(cN) {
	// initialize Matrix class object with row number rN, col number cN and a pointer to an 
	
	data = new float[rowN * colN];
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			data[i * colN + j] = srcPtr[i * colN + j];
		}
	}
}

const float* Matrix::getData()const {
	// create a temp pointer and copy  the array values  which data pointer points,
	// then returns temp.

	float* temp = new float[rowN * colN];
	for (int i = 0; i < rowN * colN; i++) {
		temp[i] = data[i];
	}
	return temp;
}

int Matrix::getRowN()const { return rowN; }
int Matrix::getColN()const { return colN; }

/*
void Matrix::print()const {
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			cout << data[i * colN + j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
*/

Matrix Matrix::transpose() {
	// takes the transpose of the matrix

	float* tempData = new float[rowN*colN];

	for (int i = 0; i < (rowN); i++) {
		for (int j = 0; j < (colN); j++) {
			tempData[(j * rowN) + i] = data[(i * colN) + j];
		}
	}
	Matrix transposedMatrix(colN, rowN, tempData);
	return transposedMatrix;
}


