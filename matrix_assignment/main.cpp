#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main() {
    //assignment test code 

    float arr1[] = { 1,2,3,4,5, 11,12,13,14,15, 21,22,23,24,25 };
    float arr2[] = { 9,8,7,6,5, 19,18,17,16,15, 29,28,27,26,25 };

    Matrix m1(3, 5);
    Matrix m2(m1);
    Matrix m3(3, 5, arr1);
    Matrix m4(3, 5, arr2);

    //-------------------
    cout << "m1(3,5)" << endl;
    m1.print();
    cout << "m2(m1)" << endl;
    m2.print();
    cout << "m3(3,5,arr1)" << endl;
    m3.print();
    cout << "m3.transpose()" << endl;
    m3.transpose().print();
    cout << "m4(3,5,arr2)" << endl;
    m4.print();
    //------------------
    cout << "elements=m3.getData()" << endl;
    const float* const elements = m3.getData();
    const int rN = m3.getRowN();
    const int cN = m3.getColN();

    for (int i = 0; i < rN; i++)
    {
        for (int j = 0; j < cN; j++)
            cout << setw(4) << elements[i * cN + j];
        cout << "\n";
    }
    //-------------------


    cout << "m3+=m4" << endl;
    (m3 += m4).print();
    cout << "m3-=m4" << endl;
    (m3 -= m4).print();
    cout << "m3+m4" << endl;
    (m3 + m4).print();
    cout << "m3" << endl;
    m3.print();
    cout << "m3=m3+m4" << endl;
    (m3 = m3 + m4).print();
    cout << "m3" << endl;
    m3.print();

    cout << "m3(2,2)=" << m3(2, 2) << endl << endl;

    //---------------
    (m1 == m2) ? cout << "m1==m2\n" << endl : cout << "m1!=m2\n" << endl;
    (m3 != m4) ? cout << "m3!=m4\n" << endl : cout << "m3==m4\n" << endl;

    cout << "(m4*m4)\n";
    (m4 * m4).print();
    //---------------

    cout << "(m4*m4)\n";
    cout << (m4 * m4) << endl;
    return 0;
}