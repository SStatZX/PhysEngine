#pragma once

#include <cmath>

struct Vector2
{ 
public:

    float x, y;

    Vector2();

    Vector2(float newX, float newY);

    float length() const;

    float dot(const Vector2& vector) const;

    void normalize();

    void setToZero();

    std::string toString() const;

    Vector2& operator+=(const Vector2& vector);

    Vector2& operator-=(const Vector2& vector);

    Vector2& operator*=(float num);

    Vector2& operator/=(float num);

    bool operator==(const Vector2& vector) const;

    bool operator!=(const Vector2& vector) const;

    float& operator[] (int index);

    const float& operator[] (int index) const;

    friend Vector2 operator+(const Vector2& vec1, const Vector2& vec2);
    friend Vector2 operator-(const Vector2& vec1, const Vector2& vec2);
    friend Vector2 operator-(const Vector2& vec);
    friend Vector2 operator*(const Vector2& vec, float num);
    friend Vector2 operator*(float num, const Vector2& vec);
    friend Vector2 operator*(const Vector2& vec1, const Vector2& vec2);
    friend Vector2 operator/(const Vector2& vec, float num);
    friend Vector2 operator/(const Vector2& vec1, const Vector2& vec2);

};

inline Vector2::Vector2() : x(0.0), y(0.0) { // same as just x=0 and y=0 in body I think? Just looks neater

}

inline Vector2::Vector2(float newX, float newY) : x(newX), y(newY) {

}
// Returns length or magnitude of vector.
inline float Vector2::length() const {
    return std::sqrt(x*x + y*y);
}
// Dot product of two vectors.
inline float Vector2::dot(const Vector2& vector) const {
    return (x*vector.x + y*vector.y);
}
// Normalized form.
inline void Vector2::normalize() {
    float magnitude = length();
    x /= magnitude;
    y /= magnitude;
}
// Additition operator.
inline Vector2 operator+(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x+vec2.x, vec1.y+vec2.y);
}
// Subtraction operation.
inline Vector2 operator-(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}
// Subtraction (overload for minus values).
inline Vector2 operator-(const Vector2 vec)
{
    return Vector2(-vec.x, -vec.y);
}
// Multiplication with number.
inline Vector2 operator*(const Vector2& vec, float num)
{
    return Vector2(vec.x * num, vec.y * num);
}
// Multiplication with two vector2s.
inline Vector2 operator*(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x * vec2.x, vec1.y * vec2.y);
}
// Reverse input compatability.
inline Vector2 operator*(float num, const Vector2& vec)
{
    return vec * num;
}
// Division with number.
inline Vector2 operator/(const Vector2& vec, float num)
{
    return Vector2(vec.x / num, vec.y / num);
}
// Division with two vector2s.
inline Vector2 operator/(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x / vec2.x, vec1.y / vec2.y);
}
// Addition equals operator.
inline Vector2& Vector2::operator+=(const Vector2& vector) {
    x += vector.x;
    y += vector.y;
    return *this;
}
// Subtraction equals operator.
inline Vector2& Vector2::operator-=(const Vector2& vector) {
    x -= vector.x;
    y -= vector.y;
    return *this;
}
// Multiplication equals operator.
inline Vector2& Vector2::operator*=(float num) {
    x *= num;
    y *= num;
    return *this;
}
// Division equals operator.
inline Vector2& Vector2::operator/=(float num) {
    x /= num;
    y /= num;
    return *this;
}

inline void Vector2::setToZero() {
    x=0; y=0;
}

inline bool Vector2::operator==(const Vector2& vector) const {
    return (x == vector.x && y == vector.y);
}

inline bool Vector2::operator!=(const Vector2& vector) const {
    return !(*this == vector);
}

inline std::string Vector2::toString() const {
    return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

inline float& Vector2::operator[] (int index) {
    return (&x)[index];
}

inline const float& Vector2::operator[] (int index) const {
    return (&x)[index];
}