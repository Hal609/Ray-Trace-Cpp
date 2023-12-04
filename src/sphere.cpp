#include <iostream>
#include <fstream>
#include <vector>
#include "sphere.h"
#include <sstream> // Include stringstream

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
        // Remove the '0x' prefix if present
        if (colorHex.find("0x") == 0 || colorHex.find("0X") == 0) {
            colorHex = colorHex.substr(2);
        }
        std::stringstream ss;
        ss << std::hex << colorHex;
        uint32_t color;
        ss >> color;

        Color colorObj(color);
        Sphere sphere(r, centre, colorObj, specExp, reflCoeff);
        spheres.push_back(sphere);
    }

    file.close();
    return spheres;
}
