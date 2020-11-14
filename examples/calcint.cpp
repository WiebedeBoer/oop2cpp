// calcint.cpp
// Compile with: g++ calcint.cpp -o calcint

#include <iostream>

using namespace std;

class Calc
{
public:
    int multiply(int x, int y);
    int add(int x, int y);
};

int Calc::multiply(int x, int y)
{
  return x*y;
}

int Calc::add(int x, int y)
{
  return x+y;
}

int main()
{
    Calc calc;
    cout << calc.add(5,3) << endl;
    cout << calc.multiply(5,3) << endl;

    return 0;
}

