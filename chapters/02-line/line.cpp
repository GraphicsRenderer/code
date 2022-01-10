// line.cpp

#include <algorithm>
using namespace std;
#include <SoftwareRenderer.h>
using namespace SoftwareRenderer;

void Draw(Texture& tex, Vec2f x, Vec2f y, float step, Color color)
{
    if (x.X() >= y.X())
        std::swap(x, y);
    auto dir = y - x;
    for (auto t = 0.0f; t <= 1.0f; t += step) {
        auto p = x + dir * t;
        tex.SetColor(tex.Width() * p.X(), tex.Height() * p.Y(), color);
    }
}

void DrawInPixel(Texture& tex, Vec2f x, Vec2f y, Color color)
{
    if (x.X() >= y.X())
        std::swap(x, y);
    auto px = Vec2i(tex.Width() * x.X(), tex.Height() * x.Y());
    auto py = Vec2i(tex.Width() * y.X(), tex.Height() * y.Y());

    for (auto x = px.X(); x <= py.X(); x++) {
        auto t = (x - px.X()) / (float)(py.X() - px.X());
        auto y = (int)(t * (py.Y() - px.Y()) + px.Y());
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