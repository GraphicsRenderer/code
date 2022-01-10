#include "buffer.h"

#include "log.h"
#include "vec.h"

using namespace SoftwareRenderer;
using namespace std;

ColorBuffer::ColorBuffer()
    : ColorBuffer(0, 0)
{
}

ColorBuffer::ColorBuffer(int width, int height)
    : ColorBuffer(width, height, Color::Black())
{
}

ColorBuffer::ColorBuffer(int width, int height, Color color)
{
    _width = width;
    _height = height;
    _pixels.resize(_width * _height);
    for (auto i = 0; i < _width * _height; i++)
        _pixels[i] = color;
}

int ColorBuffer::Width() const { return _width; }

int ColorBuffer::Height() const { return _height; }

const vector<Color>& ColorBuffer::Colors() const { return _pixels; }

Color ColorBuffer::GetColor(int x, int y) const
{
    auto idx = y * Width() + x;
    return _pixels[idx];
}

void ColorBuffer::SetColor(int x, int y, Color color)
{
    auto idx = y * Width() + x;
    _pixels[idx] = color;
}

void ColorBuffer::SetColors(Color color)
{
    for (auto i = 0; i < _pixels.size(); i++) {
        _pixels[i] = color;
    }
}

void ColorBuffer::SetColors(const std::vector<Color>& pixels)
{
    for (auto i = 0; i < _pixels.size(); i++) {
        if (i >= pixels.size())
            break;
        _pixels[i] = pixels[i];
    }
}
