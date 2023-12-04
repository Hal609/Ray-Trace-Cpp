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

};

std::vector<Sphere> loadSpheresFromFile(const std::string& filePath);

#endif // SPHERE_H
