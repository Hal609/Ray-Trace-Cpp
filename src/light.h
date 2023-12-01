#ifndef LIGHTING_H
#define LIGHTING_H

#include "vector3.h"
#include "sphere.h"  // Assuming Sphere has material properties
#include <vector>

// Abstract base class for a light source
class Light {
public:
    virtual Vector3 calculateContribution(Vector3& point, Vector3& normal, Sphere& object);
};

class PointLight : public Light {
public:
    PointLight(const Vector3& position, const Vector3& color, double intensity)
        : position(position), color(color), intensity(intensity) {}

    Vector3 calculateContribution(Vector3& point, Vector3& normal, Sphere& object);

private:
    Vector3 position;
    Vector3 color;
    double intensity;
};


// Derived classes for different types of lights (e.g., PointLight, DirectionalLight) go here

class Lighting {
public:
    void setAmbientLight(Vector3& ambient);
    void addLight(Light* light);
    Vector3 calculateTotalLighting(Vector3& point, Vector3& normal, Sphere& object);

private:
    Vector3 ambientLight;
    std::vector<Light*> lights; // List of lights in the scene
};

#endif // LIGHTING_H
