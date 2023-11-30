#include <iostream>
#include <fstream>
#include <vector>
#include "sphere.h"

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
