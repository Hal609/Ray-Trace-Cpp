#ifndef RENDERER_H
#define RENDERER_H

#include "pixel_buffer.h"
#include <vector>
#include "sphere.h"
#include <cstdint>

void renderScene(std::vector<Sphere>& sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount);

#endif // SCENEDRAWING_H
