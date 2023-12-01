#ifndef RAY_H
#define RAY_H

#include <cmath>
#include "vector3.h"
#include "sphere.h"

class Ray {
public:
    Vector3 origin;
    Vector3 direction;

    Ray(const Vector3& origin, const Vector3& direction) : origin(origin), direction(direction.normalized()) {}

    Vector3 intersectSphere(const Sphere& sphereToCheck);
    Vector3 reflect(const Vector3& normal);
};

#endif // RAY_H
