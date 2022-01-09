#pragma once

#include "buffer.h"
#include <vector>

namespace SoftwareRenderer {
class Texture : public ColorBuffer {
private:
public:
  using ColorBuffer::ColorBuffer;

  Texture(const char *filepath);

  void SaveAsPNG(const char *filepath);
};
} // namespace SoftwareRenderer