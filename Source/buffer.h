#pragma once

#include "color.h"
#include <vector>

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

  int Width();

  int Height();

  const std::vector<Color> &Pixels();

  Color GetPixel(int x, int y);

  Color SetPixel(int x, int y, Color color);

  void SetPixels(Color);
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
