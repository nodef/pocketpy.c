// This example demonstrates the simplest usage of pocketpy.c
#define POCKETPY_IMPLEMENTATION
#include <pocketpy.h>
#include <stdio.h>


int main() {
  // Initialize the PocketPy interpreter
  py_initialize();

  // Run a simple Python script
  const char *script = "print('Hello from PocketPy!')";
  bool ok = py_exec(script, "<string>", EXEC_MODE, NULL);
  if (!ok) {
    py_printexc();
    py_finalize();
    return 1;
  }

  // Clean up
  py_finalize();

  return 0;
}
