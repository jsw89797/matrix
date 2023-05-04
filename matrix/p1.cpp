#include <iostream> //needed libraries
#include "Matrix.h"
#include <random>

using namespace std;

/*Main method used for testing out our Matrix class.
  Uses all functionality of Matrix.h and Matrix.cpp*/
int main() {
    cout << "construct matrix of 0's" << endl;
    Matrix m(3,3);
    Matrix operatorUse(m);
    cout << m << endl;
    cout << "add 4 to matrix" << endl;
    Matrix opM(m);
    m = m.add(4);
    cout << m << endl;
    cout << "using operator +" << endl;
    opM = opM + 4;
    cout << opM << endl;

    Matrix m2(3,3);
    for(int i = 0; i < (int) m.numRows(); i++) {
        for(int j = 0; j < (int) m.numCols(); j++) {
            m2.at(i,j) = 1;
        }
    }
    cout << "add a matrix of 1's" << endl;
    m = m.add(m2);
    opM = opM + m2;
    cout << m << endl;
    cout << "using operator +" <<endl;
    cout << opM << endl;

    cout << "subtract by 1 from matrix" << endl;
    m = m.subtract(1);
    cout << m << endl;
    cout << "using operator -" << endl;
    opM = opM - 1;
    cout << opM << endl;

    cout << "subtract by matrix full of 1's" << endl;
    m = m.subtract(m2);
    cout << m << endl;
    cout << "using operator -" << endl;
    opM = opM - 1;
    cout << opM << endl;

    cout << "multiply matrix by 4" << endl;
    m = m.multiply(4);
    cout << m << endl;
    cout << "using operator *" << endl;
    opM = opM * 4;
    cout << opM << endl;

    cout << "multiply by matrix full of 0's" << endl;
    m2 = m2.add(m2);
    Matrix m3(2,3);
    for(int i = 0; i < (int)m.numRows(); i++) {
        for(int j = 0; j < (int)m.numCols(); j++) {
            m.at(i,j) = 0;
        } //for
    }//for
    //cout <<m3;
    m = m.multiply(m3);
    cout << m << endl;
    cout << "using operator *" << endl;
    opM = opM * m3;
    cout << opM  << endl;

    cout << "divide matrix of 4's by 2" << endl;
    for(int i = 0; i < (int)m.numRows(); i++) {
        for(int j = 0; j < (int) m.numCols(); j++) {
            m(i,j) = 4;
        }
    }
    m =  m.divide(2);
    cout << m << endl;
    cout << "using operator /" << endl;
    opM = opM /2;
    cout << opM << endl;

    cout << " adding 7.2 to matrix of 0's using left side operation" << endl;
    operatorUse = 7.2 + operatorUse;
    cout << operatorUse << endl;

    cout << "subtracing 5.3 from matrix full of 7.2 using left side operation" << endl;
    operatorUse = 20 - operatorUse;
    cout << operatorUse << endl;

    cout << "multiply by 2.2 with matrix full of 12.8 using left side operation" << endl;
    operatorUse = 2.2 * operatorUse;
    cout << operatorUse << endl;

    cout << "divide 56.32 by matrix full of 28.16 using left side operation (results in 2)" << endl;
    operatorUse = 56.32 / operatorUse;
    cout << operatorUse << endl;

    cout << "make matrix of -2's using negation overload !" << endl;
    cout << -operatorUse << endl;

    Matrix last(3,3);
    for(int i = 0; i < (int)last.numRows(); i++) {
        for(int j = 0; j < (int)last.numCols(); j++) {
            last.at(i,j) = rand()%10;
        }
    }
    cout << "Matrix to undergo transposition" << endl;
    cout << last << endl;
    cout << "Transpose matrix" << endl;
    last = last.t();
    cout << last << endl;
    return 0;
} //main
