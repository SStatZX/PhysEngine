#pragma once

#include <cmath>
#include <string>
#include <cassert>
#define MACHINE_EPSILON 1.192092896e-07F

struct Vector2
{ 
public:

    float x, y;
    inline Vector2() : x(0.0), y(0.0) { }

    inline Vector2(float newX, float newY) : x(newX), y(newY) { }
    // Returns length or magnitude of vector.
    inline float length() const {
        return std::sqrt(x*x + y*y);
    }
    // Dot product of two vectors.
    inline float dot(const Vector2& vector) const {
        return (x*vector.x + y*vector.y);
    }
    // Normalized form.
    inline void normalize() {
        float magnitude = length();
        x /= magnitude;
        y /= magnitude;
    }

    inline void setToZero() {
        x=0; y=0;
    }

    inline Vector2 reflect(const Vector2& normal) const {
        return *this - (normal * this->dot(normal) * 2);
    }

    inline std::string to_string() const {
        return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // Addition equals operator.
    inline Vector2& operator+=(const Vector2& vector) {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    // Subtraction equals operator.
    inline Vector2& operator-=(const Vector2& vector) {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    // Multiplication equals operator.
    inline Vector2& operator*=(float num) {
        x *= num;
        y *= num;
        return *this;
    }

    // Division equals operator.
    inline Vector2& operator/=(float num) {
        x /= num;
        y /= num;
        return *this;
    }

    inline bool operator==(const Vector2& vector) const {
        return (x == vector.x && y == vector.y);
    }


    inline bool operator!=(const Vector2& vector) const {
        return !(*this == vector);
    }

    inline float& operator[] (int index) {
        return (&x)[index];
    }

    inline const float& operator[] (int index) const {
        return (&x)[index];
    }

    // Additition operator.
    friend inline Vector2 operator+(const Vector2& vec1, const Vector2& vec2)
    {
        return Vector2(vec1.x+vec2.x, vec1.y+vec2.y);
    }
    // Subtraction operation.
    friend inline Vector2 operator-(const Vector2& vec1, const Vector2& vec2)
    {
        return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
    }
    // Subtraction (overload for minus values).
    friend inline Vector2 operator-(const Vector2 vec)
    {
        return Vector2(-vec.x, -vec.y);
    }
    // Multiplication with number.
    friend inline Vector2 operator*(const Vector2& vec, float num)
    {
        return Vector2(vec.x * num, vec.y * num);
    }
    // Multiplication with two vector2s.
    friend inline Vector2 operator*(const Vector2& vec1, const Vector2& vec2)
    {
        return Vector2(vec1.x * vec2.x, vec1.y * vec2.y);
    }
    // Reverse input compatability.
    friend inline Vector2 operator*(float num, const Vector2& vec)
    {
        return vec * num;
    }
    // Division with number.
    friend inline Vector2 operator/(const Vector2& vec, float num)
    {
        return Vector2(vec.x / num, vec.y / num);
    }
    // Division with two vector2s.
    friend inline Vector2 operator/(const Vector2& vec1, const Vector2& vec2)
    {
        return Vector2(vec1.x / vec2.x, vec1.y / vec2.y);
    }

};

struct Vector3
{ 
public:
    float x, y, z;

    inline Vector3() : x(0.0), y(0.0), z(0.0) { }

    inline Vector3(float newX, float newY, float newZ) : x(newX), y(newY), z(newZ) { }

    // Returns length or magnitude of vector.
    inline float length() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    // Dot product of two vectors.
    inline float dot(const Vector3& vector) const {
        return (x*vector.x + y*vector.y + z*vector.z);
    }
    // Cross product.
    inline Vector3 cross(const Vector3& vector) const {
        return Vector3(y * vector.z - z * vector.y,
                       z * vector.x - x * vector.z,
                       x * vector.y - y * vector.x);
    }
    // Normalized form.
    inline void normalize() {
        float magnitude = length();
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }

    inline void setToZero() {
        x = 0;
        y = 0;
        z = 0;
    }

    inline std::string to_string() const {
        return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) +")";
    }

    // Addition equals operator.
    inline Vector3& operator+=(const Vector3& vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        return *this;
    }

    // Subtraction equals operator.
    inline Vector3& operator-=(const Vector3& vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        return *this;
    }

    // Multiplication equals operator.
    inline Vector3& operator*=(float num) {
        x *= num;
        y *= num;
        z *= num;
        return *this;
    }

    // Division equals operator.
    inline Vector3& operator/=(float num) {
        x /= num;
        y /= num;
        z /= num;
        return *this;
    }

    inline bool operator==(const Vector3& vector) const {
        return (x == vector.x && y == vector.y && z == vector.z);
    }

    inline bool operator!=(const Vector3& vector) const {
        return !(*this == vector);
    }

    // Overloaded operator for value access
    inline float& operator[] (int index) {
        return (&x)[index];
    }

    // Overloaded operator for value access
    inline const float& operator[] (int index) const {
        return (&x)[index];
    }

    // Overloaded operator for addition
    inline friend Vector3 operator+(const Vector3& vector1, const Vector3& vector2) {
        return Vector3(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
    }

    // Overloaded operator for substraction
    inline friend Vector3 operator-(const Vector3& vector1, const Vector3& vector2) {
        return Vector3(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
    }

    // Overloaded operator for the negative of a vector
    inline friend Vector3 operator-(const Vector3& vector) {
        return Vector3(-vector.x, -vector.y, -vector.z);
    }

    // Overloaded operator for multiplication with a number
    inline friend Vector3 operator*(const Vector3& vector, float number) {
        return Vector3(number * vector.x, number * vector.y, number * vector.z);
    }

    // Overloaded operator for division by a number
    inline friend Vector3 operator/(const Vector3& vector, float number) {
        assert(number > MACHINE_EPSILON);
        return Vector3(vector.x / number, vector.y / number, vector.z / number);
    }

    // Overload operator for division between two vectors
    inline friend Vector3 operator/(const Vector3& vector1, const Vector3& vector2) {
        assert(vector2.x > MACHINE_EPSILON);
        assert(vector2.y > MACHINE_EPSILON);
        assert(vector2.z > MACHINE_EPSILON);
        return Vector3(vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z);
    }

    // Overloaded operator for multiplication with a number
    inline friend Vector3 operator*(float number, const Vector3& vector) {
        return vector * number;
    }

    // Overload operator for multiplication between two vectors
    inline friend Vector3 operator*(const Vector3& vector1, const Vector3& vector2) {
        return Vector3(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
    }

    // Overloaded less than operator for ordering to be used inside std::set for instance
    inline bool operator<(const Vector3& vector) const {
        return (x == vector.x ? (y == vector.y ? z < vector.z : y < vector.y) : x < vector.x);
    }
};

class Matrix2x2 {

private:

    // -------------------- Attributes -------------------- //

    /// Rows of the matrix;
    Vector2 mRows[2];

public:

    // Constructor of the class Matrix2x2
    inline Matrix2x2() {

        // Initialize all values in the matrix to zero
        setAllValues(0.0, 0.0, 0.0, 0.0);
    }

    // Constructor
    inline Matrix2x2(float value) {
        setAllValues(value, value, value, value);
    }

    // Constructor with arguments
    inline Matrix2x2(float a1, float a2, float b1, float b2) {

        // Initialize the matrix with the values
        setAllValues(a1, a2, b1, b2);
    }

    // Method to set all the values in the matrix
    inline void setAllValues(float a1, float a2,
                                        float b1, float b2) {
        mRows[0][0] = a1; mRows[0][1] = a2;
        mRows[1][0] = b1; mRows[1][1] = b2;
    }

    // Set the matrix to zero
    inline void setToZero() {
        mRows[0].setToZero();
        mRows[1].setToZero();
    }

    // Return a column
    inline Vector2 getColumn(int i) const {
        assert(i>= 0 && i<2);
        return Vector2(mRows[0][i], mRows[1][i]);
    }

    // Return a row
    inline Vector2 getRow(int i) const {
        assert(i>= 0 && i<2);
        return mRows[i];
    }

    // Return the transpose matrix
    inline Matrix2x2 getTranspose() const {

        // Return the transpose matrix
        return Matrix2x2(mRows[0][0], mRows[1][0],
                        mRows[0][1], mRows[1][1]);
    }

    // Return the determinant of the matrix
    inline float getDeterminant() const {

        // Compute and return the determinant of the matrix
        return mRows[0][0] * mRows[1][1] - mRows[1][0] * mRows[0][1];
    }

    // Return the trace of the matrix
    inline float getTrace() const {

        // Compute and return the trace
        return (mRows[0][0] + mRows[1][1]);
    }

    // Set the matrix to the identity matrix
    inline void setToIdentity() {
        mRows[0][0] = 1.0; mRows[0][1] = 0.0;
        mRows[1][0] = 0.0; mRows[1][1] = 1.0;
    }

    // Return the 2x2 identity matrix
    inline Matrix2x2 identity() {

        // Return the isdentity matrix
        return Matrix2x2(1.0, 0.0, 0.0, 1.0);
    }

    // Return the 2x2 zero matrix
    inline Matrix2x2 zero() {
        return Matrix2x2(0.0, 0.0, 0.0, 0.0);
    }

    // Return the inverse matrix
    inline Matrix2x2 getInverse() const {

        return getInverse(getDeterminant());
    }

    inline Matrix2x2 getInverse(float determinant) const;

    // Return the matrix with absolute values
    inline Matrix2x2 getAbsoluteMatrix() const {
        return Matrix2x2(std::abs(mRows[0][0]), std::abs(mRows[0][1]),
                        std::abs(mRows[1][0]), std::abs(mRows[1][1]));
    }

    // Overloaded operator for addition
    inline friend Matrix2x2 operator+(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
        return Matrix2x2(matrix1.mRows[0][0] + matrix2.mRows[0][0],
                        matrix1.mRows[0][1] + matrix2.mRows[0][1],
                        matrix1.mRows[1][0] + matrix2.mRows[1][0],
                        matrix1.mRows[1][1] + matrix2.mRows[1][1]);
    }

    // Overloaded operator for substraction
    inline friend Matrix2x2 operator-(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
        return Matrix2x2(matrix1.mRows[0][0] - matrix2.mRows[0][0],
                        matrix1.mRows[0][1] - matrix2.mRows[0][1],
                        matrix1.mRows[1][0] - matrix2.mRows[1][0],
                        matrix1.mRows[1][1] - matrix2.mRows[1][1]);
    }

    // Overloaded operator for the negative of the matrix
    inline friend Matrix2x2 operator-(const Matrix2x2& matrix) {
        return Matrix2x2(-matrix.mRows[0][0], -matrix.mRows[0][1],
                        -matrix.mRows[1][0], -matrix.mRows[1][1]);
    }

    // Overloaded operator for multiplication with a number
    inline friend Matrix2x2 operator*(float nb, const Matrix2x2& matrix) {
        return Matrix2x2(matrix.mRows[0][0] * nb, matrix.mRows[0][1] * nb,
                        matrix.mRows[1][0] * nb, matrix.mRows[1][1] * nb);
    }

    // Overloaded operator for multiplication with a matrix
    inline friend Matrix2x2 operator*(const Matrix2x2& matrix, float nb) {
        return nb * matrix;
    }

    // Overloaded operator for matrix multiplication
    inline friend Matrix2x2 operator*(const Matrix2x2& matrix1, const Matrix2x2& matrix2) {
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
    inline friend Vector2 operator*(const Matrix2x2& matrix, const Vector2& vector) {
        return Vector2(matrix.mRows[0][0]*vector.x + matrix.mRows[0][1]*vector.y,
                    matrix.mRows[1][0]*vector.x + matrix.mRows[1][1]*vector.y);
    }

    // Overloaded operator for equality condition
    inline bool operator==(const Matrix2x2& matrix) const {
        return (mRows[0][0] == matrix.mRows[0][0] && mRows[0][1] == matrix.mRows[0][1] &&
                mRows[1][0] == matrix.mRows[1][0] && mRows[1][1] == matrix.mRows[1][1]);
    }

    // Overloaded operator for the is different condition
    inline bool operator!= (const Matrix2x2& matrix) const {
        return !(*this == matrix);
    }

    // Overloaded operator for addition with assignment
    inline Matrix2x2& operator+=(const Matrix2x2& matrix) {
    mRows[0][0] += matrix.mRows[0][0]; mRows[0][1] += matrix.mRows[0][1];
    mRows[1][0] += matrix.mRows[1][0]; mRows[1][1] += matrix.mRows[1][1];
    return *this;
    }

    // Overloaded operator for substraction with assignment
    inline Matrix2x2& operator-=(const Matrix2x2& matrix) {
    mRows[0][0] -= matrix.mRows[0][0]; mRows[0][1] -= matrix.mRows[0][1];
    mRows[1][0] -= matrix.mRows[1][0]; mRows[1][1] -= matrix.mRows[1][1];
    return *this;
    }

    // Overloaded operator for multiplication with a number with assignment
    inline Matrix2x2& operator*=(float nb) {
    mRows[0][0] *= nb; mRows[0][1] *= nb;
    mRows[1][0] *= nb; mRows[1][1] *= nb;
    return *this;
    }

    // Overloaded operator to return a row of the matrix.
    /// This operator is also used to access a matrix value using the syntax
    /// matrix[row][col].
    inline const Vector2& operator[](int row) const {
        return mRows[row];
    }

    // Overloaded operator to return a row of the matrix.
    /// This operator is also used to access a matrix value using the syntax
    /// matrix[row][col].
    inline Vector2& operator[](int row) {
        return mRows[row];
    }

    // Get the string representation
    inline std::string to_string() const {
        return "Matrix2x2(" + std::to_string(mRows[0][0]) + ", " + std::to_string(mRows[0][1]) + ", " +
            std::to_string(mRows[1][0]) + ", " + std::to_string(mRows[1][1]) + ")";
    }
};

class Matrix3x3 {

private:

    // -------------------- Attributes -------------------- //

    /// Rows of the matrix;
    Vector3 mRows[3];

public:

    // Constructor of the class Matrix3x3
    inline Matrix3x3() {
        // Initialize all values in the matrix to zero
        setAllValues(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    }

    // Constructor
    inline Matrix3x3(float value) {
        setAllValues(value, value, value, value, value, value, value, value, value);
    }

    // Constructor with arguments
    inline Matrix3x3(float a1, float a2, float a3,
                        float b1, float b2, float b3,
                        float c1, float c2, float c3) {
        // Initialize the matrix with the values
        setAllValues(a1, a2, a3, b1, b2, b3, c1, c2, c3);
    }

    // Method to set all the values in the matrix
    inline void setAllValues(float a1, float a2, float a3,
                                        float b1, float b2, float b3,
                                        float c1, float c2, float c3) {
        mRows[0][0] = a1; mRows[0][1] = a2; mRows[0][2] = a3;
        mRows[1][0] = b1; mRows[1][1] = b2; mRows[1][2] = b3;
        mRows[2][0] = c1; mRows[2][1] = c2; mRows[2][2] = c3;
    }

    // Set the matrix to zero
    inline void setToZero() {
        mRows[0].setToZero();
        mRows[1].setToZero();
        mRows[2].setToZero();
    }

    // Return a column
    inline Vector3 getColumn(int i) const {
        assert(i>= 0 && i<3);
        return Vector3(mRows[0][i], mRows[1][i], mRows[2][i]);
    }

    // Return a row
    inline Vector3 getRow(int i) const {
        assert(i>= 0 && i<3);
        return mRows[i];
    }

    // Return the transpose matrix
    inline Matrix3x3 getTranspose() const {

        // Return the transpose matrix
        return Matrix3x3(mRows[0][0], mRows[1][0], mRows[2][0],
                        mRows[0][1], mRows[1][1], mRows[2][1],
                        mRows[0][2], mRows[1][2], mRows[2][2]);
    }

    // Return the determinant of the matrix
    inline float getDeterminant() const {

        // Compute and return the determinant of the matrix
        return (mRows[0][0]*(mRows[1][1]*mRows[2][2]-mRows[2][1]*mRows[1][2]) -
                mRows[0][1]*(mRows[1][0]*mRows[2][2]-mRows[2][0]*mRows[1][2]) +
                mRows[0][2]*(mRows[1][0]*mRows[2][1]-mRows[2][0]*mRows[1][1]));
    }

    // Return the trace of the matrix
    inline float getTrace() const {

        // Compute and return the trace
        return (mRows[0][0] + mRows[1][1] + mRows[2][2]);
    }

    // Set the matrix to the identity matrix
    inline void setToIdentity() {
        mRows[0][0] = 1.0; mRows[0][1] = 0.0; mRows[0][2] = 0.0;
        mRows[1][0] = 0.0; mRows[1][1] = 1.0; mRows[1][2] = 0.0;
        mRows[2][0] = 0.0; mRows[2][1] = 0.0; mRows[2][2] = 1.0;
    }

    // Return the 3x3 identity matrix
    inline Matrix3x3 identity() {
        return Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    }

    // Return the 3x3 zero matrix
    inline Matrix3x3 zero() {
        return Matrix3x3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    }

    // Return the inverse matrix
    inline Matrix3x3 getInverse() const {

        return getInverse(getDeterminant());
    }

    inline Matrix3x3 getInverse(float determinant) const;

    // Return a skew-symmetric matrix using a given vector that can be used
    // to compute cross product with another vector using matrix multiplication
    inline Matrix3x3 computeSkewSymmetricMatrixForCrossProduct(const Vector3& vector) {
        return Matrix3x3(0, -vector.z, vector.y, vector.z, 0, -vector.x, -vector.y, vector.x, 0);
    }

    // Return the matrix with absolute values
    inline Matrix3x3 getAbsoluteMatrix() const {
        return Matrix3x3(std::abs(mRows[0][0]), std::abs(mRows[0][1]), std::abs(mRows[0][2]),
                        std::abs(mRows[1][0]), std::abs(mRows[1][1]), std::abs(mRows[1][2]),
                        std::abs(mRows[2][0]), std::abs(mRows[2][1]), std::abs(mRows[2][2]));
    }

    // Overloaded operator for addition
    inline friend Matrix3x3 operator+(const Matrix3x3& matrix1, const Matrix3x3& matrix2) {
        return Matrix3x3(matrix1.mRows[0][0] + matrix2.mRows[0][0], matrix1.mRows[0][1] +
                        matrix2.mRows[0][1], matrix1.mRows[0][2] + matrix2.mRows[0][2],
                        matrix1.mRows[1][0] + matrix2.mRows[1][0], matrix1.mRows[1][1] +
                        matrix2.mRows[1][1], matrix1.mRows[1][2] + matrix2.mRows[1][2],
                        matrix1.mRows[2][0] + matrix2.mRows[2][0], matrix1.mRows[2][1] +
                        matrix2.mRows[2][1], matrix1.mRows[2][2] + matrix2.mRows[2][2]);
    }

    // Overloaded operator for substraction
    inline friend Matrix3x3 operator-(const Matrix3x3& matrix1, const Matrix3x3& matrix2) {
        return Matrix3x3(matrix1.mRows[0][0] - matrix2.mRows[0][0], matrix1.mRows[0][1] -
                        matrix2.mRows[0][1], matrix1.mRows[0][2] - matrix2.mRows[0][2],
                        matrix1.mRows[1][0] - matrix2.mRows[1][0], matrix1.mRows[1][1] -
                        matrix2.mRows[1][1], matrix1.mRows[1][2] - matrix2.mRows[1][2],
                        matrix1.mRows[2][0] - matrix2.mRows[2][0], matrix1.mRows[2][1] -
                        matrix2.mRows[2][1], matrix1.mRows[2][2] - matrix2.mRows[2][2]);
    }

    // Overloaded operator for the negative of the matrix
    inline Matrix3x3 operator-(const Matrix3x3& matrix) {
        return Matrix3x3(-matrix.mRows[0][0], -matrix.mRows[0][1], -matrix.mRows[0][2],
                        -matrix.mRows[1][0], -matrix.mRows[1][1], -matrix.mRows[1][2],
                        -matrix.mRows[2][0], -matrix.mRows[2][1], -matrix.mRows[2][2]);
    }

    // Overloaded operator for multiplication with a number
    inline friend Matrix3x3 operator*(float nb, const Matrix3x3& matrix) {
        return Matrix3x3(matrix.mRows[0][0] * nb, matrix.mRows[0][1] * nb, matrix.mRows[0][2] * nb,
                        matrix.mRows[1][0] * nb, matrix.mRows[1][1] * nb, matrix.mRows[1][2] * nb,
                        matrix.mRows[2][0] * nb, matrix.mRows[2][1] * nb, matrix.mRows[2][2] * nb);
    }

    // Overloaded operator for multiplication with a matrix
    inline friend Matrix3x3 operator*(const Matrix3x3& matrix, float nb) {
        return nb * matrix;
    }

    // Overloaded operator for matrix multiplication
    inline friend Matrix3x3 operator*(const Matrix3x3& matrix1, const Matrix3x3& matrix2) {
        return Matrix3x3(matrix1.mRows[0][0]*matrix2.mRows[0][0] + matrix1.mRows[0][1] *
                        matrix2.mRows[1][0] + matrix1.mRows[0][2]*matrix2.mRows[2][0],
                        matrix1.mRows[0][0]*matrix2.mRows[0][1] + matrix1.mRows[0][1] *
                        matrix2.mRows[1][1] + matrix1.mRows[0][2]*matrix2.mRows[2][1],
                        matrix1.mRows[0][0]*matrix2.mRows[0][2] + matrix1.mRows[0][1] *
                        matrix2.mRows[1][2] + matrix1.mRows[0][2]*matrix2.mRows[2][2],
                        matrix1.mRows[1][0]*matrix2.mRows[0][0] + matrix1.mRows[1][1] *
                        matrix2.mRows[1][0] + matrix1.mRows[1][2]*matrix2.mRows[2][0],
                        matrix1.mRows[1][0]*matrix2.mRows[0][1] + matrix1.mRows[1][1] *
                        matrix2.mRows[1][1] + matrix1.mRows[1][2]*matrix2.mRows[2][1],
                        matrix1.mRows[1][0]*matrix2.mRows[0][2] + matrix1.mRows[1][1] *
                        matrix2.mRows[1][2] + matrix1.mRows[1][2]*matrix2.mRows[2][2],
                        matrix1.mRows[2][0]*matrix2.mRows[0][0] + matrix1.mRows[2][1] *
                        matrix2.mRows[1][0] + matrix1.mRows[2][2]*matrix2.mRows[2][0],
                        matrix1.mRows[2][0]*matrix2.mRows[0][1] + matrix1.mRows[2][1] *
                        matrix2.mRows[1][1] + matrix1.mRows[2][2]*matrix2.mRows[2][1],
                        matrix1.mRows[2][0]*matrix2.mRows[0][2] + matrix1.mRows[2][1] *
                        matrix2.mRows[1][2] + matrix1.mRows[2][2]*matrix2.mRows[2][2]);
    }

    // Overloaded operator for multiplication with a vector
    inline friend Vector3 operator*(const Matrix3x3& matrix, const Vector3& vector) {
        return Vector3(matrix.mRows[0][0]*vector.x + matrix.mRows[0][1]*vector.y +
                    matrix.mRows[0][2]*vector.z,
                    matrix.mRows[1][0]*vector.x + matrix.mRows[1][1]*vector.y +
                    matrix.mRows[1][2]*vector.z,
                    matrix.mRows[2][0]*vector.x + matrix.mRows[2][1]*vector.y +
                    matrix.mRows[2][2]*vector.z);
    }

    // Overloaded operator for equality condition
    inline bool operator==(const Matrix3x3& matrix) const {
        return (mRows[0][0] == matrix.mRows[0][0] && mRows[0][1] == matrix.mRows[0][1] &&
                mRows[0][2] == matrix.mRows[0][2] &&
                mRows[1][0] == matrix.mRows[1][0] && mRows[1][1] == matrix.mRows[1][1] &&
                mRows[1][2] == matrix.mRows[1][2] &&
                mRows[2][0] == matrix.mRows[2][0] && mRows[2][1] == matrix.mRows[2][1] &&
                mRows[2][2] == matrix.mRows[2][2]);
    }

    // Overloaded operator for the is different condition
    inline bool operator!= (const Matrix3x3& matrix) const {
        return !(*this == matrix);
    }

    // Overloaded operator for addition with assignment
    inline Matrix3x3& operator+=(const Matrix3x3& matrix) {
    mRows[0][0] += matrix.mRows[0][0]; mRows[0][1] += matrix.mRows[0][1];
    mRows[0][2] += matrix.mRows[0][2]; mRows[1][0] += matrix.mRows[1][0];
    mRows[1][1] += matrix.mRows[1][1]; mRows[1][2] += matrix.mRows[1][2];
    mRows[2][0] += matrix.mRows[2][0]; mRows[2][1] += matrix.mRows[2][1];
    mRows[2][2] += matrix.mRows[2][2];
    return *this;
    }

    // Overloaded operator for substraction with assignment
    inline Matrix3x3& operator-=(const Matrix3x3& matrix) {
    mRows[0][0] -= matrix.mRows[0][0]; mRows[0][1] -= matrix.mRows[0][1];
    mRows[0][2] -= matrix.mRows[0][2]; mRows[1][0] -= matrix.mRows[1][0];
    mRows[1][1] -= matrix.mRows[1][1]; mRows[1][2] -= matrix.mRows[1][2];
    mRows[2][0] -= matrix.mRows[2][0]; mRows[2][1] -= matrix.mRows[2][1];
    mRows[2][2] -= matrix.mRows[2][2];
    return *this;
    }

    // Overloaded operator for multiplication with a number with assignment
    inline Matrix3x3& operator*=(float nb) {
    mRows[0][0] *= nb; mRows[0][1] *= nb; mRows[0][2] *= nb;
    mRows[1][0] *= nb; mRows[1][1] *= nb; mRows[1][2] *= nb;
    mRows[2][0] *= nb; mRows[2][1] *= nb; mRows[2][2] *= nb;
    return *this;
    }

    // Overloaded operator to return a row of the matrix.
    /// This operator is also used to access a matrix value using the syntax
    /// matrix[row][col].
    inline const Vector3& operator[](int row) const {
        return mRows[row];
    }

    // Overloaded operator to return a row of the matrix.
    /// This operator is also used to access a matrix value using the syntax
    /// matrix[row][col].
    inline Vector3& operator[](int row) {
        return mRows[row];
    }

    // Get the string representation
    inline std::string to_string() const {
        return "Matrix3x3(" + std::to_string(mRows[0][0]) + ", " + std::to_string(mRows[0][1]) + ", " + std::to_string(mRows[0][2]) + ", " +
            std::to_string(mRows[1][0]) + ", " + std::to_string(mRows[1][1]) + ", " + std::to_string(mRows[1][2]) + ", " +
            std::to_string(mRows[2][0]) + ", " + std::to_string(mRows[2][1]) + ", " + std::to_string(mRows[2][2]) + ")";
    }
};

struct Quaternion {

public:

    // -------------------- Attributes -------------------- //

    /// Component x
    float x;

    /// Component y
    float y;

    /// Component z
    float z;

    /// Component w
    float w;

    // Constructor of the class
    inline Quaternion() : x(0.0), y(0.0), z(0.0), w(0.0) {

    }

    // Constructor with arguments
    inline Quaternion(float newX, float newY, float newZ, float newW)
            :x(newX), y(newY), z(newZ), w(newW) {

    }

    // Constructor with the component w and the vector v=(x y z)
    inline Quaternion(float newW, const Vector3& v) : x(v.x), y(v.y), z(v.z), w(newW) {

    }

    // Constructor with the component w and the vector v=(x y z)
    inline Quaternion(const Vector3& v, float newW) : x(v.x), y(v.y), z(v.z), w(newW) {

    }

    // Set all the values
    inline void setAllValues(float newX, float newY, float newZ, float newW) {
        x = newX;
        y = newY;
        z = newZ;
        w = newW;
    }

    // Set the quaternion to zero
    inline void setToZero() {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }

    // Set to the identity quaternion
    inline void setToIdentity() {
        x = 0;
        y = 0;
        z = 0;
        w = 1;
    }

    // Return the vector v=(x y z) of the quaternion
    inline Vector3 getVectorV() const {

        // Return the vector v
        return Vector3(x, y, z);
    }

    // Return the length of the quaternion (inline)
    inline float length() const {
        return std::sqrt(x*x + y*y + z*z + w*w);
    }

    // Return the square of the length of the quaternion
    inline float lengthSquare() const {
        return x*x + y*y + z*z + w*w;
    }

    // Normalize the quaternion
    inline void normalize() {

        float l = length();

        // Check if the length is not equal to zero
        assert (l > MACHINE_EPSILON);

        x /= l;
        y /= l;
        z /= l;
        w /= l;
    }

    // Inverse the quaternion
    inline void inverse() {

        // Use the conjugate of the current quaternion
        x = -x;
        y = -y;
        z = -z;
    }

    // Return the unit quaternion
    inline Quaternion getUnit() const {
        float lengthQuaternion = length();

        // Check if the length is not equal to zero
        assert (lengthQuaternion > MACHINE_EPSILON);

        // Compute and return the unit quaternion
        return Quaternion(x / lengthQuaternion, y / lengthQuaternion,
                        z / lengthQuaternion, w / lengthQuaternion);
    }

    // Return the identity quaternion
    inline Quaternion identity() {
        return Quaternion(0.0, 0.0, 0.0, 1.0);
    }

    // Return the conjugate of the quaternion (inline)
    inline Quaternion getConjugate() const {
        return Quaternion(-x, -y, -z, w);
    }

    // Return the inverse of the quaternion (inline)
    inline Quaternion getInverse() const {

        // Return the conjugate quaternion
        return Quaternion(-x, -y, -z, w);
    }

    // Scalar product between two quaternions
    inline float dot(const Quaternion& quaternion) const {
        return (x*quaternion.x + y*quaternion.y + z*quaternion.z + w*quaternion.w);
    }

    // Return true if the values are not NAN OR INF
    inline bool isFinite() const {
        return std::isfinite(x) && std::isfinite(y) && std::isfinite(z) && std::isfinite(w);
    }

    // Return true if it is a unit quaternion
    inline bool isUnit() const {
        const float length = std::sqrt(x*x + y*y + z*z + w*w);
        const float tolerance = 1e-5f;
        return std::abs(length - float(1.0)) < tolerance;
    }

    // Return true if it is a valid quaternion
    inline bool isValid() const {
    return isFinite() && isUnit();
    }

    // Overloaded operator for the addition of two quaternions
    inline Quaternion operator+(const Quaternion& quaternion) const {

        // Return the result quaternion
        return Quaternion(x + quaternion.x, y + quaternion.y, z + quaternion.z, w + quaternion.w);
    }

    // Overloaded operator for the substraction of two quaternions
    inline Quaternion operator-(const Quaternion& quaternion) const {

        // Return the result of the substraction
        return Quaternion(x - quaternion.x, y - quaternion.y, z - quaternion.z, w - quaternion.w);
    }

    // Overloaded operator for addition with assignment
    inline Quaternion& operator+=(const Quaternion& quaternion) {
        x += quaternion.x;
        y += quaternion.y;
        z += quaternion.z;
        w += quaternion.w;
        return *this;
    }

    // Overloaded operator for substraction with assignment
    inline Quaternion& operator-=(const Quaternion& quaternion) {
        x -= quaternion.x;
        y -= quaternion.y;
        z -= quaternion.z;
        w -= quaternion.w;
        return *this;
    }

    // Overloaded operator for the multiplication with a constant
    inline Quaternion operator*(float nb) const {
        return Quaternion(nb * x, nb * y, nb * z, nb * w);
    }

    // Overloaded operator for the multiplication of two quaternions
    inline Quaternion operator*(const Quaternion& quaternion) const {

        /* The followin code is equivalent to this
        return Quaternion(w * quaternion.w - getVectorV().dot(quaternion.getVectorV()),
                            w * quaternion.getVectorV() + quaternion.w * getVectorV() +
                            getVectorV().cross(quaternion.getVectorV()));
        */

        return Quaternion(w * quaternion.x + quaternion.w * x + y * quaternion.z - z * quaternion.y,
                        w * quaternion.y + quaternion.w * y + z * quaternion.x - x * quaternion.z,
                        w * quaternion.z + quaternion.w * z + x * quaternion.y - y * quaternion.x,
                        w * quaternion.w - x * quaternion.x - y * quaternion.y - z * quaternion.z);
    }

    // Overloaded operator for the multiplication with a vector.
    /// This methods rotates a point given the rotation of a quaternion.
    inline Vector3 operator*(const Vector3& point) const {

        /* The following code is equivalent to this
        * Quaternion p(point.x, point.y, point.z, 0.0);
        * return (((*this) * p) * getConjugate()).getVectorV();
        */

        const float prodX = w * point.x + y * point.z - z * point.y;
        const float prodY = w * point.y + z * point.x - x * point.z;
        const float prodZ = w * point.z + x * point.y - y * point.x;
        const float prodW = -x * point.x - y * point.y - z * point.z;
        return Vector3(w * prodX - prodY * z + prodZ * y - prodW * x,
                    w * prodY - prodZ * x + prodX * z - prodW * y,
                    w * prodZ - prodX * y + prodY * x - prodW * z);
    }

    // Overloaded operator for equality condition
    inline bool operator==(const Quaternion& quaternion) const {
        return (x == quaternion.x && y == quaternion.y &&
                z == quaternion.z && w == quaternion.w);
    }

    // Get the string representation
    inline std::string to_string() const {
        return "Quaternion(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " +
                std::to_string(w) + ")";
    }

private:

    /// Initialize the quaternion using Euler angles
    void initWithEulerAngles(float angleX, float angleY, float angleZ);
};

