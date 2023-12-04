#ifndef RENDERER_H
#define RENDERER_H

#include "pixel_buffer.h"
#include <vector>
#include "sphere.h"

void renderScene(std::vector<Sphere>& sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount);
Vector3 viewportCoord(int x, int y, int height);
bool isValidIntersection(const Vector3& intersection);
uint32_t multiplyCol(uint32_t inputCol, double factor);

#endif // SCENEDRAWING_H
