#include <SoftwareRenderer.h>

using namespace SoftwareRenderer;

int main() {
  InitLogger();

  LogEnableBacktrace();
  auto tex = Texture(512, 512, Color::Red());
  tex.SaveAsPNG("sample.png");
  LogDumpBacktrace();

  return 0;
}
