#pragma once

#include "color.h"
#include <vector>

namespace SoftwareRenderer {
class Texture {
 private:
  int _width;
  int _height;
  std::vector<Color> _pixels;

 public:
  Texture(int width, int height);

  Texture(int width, int height, Color color);

  void SaveAsPNG(const char* filepath);
};
}  // namespace SoftwareRenderer