#include "../include/three_level_descendant.hpp"
#include <three_level.hpp>  // add_five()

// Calls add_five() in libthree_level.so
int add_five_descendant(int n)
{
    return add_five(n);
}
