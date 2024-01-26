#pragma once

#include <cmath>

struct Vector2
{ 
public:

    float x, y;

    Vector2();

    Vector2(float newX, float newY);

    float length() const;

    Vector2& operator+=(const Vector2& vector);

    Vector2& operator-=(const Vector2& vector);

    Vector2& operator*=(const Vector2& vector);

    Vector2& operator/=(const Vector2& vector);

    bool operator==(const Vector2& vector) const;

    bool operator!=(const Vector2& vector) const;
};
inline Vector2::Vector2() : x(0.0), y(0.0) { // same as just x=0 and y=0 in body I think? Just looks neater

}

inline Vector2::Vector2(float newX, float newY) : x(newX), y(newY) {

}
// dot, normalize and operators
inline float Vector2::length() const {
    return std::sqrt(x*x + y*y);
}
