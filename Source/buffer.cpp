#include "buffer.h"

#include "log.h"
#include "color.h"

using namespace SoftwareRenderer;
using namespace std;

ColorBuffer::ColorBuffer() : ColorBuffer(0, 0) {}

ColorBuffer::ColorBuffer(int width, int height)
    : ColorBuffer(width, height, Color()) {}

ColorBuffer::ColorBuffer(int width, int height, Color color) {
  _width = width;
  _height = height;
  _pixels.resize(_width * _height);
  for (auto i = 0; i < _width * _height; i++) _pixels[i] = color;
}

int ColorBuffer::Width() { return _width; }

int ColorBuffer::Height() { return _height; }

const vector<Color>& ColorBuffer::Pixels() { return _pixels; }