#include <iostream>
#include <fstream>
#include <vector>

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

std::vector<Sphere> loadSpheresFromFile(const std::string& filePath) {
    std::vector<Sphere> spheres;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return spheres;
    }

    double radius, cx, cy, cz, specExp, reflCoeff;
    while (file >> radius >> cx >> cy >> cz >> specExp >> reflCoeff) {
        Sphere sphere(radius, cx, cy, cz, specExp, reflCoeff);
        spheres.push_back(sphere);
    }

    file.close();
    return spheres;
}
