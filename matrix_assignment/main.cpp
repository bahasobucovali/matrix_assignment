#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main() {

	float arr[] = { 1, 2, 3, 11, 12, 13, 21, 22, 23 };

	Matrix m1;
	Matrix m2(2, 5);
	Matrix m3(m2);
	Matrix m4(3, 3, arr);

	cout << m2;
	cout << m4.transpose();
	cout << m4;

	return 0;
}