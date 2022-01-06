#pragma once

#include "buffer.h"
#include <vector>

namespace SoftwareRenderer {
class Texture {
private:
  ColorBuffer _buffer;

public:
  Texture();

  Texture(int width, int height);

  Texture(int width, int height, Color color);

  Texture(const char *filepath);

  void SaveAsPNG(const char *filepath);
};
} // namespace SoftwareRenderer