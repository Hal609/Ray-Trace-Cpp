#include "light.h"

void Lighting::setAmbientLight(double ambient) {
    ambientLight = ambient;
}

void Lighting::addLight(Light* light) {
    lights.push_back(light);
}

double Lighting::calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object) {
    double totalLight = 0; // Start with ambient light

    for (auto& light : lights) {
        // Check for shadow; if not in shadow, add light contribution
        // Shadow check logic goes here (ray tracing from point to light source)

        // Assuming no shadow for simplicity
        totalLight = totalLight + light->calculateContribution(point, normal, object);
    }
    totalLight = std::min(1.0, totalLight); // Clamp to 1.0
    return totalLight;
}

double Light:: calculateContribution(Vector3& point, Vector3& normal, Sphere& object) {
    Vector3 lightDir = (position - point).normalized();
    float lightIntensity = intensity * std::max(0.0, normal.dot(lightDir));
    return lightIntensity; // Need to add colour later when colour class supports operations
}
