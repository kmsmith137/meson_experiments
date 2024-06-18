#include "../include/three_level.hpp"

// Linked into three_level._three_level_pyext
int add_three(int n)
{
    return n+3;
}

// Linked into three_level_descendant/._three_level_descendent_pyext
int add_four(int n)
{
    return n+4;
}

// Linked into three_level_descendant/libthree_level_descendant.so
int add_five(int n)
{
    return n+5;
}
