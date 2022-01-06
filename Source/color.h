#pragma once

namespace SoftwareRenderer {
struct Color {
  char r;
  char g;
  char b;
  char a;

  Color() : Color(0, 0, 0, 0) {}

  Color(char r, char g, char b, char a) : r(r), g(g), b(b), a(a) {}

  static inline Color White() { return Color(255, 255, 255, 255); }

  static inline Color Black() { return Color(0, 0, 0, 0); }

  static inline Color Red() { return Color(255, 0, 0, 255); }

  static inline Color Green() { return Color(0, 255, 0, 255); }

  static inline Color Blue() { return Color(0, 0, 255, 255); }
};
} // namespace SoftwareRenderer