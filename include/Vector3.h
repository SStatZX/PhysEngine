#pragma once

#include <cmath>

struct Vector3
{ 
public:

    float x, y, z;

    Vector3();

    Vector3(float newX, float newY, float newZ);

    float length() const;

    float dot(const Vector3& vector) const;

    void normalize();

    std::string toString() const;

    Vector3& operator+=(const Vector3& vector);

    Vector3& operator-=(const Vector3& vector);

    Vector3& operator*=(float num);

    Vector3& operator/=(float num);

    bool operator==(const Vector3& vector) const;

    bool operator!=(const Vector3& vector) const;
};

inline Vector3::Vector3() : x(0.0), y(0.0), z(0.0) { // same as just x=0 and y=0 in body I think? Just looks neater

}

inline Vector3::Vector3(float newX, float newY, float newZ) : x(newX), y(newY), z(newZ) { }

// Returns length or magnitude of vector.
inline float Vector3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}
// Dot product of two vectors.
inline float Vector3::dot(const Vector3& vector) const {
    return (x*vector.x + y*vector.y + z*vector.z);
}
// Normalized form.
inline void Vector3::normalize() {
    float magnitude = length();
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
}
// Addition equals operator.
inline Vector3& Vector3::operator+=(const Vector3& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}
// Subtraction equals operator.
inline Vector3& Vector3::operator-=(const Vector3& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}
// Multiplication equals operator.
inline Vector3& Vector3::operator*=(float num) {
    x *= num;
    y *= num;
    z *= num;
    return *this;
}
// Division equals operator.
inline Vector3& Vector3::operator/=(float num) {
    x /= num;
    y /= num;
    z /= num;
    return *this;
}

inline bool Vector3::operator==(const Vector3& vector) const {
    return (x == vector.x && y == vector.y && z == vector.z);
}

inline bool Vector3::operator!=(const Vector3& vector) const {
    return !(*this == vector);
}
inline std::string Vector3::toString() const {
    return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) +")";
}