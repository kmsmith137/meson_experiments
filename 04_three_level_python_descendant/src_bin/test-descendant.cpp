#include <iostream>
#include <three_level.hpp>
#include "../include/three_level_descendant.hpp"

using namespace std;

int main(int argc, char **argv)
{
    cout << "Should be 13: " << add_three(10) << endl;
    cout << "Should be 15: " << add_five_descendant(10) << endl;
    cout << "Wow, it works" << endl;
    return 0;
}
