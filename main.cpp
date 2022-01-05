#include <SoftwareRenderer.h>

using namespace SoftwareRenderer;

int main() {
  InitLogger();
  LogInfo("Hello World!");
  LogError("Hello World!");
  LogWarn("Hello World!");
  LogEnableBacktrace();
  LogDebug("Hello World!");
  auto one = Vector3(1, 1, 1);
  LogDumpBacktrace();
  return 0;
}
