// libhello.cpp
// Compile with: g++ -shared -fPIC libhello.cpp -o libhello.so

#include "libhello.h"

int sum(int i, int j)
{
    return i + j;
}

