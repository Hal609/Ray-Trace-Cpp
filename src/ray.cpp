#include <cmath>
#include "vector3.h"

class Ray {
public:
    Vector3 origin;
    Vector3 direction;

    Ray(const Vector3& origin, const Vector3& direction) : origin(origin), direction(direction.normalized()) {}

    bool intersectSphere(const Vector3& center, double radius, double& t) const {
        Vector3 oc = origin - center;
        double a = direction.dot(direction);
        double b = 2.0 * oc.dot(direction);
        double c = oc.dot(oc) - radius * radius;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }

        double sqrtDiscriminant = std::sqrt(discriminant);
        double t0 = (-b - sqrtDiscriminant) / (2.0 * a);
        double t1 = (-b + sqrtDiscriminant) / (2.0 * a);

        if (t0 > t1) {
            std::swap(t0, t1);
        }

        if (t0 < 0) {
            t0 = t1;
            if (t0 < 0) {
                return false;
            }
        }

        t = t0;
        return true;
    }

    Vector3 reflect(const Vector3& normal) const {
        return direction - normal * 2.0 * direction.dot(normal);
    }
};
