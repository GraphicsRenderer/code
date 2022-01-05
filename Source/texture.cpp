#include "texture.h"

#include "log.h"

// This line is required for stb image library
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

using namespace SoftwareRenderer;
using namespace std;

Texture::Texture(int width, int height) {
  _width = width;
  _height = height;
  _pixels.resize(_width * _height);
}

Texture::Texture(int width, int height, Color color) {
  _width = width;
  _height = height;
  _pixels.resize(_width * _height);
  for (auto i = 0; i < _width * _height; i++) _pixels[i] = color;
}

void Texture::SaveAsPNG(const char* filepath) {
  LogDebug("Texture::SaveAsPNG width: {}, height: {}, filepath: {}", _width,
           _height, filepath);

  stbi_write_png(filepath, _width, _height, 4, _pixels.data(), _width * 4);
}