#include <iostream> //needed libraries
#include "Matrix.h"

using namespace std;
//Needed instance variables
double** matrix;
int row;
int col;
double x;
/*Constructor for Matrices, initializes rows/columns as
  input rows and columns. Initializes every value as 0 */

Matrix::Matrix(uint rows,  uint cols) {
    matrix = new double* [rows+1];
    for(int i = 0; i < (int)rows; i++) {
        matrix[i] = new double[cols+1]; //for loop used to initialize matrix
    } //for
    row = rows;
    col = cols;
    for(int i = 0; i < (int) rows; i++) {
        for(int j = 0; j < (int)cols; j++) {
            at(i,j) = 0;
        } //for
    } //for
} //Matrix

/*Constructor for Matrices, sets Values for matrix, as well as initializing correct
  # of rows/columns*/
Matrix::Matrix(double** values, int w, int h) {
    this-> matrix = values;
    this->row = w;
    this->col = h;
} //Matrix


//Constructor for Matrices, copies input matrix as current matrix.
Matrix::Matrix(const Matrix & m) {
    matrix = new double*[m.row];
    for(int i = 0; i < m.row; i++) {
      matrix[i] = new double[m.col];

  } //for
  this->row = m.row;
  this->col = m.col;
  for (int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          matrix[i][j] = m.matrix[i][j];
      } //for
  }//for
} //Matrix

//Destructor used to remove memory no longer needed.
Matrix::~Matrix() {
    for(int i = 0; i < row; i++) {
        delete[] matrix[i];
    } //for
    delete [] matrix;
} //Matrix

//Adds scalar to every element in calling matrix.
Matrix Matrix::add(double s) const {
    Matrix mcopy(row,col);
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          mcopy.at(i,j) = at(i,j) + s;
      } //for
    }//for
    //cout << mcopy;
    return mcopy;
} //add

//Adds each element of two matrices together.
Matrix Matrix::add(const Matrix & m ) const {
    Matrix mcopy(row,col);
//    if(this->row == m.row && this->col == m.col) {
      for(int i = 0; i < row; i++) {
          for(int j = 0; j < col; j++) {
              mcopy.at(i,j) = at(i,j) + m.at(i,j);
          } //for
      }//for
      return mcopy;
      // }

} //add



//Subtracts scalar from every element in calling matrix.
Matrix Matrix::subtract(double s) const {
    Matrix mcopy(row,col);
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          mcopy.matrix[i][j] = matrix[i][j] - s;
      } //for
    }//for
    return mcopy;
} //subtract

//subtracts elements from calling matrix by elements in param matrix.
Matrix Matrix::subtract(const Matrix & m) const {
    Matrix mcopy(m.row,m.col);
    if(this->row == m.row && this->col == m.col) {
      for(int i = 0; i < row; i++) {
          for(int j =0; j < col; j++) {
              mcopy.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
          }//for
      }//for
  }
    return mcopy;
}//subtract


//Multiplies each element in a matrix by a scalar s.
Matrix Matrix::multiply(double s) const {
    Matrix mcopy(row,col);
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          mcopy.matrix[i][j] = matrix[i][j] * s;
      } //for
    }//for
    return mcopy;
} //multiply

/*Multiplies each element in calling matrix by
each element in param matrix m. */
Matrix Matrix::multiply(const Matrix & m) const {
    Matrix mcopy(row,col);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            for(int k = 0; k < col-1; k++) {
                mcopy.at(i,j) = matrix[i][k]*m.matrix[k][j];
            }
        }
    } //Triple nested for-loop
    return mcopy;
} //multiply



//Divides each element in calling matrix by scalar s.
Matrix Matrix::divide(double s) const {
    Matrix mcopy(row,col);
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          mcopy.at(i,j) = at(i,j)/s;
      }//for
    }//for
    return mcopy;
} //divide

//Transposes calling matrix.
Matrix Matrix::t() const {
    Matrix mcopy(row,col);
  for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          mcopy.matrix[i][j]= matrix[j][i];
      } //for
  }//for
  for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
          matrix[i][j] = mcopy.matrix[i][j];
      } //for
  } //for
  return mcopy;
} //t

//returns number of rows in calling matrix.
const uint Matrix::numRows() const {
  return this->row;
}//numRows

//returns number of columns in calling matrix.
const uint Matrix::numCols() const {
  return this->col;
} //numCols


//Returns the element located at param row and col (matrix[row][col]);
double & Matrix::at(uint row, uint col) {
    return matrix[row][col];
} //at

//Returns the element located at param row and col (matrix[row][col]);
const double & Matrix::at(uint row, uint col) const {
    x  = matrix[row][col];
    return x;
} //at

//Overloads addition operator for matrices (matrix + scalar).
Matrix Matrix::operator+(double s) const {
    return add(s);
} //+overload

//Overloads addition operator for matrices (matrix + matrix).
Matrix Matrix::operator+(const Matrix & m) const {
    return add(m);
} //+overload

//Overloads subtraction operator for matrices (matrix - scalar).
Matrix Matrix::operator-(double s) const {
    return subtract(s);
} //-overload;

//Overloads subtraction operator for matrices (matrix - matrix)
Matrix Matrix::operator-(const Matrix & m) const{
    return subtract(m);
}//-overload

//overloads multiplication operator for matrices (matrix by scalar).
Matrix Matrix::operator*(double s) const {
    return multiply(s);
} //*overload

//Overloads multiplication operator for matrices (matrix by matrix).
Matrix Matrix::operator*(const Matrix & m) const {
    return multiply(m);
} //*overload

//Overloads division operator for matrices.
Matrix Matrix::operator/(double s) const {
    return divide(s);
} //operator / overload

//overloads = operator so matrices can be dealt with in main.
void Matrix::operator=(const Matrix & m) {
    if(row == m.row && col == m.col) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                matrix[i][j] = m.matrix[i][j];
            } //for
        }//for
    } //if

} //= operator overload

//returns the element located at param row and col.
double & Matrix::operator()(uint row, uint col) {
    return at(row,col);
} //() overload

//Negation overload multiplies each element in calling matrix by -1.
Matrix Matrix::operator-() {
    return multiply(-1);
} //negation overload
