#pragma once

#include <vector>

#include "vec.h"

namespace SoftwareRenderer {
class ColorBuffer {
private:
    int _width;
    int _height;
    std::vector<Color> _pixels;

public:
    ColorBuffer();

    ColorBuffer(int width, int height);

    ColorBuffer(int width, int height, Color color);

    int Width() const;

    int Height() const;

    const std::vector<Color>& Colors() const;

    Color GetColor(int x, int y) const;

    void SetColor(int x, int y, Color color);

    void SetColors(Color color);

    void SetColors(const std::vector<Color>& pixels);
};

class DepthBuffer {
private:
    int _width;
    int _height;
    std::vector<float> _depth;
};

class FrameBuffer {
private:
    int _width;
    int _height;
    ColorBuffer _colorBuffer;
    DepthBuffer _depthBuffer;
};
} // namespace SoftwareRenderer
