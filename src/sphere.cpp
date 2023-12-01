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

    double r, specExp, reflCoeff;
    Vector3 centre;
    uint32_t color;

    while (file >> r >> centre.x >> centre.y >> centre.z >> color >> specExp >> reflCoeff) {
        Sphere sphere(r, centre, color, specExp, reflCoeff);
        spheres.push_back(sphere);
    }

    file.close();
    return spheres;
}
