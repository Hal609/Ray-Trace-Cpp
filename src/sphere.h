#ifndef SPHERE_H
#define SPHERE_H

#include <vector3.h>
#include <color.h>
#include <vector>
#include <string>

class Sphere {
public:
    double radius;
    Vector3 center;
    Color color;
    double specularExponent;
    double reflectionCoefficient;

    Sphere(double r, Vector3 c, Color color,  double specExp, double reflCoeff)
        : radius(r), center(c), color(color), specularExponent(specExp), reflectionCoefficient(reflCoeff) {}

    inline bool operator==(const Sphere& other) const {
        return radius == other.radius && center == other.center && color == other.color && specularExponent == other.specularExponent && reflectionCoefficient == other.reflectionCoefficient;
    }

    inline bool operator!=(const Sphere& other) const {
        return !(*this == other);
    }

};

std::vector<Sphere> loadSpheresFromFile(const std::string& filePath);

#endif // SPHERE_H
