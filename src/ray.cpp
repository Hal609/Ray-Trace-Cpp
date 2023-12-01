#include <cmath>
#include "vector3.h"
#include "sphere.h"
#include "ray.h"

Vector3 Ray::intersectSphere(const Sphere& sphereToCheck) {
        Vector3 oc = origin - sphereToCheck.center;
        double a = direction.dot(direction);
        double b = 2.0 * oc.dot(direction);
        double c = oc.dot(oc) - sphereToCheck.radius * sphereToCheck.radius;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return Vector3(-1, -1, -1); // Return NULL to indicate no intersection
        }

        double sqrtDiscriminant = std::sqrt(discriminant);
        double t0 = (-b - sqrtDiscriminant) / (2.0 * a);
        double t1 = (-b + sqrtDiscriminant) / (2.0 * a);

        // Ensure t0 is the smaller t (i.e. closer to the camera)
        if (t0 > t1) {
            std::swap(t0, t1);
        }

        // If t0 is negative (intersects behind the camera), try t1
        if (t0 < 0) {
            t0 = t1; 
            if (t0 < 0) {
                return Vector3(-1, -1, -1); // Return NULL to indicate no intersection
            }
        }

        // Return the intersection point
        return origin + direction * t0;
}


Vector3 Ray::reflect(const Vector3& normal) {
    return direction - (normal * 2.0) * direction.dot(normal);
}
