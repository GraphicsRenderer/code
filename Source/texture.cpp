#include "texture.h"

#include "log.h"

// This line is required for stb image library
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

using namespace SoftwareRenderer;
using namespace std;

Texture::Texture() : Texture(0, 0) {}

Texture::Texture(int width, int height) : Texture(width, height, Color()) {}

Texture::Texture(int width, int height, Color color) {
  _buffer = ColorBuffer(width, height, color);
}

Texture::Texture(const char *filepath) {}

void Texture::SaveAsPNG(const char *filepath) {
  LogDebug("Texture::SaveAsPNG width: {}, height: {}, filepath: {}",
           _buffer.Width(), _buffer.Height(), filepath);

  stbi_write_png(filepath, _buffer.Width(), _buffer.Height(), 4,
                 _buffer.Pixels().data(), _buffer.Width() * 4);
}