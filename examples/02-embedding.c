#define POCKETPY_IMPLEMENTATION
#include <pocketpy.h>
#include <stdio.h>


int main() {
  // Initialize the PocketPy interpreter
  py_initialize();

  // Define a Python function
  const char *script = "def add(a, b):\n    return a + b\n";
  bool ok = py_exec(script, "<string>", EXEC_MODE, NULL);
  if (!ok) {
    py_printexc();
    py_finalize();
    return 1;
  }

  // Call the Python function from C
  py_Ref f_add = py_getglobal(py_name("add"));
  py_push(f_add);
  py_pushnil();
  py_Ref r0 = py_getreg(0);
  py_Ref r1 = py_getreg(1);
  py_newint(r0, 5);
  py_newint(r1, 7);
  py_push(r0);
  py_push(r1);
  ok = py_vectorcall(2, 0);
  if (!ok) {
    py_printexc();
    py_finalize();
    return 1;
  }

  printf("Result: %d\n", (int)py_toint(py_retval()));

  // Clean up
  py_finalize();

  return 0;
}
