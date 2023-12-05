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
    std::string colorHex;

    while (file >> r >> centre.x >> centre.y >> centre.z >> colorHex >> specExp >> reflCoeff) {
        Color colorObj(std::stoi(colorHex, 0, 16));
        Sphere sphere(r, centre, colorObj, specExp, reflCoeff);
        spheres.push_back(sphere);
    }

    file.close();
    return spheres;
}
