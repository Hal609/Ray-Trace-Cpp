
#include "vector3D.h"
#include <cmath>

// Class definition
class Vector3D {
public:
    double x, y, z;

    // Default constructor
    Vector3D() : x(0.0), y(0.0), z(0.0) {}

    // Parameterized constructor
    Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    // Vector addition
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Vector subtraction
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    // Length calculation
    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Other vector-related utility functions
    // ...

};

// Other function implementations
// ...
