// line.cpp

#include <algorithm>
using namespace std;
#include <SoftwareRenderer.h>
using namespace SoftwareRenderer;

void Draw(Texture& tex, Vec2f x, Vec2f y, float step, Color color)
{
    if (x.x >= y.x)
        std::swap(x, y);
    auto dir = y - x;
    for (auto t = 0.0f; t <= 1.0f; t += step) {
        auto p = x + t * dir;
        tex.SetColor(tex.Width() * p.x, tex.Height() * p.y, color);
    }
}

void DrawInPixel(Texture& tex, Vec2f x, Vec2f y, Color color)
{
    if (x.x >= y.x)
        std::swap(x, y);
    auto px = Vec2i(tex.Width() * x.x, tex.Height() * x.y);
    auto py = Vec2i(tex.Width() * y.x, tex.Height() * y.y);

    for (auto x = px.x; x <= py.x; x++) {
        auto t = (x - px.x) / (float)(py.x - px.x);
        auto y = (int)(t * (py.y - px.y) + px.y);
        tex.SetColor(x, y, color);
    }
}

int main()
{
    auto tex = Texture(200, 200);

    tex.SetColors(Color::Black());
    Draw(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.6f), 0.01f, Color::Red());
    tex.SaveAsPNG("line-0.01.png");

    tex.SetColors(Color::Black());
    Draw(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.6f), 0.02f, Color::Red());
    tex.SaveAsPNG("line-0.02.png");

    tex.SetColors(Color::Black());
    DrawInPixel(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.6f), Color::Red());
    tex.SaveAsPNG("line-pixel.png");

    tex.SetColors(Color::Black());
    DrawInPixel(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.6f), Color::Red());
    DrawInPixel(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.25f), Color::Green());
    DrawInPixel(tex, Vec2f(0.2f, 0.2f), Vec2f(0.6f, 0.95f), Color::Blue());
    tex.SaveAsPNG("line-pixel-2.png");

    return 0;
}