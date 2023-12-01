#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3 {
public:
    double x, y, z;

    Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    bool operator==(const Vector3& other) const;
    double dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    double length() const;
    Vector3 normalized() const;
};

#endif // VECTOR3_H
