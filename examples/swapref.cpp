// swapref.cpp
// Compile with: g++ swapref.cpp -o swapref

#include <iostream>

using namespace std;

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

void swap(double &i, double &j) {
    double temp = i;
    i = j;
    j = temp;
}

int main()
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    cout << "inputs: " << m << ", " << n << endl;
    swap(m, n);
    cout << "outputs: " << m << ", " << n << endl;
    
    cout << "double inputs: " << x << ", " << y << endl;
    swap(x, y);
    cout << "double outputs: " << x << ", " << y << endl;

    return 0;
}

