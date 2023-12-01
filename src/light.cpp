#include "light.h"

void Lighting::setAmbientLight(Vector3& ambient) {
    ambientLight = ambient;
}

void Lighting::addLight(Light* light) {
    lights.push_back(light);
}

Vector3 Lighting::calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object) {
    Vector3 totalLight = ambientLight; // Start with ambient light

    for (auto& light : lights) {
        // Check for shadow; if not in shadow, add light contribution
        // Shadow check logic goes here (ray tracing from point to light source)

        // Assuming no shadow for simplicity
        totalLight = totalLight + light->calculateContribution(point, normal, object);
    }

    return totalLight;
}
