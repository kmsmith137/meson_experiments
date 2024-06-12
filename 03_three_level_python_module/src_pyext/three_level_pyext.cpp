#include <pybind11/pybind11.h>
#include "../include/add_three.hpp"

int add_two(int n) {
    return n + 2;
}

// Note leading underscore (this will end up becoming three_level._three_level_pyext)
PYBIND11_MODULE(_three_level_pyext, m) {
    m.doc() = "Level two!"; // optional module docstring
    m.def("add_two", &add_two, "The function n -> (n+2).");
    m.def("add_three", &add_three, "The function n -> (n+3).");
}
