#ifndef RENDERER_H
#define RENDERER_H

#include "pixel_buffer.h"
#include "sphere.h"

void drawScene(std::vector<Sphere> sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount);

#endif // SCENEDRAWING_H
