#define POCKETPY_IMPLEMENTATION
#include <pocketpy.h>
#include <stdio.h>


// Custom C function to be exposed to Python
static bool c_multiply(int argc, py_Ref argv) {
  PY_CHECK_ARGC(2);
  PY_CHECK_ARG_TYPE(0, tp_int);
  PY_CHECK_ARG_TYPE(1, tp_int);
  py_i64 a = py_toint(py_arg(0));
  py_i64 b = py_toint(py_arg(1));
  py_newint(py_retval(), a * b);
  return true;
}


int main() {
  // Initialize the PocketPy interpreter
  py_initialize();

  // Register the custom C function
  py_Ref multiply_func = py_getreg(0);
  py_newnativefunc(multiply_func, c_multiply);
  py_setglobal(py_name("multiply"), multiply_func);

  // Use the custom function in a Python script
  const char *script = "result = multiply(6, 9)\nprint(f'6 * 9 = {result}')";
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
