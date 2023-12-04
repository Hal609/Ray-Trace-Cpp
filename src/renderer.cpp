#include "renderer.h"
#include "sphere.h"
#include "vector3.h"
#include <vector>
#include "ray.h"
#include <array>
#include <cmath> // For sin and M_PI
#include "light.h"


std::array<Sphere, 4> spheres = {{
        Sphere(1.0, Vector3(2.0, 1.0, 4.0), 0xff0000, 500.0, 0.2), // Sphere 1
        Sphere(0.4, Vector3(0.0, 0.4, 3), 0xffffff, 500.0, 0.2), // Sphere 2
        Sphere(0.3, Vector3(-0.7, 0.3, 5.5), 0x14DC00, 400.0, 0.8), // Sphere 3
        Sphere(5000, Vector3(0, -5000, 0), 0xeeeedd, 500, 0.3) // Floor
    }};

Lighting lighting;

Vector3 camStart = Vector3(0.0, 1.0, 0.0);
float viewHeight = 1;
float viewZ = 0.9;

void setupLighting() {
    lighting.setAmbientLight(0.2);
    Light* light = new Light(Vector3(1.0, 1.0, 0.0), 0xFFFFFF, 0.8);
    lighting.addLight(light);
}


void renderScene(std::vector<Sphere>& sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount) {
    Vector3 camPos = camStart + Vector3(0.005, 0.005, 0.01) * frameCount;
    float heightRatio = viewHeight / height;
    
    if (frameCount == 0) {
        setupLighting();
    }
    #pragma omp parallel for schedule(dynamic) // Parallelization
    for (int iy = height/2; iy >= -height/2; iy--){
        for (int ix = -width/2; ix <= width/2; ix++) {
            Vector3 viewportCoords = Vector3(ix * heightRatio, iy * heightRatio, viewZ);
            u_int32_t col;
            bool hit = false;

            for (auto &sphere : spheres) {
                Vector3 intersection = Ray(camPos, viewportCoords.normalized()).intersectSphere(sphere);
                if (isValidIntersection(intersection)) {
                    hit = true;
                    Vector3 normal = (intersection - sphere.center).normalized();
                    col = sphere.color;
                    float light = lighting.calculateTotalLighting(intersection, normal, sphere);
                    col = multiplyCol(col, light);
                    break;
                }
            }

            if (!hit) {
                continue;
            }

            int x = width/2 + ix;
            int y = height/2 - iy;
            pixelBuffer.setPixel(x, y, col);
                
        }
    }
}

u_int32_t multiplyCol(u_int32_t inputCol, double factor){
    u_int32_t r = (inputCol & 0xff0000) >> 16;
    u_int32_t g = (inputCol & 0x00ff00) >> 8;
    u_int32_t b = (inputCol & 0x0000ff);
    r = std::min(255.0, r * factor);
    g = std::min(255.0, g * factor);
    b = std::min(255.0, b * factor);
    return (r << 16) + (g << 8) + b;
}

bool isValidIntersection(const Vector3& intersection) {
    return !(intersection == Vector3(-1, -1, -1));
}


/*
1st Function:
Convert each pixel convert to viewport coordinates 
2nd Function:
Create a ray from the camera to the viewport coordinates 
3rd Function:
For each ray, check every sphere to see if it intersects with the ray by calling the intersectSphere method from the ray class and passing in the sphere
If the ray returns NULL for the intersection then continue
If it intersects with multiple spheres, use the closest sphere

4th Function (lighting) (possibly broken into multiple functions):
If it intersects with a sphere use a separate function to compute the total lighting on that point in the scene (based on the intersection point vector3)
Add ambient lighting as a flat value to all pixels
For each point light in the scene, create a ray from the intersection point to the light
Compute the dot product of the normal of the sphere at the intersection point and the ray to the light (for directional lights, use the negative of the light direction)
Multiply the color of the sphere by the lighting coefficient and return the value

5th Function (reflection):
For this closest sphere, recursively call the same process of finding intersecting spheres but using the intersection point as the camera to find reflections.
Add the color of the sphere to the color of the reflection ray based on the reflective coefficient of the sphere with a cooefficient of 1 meaning it is a perfect mirror and 0 meaning it is not reflective at all.

Return to first function:
Colour the pixel with the resulting color
*/

