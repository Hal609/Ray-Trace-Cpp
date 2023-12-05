#include "renderer.h"
#include "sphere.h"
#include "vector3.h"
#include <vector>
#include "ray.h"
#include <array>
#include <cmath> // For sin and M_PI
#include "light.h"
#include "color.h"

Lighting lighting;

Vector3 camPos = Vector3(0.0, 1.0, 0.0);
float viewHeight = 1;
float viewZ = 0.9;

void setupLighting() {
    lighting.setAmbientLight(0.2);
    Light* light = new Light(Vector3(1.0, 1.0, 0.0), 0xFFFFFF, 0.8);
    lighting.addLight(light);
}

void renderScene(std::vector<Sphere>& sphereData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount) {
    camPos = camPos + Vector3(0.0005, 0.0005, 0.001);
    float heightRatio = viewHeight / height;
    
    if (frameCount == 0) {
        setupLighting();
    }

    #pragma omp parallel for schedule(dynamic) proc_bind(spread) // Parallelization
    for (int iy = height/2; iy >= -height/2; iy--){
        for (int ix = -width/2; ix <= width/2; ix++) {
            Vector3 viewportCoords = Vector3(ix * heightRatio, iy * heightRatio, viewZ);
            Color col;
            bool hit = false;

            for (auto& sphere : sphereData) {
                Vector3 intersection = Ray(camPos, viewportCoords).intersectSphere(sphere);
                if (!(intersection == Vector3(-1, -1, -1))) {
                    hit = true;
                    Vector3 normal = (intersection - sphere.center).normalized();
                    float light = lighting.calculateTotalLighting(intersection, normal, sphere, sphereData);
                    col = sphere.color;
                    col.multiplyBrightness(light);
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

