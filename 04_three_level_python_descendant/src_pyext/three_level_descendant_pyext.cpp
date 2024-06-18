#include <pybind11/pybind11.h>
#include "../include/three_level_descendant.hpp"
#include <three_level.hpp>

// Note leading underscore (this will end up becoming three_level_descendant._three_level_descendant_pyext)
PYBIND11_MODULE(_three_level_descendant_pyext, m) {
    m.doc() = "Three-level descendant"; // optional module docstring
    m.def("add_four", &add_four, "The function n -> (n+4).");
    m.def("add_five", &add_five_descendant, "The function n -> (n+5).");
}
