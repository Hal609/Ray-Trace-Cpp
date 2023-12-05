#ifndef LIGHTING_H
#define LIGHTING_H

#include "vector3.h"
#include "sphere.h"  // Assuming Sphere has material properties
#include <vector>


class Light {
public:
    Light(const Vector3& position, const Vector3& color, double intensity)
        : position(position), color(color), intensity(intensity) {}

    double calculateContribution(Vector3& point, Vector3& normal, Sphere& object);
    Vector3 getPosition() const;
    double getIntensity() const;

private:
    Vector3 position;
    Vector3 color;
    double intensity;
};


// Derived classes for different types of lights (e.g., PointLight, DirectionalLight) go here

class Lighting {
public:
    void setAmbientLight(double ambient);
    void addLight(Light* light);
    double calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object, std::vector<Sphere>& sphereData, Vector3 rayToViewport) const;
    double calculateSpecular(Vector3& point, Vector3& normal, Sphere& object, Light* light, Vector3 viewDirection) const;
    bool isInShadow(Vector3& point, Light* light, Sphere& object, const std::vector<Sphere>& sphereData) const;

private:
    double ambientLight;
    std::vector<Light*> lights; // List of lights in the scene
};

#endif // LIGHTING_H
