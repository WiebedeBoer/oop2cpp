// testlib.cpp
// Compile with: g++ testlib.cpp -o testlib -lhello

#include "libhello.h"

#include <iostream>

int main()
{
	std::cout << sum(5,3) << std::endl;
    return 0;
}

