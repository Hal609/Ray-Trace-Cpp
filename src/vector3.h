#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3 {
public:
    double x, y, z;

    Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    inline Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    inline Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    inline Vector3 operator*(double scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    inline double dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    inline bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }

    inline Vector3 cross(const Vector3& other) const {
        return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    inline double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    inline Vector3 normalized() const {
        double len = length();
        return Vector3(x / len, y / len, z / len);
    }

    inline Vector3 reflected(const Vector3& normal) const {
        return *this - normal * 2.0 * this->dot(normal);
    }
};

#endif // VECTOR3_H
