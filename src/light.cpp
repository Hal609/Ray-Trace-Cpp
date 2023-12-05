#include "light.h"
#include "ray.h"

void Lighting::setAmbientLight(double ambient) {
    ambientLight = ambient;
}

void Lighting::addLight(Light* light) {
    lights.push_back(light);
}

double Lighting::calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object, std::vector<Sphere>& sphereData, Vector3 rayToViewport) const {
    double totalLight = ambientLight; // Start with ambient light

    for (auto& light : lights) {
        if (!isInShadow(point, light, object, sphereData)) {
            totalLight += light->calculateContribution(point, normal, object);
            Vector3 viewDirection = rayToViewport.normalized();
            totalLight += calculateSpecular(point, normal, object, light, viewDirection) * light->getIntensity();
        }
    }
    totalLight = std::min(1.0, totalLight); // Clamp to 1.0
    return totalLight;
}

double Lighting::calculateSpecular(Vector3& point, Vector3& normal, Sphere& object, Light* light, Vector3 viewDirection) const {
    double shine = 0.0;
    if (object.specularExponent != 0) {
        Vector3 lightDirection = (point - light->getPosition()).normalized();
        Vector3 reflected = lightDirection.reflected(normal);

        shine = pow(std::max(0.0, reflected.dot(viewDirection)), object.specularExponent);
        shine = std::min(1.0, shine); // Clamp to 1.0
    }
    return shine;
}

bool Lighting::isInShadow(Vector3& point, Light* light, Sphere& object, const std::vector<Sphere>& sphereData) const {
    Vector3 lightDir = (light->getPosition() - point).normalized();
    Ray shadowRay(point, lightDir);

    for (const auto& sphere : sphereData) {
        if (&object != &sphere && shadowRay.intersectSphere(sphere) != Vector3(-1, -1, -1)) {
            return true; // Point is in shadow
        }
    }
    return false; // Point is not in shadow
}

Vector3 Light::getPosition() const {
    return position;
}

double Light::getIntensity() const {
    return intensity;
}

double Light::calculateContribution(Vector3& point, Vector3& normal, Sphere& object) {
    Vector3 lightDir = (position - point).normalized();
    double lightIntensity = intensity * std::max(0.0, normal.dot(lightDir));
    return lightIntensity; // Need to add colour later when colour class supports operations
}
