#include <pybind11/pybind11.h>
#include "../include/three_level.hpp"

int add_two(int n) {
    return n + 2;
}

PYBIND11_MODULE(three_level_pybind11, m) {
    m.doc() = "Level two!"; // optional module docstring
    m.def("add_two", &add_two, "The function n -> (n+2).");
    m.def("add_three", &add_three, "The function n -> (n+3).");
}
