// line.cpp

#include <SoftwareRenderer.h>
using namespace SoftwareRenderer;

int main() {
  auto tex = Texture(200, 200);

  float x1 = 0.2f, y1 = 0.2f;
  float x2 = 0.6f, y2 = 0.6f;
  float lx = x2 - x1, ly = y2 - y1;

  // t changes from 0 to 1, step 0.01
  tex.SetColors(Color::Black());
  for (auto t = 0.0f; t <= 1.0f; t += 0.01f) {
    auto x = x1 + t * lx;
    auto y = y1 + t * ly;
    tex.SetColor(tex.Width() * x, tex.Height() * y, Color(255, 0, 0));
  }
  tex.SaveAsPNG("line-0.01.png");

  // t changes from 0 to 1, step 0.02
  tex.SetColors(Color::Black());
  for (auto t = 0.0f; t <= 1.0f; t += 0.02f) {
    auto x = x1 + t * lx;
    auto y = y1 + t * ly;
    tex.SetColor(tex.Width() * x, tex.Height() * y, Color(255, 0, 0));
  }
  tex.SaveAsPNG("line-0.02.png");

  // x changes from pixel min x to max x
  tex.SetColors(Color::Black());
  int px1 = x1 * tex.Width(), px2 = x2 * tex.Width();
  int py1 = y1 * tex.Height(), py2 = y2 * tex.Height();
  for (auto x = px1; x <= px2; x++) {
    auto t = (x - px1) / (float)(px2 - px1);
    auto y = (int)(t * (py2 - py1) + py1);
    tex.SetColor(x, y, Color(255, 0, 0));
  }
  tex.SaveAsPNG("line-pixel.png");

  return 0;
}