#include "light.h"
#include "ray.h"

void Lighting::setAmbientLight(double ambient) {
    ambientLight = ambient;
}

void Lighting::addLight(Light* light) {
    lights.push_back(light);
}

double Lighting::calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object, std::vector<Sphere>& sphereData) const {
    double totalLight = ambientLight; // Start with ambient light

    for (auto& light : lights) {
        if (!(isInShadow(point, light, object, sphereData))) {
            totalLight = totalLight + light->calculateContribution(point, normal, object);
        }
    }
    totalLight = std::min(1.0, totalLight); // Clamp to 1.0
    return totalLight;
}

bool Lighting::isInShadow(Vector3& point, Light* light, Sphere& object, const std::vector<Sphere>& sphereData) const {
    Vector3 lightDir = (light->getPosition() - point).normalized();
    Ray shadowRay(point, lightDir);

    for (const auto& sphere : sphereData) {
        if (object == sphere) {
            continue; // Don't check for intersection with the object itself
        }
        if (!(shadowRay.intersectSphere(sphere) == Vector3(-1, -1, -1))) {
            return true; // Point is in shadow
        }
    }
    return false; // Point is not in shadow
}

Vector3 Light::getPosition() const {
    return position;
}

double Light:: calculateContribution(Vector3& point, Vector3& normal, Sphere& object) {
    Vector3 lightDir = (position - point).normalized();
    float lightIntensity = intensity * std::max(0.0, normal.dot(lightDir));
    return lightIntensity; // Need to add colour later when colour class supports operations
}
