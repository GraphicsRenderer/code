#pragma once

#include <vector>

#include "buffer.h"

namespace SoftwareRenderer {
class Texture : public ColorBuffer {
private:
public:
    using ColorBuffer::ColorBuffer;

    explicit Texture(const char* filepath);

    void SaveAsPNG(const char* filepath);
};
} // namespace SoftwareRenderer
