#ifndef SPHERE_H
#define SPHERE_H

#include <vector3.h>
#include <string>

class Sphere {
public:
    double radius;
    Vector3 center;
    uint32_t color;
    double specularExponent;
    double reflectionCoefficient;

    Sphere(double r, Vector3 c, uint32_t color,  double specExp, double reflCoeff)
        : radius(r), center(c), color(color), specularExponent(specExp), reflectionCoefficient(reflCoeff) {}

};

std::vector<Sphere> loadSpheresFromFile(const std::string& filePath);

#endif // SPHERE_H
