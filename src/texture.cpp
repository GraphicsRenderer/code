#include "texture.h"

#include <vector>

#include "log.h"

// This line is required for stb image library
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include <stb_image_write.h>

using namespace SoftwareRenderer;
using namespace std;

Texture::Texture(const char* filepath) { }

void Texture::SaveAsPNG(const char* filepath)
{
    LogDebug("Texture::SaveAsPNG width: {}, height: {}, filepath: {}", Width(),
        Height(), filepath);

    auto pixels = vector<Color>();
    pixels.resize(Width() * Height());
    for (auto x = 0; x < Width(); x++)
        for (auto y = 0; y < Height(); y++) {
            auto idx = (Height() - y - 1) * Width() + x;
            if (idx < 0 || idx >= Width() * Height())
                continue;
            pixels[idx] = GetColor(x, y);
        }
    stbi_write_png(filepath, Width(), Height(), 4, pixels.data(), Width() * 4);
}
