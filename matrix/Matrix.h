#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;
using namespace std;
class Matrix {

    double** matrix;
    int row;
    int col;

    public:

    Matrix(uint rows, uint cols);               // constructor (all elements initialized to 0)
    Matrix(double** values, int w, int h);          // constructor (must make a copy of the passed in array)
    Matrix(const Matrix & m);                       // copy constructor
    ~Matrix();                                      // destructor

    Matrix add(double s) const;                     // add scalar to this matrix
    Matrix add(const Matrix & m) const;             // add this matrix and another matrix

    Matrix subtract(double s) const;                // subtract scalar from this matrix
    Matrix subtract(const Matrix & m) const;        // subtract another matrix from this matrix

    Matrix multiply(double s) const;                // multiply this matrix by a scalar
    Matrix multiply(const Matrix & m) const;        // multiply this matrix by another matrix

    Matrix divide(double s) const;                  // divide this matrix by a scalar
    Matrix t() const;                               // transpose of this matrix

    const uint numRows() const;                     // returns the number of rows
    const uint numCols() const;                     // returns the number of cols

    double & at(uint row, uint col);                // get/set element at row,col
    const double & at(uint row, uint col) const; // get element at row,col (when using a const object)
    Matrix operator+(double s) const; //operator overload for adding scalar
    Matrix operator+(const Matrix & m) const; //operator overload for adding matrix
    Matrix operator-(double s) const; //operator overload for subtracting scalar
    Matrix operator-(const Matrix & m) const; //operator overload for subtracting matrix
    Matrix operator*(const Matrix & m) const; //operator overload for multiplying matrix
    Matrix operator/(double s) const; //operator overload for dividing by scalar
    Matrix operator-(); //operator overload for negation
    void operator=(const Matrix & m); //operator overload for copy assignment
    double & operator()(uint row, uint col); //operator overload for assignment
    Matrix operator*(double s) const; //operator overload for multiplying scalars

friend std::ostream & operator<<(std::ostream & o, const Matrix & m){
    for(int i = 0; i < m.row; i++) {
        o << "[";
        for(int j = 0; j < m.col; j++) {
            o << m.at(i,j);
            if(j <m.col -1 ) {
                o << ",";
            } //if
            if(j == m.col -1) {

                o << "]" << endl;
            } //if
        }
    }
    return o;
}

    friend Matrix operator+(const double & s, const Matrix & m) {
        return m.add(s);
    } //+ overload for scalars on the left side

    friend Matrix operator-(const double & s, const Matrix & m) {
        Matrix m2(m);
        for(int i = 0; i < (int) m.numRows(); i++) {
            for(int j = 0; j < (int) m.numCols(); j++) {
                m2.at(i,j) = s - m2.at(i,j);
            }
        } //double nested for loop
        return m2;
    } //- overload for scalars on left side

    friend Matrix operator*(const double & s, const Matrix & m) {
        return m.multiply(s);
    } //* overload for scalars on left side

    friend Matrix operator/(const double & s, const Matrix & m) {
        Matrix m2(m);
        for(int i = 0; i < (int) m.numRows(); i++) {
            for(int j = 0; j < (int) m.numCols(); j++) {
                m2.at(i,j) = s / m2.at(i,j);
            }
        } //double nested for loop
        return m2;
    } //'/' overload for scalars on left side
};

#endif
