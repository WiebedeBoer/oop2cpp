// calcgen.cpp
// Compile with: g++ calcgen.cpp -o calcgen

#include <iostream>

using namespace std;

template<class T>
class Calc
{
public:
    T multiply(T x, T y);
    T add(T x, T y);
};

template<class T>
T Calc<T>::multiply(T x, T y)
{
  return x*y;
}

template<class T>
T Calc<T>::add(T x, T y)
{
  return x+y;
}

int main()
{
    Calc<double> calc;
    cout << calc.add(5.0,3.0) << endl;
    cout << calc.multiply(5.33,3.05) << endl;

    return 0;
}

