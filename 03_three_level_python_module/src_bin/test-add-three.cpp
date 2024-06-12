#include <iostream>
#include "../include/add_three.hpp"

using namespace std;

int main(int argc, char **argv)
{
    for (int n = 1; n <= 5; n++)
	cout << n << " -> " << add_three(n) << endl;
    
    cout << "Wow, it works" << endl;
    return 0;
}
