// exception.cpp
// Compile with: g++ exception.cpp -o exception

#include <iostream>
#include <exception>

using namespace std;

int main() 
{
    try
    {
        int *i = new int[999999999999999999];
    	delete [] i;
    }
    catch (exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}

