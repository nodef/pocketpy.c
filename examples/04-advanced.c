#define POCKETPY_IMPLEMENTATION
#include <math.h>
#include <pocketpy.h>
#include <stdio.h>


// Custom C function to calculate the hypotenuse using the math library
static bool c_hypotenuse(int argc, py_Ref argv) {
  PY_CHECK_ARGC(2);
  PY_CHECK_ARG_TYPE(0, tp_float);
  PY_CHECK_ARG_TYPE(1, tp_float);
  double a = py_tofloat(py_arg(0));
  double b = py_tofloat(py_arg(1));
  py_newfloat(py_retval(), sqrt(a * a + b * b));
  return true;
}


int main() {
  // Initialize the PocketPy interpreter
  py_initialize();

  // Register the custom C function
  py_Ref hypotenuse_func = py_getreg(0);
  py_newnativefunc(hypotenuse_func, c_hypotenuse);
  py_setglobal(py_name("hypotenuse"), hypotenuse_func);

  // Use the custom function in a Python script
  const char *script = "a = 3.0\n"
                       "b = 4.0\n"
                       "result = hypotenuse(a, b)\n"
                       "print(f\"The hypotenuse of a triangle with sides {a} "
                       "and {b} is {result}\")\n";

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
