#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include <string>

class Sphere {
public:
    double radius;
    double center[3];
    double specularExponent;
    double reflectionCoefficient;

    Sphere(double r, double cx, double cy, double cz, double specExp, double reflCoeff)
        : radius(r), specularExponent(specExp), reflectionCoefficient(reflCoeff) {
        center[0] = cx;
        center[1] = cy;
        center[2] = cz;
    }
};

std::vector<Sphere> loadSpheresFromFile(const std::string& filePath);

#endif // SPHERE_H
