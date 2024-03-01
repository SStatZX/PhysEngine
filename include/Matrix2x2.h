#pragma once

#include <cmath>
#include "Vector2.h"

class Matrix2x2 
{
private:

    Vector2 mRows[2]; // This is 2 Vector2s in array, hence 2x2

public:

    Matrix2x2();

    Matrix2x2(float value);

    Matrix2x2(float a1, float a2, float b1, float b2); //_LDBL_HAS_QUIET_NAN__

    void setAllValues(float a1, float a2, float b1, float b2);

    void setToZero();

    Vector2 getColumn(int i) const;

    Vector2 getRow(int i) const;

    Matrix2x2 getTranspose() const;

    float getDeterminant() const;

    float getTrace() const;

    Matrix2x2 getInverse() const;

    Matrix2x2 getInverse(float determinant) const;

    Matrix2x2 getAbsoluteMatrix() const;

    void setToIdentity();

    static Matrix2x2 identity();

    static Matrix2x2 zero();

    friend Matrix2x2 operator+(const Matrix2x2& matrix1, const Matrix2x2& matrix2);
    friend Matrix2x2 operator-(const Matrix2x2& matrix1, const Matrix2x2& matrix2);
    friend Matrix2x2 operator-(const Matrix2x2& matrix);
    friend Matrix2x2 operator*(float nb, const Matrix2x2& matrix);
    friend Matrix2x2 operator*(const Matrix2x2& matrix, float nb);
    friend Matrix2x2 operator*(const Matrix2x2& matrix1, const Matrix2x2& matrix2);
    friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vector);


    bool operator==(const Matrix2x2& matrix) const;

    bool operator!=(const Matrix2x2& matrix) const;

    Matrix2x2& operator+=(const Matrix2x2& matrix);

    Matrix2x2& operator-=(const Matrix2x2& matrix);

    Matrix2x2& operator*=(float n);

    const Vector2& operator[](int row) const;

    Vector2& operator[](int row);

    std::string toString() const;
};

inline Matrix2x2::Matrix2x2() {

    setAllValues(0.0, 0.0, 0.0, 0.0);
}

inline Matrix2x2::Matrix2x2(float value) {
    setAllValues(value, value, value, value);
}

inline Matrix2x2::Matrix2x2(float a1, float a2, float b1, float b2) {
    setAllValues(a1, a2, b1, b2);
}

inline void Matrix2x2::setAllValues(float a1, float a2, float b1, float b2) {
    mRows[0][0] = a1; mRows[0][1] = a2;
    mRows[1][0] = b1; mRows[1][1] = b2;
}

inline void Matrix2x2::setToZero() {
    mRows[0].setToZero();
    mRows[1].setToZero();
}

inline Vector2 Matrix2x2::getColumn(int i) const
{
    return Vector2(mRows[0][i], mRows[1][i]);
}

inline Vector2 Matrix2x2::getRow(int i) const
{
    return Vector2(mRows[i][0], mRows[i][1]);
}

inline Matrix2x2 Matrix2x2::getTranspose() const
{
    return Matrix2x2(mRows[0][0], mRows[1][0],
                     mRows[0][1], mRows[1][1]);
}

inline float Matrix2x2::getDeterminant() const
{
    return mRows[0][0] * mRows[1][1] - mRows[1][0] * mRows[0][1];
}

inline float Matrix2x2::getTrace() const {
    return (mRows[0][0] + mRows[1][1]);
}

inline void Matrix2x2::setToIdentity() {
    mRows[0][0] = 1.0; mRows[0][1] = 0.0;
    mRows[1][0] = 0.0; mRows[1][1] = 1.0;
}

inline Matrix2x2 Matrix2x2::identity() {
    return Matrix2x2(1.0, 0.0, 0.0, 1.0);
}

// Return the 2x2 zero matrix
inline Matrix2x2 Matrix2x2::zero() {
    return Matrix2x2(0.0, 0.0, 0.0, 0.0);
}

// Return the inverse matrix
inline Matrix2x2 Matrix2x2::getInverse() const {

    return getInverse(getDeterminant());
}

// Return the matrix with absolute values
inline Matrix2x2 Matrix2x2::getAbsoluteMatrix() const {
    return Matrix2x2(std::abs(mRows[0][0]), std::abs(mRows[0][1]),
                     std::abs(mRows[1][0]), std::abs(mRows[1][1]));
}

// Overloaded operator for addition
inline Matrix2x2 operator+(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
    return Matrix2x2(matrix1.mRows[0][0] + matrix2.mRows[0][0],
                     matrix1.mRows[0][1] + matrix2.mRows[0][1],
                     matrix1.mRows[1][0] + matrix2.mRows[1][0],
                     matrix1.mRows[1][1] + matrix2.mRows[1][1]);
}

// Overloaded operator for substraction
inline Matrix2x2 operator-(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
    return Matrix2x2(matrix1.mRows[0][0] - matrix2.mRows[0][0],
                     matrix1.mRows[0][1] - matrix2.mRows[0][1],
                     matrix1.mRows[1][0] - matrix2.mRows[1][0],
                     matrix1.mRows[1][1] - matrix2.mRows[1][1]);
}

// Overloaded operator for the negative of the matrix
inline Matrix2x2 operator-(const Matrix2x2& matrix) {
    return Matrix2x2(-matrix.mRows[0][0], -matrix.mRows[0][1],
                     -matrix.mRows[1][0], -matrix.mRows[1][1]);
}

// Overloaded operator for multiplication with a number
inline Matrix2x2 operator*(float nb, const Matrix2x2& matrix) {
    return Matrix2x2(matrix.mRows[0][0] * nb, matrix.mRows[0][1] * nb,
                     matrix.mRows[1][0] * nb, matrix.mRows[1][1] * nb);
}

// Overloaded operator for multiplication with a matrix
inline Matrix2x2 operator*(const Matrix2x2& matrix, float nb) {
    return nb * matrix;
}

// Overloaded operator for matrix multiplication
inline Matrix2x2 operator*(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
    return Matrix2x2(matrix1.mRows[0][0] * matrix2.mRows[0][0] + matrix1.mRows[0][1] *
                     matrix2.mRows[1][0],
                     matrix1.mRows[0][0] * matrix2.mRows[0][1] + matrix1.mRows[0][1] *
                     matrix2.mRows[1][1],
                     matrix1.mRows[1][0] * matrix2.mRows[0][0] + matrix1.mRows[1][1] *
                     matrix2.mRows[1][0],
                     matrix1.mRows[1][0] * matrix2.mRows[0][1] + matrix1.mRows[1][1] *
                     matrix2.mRows[1][1]);
}

// Overloaded operator for multiplication with a vector
inline Vector2 operator*(const Matrix2x2& matrix, const Vector2& vector) {
    return Vector2(matrix.mRows[0][0]*vector.x + matrix.mRows[0][1]*vector.y,
                   matrix.mRows[1][0]*vector.x + matrix.mRows[1][1]*vector.y);
}

// Overloaded operator for equality condition
inline bool Matrix2x2::operator==(const Matrix2x2& matrix) const {
    return (mRows[0][0] == matrix.mRows[0][0] && mRows[0][1] == matrix.mRows[0][1] &&
            mRows[1][0] == matrix.mRows[1][0] && mRows[1][1] == matrix.mRows[1][1]);
}

// Overloaded operator for the is different condition
inline bool Matrix2x2::operator!= (const Matrix2x2& matrix) const {
    return !(*this == matrix);
}

// Overloaded operator for addition with assignment
inline Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& matrix) {
   mRows[0][0] += matrix.mRows[0][0]; mRows[0][1] += matrix.mRows[0][1];
   mRows[1][0] += matrix.mRows[1][0]; mRows[1][1] += matrix.mRows[1][1];
   return *this;
}

// Overloaded operator for substraction with assignment
inline Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& matrix) {
   mRows[0][0] -= matrix.mRows[0][0]; mRows[0][1] -= matrix.mRows[0][1];
   mRows[1][0] -= matrix.mRows[1][0]; mRows[1][1] -= matrix.mRows[1][1];
   return *this;
}

// Overloaded operator for multiplication with a number with assignment
inline Matrix2x2& Matrix2x2::operator*=(float nb) {
   mRows[0][0] *= nb; mRows[0][1] *= nb;
   mRows[1][0] *= nb; mRows[1][1] *= nb;
   return *this;
}

// Overloaded operator to return a row of the matrix.
/// This operator is also used to access a matrix value using the syntax
/// matrix[row][col].
inline const Vector2& Matrix2x2::operator[](int row) const {
    return mRows[row];
}

// Overloaded operator to return a row of the matrix.
/// This operator is also used to access a matrix value using the syntax
/// matrix[row][col].
inline Vector2& Matrix2x2::operator[](int row) {
    return mRows[row];
}

// Get the string representation
inline std::string Matrix2x2::toString() const {
    return "Matrix2x2(" + std::to_string(mRows[0][0]) + ", " + std::to_string(mRows[0][1]) + ", " +
           std::to_string(mRows[1][0]) + ", " + std::to_string(mRows[1][1]) + ")";
}