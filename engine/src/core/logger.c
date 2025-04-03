#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 32000

b8 initalize_logging() {
  // TODO: create log file
  return TRUE;
}

void shutdown_logging() {
  // TODO: cleanup logging/write queued entries
}

KAPI void log_output(log_level level, const char *message, ...) {
  const char *level_string[6] = {"[FATAL]: ", "[ERROR]: ", "[WARNING]: ",
                                 "[DEBUG]: ", "[INFO]: ", "[TRACE] :"};
  //   b8 is_error = level < 2;

  // arena stack allocation to avoid dynamic memory allocation with malloc
  // 32K character limit on a log message... Should be enough
  char out_message[BUFFER_SIZE];
  memset(out_message, 0, sizeof(out_message));

  // format original message
  // NOTE: Oddly enough, MS's headers override the GCC/Clang va_list type with a
  // "typedef char* va_list" in some cases, and as a result throws a strange
  // error here. If this happens the __builtin_va_list can be used, which
  // is the type GCC/Clang's va_start expects.
  va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(out_message, BUFFER_SIZE, message, arg_ptr);
  va_end(arg_ptr);

  char out_message_buffer[BUFFER_SIZE];
  sprintf(out_message_buffer, "%s%s\n", level_string[level], out_message);

  // TODO: platform specific output
  printf("%s", out_message_buffer);
}
