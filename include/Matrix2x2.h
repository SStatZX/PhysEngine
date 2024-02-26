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

    friend Matrix2x2 operator+(const Matrix2x2& m1, const Matrix2x2& m2);
    friend Matrix2x2 operator-(const Matrix2x2& m1, const Matrix2x2 m2);
    friend Matrix2x2 operator-(const Matrix2x2& matrix);
    friend Matrix2x2 operator*(float n, const Matrix2x2& matrix);
    friend Matrix2x2 operator*(const Matrix2x2& matrix, float n);
    friend Matrix2x2 operator*(const Matrix2x2& matrix, const Vector2& vector);

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