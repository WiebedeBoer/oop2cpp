// exception2.cpp
// Compile with: g++ exception2.cpp -o exception2

#include <iostream>
#include <exception>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main() 
{
    try
    {
        throw myex;
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }
    return 0;
}

