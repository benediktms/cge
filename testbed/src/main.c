#include <core/logger.h>

int main(void) {
  KFATAL("This is a fatal error message: %d", 42);
  KERROR("This is an error message: %d", 42);
  KWARN("This is a warning message: %d", 42);
  KDEBUG("This is a debug message: %d", 42);
  KINFO("This is an info message: %d", 42);
  KTRACE("This is a trace message: %d", 42);
  return 0;
}
