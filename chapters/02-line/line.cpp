// line.cpp

#include <SoftwareRenderer.h>
using namespace SoftwareRenderer;

void DrawLine(Texture &tex, float x1, float y1, float x2, float y2, float step,
              Color color) {
  float lx = x2 - x1, ly = y2 - y1;
  for (auto t = 0.0f; t <= 1.0f; t += step) {
    auto x = x1 + t * lx;
    auto y = y1 + t * ly;
    tex.SetColor(tex.Width() * x, tex.Height() * y, color);
  }
}

void DrawLinePixel(Texture &tex, float x1, float y1, float x2, float y2,
                   float step, Color color) {
  int px1 = x1 * tex.Width(), px2 = x2 * tex.Width();
  int py1 = y1 * tex.Height(), py2 = y2 * tex.Height();
  for (auto x = px1; x <= px2; x++) {
    auto t = (x - px1) / (float)(px2 - px1);
    auto y = (int)(t * (py2 - py1) + py1);
    tex.SetColor(x, y, color);
  }
}

int main() {
  auto tex = Texture(200, 200);

  tex.SetColors(Color::Black());
  DrawLine(tex, 0.2f, 0.2f, 0.6f, 0.6f, 0.01f, Color::Red());
  tex.SaveAsPNG("line-0.01.png");

  tex.SetColors(Color::Black());
  DrawLine(tex, 0.2f, 0.2f, 0.6f, 0.6f, 0.02f, Color::Red());
  tex.SaveAsPNG("line-0.02.png");

  tex.SetColors(Color::Black());
  DrawLinePixel(tex, 0.2f, 0.2f, 0.6f, 0.6f, 0.02f, Color::Red());
  tex.SaveAsPNG("line-pixel.png");

  tex.SetColors(Color::Black());
  DrawLinePixel(tex, 0.2f, 0.2f, 0.6f, 0.6f, 0.02f, Color::Red());
  DrawLinePixel(tex, 0.2f, 0.2f, 0.6f, 0.25f, 0.02f, Color::Green());
  DrawLinePixel(tex, 0.2f, 0.2f, 0.6f, 0.95f, 0.02f, Color::Blue());
  tex.SaveAsPNG("line-pixel-2.png");

  return 0;
}